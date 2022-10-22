1.  the global resolution operator ::  gives the value of global operator 

#include<iostream>
using namespace std;
int c=34;
int main(){
    int c=4;
    cout<<"the value of c is "<<c<<endl;  //as precedence is given to local value over global value
    cout<<"the global value of c is "<<::c<<endl;   
    return 0;
}

