#include <stdio.h>

void merge(int arr[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=arr[m+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<R[i]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int l,int r){
    
    if(l<r){
        int m=l+(r-l)/2;

        mergesort(arr,l,m);
        mergesort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}

void swap(int* a,int* b){
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

int partitionL(int arr[],int low,int high){
    int pivot=arr[low];
    int i=high;

    for(int j=high;i>low;i--){
        if(arr[j]>pivot){
            swap(&arr[i--],&arr[j]);
        }
    }
    swap(&arr[low],&arr[i]);
    return i;
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);

        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
int main(){
    int n;

    return 0;
}