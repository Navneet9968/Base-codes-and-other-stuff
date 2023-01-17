#include<stdio.h>
int main(){
    FILE * fptr;
    fptr = fopen("sample.txt","r");
    fseek(fptr,0,SEEK_END);
    printf("%d\n",ftell(fptr));
    int size=ftell(fptr);
    char ch;
    fseek(fptr,0,SEEK_SET);
    for(int i=0; i<size; i++){
        fscanf(fptr, "%c",&ch);
        printf("%c",ch);
    }
    fclose(fptr);
    
return 0;
}
