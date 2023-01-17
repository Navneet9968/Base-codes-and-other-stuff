#include <bits/stdc++.h>
using namespace std;


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

//peak elements in a mountain array
int peakIndexInMountainArray(vector<int>& arr) {
        int low=0;
        int high=arr.size()-1;
        int mid=(low+high)/2;
        if(arr[0]>arr[1]){
            return 0;
        }
        if(arr[high]>arr[high-1]){
            return high;
        }
        while(low<=high){
            mid=(low+high)/2;
            if(mid==0 ||mid==high){
                break;
            }
            if((arr[mid]>arr[mid-1]) && (arr[mid]>arr[mid+1])){
                return mid;
            } 
            if((arr[mid]<arr[mid+1]) && (arr[mid]>arr[mid-1])){
                low=mid+1;
                if(arr[low]>arr[low+1]){
                    return low;
                }
            }
            else{
                high=mid-1;
                if(arr[high]>arr[high-1]){
                    return high;
                }
            }
        }
        return mid;
    }


    ///////////
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