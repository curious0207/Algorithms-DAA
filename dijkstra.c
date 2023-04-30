#include <stdio.h>
#include <limits.h>
#include <stdbool.h>


void printpath(int curridx,int parent[]){
    if(curridx==-1){
        return;
    }
    printpath(parent[curridx],parent);
    printf("%d ",curridx);
}
int minDistance(int dist[],bool sptset[],int v){
    int mindist=INT_MAX,minidx;
    for(int i=0;i<v;i++){
        if(!sptset[i] && dist[i]<mindist){
            mindist=dist[i];
            minidx=i;
        }
    }
    return minidx;
}

void dijkstras(int v,int graph[][v],int src){

    bool stpset[v];  // included in the path or not.
    int dist[v];
    int parent[v];
    for(int i=0;i<v;i++){
        dist[i]=INT_MAX;
        stpset[i]=false;
    }
    dist[src]=0;
    parent[src]=-1;

    for(int i=0;i<v-1;i++){
        int u=minDistance(dist,stpset,v);   // selected vertex.
        stpset[u]=true;

        for(int ver=0;ver<v;ver++){
            if(!stpset[ver] && dist[u]!=INT_MAX && graph[u][ver] && dist[u]+graph[u][ver]<dist[ver]){
                dist[ver]=dist[u]+graph[u][ver];
                parent[ver]=u;
            }
        }
    }

    printf("Vertex\t\tDistance   Path:\n");
    for(int i=0;i<v;i++){
       if(i!=src){
        printf("\n %d -> %d\t\t%d \t",src,i,dist[i]);
        printpath(i,parent);
       }
    }

}
int main(){

    int V;
    printf("Enter number of vertices: ");
    scanf("%d",&V);
    int graph[V][V];
    int src;
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("Enter starting vertex: ");
    scanf("%d",&src);
    dijkstras(V,graph,src);
    return 0;
}


/*
// Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]


*/