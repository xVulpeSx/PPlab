//
// Created by vulpes on 26.10.2020.
//

#include <stdio.h>

int fibo(int n){
    int a=0,b=1,c=0;

    if(n==0)
        return a;
    if(n==1)
        return b;

    for(int i=2; i <= n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int main() {
    int a;
    printf("podaj ktory wyraz ciagu potrzebujesz:\n");
    scanf("%d", &a);

    if(a>30){
        printf("za duze n.");
    }else{
        int result = fibo(a);
        printf("\n%d", result);
    }

    return 0;
}

