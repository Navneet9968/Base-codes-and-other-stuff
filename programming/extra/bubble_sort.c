#include<stdio.h>
void printarr(int *arr,int arrsize){
    for(int i=0;i<arrsize;i++){
        printf("%d\t",arr[i]);
    }
}
void bubsort(int *arr,int arrsize){
    int temp;
    for(int i=0; i<arrsize-1;i++){
        for(int j=0; j<arrsize-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    
}
int main()
{
int arr[]={1,2,38,23,21,1,3,4,5,2,4,53};
int arrsize=sizeof(arr)/sizeof(int);
printarr(arr,arrsize);
printf("\n");
bubsort(arr,arrsize);
printarr(arr,arrsize);

return 0;
}