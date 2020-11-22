#include <stdio.h>
 
int T;
int cnt;
int idx;
int queue[1000];
int fp;
int bp;

int ans[1000];
int ansp;

void push(int a){
      queue[++fp] = a;
}
void pop(){
      ++bp;
}
int top(){
     return queue[fp];
}
int back(){
      return queue[bp];
}
int size(){
      return fp-bp;
}

void init(){
      int i=0;
      for(i=0; i<1000; ++i){
            queue[i] = 0;
      }
      fp = 0;
      bp = 0;
}

int solve(){
      int thisPop = -1;
      int i;
      int max = -1;
      int ans = 0;
      while(size() != 0){
            for(i=0; i<size(); ++i){
                  if(i==idx) continue;
                  if(queue[i]>max) max = queue[i];

                  if(top()==max){
                        pop();
                        ans++;
                        if(idx==0) return ans;
                  }
                  else{
                        push(back());
                        pop();
                        if(idx == 0) idx = size() - 1;
                        else idx--;
                  }
            }
      }
      return ans;
}

int main(void)
{
      int temp;
      int i, j, k;
      scanf("%d", &T);
      for(i=0; i<T; ++i){
            scanf("%d %d", &cnt, &idx);
            for(j=0; j<cnt; ++j){
                  scanf("%d", &temp);
                  push(temp);
            }
            ans[ansp++] = solve();
            printf("ans: %d\n", ans[ansp-1]);
            init();
      }

      for(i=0; i<ansp; ++i){
            printf("%d\n", ans[i]);
      }

      return 0;
}
