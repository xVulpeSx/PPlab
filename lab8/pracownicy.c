#include<stdio.h>

struct dane_os
{
    char imie[32], nazwisko[32], pesel[11];
};

struct Pracownicy{
    struct dane_os daneOsobowe;
    int wyplaty[12];
};

int main(){

    return 0;
}
