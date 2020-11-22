#include <stdio.h>
 
int M, N, L;
int x[100000+10];
int sol;
 
int abs(int a){
	if(a>=0) return a;
	else return -a;
}

typedef struct{
	int x;
	int y;
	int dead;
}Animal;

Animal animals[100000+10];

int main(void)
{
      int i;
	  int a, b;

      // 입력받는 부분
      scanf("%d %d %d", &M, &N, &L);
      for(i=0; i<M; i++)
      {
            scanf("%d", &x[i]);
      }
      for(i=0; i<N; i++)
      {
            scanf("%d %d", &animals[i].x, &animals[i].y);
      }
 
      // 여기서부터 작성
	  
 
      // 출력하는 부분
      printf("%d", sol);
 
      return 0;
}