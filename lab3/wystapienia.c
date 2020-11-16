#include <stdio.h>

int main() {
    int x, n, a, res=0;

    scanf("%d %d", &x, &n);
    
    for(int i=0; i<n;i++){
        scanf("%d", &a);
        if(a == x){
            res++;
        }
    }

    printf("\n%d\n", res);

    return 0;
}

