#include <stdio.h>

int main() {
    int n, naj=2, naj2=1, a;

    scanf("%d", &n);
    
    for(int i=0; i<n;i++){
        scanf("%d", &a);
        if(a > naj){
            naj2 = naj;
            naj = a;
        }else if(a > naj2){
            naj2 = a;
        }
    }

    FILE *fileWrite;
    fileWrite=fopen("c:\\folder\\nasz_plik.txt","w");   //c:\\folder\\nasz_plik.txt -- pamietaj o zmianie typu odczyt czy zapis

    fprintf(fileWrite, "%d %d", naj, naj2); // https://stackoverflow.com/questions/2229377/writing-an-integer-to-a-file-with-fputs 


    fclose(fileWrite);

    return 0;
}