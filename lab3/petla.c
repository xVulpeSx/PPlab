#include <stdio.h>

int main() {
    int n, a;
    
    scanf("%d", &n);

    for(int i=0; i < n; i++){
        scanf("%d", &a);
        if(a < -100 && a < 100){
            printf("liczba za mala lub za duza\n");
            break;
        }else{
            if(a>0){
                printf("1\n");
            }else{
                printf("0\n");
            }
        }
    }

    return 0;
}
