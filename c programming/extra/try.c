int sum_left(int *nums,int numsSize,int index){
    int leftsum=0;
    for(int i=0;i<index;i++){
        leftsum+=nums[i];
    }
    return leftsum;
}

int sum_right(int *nums, int numsSize, int index){
    int rightsum=0;
    for(int i=index;i<numsSize;i++){
        rightsum+=nums[i];
    }
    return rightsum;
}
int pivotIndex(int* nums, int numsSize){
    for(int i=0;i<numsSize;i++){
        if(sum_left(nums,numsSize,i)==sum_right(nums,numsSize,i)){
            return i;
        }
    }
    return -1;

}