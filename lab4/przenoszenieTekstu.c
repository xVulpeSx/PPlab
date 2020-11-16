#include <stdio.h>

int main() {
    char pom;
    FILE *fileWrite, *fileRead;

    fileRead = fopen("c:\\folder\\pierwszy.txt","r");   //c:\\folder\\nasz_plik.txt -- pamietaj o zmianie typu odczyt czy zapis
    fileWrite = fopen("c:\\folder\\drugi.txt","w");   //c:\\folder\\nasz_plik.txt -- pamietaj o zmianie typu odczyt czy zapis

    pom = getc(fileRead);
    while (pom != EOF)
    {
        putc(pom,fileWrite);
        pom = getc(fileRead);
    }

    fclose(fileWrite);
    fclose(fileRead);

    return 0;
}