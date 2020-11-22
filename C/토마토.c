#include <stdio.h>
 
int N, M;
int a[1000+10][1000+10];
int visited[1000+10][1000+10];
int sol;

typedef struct{
	int x;
	int y;
	int time;
}Tomato;
 
Tomato queue[1000000];
int wp;
int rp;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void push(Tomato t){
	queue[wp++] = t;
}
Tomato front(){
	return queue[rp];
}
void pop(){
	rp++;
}
int empty(){
	return wp==rp;
}

int bfs(){
	int i;

	Tomato t;
	Tomato next;
	int nx;
	int ny;

	while(!empty()){
		t = front(); pop();

		for(i=0; i<4; ++i){
			nx = t.x + dx[i];
			ny = t.y + dy[i];

			if(nx < 1 || nx > M || ny < 1 || ny > N) continue;
			if(a[ny][nx] == -1 || visited[ny][nx] == 1) continue;
			next.x = nx;
			next.y = ny;
			next.time = t.time + 1;
			visited[ny][nx] = 1;
			push(next);
			// printf("%d %d\n", nx, ny);
		}
		// printf("===========\n");
	}
	return next.time;
}

int main(void)
{
      int i, j;
	  int flag = 0;
	  Tomato init;
      // 입력받는 부분
      scanf("%d %d", &M, &N);
      for(i=1;i<=N;i++)
      {
            for(j=1;j<=M;j++)
            {
                  scanf("%d", &a[i][j]);
				  if(a[i][j]==0) flag = 1;
				  if(a[i][j] == 1){
					  init.x = j;
					  init.y = i;
					  push(init);
					  visited[i][j] = 1;
				  }
            }
      }
	  if(flag == 0) {	// 모든 토마토 이미 익은 상태
		  printf("%d", 0);
		  return 0;
	  }

      // 여기서부터 작성
	  sol = bfs();
      // 출력하는 부분
      printf("%d", sol);
 
      return 0;
}