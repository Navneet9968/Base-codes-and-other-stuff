#include <iostream>
#include<windows.h>
#include<mysql.h>
#include<sstream>
#include<bits/stdc++.h>


using namespace std;

int main()
{
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.1.38", "admin", "admin", "file", 0, NULL, 0);
    MYSQL_ROW row;
    MYSQL_RES* res;

        if(conn){
        int qstate = mysql_query(conn, "delimiter $$\
                create trigger verify_age before insert on employee\
                for each row\
                                    begin\
                if new.dob > '1995-01-01' then\
                signal sqlstate '45000'\
                set message_text = 'error:age must be atleast 25 years!';\
                end if;end;");
        if(!qstate){
            res = mysql_store_result(conn);
            int count = mysql_num_fields(res);
            while(row = mysql_fetch_row(res)){
                    for(int i=0;i<count;i++){
                        cout<<"\t"<<row[i];
                    }
                    cout<<endl;
            }
        }
    }

    else{
        cout<<"not connected"<<endl;
    }
    cout << "Hello world!" << endl;






    return 0;
}
