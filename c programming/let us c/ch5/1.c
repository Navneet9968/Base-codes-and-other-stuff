#include<stdio.h>
int main(){
    for (int i=1; i<11;i++){
        int hours;
        printf("enter the number of hours worked for employee no : %d\n",i);
        scanf("%d",&hours);
        int otpay;
        if (hours<=40)
        {
            printf("Your overtime pay is zero.\n");
        }
        else
        {
            int extrahours=hours-40;
            printf("Your overtime pay is %d rupees.\n",extrahours*12);
        }
    }
    return 0;
}