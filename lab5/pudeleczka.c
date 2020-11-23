#include <stdio.h>

int zawartosc(int tab[], int begin, int end){
    int res = 0;
    for(int i=begin-1;i<end;i++){
        res+=tab[i];
    }

    return res;
}

int main() {
   int pudelka[1000];
   int n, x, begin, end, pom;

   scanf("%d", &x);

   for(int i=0;i<x;i++){
       scanf("%d", &pom);
       pudelka[i] = pom;
   }

   scanf("%d", &n);

   for(int i = 0; i < n; i++){
       scanf("%d %d", &begin, &end);
        printf("%d\n", zawartosc(pudelka,begin,end));
   }

    return 0;
}