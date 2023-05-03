#include <stdio.h>
#include <stdlib.h>

struct Item{
    int profit;
    int weight;
};

int cmp(const void* a,const void* b){
    struct Item* item1=(struct Item*)a;
    struct Item* item2=(struct Item*)b;
    double r1=(double) item1->profit/item1->weight;
    double r2=(double) item2->profit/item2->weight;
    return r2>r1;
}
double fractionalknapsack(int W,int n,struct Item arr[]){
    qsort(arr,n,sizeof(struct Item),cmp);
    double maxProfit=0.0;

    for(int i=0;i<n;i++){
        if(arr[i].weight<=W){
            W-=arr[i].weight;
            maxProfit+=arr[i].profit;
        }
        else{
            maxProfit+=(double)arr[i].profit * (W/ (double)arr[i].weight);
            break;
        }
    }
    return maxProfit;
}

int main(){
    int W,n;
    printf("Enter number of items: ");
    scanf("%d",&n);
    printf("Enter max capacity: ");
    scanf("%d",&W);
    struct Item arr[n];
    printf("Enter weights and profits:\n");
    for(int i=0;i<n;i++){
        scanf("%d %d",&arr[i].weight,&arr[i].profit);
    }
    printf("Maximum profit: %f",fractionalknapsack(W,n,arr));
}