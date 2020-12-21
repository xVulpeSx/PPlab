#include<stdio.h>

int main(){

    int n, a, b;

    printf("Podaj wielkosc taablicy - min. 1 max 100\n");
    scanf("%d", &n);

    while (n<1 || n > 100){
        printf("podales nie prawidlowy rozmiar!!!\n");
        printf("Podaj wielkosc talbicy - min. 1 max 100\n");
        scanf("%d", &n);
    }

    int * tab = malloc(sizeof(int) * n);

    printf("Podaj wszystkie elementy tablicy (conajmniej 1 podzielny przez 3):\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &tab[i]);
    }

    printf("tablica bez elementow podzielnych przez 3:\n");
    for(int i=0; i < n; i++){
        if(tab[i] %3 != 0){
            printf("%d ", tab[i]);
        }
    }
    
    return 0;
}