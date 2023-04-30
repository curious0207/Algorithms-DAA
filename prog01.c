#include <stdio.h>
#include <math.h>

double fun1(int n){        // n log(n)
    double ans=n*log(n);
    return ans;
}
double fun2(int n){         // logn
    double ans=log(n);
    return ans;
}
double fun3(int n){         //  log(log n)
    double ans=log((log)(n));
    return ans;
}
double fun4(int n){         //  sqrt(log2 n)
    double ans=sqrt((log2)(n));
    return ans;
}
double fun5(int n){         //  2^log n
    double ans=pow(2,log(n));
    return ans;
}
double fun6(int n){         //  2^log2 n
    double ans=pow(2,log2(n));
    return ans;
}
double fun7(int n){         //  log2 n
    double ans=log2(n);
    return ans;
}
double fun8(int n){         //  root(2)^log2n
    double ans=pow(1.4142,log2(n));
    return ans;
}
double fun9(int n){          //  2^root(2*log2n)
    double root=sqrt(2*log2(n));
    double ans=pow(2,root);
    return ans;
}
double fun10(int n){          // n
    return n;
}

long long factorial(int n){
    long long pro=1;
    for(int i=1;i<=n;i++){
        pro*=i;
    }
    printf("%lld\n",pro);
}

int main()
{
    int n=100;
    printf("n\t");
    printf("Fun1\t");
    printf("Fun2\t");
    printf("Fun3\t");
    printf("Fun4\t");
    printf("Fun5\t");
    printf("Fun6\t");
    printf("Fun7\t");
    printf("Fun8\t");
    printf("Fun9\t");
    printf("Fun10\n");
    // printf("\n");
    
    for(int i=0;i<n;i++){
        printf("%d\t",i);
        double f1=fun1(i);
        printf("%.3f\t",f1);
        double f2=fun2(i);
        printf("%.3f\t",f2);
        double f3=fun3(i);
        printf("%.3f\t",f3);
        double f4=fun4(i);
        printf("%.3f\t",f4);
        double f5=fun5(i);
        printf("%.3f\t",f5);
        double f6=fun6(i);
        printf("%.3f\t",f6);
        double f7=fun7(i);
        printf("%.3f\t",f7);
        double f8=fun8(i);
        printf("%.3f\t",f8);
        double f9=fun9(i);
        printf("%.3f\t",f9);
        double f10=fun10(i);
        printf("%.3f\t",f10);
        
        printf("\n");
    }
    printf("factorials:\n");
    for(int i=1;i<=20;i++){
        factorial(i);
    }
    
    return 0;
}
