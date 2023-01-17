#include<stdio.h>
void display(int arr[],int size){
    for (int i = 0; i < size;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int arr[100]={3,6,7,3,23,45,67};
    display(arr,7);
    return 0;
}