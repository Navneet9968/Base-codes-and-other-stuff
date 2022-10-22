#include<stdio.h>
//traversal
void display(int arr[],int size){
    
    for (int i = 0; i < size;i++){
        printf("%d ",arr[i]);
    }
}
//insertion at index
int indInsertion(int arr1[],int *size,int element,int cap,int index){
    if ((*size)>=cap){
        printf("overflow");}
    else{
        for (int i=(*size-1);i>=index;i--){  //size is greater than index of last element by 1 so we do size-1
            arr1[i+1]=arr1[i];
        }
        arr1[index]=element;
        (*size)++;
        return 1;
    }
}
//deletion at index
int indDeletion(int arr[],int *size,int index){
    if ((*size)<=0){
        printf("no element in list");
    }
    else{
    for(int i=index;i<(*size-1);i++){
        arr[i]=arr[i+1];
        }
        (*size)--;
        return 1;
    }
    
}
int main(){
    int arr[100]={3,6,7,9,23,45,67};
    int size=7,capacity=100;
    display(arr,size);
    int element =34,index=3;
    indInsertion(arr,&size,element,capacity,index);
    printf("\n");
    printf("size=%d",size);
    printf("\n");
    display(arr,size);
    index=5;
    indDeletion(arr,&size,index);
    printf("\n");
    printf("size=%d",size);
    printf("\n");
    display(arr,size);
    return 0;
}  