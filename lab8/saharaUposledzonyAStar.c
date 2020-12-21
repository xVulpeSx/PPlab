#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define gora 2
#define prawo 4
#define dol 1
#define lewo 3
#define INF 9999999

struct Sahara
{
    int value;
    int source; // ustawione w kolejnosci leksykograficznej
};

struct Wsp
{
    int x,y;
};

struct Wsp goal;

int inRange(int x, int y, int n, int m){
    // printf("R: x: %d, y: %d, n: %d, m: %d V:", x, y, n, m);
    if(x < 0 || y < 0 || x >= n || y >= m){
        // printf("0\n");
        return 0;
    }
    // printf("1\n");
    return 1;
}

int distanceToGoalSquare(int x, int y){
    int xDiff=goal.x-x, yDiff=goal.y-y;
    return (xDiff*xDiff)+(yDiff*yDiff);
}

int minFromTab(int * tab){  // INF jak nie ma wynikow a tak to indeks najlepszego
    int min = tab[0];
    for(int i = 2; i < 5; i++){
        if(tab[i] < min){
            min = i;
        }
    }
    return min;
}

void dickStraNaSterydach(struct Sahara ** pustynia, int n, int m, struct Wsp start){
    struct Wsp newStart;
    int currentValue = pustynia[start.x][start.y].value + 1;
    int tab[5];
    for(int i=0;i < 5;i++){
        tab[i] = INF;
    }
    // printf("D: start.x: %d start.y: %d value: %d\n", start.x, start.y, currentValue);

    if(inRange(start.x+1, start.y,n,m) == 1){
        // printf("value: %d\n", pustynia[start.x+1][start.y].value);
        if(pustynia[start.x+1][start.y].value > currentValue){
            pustynia[start.x+1][start.y].source = gora;
            pustynia[start.x+1][start.y].value = currentValue;
            tab[gora] = distanceToGoalSquare(start.x+1, start.y);
        }
    }
    if(inRange(start.x-1, start.y,n,m) == 1){
        // printf("value: %d\n", pustynia[start.x-1][start.y].value);
        if(pustynia[start.x-1][start.y].value > currentValue){
            pustynia[start.x-1][start.y].source = dol;
            pustynia[start.x-1][start.y].value = currentValue;
            tab[dol] = distanceToGoalSquare(start.x-1, start.y);
        }
    }
    if(inRange(start.x, start.y+1, n, m) == 1){
        // printf("value: %d\n", pustynia[start.x][start.y+1].value);
        if(pustynia[start.x][start.y+1].value > currentValue){
            pustynia[start.x][start.y+1].source = lewo;
            pustynia[start.x][start.y+1].value = currentValue;
            tab[lewo] = distanceToGoalSquare(start.x, start.y+1);
        }
    }
    if(inRange(start.x, start.y-1, n, m) == 1){
        // printf("value: %d\n", pustynia[start.x][start.y-1].value);
        if(pustynia[start.x][start.y-1].value > currentValue){
            pustynia[start.x][start.y-1].source = prawo;
            pustynia[start.x][start.y-1].value = currentValue;
            tab[prawo] = distanceToGoalSquare(start.x, start.y-1);
        }
    }
    int min = minFromTab(tab);
    while(min != INF){
        if(min == prawo){
            start.y--;
        }else if(min == lewo){
            start.y++;
        }else if(min == gora){
            start.x++;
        }else if(min == dol){
            start.x--;
        }
        tab[min] = INF;
        dickStraNaSterydach(pustynia, n,m, start);
        min = minFromTab(tab);
    }
    

}

void task(int n, int m){
    struct Sahara ** pustynia = malloc(n*sizeof(struct Sahara));
    for(int i = 0; i < n; i++){
        pustynia[i] = malloc(m*sizeof(struct Sahara));
    }
    char pom;
    struct Wsp start;

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
                goal.x = i;
                goal.y = j;
                pustynia[i][j].value = INF;
                pustynia[i][j].source = -1;
            }
        }
    }
    ///////////////////////////////////////////////////
    // printf("poWczytaniu: startx: %d starty: %d celx: %d cely: %d\n", start.x, start.y, koniec.x, koniec.y);
    // dickStra(pustynia, n, m, start);
    // printf("poDickStra\n");

    int x = goal.x, y = goal.y, source;

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