#include<stdio.h>
void bubsort(int *arr,int sizearr){
    int temp;
    for(int i=0; i<sizearr-1;i++){
        for(int j=0; j<sizearr-i-1;j++){
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
    int sum=0;
    int sizearr=sizeof(arr)/sizeof(int);
    // printf("%d\n",sizearr);
    for (int i=0;i<sizearr;i++){
        sum+=arr[i];
    }
    bubsort(arr,sizearr);
    printf("the mean of given array of numbers is = %f\n",(float)sum/sizearr);
    if(sizearr%2==0){
        printf("the median of given array of numbers is = %d\n",(arr[sizearr/2]+arr[(sizearr/2)+1])/2);
    }
    else{
        printf("the median of given array of numbers is = %d\n",arr[(sizearr+1)/2]);
    }
    return 0;
}