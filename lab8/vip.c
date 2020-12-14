#include<stdio.h>

int vip(int d){
    int * ileOsobJaZna = calloc(d, sizeof(int));
    int * ileOsobZnaOsoba = calloc(d, sizeof(int));

    int pom;

    for(int i = 0; i < d; i++){
        int sum=0;
        for(int j=0; j < d; j++){
            scanf("%d", &pom);
            ileOsobJaZna[j]+= pom;
            sum+=pom;
        }
        ileOsobZnaOsoba[i] = sum;
    }

    for(int i = 0; i < d; i++){
        if(ileOsobZnaOsoba[i] == 1 && ileOsobJaZna[i] == d){
            pom = i+1;
        }
    }
    
    free(ileOsobJaZna);
    free(ileOsobZnaOsoba);
    return pom;
}

int main(){
    int n, d;

    scanf("%d", &n);

    for(int i= 0; i < n; i++){
        scanf("%d", &d);

        printf("%d\n", vip(d));
    }

    return 0;
}