#include<stdio.h>
#include<stdlib.h>
void traversal(int *nums,int numsSize){
    for(int i = 0; i < numsSize; i++){
        printf("%d\t",nums[i]);
    }
    printf("\n");
}


void merge(int *arr,int s, int e){
   
    int mid=(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;

    int *arr1=(int *)malloc(len1*sizeof(int));
    int *arr2=(int *)malloc(len2*sizeof(int ));

    //copying left part of arr to arr1 and right part of arr to arr2
    int k=s;
    for(int i=0;i<len1;i++){
        arr1[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<len2;i++){
        arr2[i]=arr[k++];
    }

    int index1=0;
    int index2=0;
    k=s;

    //k is the starting index of main array

    while(index1<len1 && index2<len2){
        if(arr1[index1]<arr2[index2]){
            arr[k]=arr1[index1];
            k++;
            index1++;
        }
        else if(arr2[index2]<arr1[index1]){
            arr[k]=arr2[index2];
            k++;
            index2++;
        }
        else{
            arr[k]=arr1[index1];
            arr[k+1]=arr2[index2];
            k=k+2;
            index1++;
            index2++;
        }
    }
    while(index1<len1){
        arr[k]=arr1[index1];
        index1++;
        k++;
    }
    while(index2<len2){
        arr[k]=arr2[index2];
        index2++;
        k++;


    }

}

void mergeSort(int *arr, int s, int e){
    //base case
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    //recursively left part mergeSort
    mergeSort(arr,s,mid);

    //recursively right part mergeSort
    mergeSort(arr,mid+1,e);
    
    //now left part and right part part are sorted just need to merge them
    merge(arr,s,e);
}
int main(){

    int arr[7]={24,37,62,99,2,60,1};
    int size=7;
    printf("array before sort\n");
    traversal(arr,size);
    mergeSort(arr,0,size-1);
    printf("array after sorting\n");
    traversal(arr,size);



    return 0;
}