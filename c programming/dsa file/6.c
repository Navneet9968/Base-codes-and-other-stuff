#include<stdio.h>
//printing the 2d array
void print2darr(int arr[10][5]){
    for (int i=0; i<10;i++){
        printf("for student %d \n",i+1);
        for(int j=0; j<5;j++){
            printf("%d\t",arr[i][j]);
        }
    printf("\n");
    }
}

int main()
{
    int arr[10][5];

    for(int i=0; i<10; i++){
        for(int j=0; j<5; j++){
            printf("enter marks for student %d and course %d \n",i+1,j+1);
            scanf("%d",&arr[i][j]);
            fflush(stdin);
        }
    }
    print2darr(arr);

    return 0;
}