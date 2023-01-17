#include <iostream>
#include <vector>

using namespace std;
class node
{
public:
    string name;
    node *next;
    node(string data)
    {
        this->name = data;
        this->next = NULL;
    }
};

void addPassenger(vector<pair<node *, string>> &flight_head)
{
    string flight;
    cout << "Enter flight Number:";
    cin >> flight;

    int size;
    cout << "Enter no of passengers:";
    cin >> size;

    int flight_no = -1;
    node *head;
    for (int i = 0; i < flight_head.size(); i++)
    {
        if (flight == flight_head[i].second)
        {
            head = flight_head[i].first;
            flight_no = i;
            break;
        }
    }
    if (flight_no == -1)
    {
        cout << "Flight not found !" << endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        string name;
        cout << "Enter Passenger Name :";
        cin >> name;
        cout << endl;
        node *node1 = new node(name);
        node1->next = head;
        head = node1;
    }
    flight_head[flight_no].first = head;
}

node *deleteNode(node *head, string data)
{
    if (head == NULL)
        return NULL;
    // delete at head
    if (head->name == data)
    {
        node *temp = head;
        temp->next = NULL;
        head = head->next;
        return head;
    }
    node *prev = head;
    node *cur = head->next;
    while (cur != NULL)
    {
        if (cur->name == data)
        {
            prev->next = cur->next;
            cur->next = NULL;
            return head;
        }
        prev = cur;
        cur = cur->next;
    }
    if (prev->name == data)
    {
        prev->next = NULL;
        return head;
    }
    cout << "Name not found !" << endl;
    return head;
}

void removePassenger(vector<pair<node *, string>> &flight_head)
{
    string flight;
    cout << "Enter flight Number:";
    cin >> flight;

    int size;
    cout << "Enter no of passengers:";
    cin >> size;

    int flight_no = -1;
    node *head;
    for (int i = 0; i < flight_head.size(); i++)
    {
        if (flight == flight_head[i].second)
        {
            head = flight_head[i].first;
            flight_no = i;
            break;
        }
    }
    if (flight_no == -1)
    {
        cout << "Flight not found !" << endl;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        string name;
        cout << "Enter Passenger Name :";
        cin >> name;
        cout << endl;
        head = deleteNode(head, name);
    }
    flight_head[flight_no].first = head;
}

void displayName(vector<pair<node *, string>> &flight_head)
{
    string flight;
    cout << "Enter flight Number:";
    cin >> flight;
    cout << endl;

    int flight_no = -1;
    node *head;
    for (int i = 0; i < flight_head.size(); i++)
    {
        if (flight == flight_head[i].second)
        {
            head = flight_head[i].first;
            flight_no = i;
            break;
        }
    }
    if (flight_no == -1)
    {
        cout << "Flight not found !" << endl;
        return;
    }

    if (head == NULL)
    {
        cout << "No Passengers" << endl;
        return;
    }

    while (head != NULL)
    {
        cout << head->name << "  ";
        head = head->next;
    }
    cout << endl
         << endl;
    return;
}

void passengerCount(vector<pair<node *, string>> &flight_head)
{
    string flight;
    cout << "Enter flight Number:";
    cin >> flight;
    cout << endl;

    int flight_no = -1;
    node *head;
    for (int i = 0; i < flight_head.size(); i++)
    {
        if (flight == flight_head[i].second)
        {
            head = flight_head[i].first;
            flight_no = i;
            break;
        }
    }
    if (flight_no == -1)
    {
        cout << "Flight not found !" << endl;
        return;
    }

    if (head == NULL)
    {
        cout << "Number of passanger = 0" << endl;
        return;
    }
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    cout << "Number of passanger = " << count << endl;
    return;
}

int main()
{

    int flight_count;
    cout << "Enter no, of flights:";
    cin >> flight_count;
    vector<pair<node *, string>> flight_head;
    for (int i = 0; i < flight_count; i++)
    {
        pair<node *, string> data;
        string flight_no;
        cout << "Enter flight number : ";
        cin >> flight_no;
        data = {NULL, flight_no};
        flight_head.push_back(data);
    }

    char enter;
    cout << "do you want to enter any data (y/n):";
    cin >> enter;
    cout << endl;
    while (enter == 'y' || enter == 'Y')
    {
        int i;
        cout << " 1.for adding passenger." << endl;
        cout << " 2.for removing passenger." << endl;
        cout << " 3.for displaying passenger." << endl;
        cout << "Enter your choice:";
        cin >> i;
        cout << endl;
        switch (i)
        {
        case 1:
            addPassenger(flight_head);
            break;
        case 2:
            removePassenger(flight_head);
            break;
        case 3:
            displayName(flight_head);
            break;
        case 4:
            passengerCount(flight_head);
            break;
        default:
            cout << "Invalid input !" << endl;
            break;
        }
        cout << "Continue (y/n):";
        cin >> enter;
    }
}