#include<stdio.h>
#include<stdlib.h>

struct myArray{
    int total_size;
    int used_size;
    int *ptr;
};
void create_array(struct myArray *a ,int tSize, int uSize){       // (*a).   and a->  are same 
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr=(int *)malloc(tSize*sizeof(int));
}
void setVal(struct myArray *a){
    int n;
    for(int i=0;i<(a->used_size);i++){
        printf("enter element %d: ",i);
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
}
void display(struct myArray *a){
    for(int i=0;i<(a->used_size);i++){
        printf("%d  ",(a->ptr)[i]);
    }
}

int main(){
    struct myArray roll;
    create_array(&roll,10,2);
    
    printf("running set val now\n");
    setVal(&roll);
    printf("running display now\n");
    display(&roll);
    return 0;
}