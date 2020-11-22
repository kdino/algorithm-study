#include <stdio.h>
 
int X, Y;
int sx, sy, ex, ey;
int a[100+10][100+10];
int visited[100+10][100+10];
int sol;

typedef struct{
	int x;
	int y;
	int time;
}Point;
 
Point queue[1000000];
int wp;
int rp;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void push(Point p){
	queue[wp++] = p;
}
Point front(){
	return queue[rp];
}
int empty(){
	return wp==rp;
}
void pop(){
	rp++;
}

int bfs(){
	Point init;
	init.x = sx;
	init.y = sy;
	
	push(init);
	visited[sy][sx] = 1;
	Point target;
	Point next;

	int nx;
	int ny;
	int i;

	while(!empty()){
		target = front(); pop();
		if(target.x == ex && target.y==ey) return target.time;

		for(i=0; i<4; ++i){
			nx = target.x + dx[i];
			ny = target.y + dy[i];

			if(a[ny][nx]==1 || visited[ny][nx]==1) continue;
			if(ny<1 || ny>Y || nx<1 || nx>X) continue;
			next.x = nx;
			next.y = ny;
			next.time = target.time + 1;
			visited[ny][nx] = 1;
			push(next);
		}
	}
	return -1;
}

int main(void)
{
      int x, y;
 
      // 입력받는 부분
      scanf("%d %d", &X, &Y);
      scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
      for(y=1 ; y<=Y ; y++)
      {
            for(x=1 ; x<=X ; x++)
            {
                  scanf("%1d", &a[y][x]);
            }
      }
 
      // 여기서부터 작성
	  sol = bfs();
      // 출력하는 부분
      printf("%d", sol);
 
      return 0;
}
