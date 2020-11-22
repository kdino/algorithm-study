#include <stdio.h>

int N;
int in[4];
int out[4];
int sol;

void solve(){
	N = in[0];
	sol = N;
	for(int i=1; i<4; ++i){
		N -= out[i];
		N += in[i];
		if(N > sol) sol = N;
	}
}

int main(void)
{
	int i;
	int t = 0;

	// 입력받는 부분
	for (i = 0; i < 4; i++)
	{
		scanf("%d %d", &out[i], &in[i]);
	}

	// 여기서부터 작성
	solve();
	// 출력하는 부분
	printf("%d", sol);

	return 0;
}