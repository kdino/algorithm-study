#include <stdio.h>
#include <string.h>

typedef struct{
	int p;	// 우선순위
	int num;	// 문서 번호
}Print;

int T;
Print queue[100000];
int wp;
int rp;
int M;
int N;
int sol[10000];
int cnt;

void push(Print a){
	queue[wp++] = a;
}
Print front(){
	return queue[rp];
}
void pop(){
	rp++;
}
int empty(){
	return wp==rp;
}
int size(){
	return wp-rp;
}

int solve(){
	Print curr;
	int i;
	int flag = 0;
	while(!empty()){
		curr = front(); pop();
		// printf("p: %d num: %d\n", curr.p, curr.num);
		for(i=rp; i<rp+size(); ++i){
			if(curr.p < queue[i].p){
				push(curr);
				// printf("REPUSH curr : %d\n", curr.num);
				flag = 1;
				break;
			}
		}
		if(flag == 1){
			flag = 0;
			continue;
		}
		if(curr.num == M){
			cnt++;
			// printf("END!! curr : %d\n", curr.num);
			return cnt;
		}
		else{
			// printf("pop!! curr : %d\n", curr.num);
			cnt++;
		}
	}
	return -1;
}

int main(){
	int i, j;
	Print temp;

	scanf("%d", &T);

	for(i=0; i<T; ++i){
		scanf("%d %d", &N, &M);
		for(j=0; j<N; ++j){
			scanf("%d", &temp.p);
			temp.num = j;
			push(temp);
		}
		sol[i] = solve();

		cnt = 0;
		memset(queue, 0, 100000);
		wp = 0;
		rp = 0;	
	}

	for(i=0; i<T; ++i){
		printf("%d\n", sol[i]);
	}
	return 0;
}