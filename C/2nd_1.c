#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)5e3)
int N;
int A[MAXN+10];
void InputData(){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
}
int comp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int Solve(){
    int sum=0;
    for (int i=0; i<N-1; i++){
        //1. 오름차순 정렬
        qsort(&A[i], N-i, sizeof(A[0]), comp);
        //2. 최소값 두개 합치기
        A[i+1] += A[i];
        sum += A[i+1];
    }
    return sum;
}
int main(){
    InputData();
    int ans = Solve();
    printf("%d\n", ans);
    return 0;
}