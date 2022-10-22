#include<stdio.h>

void printarr(int *arr, int size){
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
int count_cmp=0;
void adaptive_bubsort(int *arr,int sizearr){     //adaptive means that if it is sorted then program will not do any more passes and end
    int temp;                                    //increases the efficiency of the code
    int issorted=1;
    
    for(int i=0; i<sizearr-1;i++){
        issorted=1;
        for(int j=0; j<sizearr-i-1;j++){
            count_cmp++;
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                issorted=0;
            }
        }
        if(issorted){
            return;
        }
    }   
}

int main(){
    printf("THIS IS FOR WORST CASE\n\n");
    printf("list initially is ->\n\n");
    int arr[]={322,23,11,7,6,6,6,5,5,4,4,4,3,3,2};
    
    int size=15;
    printarr(arr,size);
    printf("\n");
    adaptive_bubsort(arr,size);
    printf("list after sorting is ->\n\n");
    printarr(arr,size);
    printf("\n");
    printf("number of comparisons made in this is ->\n\n");
    printf("%d\n",count_cmp);
    
    printf("\n");
    return 0;
}
