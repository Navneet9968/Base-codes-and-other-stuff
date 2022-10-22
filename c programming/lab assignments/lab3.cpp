#include<iostream>
#include<list>

using namespace std;

class node{
    public:
        int data; 
        node*next;

        //constructor
        node(int data){
            this->data = data;
            this->next = NULL;
        }
};

//function for returning new node with data from heap
node* newNode(int data){
    node* new_node= new node(data);
    new_node->next = NULL;
    return new_node;
}

//insertion at end of the linked list
node * insert_end(node *head,int data){
    node*new_node=newNode(data);
    
    node *ptr=head;

    while((ptr->next)!=NULL){
        ptr=ptr->next;
    }
    
    ptr->next=new_node;
    new_node->next=NULL;
    return head;
}

// Function to print the
// nodes of the linked list.
void printlist(node *head)
{
    node* temp = head;
  
    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
  
    // Traverse the list.
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void FPE(node*head){
    node* prev = head;
    node*cur = head->next;
    node*next = cur->next;
    int count = 0;
    while(next!=NULL){
        if(cur->data > prev->data&&cur->data > next->data){
            cout<<cur->data<<endl;
            count++;
        }
        prev = cur;
        cur = next;
        next=next->next;
    }
    if(count==0){
        cout<<"no peak elements found"<<endl;
    }
    
}
int main(){
    cout<<"enter size of linked list :  "<<endl;
    int size = 0;
    cin>>size;
    node * head=newNode(10);
    int new_data=0;
    for(int i = 0; i<size; i++){
        cout<<"enter data for index   " <<i<<"  "<<endl;
        cin>>new_data;
        insert_end(head,new_data);
    }
    cout<<"the list you entered is  "<<endl;
    printlist(head->next);
    cout<<" \n"<<endl;
    FPE(head->next);
}