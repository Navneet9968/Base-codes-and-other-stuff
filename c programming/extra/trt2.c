#include <stdio.h>
int fib(int n);
int main(){
    int n;
    printf("enter the number: ");
    scanf("%d",&n);
    printf("the nth fibonacci number is :%d ",fib(n));
}
int fib(int n ){
    if (n==1){
        return 0;
    }
    if(n==2){
        return(1);
    }
    int fibnm1=fib(n-1);
    int fibnm2=fib(n-2);
    int fib=fibnm1+fibnm2;
    return (fib);
}