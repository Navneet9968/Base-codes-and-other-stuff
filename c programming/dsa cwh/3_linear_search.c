#include<stdio.h>
void linearsearch(int arr[],int size , int element){
    for (int i = 0; i < size;i++){
        if (arr[i] ==element){
            printf("the element is at index %d\n",i);
        }
    }
}
int main()
{
    printf("enter the element:");
    int element = 0;
    scanf("%d",&element);
    int arr[] ={2,5,75,45,87,87,454,34,23,231,23,56,67,82};
    int size=sizeof(arr)/sizeof(int);
    linearsearch(arr,size,element);
    return 0;
}