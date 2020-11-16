#include <stdio.h>

int main() {
    int x, n, a, res=0;

    scanf("%d %d", &x, &n);
    
    for(int i=0; i<n;i++){
        scanf("%d", &a);
        if(a == x){
            res++;
        }
    }

    FILE *zw;
    zw=fopen("c:\\folder\\wynik.txt","w");   //c:\\folder\\nasz_plik.txt -- pamietaj o zmianie typu odczyt czy zapis

    fprintf(zw, "%d", res); // https://stackoverflow.com/questions/2229377/writing-an-integer-to-a-file-with-fputs 


    fclose(zw);

    return 0;
}

