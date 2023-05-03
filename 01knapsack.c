#include <stdio.h>
#include <stdlib.h>

struct Item{
    int weight;
    int profit;
};

struct Node{
    int weight;
    int profit;
    int level;
    int bound;
};

int cmp(const void* a,const void* b){
    struct Item* item1=(struct Item*)a;
    struct Item* item2=(struct Item*)b;
    double r1=(double)item1->profit/item1->weight;
    double r2=(double)item2->profit/item2->weight;
    return r2>r1;
}

int calculateBound(struct Node u,int W,int n,struct Item arr[]){
    if(u.weight>=W){
        return 0;
    }
    int j=u.level+1;
    int totalW=u.weight;
    int profitBound=u.profit;
    while(j<n && (totalW+arr[j].weight<=W)){
        profitBound+=arr[j].profit;
        totalW+=arr[j].weight;
        j++;
    }
    if(j<n){
        profitBound += arr[j].profit*(W-totalW)/arr[j].weight;
    }
    return profitBound;
}

int knapsackBB(int W,int n,struct Item arr[]){
    qsort(arr,n,sizeof(struct Item),cmp);   // sort in decreasing order of profit/weight
    struct Node u,v;
    u.level=-1;
    u.profit=u.weight=0;
    struct Node queue[1000];
    int front=0,rear=0;
    int maxProfit=0;
    queue[rear++]=u;
    while(front<rear){
        u=queue[front++];
        if(u.level==-1){
            v.level=0;
        }
        if(u.level==n-1){
            continue;
        }
        v.level=u.level+1;
        v.profit=u.profit+arr[v.level].profit;  // taking v
        v.weight=u.weight+arr[v.level].weight;
        if(v.weight<=W && v.profit>maxProfit){
            maxProfit=v.profit;
        }
        v.bound=calculateBound(v,W,n,arr);
        if(v.bound>maxProfit){
            queue[rear++]=v;
        }
        v.profit=u.profit;  // not taking v
        v.weight=u.weight;
        v.bound=calculateBound(v,W,n,arr);
        if(v.bound>maxProfit){
            queue[rear++]=v;
        }
        // printf("%d\n",maxProfit);

    }
    return maxProfit;
}

int main(){
    int n,W;
    printf("Enter number of items: ");
    scanf("%d",&n);
    printf("Enter maximum capacity of knapsack: ");
    scanf("%d",&W);
    struct Item arr[n];
    printf("Enter weight and profit of items: ");
    for(int i=0;i<n;i++){
        scanf("%d%d",&arr[i].weight,&arr[i].profit);
    }
    printf("Maximum Profit: %d",knapsackBB(W,n,arr));

    return 0;
}