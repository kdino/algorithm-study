#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int price;
    int qty;
}Good;

typedef struct{
    int rate;
    int qty;
}Coupon;

int goods[][2] = {{25400, 2}, {10000, 1}, {31600, 1}};
int coupons[][2] = { {5, 3}, {23, 2}, {11, 2}, {9, 5} };

int compare1(const void *a, const void *b){
    Good *pa = (Good*)a;
    Good *pb = (Good*)b;
    
    return pb->price - pa->price;
}

int compare2(const void *a, const void *b){
    Coupon *pa = (Coupon*)a;
    Coupon *pb = (Coupon*)b;
    
    return pb->rate - pa->rate;
}

Good myGoods[10000];
Coupon myCoupons[10000];
int goodQueue[10000];
int couponQueue[10000];
int gp;
int cp;
int gCnt;
int cCnt;
int answer;

int main() {
    int goodNum = sizeof(goods)/sizeof(goods[0]);
    int couponNum = sizeof(coupons)/sizeof(coupons[0]);
    
    for(int i=0; i<goodNum; i++){
        myGoods[i].price = goods[i][0];
        myGoods[i].qty = goods[i][1];
    }
    
    for(int i=0; i<couponNum; i++){
        myCoupons[i].rate = coupons[i][0];
        myCoupons[i].qty = coupons[i][1];
    }
    
    qsort(myGoods, goodNum, sizeof(Good), compare1);
    qsort(myCoupons, couponNum, sizeof(Coupon), compare2);
    
    
    for(int i=0; i<goodNum; ++i){
        for(int j=0; j<myGoods[i].qty; ++j){
            goodQueue[gp++] = myGoods[i].price;
            gCnt++;
        }
    }
    
    for(int i=0; i<couponNum; ++i){
        for(int j=0; j<myCoupons[i].qty; ++j){
            couponQueue[cp++] = myCoupons[i].rate;
            cCnt++;
        }
    }
    
//    printf("%d\n", gCnt);
    
    
    
    for(int i=0; i<gCnt; ++i){
        if(i<=cCnt){
            answer += goodQueue[i] * (100.0 - couponQueue[i]) * 0.01;
            printf("%d * %f = %f tot: %d\n", goodQueue[i], (100.0 - couponQueue[i]) * 0.01, goodQueue[i] * (100.0 - couponQueue[i]) * 0.01 ,answer);
        }
        else{
            answer += goodQueue[i];
            printf("answer = %d\n", answer);
        }
    }
    
    printf("final: %d\n", answer);
    
    return 0;
}



