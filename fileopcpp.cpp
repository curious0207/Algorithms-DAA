#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <chrono>

using namespace std;

void selectionsort(int array[],int end){
    for(int i=0;i<end;i++){
      int mini=i;
      for(int j=i+1;j<end;j++){
        if(array[j]<array[mini]){
          mini=j;
        }
      }
      int temp=array[i];
      array[i]=array[mini];
      array[mini]=temp;
    }
}

void insertionsort(int a[],int n){
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
}

int main(){
    int n=200;
    ofstream fout;
    fout.open("randomcpp.txt");
    
    srand(time(0));
    for(int i=1;i<=n;i++){
        int r=rand()%100;
        fout<<r<<endl;
    }
    fout.close();

    ifstream fin;
    int block=1;
    for(int i=100;i<=n;i+=100){
        fin.open("randomcpp.txt");
        int arr[i];     // i size
        for(int j=0;j<i;j++){
            fin>>arr[j];
        }
        fin.close();

        using namespace std::chrono;
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        selectionsort(arr,i);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

        fin.open("randomcpp.txt");
        int arr2[i];     // i size
        for(int j=0;j<i;j++){
            fin>>arr2[j];
        }
        fin.close();

        high_resolution_clock::time_point tis1 = high_resolution_clock::now();
        insertionsort(arr2,i);
        high_resolution_clock::time_point tis2 = high_resolution_clock::now();
        duration<double> time_spanis = duration_cast<duration<double>>(tis2 - tis1);

        cout<<"Block "<<block <<" took "<<time_span.count()<<" seconds for Selection sort and "<<time_spanis.count()<<" seconds for InsertionSort\n";

        block++;
    }   


    return 0;
}