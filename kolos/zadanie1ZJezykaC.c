#include<stdio.h>

int nww(int a, int b){
    int aV = a, bV = b;
    while(a != b){
        if(a < b){
            a+=aV;
        }else{
            b+=bV;
        }
    }

    return a;
}

int main(){

    int n, a, b;

    printf("Podaj ilosc zestawow danych - min. 1 max 20\n");
    scanf("%d", &n);

    while (n<1 || n > 20){
        printf("podales nie prawidlowa liczbe prob!!!\n");
        printf("Podaj ilosc zestawow danych - min. 1 max 20\n");
        scanf("%d", &n);
    }

    int * tab = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        printf("to %d zestaw danych:\n", i+1);
        printf("podaj liczbe uczniow z grupy pierwszej i drugiej(min. 10 max 30)\n");
        scanf("%d %d", &a, &b);

        while (a < 10 || a > 30 || b < 10 || b > 30){
            printf("podales nie prawidlowa wartosc!\n");
            printf("podaj liczbe uczniow z grup(min. 10 max 30)\n");
            scanf("%d %d", &a, &b);
        }
        ///////dane

        tab[i] = nww(a,b);
    }

    for(int i = 0; i < n; i++){
        printf("dla %d zestawu danych odpowiedz to: %d\n", i+1, tab[i]);
    }
    
    return 0;
}