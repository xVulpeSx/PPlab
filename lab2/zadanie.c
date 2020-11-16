//
// Created by vulpes on 26.10.2020.
//
#include <stdio.h>

int main() {
    int a, res=0;
    printf("podaj zarobki:\n");
    scanf("%d", &a);

    if(a < 5000){
        res=0;
    }else if(a < 85528) {
        res += (a - 5000) * 18 / 100;
    }else{
        res+= (85528-5000)*18/100;
        a-=85528;
        res+=a*32/100;
    }

    printf("\n%d", res);
    return 0;
}
