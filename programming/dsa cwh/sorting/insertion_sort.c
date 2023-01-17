#include<stdio.h>
void printarr(int *arr, int size){
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void insertion_sort(int *arr, int size){
    int key,j;
    //loop for passes
    for(int i=1;i<=size-1;i++){
        key =arr[i];
        j=i-1;
        //loop for each pass
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int arr[]={3,6,2,4,6,3,11,4,6,7,5,322,23,4,5};
    int size=15;
    printarr(arr,size);
    insertion_sort(arr,size);
    printarr(arr,size);

    return 0;
}