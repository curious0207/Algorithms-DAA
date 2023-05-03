#include <stdio.h>
#include <string.h>

#define d 256
int spurioushit;

void search(char text[],char pattern[],int q){
    int M=strlen(pattern);
    int N=strlen(text);
    int p=0;
    int t=0;
    int h=1;
    int j;
    for(int i=0;i<M-1;i++){     // M-1
        h=(h*d)%q;
    }
    for(int i=0;i<M;i++){
        p=(p*d+pattern[i])%q;
        t=(t*d+text[i])%q;
    }

    for(int i=0;i<=N-M;i++){
        if(p==t){
            for(j=0;j<M;j++){
                if(pattern[j]!=text[i+j]){
                    spurioushit++;
                    break;
                }
            }
            if(j==M){
                printf("Pattern found at index %d\n",i);
            }
        }
        
        if(i<N-M){
            t=(d*(t-text[i]*h)+text[i+M]) %q;
            if(t<0){
                t=t+q;
            }
        }
    }
}

int main(){
    char text[100];
    char pattern[50];
    printf("Enter string text: ");
    scanf("%s",text);
    printf("Enter pattern to search: ");
    scanf("%s",pattern);
    int q;
    printf("Enter a prime number: ");
    scanf("%d",&q);
    search(text,pattern,q);
    printf("Spurious hits: %d",spurioushit);
    return 0;
}