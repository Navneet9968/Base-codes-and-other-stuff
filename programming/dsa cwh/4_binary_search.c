#include<stdio.h>
int bin_search(int arr[],int size, int element){
    int low =0 ,high=size-1 ;
    int mid = (low+high)/2;
    while(low<=high){
        mid=(low+high)/2 ;
        if (arr[mid]==element){
            return mid;
        }
        if(arr[mid]<element){
            low=mid +1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
} 
int main()
{
    printf("enter the element:");
    int element;
    scanf("%d",&element);
    int arr[] = {1,3,5,56,64,73,123,225,444};
    int size=sizeof(arr)/sizeof(int);
    int searched_index=bin_search(arr,size,element);
    printf("the element %d is at the index %d. \n",element,searched_index);
    return 0;
}