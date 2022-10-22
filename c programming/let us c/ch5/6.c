#include<stdio.h>
int main(){
    int match=21;
    while(match>1){
        int person;
        printf("pick a number between 1 and 4.\n");
        scanf("%d",&person);
        if (person>4||person<1){
            printf("you selected wrong number of sticks please pick again.\n");
            continue;
        }
        printf("total matchsticks reamining :%d\n",match-person);
        if (person==1){
            match-=1;
            printf("the computer has selected %d sticks.\n",4);
            match-=4;
            printf("total matchsticks reamining :%d\n",match);
        }
        else if (person==2){
            match-=2;
            printf("the computer has selected %d sticks.\n",3);
            match-=3;
            printf("total matchsticks reamining :%d\n",match);
        }
        else if (person==3){
            match-=3;
            printf("the computer has selected %d sticks.\n",2);
            match-=2;
            printf("total matchsticks reamining :%d\n",match);
        }
        else if (person==4){
            match-=4;
            printf("the computer has selected %d stick.\n",1);
            match-=1;
            printf("total matchsticks reamining :%d\n",match);
        }
        


    }
    printf("the remaining stick is %d\n",match);
    printf("so you have to pick the last one and the computer wins the game.\n");
    return 0;
}