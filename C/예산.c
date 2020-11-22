#include <stdio.h>

long long  N, M;
long long a[10000];
long long sol;
long long sum;

long long max;

void bs(long long s, long long e){
	long long m;
	sum = 0;
	m = (s+e)/2;	// 상한선
	if(sol > m) return;

	for(int i=0; i<N; ++i){
		if(a[i] >= m) sum += m;
		else sum += a[i];

		if(sum>M){
			bs(s, m-1);
			return;
		}
	}
	if(m > sol){
		sol = m;
		bs(m+1, e);
	}
}

void solve(){
	if(M >= sum){
		sol = max;
		return;
	}

	bs(N, max);
}

int main(void)
{
	int i;

	// 입력받는 부분
	scanf("%lld", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%lld", &a[i]);
		sum += a[i];
		if(a[i] > max) max = a[i];
	}
	scanf("%lld", &M);

	// 여기서부터 작성
	solve();
	// 출력하는 부분
	// printf("%d %d\n", max, sum);
	printf("%lld\n", sol);

	return 0;
}