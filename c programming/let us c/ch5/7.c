#include<stdio.h>
int main(){
    int countpos=0,countnve=0,countzeros=0,num;
    char ch='y';
    while (ch=='y' || ch=='Y'){
        printf("enter the number now :\n");
        scanf("%d",&num);
        if (num==0){
            countzeros+=1;
        }
        else if (num>0){
            countpos+=1;
        }
        else if (num<0){
            countnve+=1;
        }
        else{
            printf("you entered invalid number.\n");
            continue;
        }
        printf("do you want to enter more numbers?\n");
        fflush(stdin);  // clears standard input stream
        scanf("%c",&ch);
        if (ch=='y'||ch=='Y'){
            continue;
        }
        else{
            printf("positive numbers : %d\n",countpos);
            printf("negative numbers : %d\n",countnve);
            printf("zeros:%d\n",countzeros);
        }
    }

return 0;
}