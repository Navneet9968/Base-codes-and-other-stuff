#include<stdio.h>
void printarr(int *arr, int size){
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void selection_sort(int * arr, int size){
    int temp,min_element_index;
    //loop for passes
    for(int i=0;i<size-1;i++){
        min_element_index=i;
        //for comparison with rest of the elements
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min_element_index]){
                min_element_index=j;
            }
        }

        //swapping the elements
        temp=arr[min_element_index];
        arr[min_element_index]=arr[i];
        arr[i]=temp;
    }
}

int main(){
    int arr[]={3,6,2,4,6,3,11,4,6,7,5,322,23,4,5};
    int size=15;
    printarr(arr,size);
    selection_sort(arr,size);
    printarr(arr,size);

    return 0;
}