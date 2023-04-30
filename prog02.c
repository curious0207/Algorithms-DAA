#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionsort(int array[], int end){
  for (int i = 0; i < end; i++)
  {
    int mini = i;
    for (int j = i + 1; j < end; j++)
    {
      if (array[j] < array[mini])
      {
        mini = j;
      }
    }
    int temp = array[i];
    array[i] = array[mini];
    array[mini] = temp;
  }
}

void insertionsort(int a[], int n){
  for (int i = 1; i < n; i++){
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key){
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = key;
  }
}

int main(){

  FILE *fptr;
  fptr = fopen("randomm.txt", "w");
  if (fptr == NULL){
    printf("ERROR Creating File!");
    exit(1);
  }

  int n = 1000;
  srand(time(0));
  for (int i = 1; i <= n; i++){
    int r = rand() % 100;
    fprintf(fptr, "%d\n", r);
    // putw(r,fptr);
  }
  fclose(fptr);

  int block = 1;
  printf("Block\tSelection\tInsertion\n");
  for (int i = 100; i <= n; i += 100){
    fptr = fopen("randomm.txt", "r");
    int arr[i];     // i size

    for (int j = 0; j < i; j++){
      fscanf(fptr, "%d", &arr[j]);
    }
    clock_t t;
    t = clock();
    selectionsort(arr, i);
    t = clock() - t;
    double time_takenss = ((double)t) / CLOCKS_PER_SEC;   // in seconds

    // for(int k=0;k<i;k++){
    //     printf("%d ",arr[k]);    // sorted arr
    // }
    // printf("\n");
    fclose(fptr);

    fptr = fopen("randomm.txt", "r");
    int arr2[i]; // i size
    for (int j = 0; j < i; j++){
      //   arr[j]=getw(fptr);
      fscanf(fptr, "%d", &arr2[j]);
      //   printf("%d ",arr[j]);
    }
    clock_t t2;
    t2 = clock();
    insertionsort(arr2, i);
    t2 = clock() - t2;
    double time_takenis = ((double)t2) / CLOCKS_PER_SEC; // in seconds

    printf("%d\t%f\t%f\n", block, time_takenss, time_takenis);

    fclose(fptr);
    block++;

  }

  fclose(fptr);
  // insertion less time than selection.
  return 0;
}