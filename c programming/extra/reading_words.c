#include<stdio.h>
int main(){
    FILE * fptr;
    fptr = fopen("sample.txt","r");
    fseek(fptr,0,SEEK_END);
    printf("%d\n",ftell(fptr));
    int size=ftell(fptr);
    char ch;
    fseek(fptr,0,SEEK_SET);
    int count=0;
    for(int i=0; i<size; i++){
        fscanf(fptr, "%c",&ch);
        if (ch==' '|| ch=='\n'){
            count++;
        }
    }
    printf("\n");
    printf("no of words are : %d\n",count);
    fclose(fptr);
    
return 0;
}
