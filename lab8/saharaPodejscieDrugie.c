// Queue implementation in C - http://www.cprogrammingnotes.com/question/dynamic-queue.html
#include <stdio.h>
#include<stdlib.h>

#define INF 555557

#define dol 0
#define gora 1
#define lewo 2
#define prawo 3

#define false 0
#define true 1

struct Wsp{
    int x,y;
};

struct Sahara{
    int value;
    int source;
    int queued;
};

////////
struct node
{
    struct Wsp data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void display();
void pushBack(struct Wsp);
void popFront();
///////
int rx[] = {-1, 1, 0, 0};   //przesuwanie sie po tablicy przy wracaniu
int ry[] = {0, 0, 1, -1};

int dx[] = {1, -1, 0, 0};   //przesuwanie sie po tablicy przy bfs
int dy[] = {0, 0, -1, 1};
char output[] = {'D', 'G', 'L', 'P'};

struct Wsp goal;

void myBfs(struct Sahara ** pustynia){
    struct Wsp curr, pom;

    while(front != NULL){
        curr.x = front->data.x;
        curr.y = front->data.y;
        for(int i = 0; i < 4; i++){
            printf("bfs: i: %d, x: %d, y: %d, if: %d\n", i, curr.x+dx[i], curr.y+dy[i], pustynia[curr.x+dx[i]][curr.y+dy[i]].queued);
            if(pustynia[curr.x+dx[i]][curr.y+dy[i]].queued == false){
                printf("im in! i: %d, queued: %d", i, pustynia[curr.x+dx[i]][curr.y+dy[i]].queued);
                pustynia[curr.x+dx[i]][curr.y+dy[i]].value = pustynia[curr.x][curr.y].value + 1;
                pustynia[curr.x+dx[i]][curr.y+dy[i]].source = i;
                pustynia[curr.x+dx[i]][curr.y+dy[i]].queued = true;
                pom.x = curr.x + dx[i];
                pom.y = curr.y + dy[i];
                if(pom.x == goal.x && pom.y == goal.y){ //skoncz jesli znajdziesz wartosci dla celu
                    return;
                }
                display();
                pushBack(pom);
                display();
            }
        }
        popFront();
    }
}

void task(int n, int m){
    printf("task: %d %d\n",n, m);
    ///////////////////////dane////////////////////////
    struct Sahara ** pustynia = malloc((n+2)*sizeof(struct Sahara));
    for(int i = 0; i < n+2; i++){
        pustynia[i] = malloc((m+2)*sizeof(struct Sahara));
    }
    // otoczenie scianami
    for(int i=0; i < n+2;i++){
        // printf("zerowane: %d %d, %d %d\n", i, 0, i, m+1);
        pustynia[i][0].value = -1;
        pustynia[i][m+1].value = -1;
        pustynia[i][0].queued = true;
        pustynia[i][m+1].queued = true;
        // printf("\tzerowane: %d %d, %d %d\n", pustynia[i][0].value, pustynia[i][m+1].value, pustynia[i][0].queued, pustynia[i][m+1].queued);

    }
    for(int i=0; i < m+2;i++){
        // printf("zerowane: %d %d, %d %d\n", 0, i, n+1, i);
        pustynia[0][i].value = -1;
        pustynia[n+1][i].value = -1;
        pustynia[0][i].queued = true;
        pustynia[n+1][i].queued = true;
        // printf("\tzerowane: %d %d, %d %d\n", pustynia[0][i].value, pustynia[n+1][i].value, pustynia[0][i].queued, pustynia[n+1][i].queued);
    }
    
    char pom;
    struct Wsp start, koniec;
    //pobieranie danych
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%c", &pom);
            while(pom == '\n'){
               scanf("%c", &pom); 
            }
            if(pom == '.'){
                pustynia[i][j].value = INF;
                pustynia[i][j].queued = false;
            }else if(pom == 'X'){
                pustynia[i][j].value = -1;
                pustynia[i][j].queued = true;
            }else if(pom == 'S'){
                start.x = i;
                start.y = j;
                pustynia[i][j].value = 0;
                pustynia[i][j].source = 0;
                pustynia[i][j].queued = true;
            }else{
                koniec.x = i;
                koniec.y = j;
                goal.x = i;
                goal.y = j;
                pustynia[i][j].value = INF;
                pustynia[i][j].source = -1;
                pustynia[i][j].queued = false;
            }
        }
    }
    ///////////////////////////////////////////////////
    printf("poWczytaniu: startx: %d starty: %d celx: %d cely: %d\n", start.x, start.y, goal.x, goal.y);
    display();
    pushBack(start);
    display();
    myBfs(pustynia);

    // printf("poDickStra\n");

    char* result;

    if(pustynia[koniec.x][koniec.y].value == INF){
        printf("BRAK\n");
    }else{
        result = malloc((pustynia[koniec.x][koniec.y].value+1)*sizeof(char));
        int i = 0, source;
        while(pustynia[koniec.x][koniec.y].value != 0){
            source = pustynia[koniec.x][koniec.y].source;
            result[i] = output[source];
            koniec.x += rx[source];
            koniec.y += ry[source];
            i++;
        }

        for(--i; i >= 0; i--){
            printf("%c", result[i]);
        }
        printf("\n");
    }

    ///////////////////////////////////////
    free(result);
    for(int i = 0; i < n; i++){
        free(pustynia[i]);
    }
    free(pustynia);
}

int main() {
    int n, x, y;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        front = rear = NULL;
        scanf("%d %d", &x, &y);
        task(x, y);
    }

  return 0;
}

void pushBack(struct Wsp item)
{
    struct node *nptr = malloc(sizeof(struct node));
    nptr->data.x = item.x;
    nptr->data.y = item.y;
    nptr->next = NULL;
    if (rear == NULL)
    {
        front = nptr;
        rear = nptr;
    }
    else
    {
        rear->next = nptr;
        rear = rear->next;
    }
}

void display()
{
    struct node *temp;
    temp = front;
    printf("\n");
    while (temp != NULL)
    {
        printf("%d %d, ", temp->data.x, temp->data.y);
        temp = temp->next;
    }
    printf("\n");
}

void popFront()
{
    if (front == NULL)
    {
        printf("\n\nqueue is empty \n");
    }
    else
    {
        struct node *temp;
        temp = front;
        front = front->next;
        // printf("\n\n%d deleted", temp->data);
        free(temp);
    }
}