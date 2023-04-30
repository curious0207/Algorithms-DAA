#include <stdio.h>
#include <string.h>

void lcs(char S1[],char S2[],int LCS_table[][20]){
    int m=strlen(S1);
    int n=strlen(S2);

    for(int i=0;i<=m;i++){
        (LCS_table[i][0])=0;
    }
    for(int j=0;j<=n;j++){
        LCS_table[0][j]=0;
    }
    for(int i=1;i<=m;i++){  // 1 to m
        for(int j=1;j<=n;j++){
            if(S1[i-1]==S2[j-1]){
                LCS_table[i][j]=LCS_table[i-1][j-1] +1;
            }
            else if(LCS_table[i-1][j]>LCS_table[i][j-1]){
                LCS_table[i][j]=LCS_table[i-1][j];
            }
            else{
                LCS_table[i][j]=LCS_table[i][j-1];
            }
        }
    }
    int idx=LCS_table[m][n];
    char ans[idx+1];
    ans[idx]='\0';
    int i=m,j=n;
    while(i>0 && j>0){
        if(S1[i-1]==S2[j-1]){
            ans[idx-1]=S1[i-1];
            i--;
            j--;
            idx--;
        }
        else if(LCS_table[i-1][j]>LCS_table[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }

    //printf("%d",m);
    printf("%s",ans);

}
int main(){
    char S1[20],S2[20];
    int LCS_table[20][20];
    printf("Enter first string: ");
    scanf("%s",S1);
    printf("Enter second string: ");
    scanf("%s",S2);
    lcs(S1,S2,LCS_table);

    return 0;
}


/*
When passing two-dimensional arrays, it is not mandatory to specify the number of rows in the array. However, the number of columns should always be specified.

*/