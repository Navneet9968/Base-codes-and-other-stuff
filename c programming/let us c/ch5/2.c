#include<stdio.h>
int fact(int num);
int main(){
    int num;
    printf("enter the number of which factorial you want \n");
    scanf("%d",&num);
    printf("factorial of number is %d\n",fact(num));
    return 0;	
}

int fact (int num){
    if (num==0)
    return 1;
    int numm1=num-1;
    int factnum=num*fact(numm1);
    return(factnum);
}

