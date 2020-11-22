#include <stdio.h>

int n;
int DY, DX;
int mount[100 + 10][100 + 10];
int visited[100 + 10][100 + 10];
int sol;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int move(int s, int e){
	if(s==e) return 0;
	if(s<e)  return (e-s)*(e-s);
	if(s>e)	return s-e;
}

void dfs(int x, int y, int pow){
	if(pow > sol) return;

	if(x)
}


void solve(){
	for(int i=1; i<n; ++i){
		dfs(i, 1, 0);
	}
}

int main()
{
	int i, j;
	
	// 입력받는 부분
	scanf("%d", &n);
	scanf("%d %d", &DY, &DX);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &mount[i][j]);
		}
	}

	// 여기서부터 작성
	sol = 9999999;
	solve();
	// 출력하는 부분
	printf("%d", sol);

	return 0;
}