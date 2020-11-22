#include <stdio.h>
#include <stdlib.h>

int N;
int sol;

typedef struct{
	int s;
	int e;
}Movie;

Movie movies[100000 + 10];

int compare(const void* a, const void* b){
	Movie* x = (Movie*) a;
	Movie* y = (Movie*) b;

	return x->e - y->e;
}

void solve(){
	qsort(movies, N, sizeof(Movie), compare);

	int end = movies[0].e;
	sol++;
	for(int i=1; i<N; ++i){
		if(end < movies[i].s){
			end = movies[i].e;
			sol++;
		}
	}

}

int main(void)
{
	int i;

	// 입력받는 부분
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &movies[i].s, &movies[i].e);
	}

	// 여기서부터 작성
	solve();

	// 출력하는 부분
	printf("%d", sol);

	return 0;
}