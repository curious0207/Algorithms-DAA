#include <stdio.h>
#include <stdbool.h>

int n;

int safe(int row, int col, int ans[][n]){
    for(int i=0;i<row;i++){     // check columns.
        if(ans[i][col]==1){
            return 0;
        }
    }
    int i=row-1,j=col-1;
    while(i>=0 && j>=0){
        if(ans[i][j]==1){
            return 0;
        }
        i--;
        j--;
    }
    i=row-1,j=col+1;
    while(i>=0 && j<n){
        if(ans[i][j]==1){
            return 0;
        }
        i--;
        j++;
    }
    return 1;
}

bool nQueens(int ans[][n],int row){
    
    if (row == n) {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ans[i][j]==1)
                    printf("Q ");
                else
                    printf(". ");
            }
            printf("\n");
        }
        printf("\n\n");
        return false;
    }
    
    for (int i = 0; i < n; i++) {
        
        if (safe(row, i, ans)) {
            ans[row][i] = 1;
            bool nextQueencheck=nQueens(ans, row + 1);
            if(nextQueencheck==true){
                return true;
            }
            ans[row][i]=0; // false backtrack.
        }
    }
    return false;
}

int main(){
    printf("Enter number of queens: ");
    scanf("%d",&n);
    int ans[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j]=0;
        }
    }

    nQueens(ans,0);

    return 0;
}