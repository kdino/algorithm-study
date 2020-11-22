#include <stdio.h>

int N;
char a[100 + 10][100 + 10];
int visited[100 + 10][100 + 10];
int sol1, sol2;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y, char c){
	int i;
	int nx, ny;

	for(i=0; i<4; ++i){
		nx = x + dx[i];
		ny = y + dy[i];

		if(nx < 1 || nx > N || ny < 1 || ny > N) continue;
		if(visited[ny][nx]==1) continue;
		if(a[ny][nx] == c){
			visited[ny][nx] = 1;
			dfs(nx, ny, c);
		}
	}
}

int main(void)
{
	int i,j;

	// 입력받는 부분
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%s", &a[i][1]);
	}

	// 여기서부터 작성
	for(i=1; i<=N; ++i){
		for(j=1; j<=N; ++j){
			if(visited[i][j]==0){
				dfs(j, i, a[i][j]);
				sol1++;
			}
		}
	}

	for(i=1; i<=N; ++i){
		for(j=1; j<=N; ++j){
			visited[i][j] = 0;
			if(a[i][j] == 'G') a[i][j] = 'R';
		}
	}

	for(i=1; i<=N; ++i){
		for(j=1; j<=N; ++j){
			if(visited[i][j]==0){
				dfs(j, i, a[i][j]);
				sol2++;
			}
		}
	}

	// 출력하는 부분
	printf("%d %d", sol1, sol2);

	return 0;
}
