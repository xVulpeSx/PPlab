#include <stdio.h>

int main() {
    int n, maksi=-1, a=-1;

    scanf("%d", &n);

    scanf("%d", &maksi);

    for(int i=1;i<n;i++){
        scanf("%d", &a);
        if(a > maksi){
            maksi = a;
        }
    }

    printf("%d\n", maksi);

    return 0;
}

