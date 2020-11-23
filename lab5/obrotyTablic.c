#include<stdio.h>

void obracajPrawo(int tab[100][100], int n, int m){
    for(int j = 0; j<m; j++){
        for(int i = n-1; i>=0; i--){
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

void obracajLewo(int tab[100][100], int n, int m){
    for(int j = m-1; j>=0; j--){
        for(int i = 0; i < n; i++){
          printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n, m, tab[100][100];

    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0;j<m;j++){
            scanf("%d", &tab[i][j]);
        }
    }

    obracajLewo(tab, n, m);

}