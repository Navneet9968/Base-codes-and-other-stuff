#include<stdio.h>
#include<math.h>
int main(){
    int num = 0;
    printf("enter the number:\n");
    scanf("%d", &num);
    int a=0,f=0,oct=0,i=0;
    while(num!=0){
        a=num/8;
        f=num%8;
        oct=oct+(pow(10,i))*f;
        i++;
        num=num/8;
    }
    printf("the octal equivalent is :%d\n",oct);


return 0;
}