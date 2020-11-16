#include<stdio.h>

int main(){
    FILE *zw;
    char zp;
    printf("podaj jedna literke: ");
    zw=fopen("/home/vulpes/Desktop/Studia/PP Lab/lab4/xD.txt","a");   //c:\\folder\\nasz_plik.txt

    for(int i=0; i < 13; i++){
        scanf("%c", &zp);
    fputc(zp,zw); // wczytanie do pliku.
    }

    fclose(zw);

    return 0;
}