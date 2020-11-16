#include<stdio.h>

int main(){
    FILE *zw;
    char zp;
    zw=fopen("c:\\folder\\nasz_plik.txt","w");   //c:\\folder\\nasz_plik.txt

    char tab[10]={"Nasz tekst"};

    for(int i=0; i < 10; i++){
        fputc(tab[i], zw);
    }

    fclose(zw);

    return 0;
}