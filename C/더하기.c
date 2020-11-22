#include <stdio.h>
#include <string.h>

int T, N, K;
int d[20];
int sol;
int prefixSum[30];

int dfsMulti(int s, int sum){
	int i;
	if(sum > prefixSum[N] - prefixSum[s-1]) return 0;
	if(sum == 0) return 1;
	if(sum < 0) return 0;
	
	for(i=s; i<=N; ++i){
		if(dfsMulti(i+1, sum-d[i])==1) return 1;
	}
	return 0;
}

int solve(){
	return dfsMulti(1, K);
}

int main(void)
{
	int i;

	// 입력받는 부분
	scanf("%d", &T);
	while (T--)
	{
		// 입력받는 부분
		scanf("%d %d", &N, &K);
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &d[i]);
		}
		
		for(i=1; i<=N; ++i){
			prefixSum[i] = prefixSum[i-1] + d[i];
		}

		// 여기서부터 작성
		sol = solve();
		// 출력하는 부분
		if (sol == 1)
			printf("YES\n");
		else
			printf("NO\n");
		
		// sol = 0;
		// memset(d, 0, 20);
	}
	return 0;
}