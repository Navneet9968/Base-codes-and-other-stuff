#include<iostream>
using namespace std;

//classes are equivalent to struct in c 

class emp{
    public:
        string name;
        int num;
        char grade;

};
int main(){
    emp emp1;
    emp1.name="navneet";
    emp1.grade='A';
    emp1.num=1;
    cout<<"employee: "<<emp1.name<<endl;
    cout<<"num: "<<emp1.num<<endl;
    cout<<"grade: "<<emp1.grade<<endl;
    return 0;
}








