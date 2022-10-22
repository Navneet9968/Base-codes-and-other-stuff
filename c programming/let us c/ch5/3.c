#include <stdio.h>
int power(int x , int y );
int main(){
    int x,y;
    printf("enter two numbers:");
    scanf("%d%d",&x,&y);
    printf("answer:%d",power(x,y));
    return 0;
}
int power(int x , int y){
    int answer=1;
    while(y>0){
        answer=answer*x;
        y--;
    }
    return answer;
}