#include <stdio.h>
int H;//세로크기
int W;//가로크기
char map[500][510];//지도
char visited[500][510];

typedef struct{
	int x;
	int y;
	int time;
}Point;

Point queue[1000000];
int wp;
int rp;

void push(Point pnt){
	queue[wp++] = pnt;
}
Point top(){
	return queue[rp];
}
void pop(){
	rp++;
}
int empty(){
	return wp==rp;
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void input_data(void){
	int i;
	scanf("%d %d", &H, &W);
	for(i=0 ; i<H ; i++){
		scanf("%s", map[i]);
	}
}

int bfs(){
	int i;
	
	Point init;
	init.x = 0;
	init.y = 0;
	init.time = 0;
	visited[init.y][init.x] = 1;
	
	push(init);
	Point target;
	Point newP;
	
	while(!empty()){
		target = top(); pop();
		if(target.x == W-1 && target.y == H-1) return target.time;
		int nx, ny;
		for(i=0; i<4; ++i){
			nx = target.x+dx[i];
			ny = target.y+dy[i];
			if(nx > W-1 || nx < 0 || ny > H-1 || ny < 0) continue;
			if(visited[ny][nx] == 1) continue;
			if(map[ny][nx] == 'X') continue;
			newP.x = nx;
			newP.y = ny;
			newP.time = target.time+1;
			// printf("%d %d\n", newP.x, newP.y);
			visited[ny][nx] = 1;
			push(newP);
		}
		// printf("========\n");
	}
	return -1;
}

int main(void){
	int ans = 0;
	input_data();

	//	코드를 작성하세요
	ans = bfs();
	
	printf("%d\n", ans);
	return 0;
}
