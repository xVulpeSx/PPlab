#include<stdio.h>
#include<string.h>

#define gora 1
#define prawo 2
#define dol 3
#define lewo 4
#define INF 2001

struct Sahara
{
    int value;
    int source; // 1 - gora, 2- prawo, 3-dol, 4-lewo, 0 start
};

struct Wsp
{
    int x,y;
};

int inRange(int x, int y, int n, int m){
    // printf("R: x: %d, y: %d, n: %d, m: %d V:", x, y, n, m);
    if(x < 0 || y < 0 || x >= n || y >= m){
        // printf("0\n");
        return 0;
    }
    // printf("1\n");
    return 1;
}

void dickStra(struct Sahara ** pustynia, int n, int m, struct Wsp start){
    struct Wsp newStart;
    int currentValue = pustynia[start.x][start.y].value + 1;

    // printf("D: start.x: %d start.y: %d value: %d\n", start.x, start.y, currentValue);

    if(inRange(start.x+1, start.y,n,m) == 1){
        // printf("value: %d\n", pustynia[start.x+1][start.y].value);
        if(pustynia[start.x+1][start.y].value > currentValue){
            newStart.x = start.x+1;
            newStart.y = start.y;
            pustynia[newStart.x][newStart.y].source = gora;
            pustynia[newStart.x][newStart.y].value = currentValue;
            dickStra(pustynia, n, m, newStart);
        }
    }
    if(inRange(start.x-1, start.y,n,m) == 1){
        // printf("value: %d\n", pustynia[start.x-1][start.y].value);
        if(pustynia[start.x-1][start.y].value > currentValue){
            newStart.x = start.x-1;
            newStart.y = start.y;
            pustynia[newStart.x][newStart.y].source = dol;
            pustynia[newStart.x][newStart.y].value = currentValue;
            dickStra(pustynia, n, m, newStart);
        }
    }
    if(inRange(start.x, start.y+1, n, m) == 1){
        // printf("value: %d\n", pustynia[start.x][start.y+1].value);
        if(pustynia[start.x][start.y+1].value > currentValue){
            newStart.x = start.x;
            newStart.y = start.y+1;
            pustynia[newStart.x][newStart.y].source = lewo;
            pustynia[newStart.x][newStart.y].value = currentValue;
            dickStra(pustynia,n, m, newStart);
        }
    }
    if(inRange(start.x, start.y-1, n, m) == 1){
        // printf("value: %d\n", pustynia[start.x][start.y-1].value);
        if(pustynia[start.x][start.y-1].value > currentValue){
            newStart.x = start.x;
            newStart.y = start.y-1;
            pustynia[newStart.x][newStart.y].source = prawo;
            pustynia[newStart.x][newStart.y].value = currentValue;
            dickStra(pustynia, n, m, newStart);
        }
    }
}

void task(int n, int m){
    struct Sahara ** pustynia = malloc(n*sizeof(struct Sahara));
    for(int i = 0; i < n; i++){
        pustynia[i] = malloc(m*sizeof(struct Sahara));
    }
    char pom;
    struct Wsp start, koniec;

    // printf("task: %d %d\n",n, m);
    ///////////////////////dane////////////////////////
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%c", &pom);
            while(pom == '\n'){
               scanf("%c", &pom); 
            }
            if(pom == '.'){
                pustynia[i][j].source = -1;
                pustynia[i][j].value = INF;
            }else if(pom == 'X'){
                pustynia[i][j].value = -1;
            }else if(pom == 'S'){
                start.x = i;
                start.y = j;
                pustynia[i][j].value = 0;
                pustynia[i][j].source = 0;
            }else{
                koniec.x = i;
                koniec.y = j;
                pustynia[i][j].value = INF;
                pustynia[i][j].source = -1;
            }
        }
    }
    ///////////////////////////////////////////////////
    // printf("poWczytaniu: startx: %d starty: %d celx: %d cely: %d\n", start.x, start.y, koniec.x, koniec.y);
    dickStra(pustynia, n, m, start);
    // printf("poDickStra\n");

    int x = koniec.x, y = koniec.y, source;

    char * result = malloc(2002 * sizeof(char));
    result[0] = 'A';
    int i=0;

    if(pustynia[x][y].value == INF){
        printf("BRAK\n");
        result[0] = 'N';    //nie ma rozwiazania
    }else{
        while(pustynia[x][y].source != 0){
            source = pustynia[x][y].source;
            if(source == gora){
                x--;
                result[i] = 'D';
            }else if(source == dol){
                x++;
                result[i] = 'G';
            }else if(source == prawo){
                y++;
                result[i] = 'L';
            }else{
                y--;
                result[i] = 'P';
            }
            i++;
        }
    }

    if(result[0] != 'N'){
        for(int i = strlen(result)-1; i >=0; i--){
            if(result[i] == 'D' || result[i] == 'G' || result[i] == 'P' || result[i] == 'L')
                printf("%c", result[i]);
        }
    }

    ///////////////////////////////////////
    free(result);
    for(int i = 0; i < n; i++){
        free(pustynia[i]);
    }
    free(pustynia);
}

int main(){
    int n, x, y;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        task(x, y);
    }

    return 0;
}