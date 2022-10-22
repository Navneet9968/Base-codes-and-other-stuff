#include<stdio.h>

void traversal(int *nums,int numsSize){
    for(int i = 0; i < numsSize; i++){
        printf("%d\t",nums[i]);
    }
    printf("\n");
}

//inserting elements in the heap
void insert(int *nums,int n){
    int i=n;
    int temp=nums[i];

    while(i>=2&&temp>nums[i/2]){
        nums[i]=nums[i/2];
        i=i/2;
    }
    
    nums[i]=temp;
}


//deleting elements one by one in the heap and placing them at last for sorting
//as root node will be maximum for deletion then max elem will be placed at last then we'll reduce the heap size by -1

void delete(int *nums,int numsSize){
    int temp=nums[1];
    nums[1]=nums[numsSize-1];
    numsSize-=1;
    nums[numsSize]=temp;
    int i=1;
    int larger;
    while(i<numsSize){
        int left=nums[2*i];
        int right=nums[2*i+1];
        if ((2*i)>numsSize-1){
            break;
        }
        if((2*i+1)>numsSize-1){
            break;
        }
        if(left>right){
            larger=2*i;
        }
        if(right>left){
            larger=2*i+1;
        }
        if(nums[i]<nums[larger]){
            int temp2=nums[larger];
            nums[larger]=nums[i];
            nums[i]=temp2;
            i=larger;
        }
        else{
            return;
        }
    }
}





void heap_sort(int *nums,int numsSize){
    for(int i=2;i<numsSize;i++){
        insert(nums,i);
    }
    traversal(nums,numsSize);
    printf("this is numssize %d\n",numsSize);
    for(int j=9;j>2;j--){
        delete(nums,j);
    }
    traversal(nums,numsSize);
}





int main()
{
    int nums[9]={0,34,2,42,1,3,5,13,63};
    int numsSize=sizeof(nums)/sizeof(int);
    printf("%d\n",numsSize);
    printf("this is before heap sort\n");
    traversal(nums,numsSize);

    heap_sort(nums,numsSize);
    printf("this is after heap sort\n");
    traversal(nums,numsSize);


    

return 0;
}