#include <stdio.h>
#include <limits.h>

void printParenthesis(int i,int j,int n,int* brackets,char* name){

    if(i==j){
        printf("%c",*name);
        *name=*name+1;
        return;
    }
    printf("(");
    printParenthesis(i,*((brackets+i*n)+j),n,brackets,name);
    printParenthesis(*((brackets+i*n)+j)+1,j,n,brackets,name);
    printf(")");
}

void mcm(int arr[],int n){

    int M[n][n];        // matrices are n-1 
    int brackets[n][n];
    for(int i=1;i<n;i++){   // start from 1.
        M[i][i]=0;
    }
    for(int L=2;L<n;L++){       // L is chain length or subproblem
        for(int i=1;i<n-L+1;i++){
            int j=i+L-1;
            M[i][j]=INT_MAX;

            for(int k=i;k<j;k++){
                int q=M[i][k] + M[k+1][j] + (arr[i-1]*arr[k]*arr[j]) ;
                if(q<M[i][j]){
                    M[i][j]=q;
                    brackets[i][j]=k;
                }
            }
        }
    }
    char name='A';
    printParenthesis(1,n-1,n,(int*)brackets,&name);

    printf("\n%d\n",M[1][n-1]);
    
}

int main(){

    int m;
    printf("Enter the number of matrices: ");
    scanf("%d",&m);
    int n=m+1;
    int arr[n];
    printf("Enter the dimensions: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mcm(arr,n);
    return 0;
}