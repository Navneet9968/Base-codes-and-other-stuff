#include<stdio.h>
int main(){
    for (int i = 1; i <1000;i++){
        int f=i;
        int sumcube=0;
        while(f!=0){
            int a=f%10;
            f=f/10;
            sumcube=sumcube+(a*a*a);
        }
        if (sumcube==i){
            printf("%d is armstrong number.\n",i);
        }
    }
    return 0;
}