#include<stdio.h>
#include<stdlib.h>

int f(int x){   // TYP<np int, float, void...> NAZWA <dowolna ale bez spacji> (...) <parametry przekazywane w nawiasach> 
    int x2 = x*x;
    int result = 2*x2 + 3*x - 3;

    return result;      // jesli funkcja nie jest voidem to MUSI zwracac watość tego samego TYPU co przy deklaracji funkcji
}

int oblicz(int a, int b, int c, int x){
    return (a*x*x) + (b*x) + c;
}

void wypisz(int a, int b){
    printf("%d %d", a, b);
}

//////////////////zmiana wartosci w srodku funkcji///////////////////////

void dodajCos(int liczba, int doDodania){   //funkcja kopiuje wartosci i operuje na skopiowanych
    liczba += doDodania;
}

void dodajCosWskaznik(int *liczba, int doDodania){      // https://stackoverflow.com/questions/2229498/passing-by-reference-in-c - funkcja pobiera adres i operuje na nim
    (*liczba) += doDodania;
}

////////////////tablice//////////////////////

void wypiszTabliceJednowymiarowa(int n, int *tab){
    printf("\nzawartosc tablicy: ");
    for(int i = 0; i< n; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
}

int *tablicaJednowymiarowa(int n, int a){
    int *tab = malloc(sizeof(int)*n);       // deklarujemy wskaznik a nastepnie 'rezerwujemy' dla niego n miejsc o rozmiarze int

    tab[0] = a;

    for(int i=1; i < n; i++){
        tab[i] = *(tab+i-1)+1;    //dodajemy do tab[i] poprzedni element+1
    }

    return tab;
}

int main(){
    int a=2, b=3, c=1, x=2; 

    printf("%d %d\n", f(x), oblicz(a,b,c,x));

    printf("\na: %d", a);
    dodajCos(a,2);  // kopiujemy wartosci do funkcji
    printf("\n'a' po dodajCos(a,2): %d", a);
    dodajCosWskaznik(&a,2);  //przekazujemy adres pamieci a nastepnie zmieniamy wartosc ktora przechowywal
    printf("\n'a' po dodajCosWskaznik(a,2): %d\n", a);

    printf("\n//////////tablice//////////\n");

    printf("int *tablica = tablicaJednowymiarowa(10,37)");
    int *tablica = tablicaJednowymiarowa(10, 37);
    wypiszTabliceJednowymiarowa(10, tablica);

    ///// sizeof
    printf("\nrozmiar: %d", sizeof(tablica));  // NIGDY TAK NIE ROBIMY BO SIE PIERDOLI


    return 0;
}