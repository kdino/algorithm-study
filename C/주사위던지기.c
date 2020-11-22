#include <stdio.h>
int N, M;
int dice[10];
int used[10];
void DFS1(int n){
    if (n > N){
        for (int i=1; i<=N; i++) printf("%d ", dice[i]);
        printf("\n");
        return;
    }
    for (int i=1; i<=6; i++){
        dice[n]=i;
        DFS1(n+1);
    }
}
void DFS2(int n, int s){
    if (n > N){
        for (int i=1; i<=N; i++) printf("%d ", dice[i]);
        printf("\n");
        return;
    }
    for (int i=s; i<=6 ;i++){
        dice[n]=i;
        DFS2(n+1, i);
    }
}
void DFS3(int n){
    if (n > N){
        for (int i=1; i<=N; i++) printf("%d ", dice[i]);
        printf("\n");
        return;
    }
    for (int i=1; i<=6; i++){
        if(used[i] == 1) continue;//해당 숫자 이미 선택했음
        used[i]=1;//사용으로 표시
        dice[n]=i;
        DFS3(n+1);
        used[i]=0;//표시제거
    }
}
int main(){
    scanf("%d %d", &N, &M);
    if (M == 1){//중복순열
        DFS1(1);
    }
    else if(M == 2){//중복조합
        DFS2(1, 1);
    }
    else{//순열
        DFS3(1);
    }
    return 0;
}