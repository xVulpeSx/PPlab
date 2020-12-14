// Queue implementation in C - https://www.programiz.com/dsa/queue
#include <stdio.h>
#include<stdlib.h>

#define SIZE INF
#define INF 500000

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

void pushBack(struct Wsp);
void popFront();
void display();
//queue
struct Wsp bfsQueue[SIZE];
int front = -1, rear = -1;

int rx[] = {-1, 1, 0, 0};   //przesuwanie sie po tablicy przy wracaniu
int ry[] = {0, 0, 1, -1};

int dx[] = {1, -1, 0, 0};   //przesuwanie sie po tablicy przy bfs
int dy[] = {0, 0, -1, 1};
char output[] = {'D', 'G', 'L', 'P'};

struct Wsp goal;

void myBfs(struct Sahara ** pustynia){
    struct Wsp curr, pom;
    // printf("bfs front: %d, rear: %d\n", front, rear);
    while(front != -1){
        curr = bfsQueue[front];
        popFront();
        for(int i = 0; i < 4; i++){
            // printf("bfs: i: %d, x: %d, y: %d, if: %d\n", i, curr.x+dx[i], curr.y+dy[i], curr.y+dy[i], pustynia[curr.x+dx[i]][curr.y+dy[i]].queued);
            if(pustynia[curr.x+dx[i]][curr.y+dy[i]].queued == false){
                pustynia[curr.x+dx[i]][curr.y+dy[i]].value = pustynia[curr.x][curr.y].value + 1;
                pustynia[curr.x+dx[i]][curr.y+dy[i]].source = i;
                pustynia[curr.x+dx[i]][curr.y+dy[i]].queued = true;
                pom.x = curr.x + dx[i];
                pom.y = curr.y + dy[i];
                if(pom.x == goal.x && pom.y == goal.y){ //skoncz jesli znajdziesz wartosci dla celu
                    return;
                }
                pushBack(pom);
            }
        }
    }
}

void task(int n, int m){
    // printf("task: %d %d\n",n, m);
    ///////////////////////dane////////////////////////
    struct Sahara ** pustynia = malloc((n + 2)*sizeof(struct Sahara));
    for(int i = 0; i < n+2; i++){
        pustynia[i] = malloc((m+2)*sizeof(struct Sahara));
    }
    // otoczenie scianami
    for(int i=1; i < n+1;i++){
        pustynia[i][0].value = -1;
        pustynia[i][m+1].value = -1;
        pustynia[i][0].queued = true;
        pustynia[i][m+1].queued = true;
    }
    for(int i=0;i < m+1;i++){
        pustynia[0][i].value = -1;
        pustynia[n+1][i].value = -1;
        pustynia[0][i].queued = true;
        pustynia[n+1][i].queued = true;
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
    // printf("poWczytaniu: startx: %d starty: %d celx: %d cely: %d\n", start.x, start.y, koniec.x, koniec.y);
   
    pushBack(start);
    myBfs(pustynia);

    // printf("poDickStra\n");


    char result[INF];
    if(pustynia[koniec.x][koniec.y].value == INF){
        printf("BRAK\n");
    }else{
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

    for(int i = 0; i < n; i++){
        free(pustynia[i]);
    }
    free(pustynia);
}

int main() {
    int n, x, y;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        front = rear = -1;
        scanf("%d %d", &x, &y);
        task(x, y);
    }

  return 0;
}

void pushBack(struct Wsp value) {
  if (rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (front == -1)
      front = 0;
    rear++;
    bfsQueue[rear] = value;
    //printf("\nInserted -> %d", value);
  }
}

void popFront() {
  if (front == -1)
    printf("\nQueue is Empty!!");
  else {
    //printf("\nDeleted : %d", items[front]);
    front++;
    if (front > rear)
      front = rear = -1;
  }
}

// Function to print the queue
void display() {
  if (rear == -1)
    printf("\nQueue is Empty!!!");
  else {
    int i;
    printf("\nQueue elements are:\n");
    for (i = front; i <= rear; i++)
      printf("%d  %d, ", bfsQueue[i].x, bfsQueue[i].y);
  }
  printf("\n");
}