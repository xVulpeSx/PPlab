#include<stdio.h>
#include<string.h>

struct Kot
{
    char imie[20], rasa[20], masc[20];
    int wiek;
};

int main(){
    struct Kot kicia;

    printf("podaj: wiek, imie, rase, i masc kota ( do 20 znakow)\n");
    scanf("%d %s %s %s", &kicia.wiek, &kicia.imie, &kicia.rasa, &kicia.masc);

    printf("\n Kot ma %d lat, wabi sie %s, jego rasa to %s, a masc to %s", kicia.wiek, kicia.imie, kicia.rasa, kicia.masc);
    
}