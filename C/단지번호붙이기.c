#include <stdio.h>
#include <stdlib.h>

int N;
int a[25 + 10][25 + 10];
int visited[25 + 10][25 + 10];
int cnt;
int sol[25 * 25 + 10];
int house;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int compare(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

void dfs(int x, int y){
	int i, j;
	int nx, ny;

	for(i=0; i<4; ++i){
		nx = x + dx[i];
		ny = y + dy[i];

		if(nx < 1 || nx > N || ny < 1 || ny > N) continue;
		if(visited[ny][nx]==1 || a[ny][nx] == 0) continue;
		house++;
		visited[ny][nx] = 1;
		dfs(nx, ny);
	}
}

int main(void)
{
	int i, j;

	// 입력받는 부분
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}
	house = 1;
	// 여기서부터 작성
	for(i=1; i<=N; i++){
		for(j=1; j<=N; j++){
			if(a[i][j]==1 && visited[i][j]==0){
				visited[i][j] = 1;
				dfs(j, i);
				sol[cnt++] = house;
				house = 1;
			}
		}
	}

	// 출력하는 부분
	printf("%d\n", cnt);
	qsort(sol, cnt, sizeof(sol[0]), compare);
	for (i = 0; i < cnt; i++)
	{
		printf("%d\n", sol[i]);
	}

	return 0;
}