#include<stdio.h>
#include<stdlib.h>



int main(){
   int *tab;
   tab = malloc(sizeof(int) * 100);

   for(int i= 0 ; i < 100; i++){
       tab[i] = i;
   }

   free(tab);

    return 0;
}