#include<stdio.h>

int main(){
    int n, res=0, tab[1000];

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &tab[i]);
        res+=tab[i];
    }

    printf("%d", res);

    return 0;
}