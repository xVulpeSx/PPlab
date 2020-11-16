//
// Created by vulpes on 26.10.2020.
//

#include <stdio.h>

int main() {
    int a, b;
    printf("podaj a oraz b:\n");
    scanf("%d %d", &a, &b);

    if(a > 100 || a < -100){
        printf("błędne A");
    }else if(b > 100 || b < -100){
        printf("bledne B");
    }else{
        printf("\n%d", a + b);
    }

    return 0;
}
