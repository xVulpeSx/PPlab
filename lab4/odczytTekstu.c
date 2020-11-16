#include<stdio.h>

int main(){
    FILE *zw;
    char zp;
    zw=fopen("c:\\folder\\nasz_plik.txt","r");   //c:\\folder\\nasz_plik.txt -- pamietaj o zmianie typu z a lub w na odczyt - r

    for(int i=0; i < 10; i++){
        zp = getc(zw);
        putc(zp, stdout);
    }

    fclose(zw);

    return 0;
}