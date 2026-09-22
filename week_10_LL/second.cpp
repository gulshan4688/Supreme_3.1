#include <iostream>
using namespace std;
class Node
{
public:
    Node *prev;
    int data;
    Node *next;
    // constructor
    Node(int value)
    {
        this->data = value;
        this->next = NULL;
        this->prev = NULL;
    }
};
int getLength(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}
void insertAtHead(Node *&head, Node *&tail, int value)
{
    if (head == NULL || tail == NULL)
    { // linked list is empty
        // we will create our first Node
        Node *firstNode = new Node(value);
        head = firstNode;
        tail = firstNode;
    }
    else
    {
        // linked list is empty
        Node *newNode = new Node(value);
        newNode->next = head;
        head->prev = newNode;

        head = newNode;
    }
}
void insertAtTail(Node *&head, Node *&tail, int value)
{
    // two case linked list is empty and its not
    if (head == NULL && tail == NULL)
    { // linked list is empty
        // we will create our first Node
        Node *firstNode = new Node(value);
        tail = firstNode;
        head = firstNode;
    }
    else
    {
        // linked list is not empty
        Node *newNode = new Node(value);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}
void insertAtPosition(Node *&head, Node *&tail, int pos, int value, int len)
{
    if (pos == 1)
    {
        insertAtHead(head, tail, value);
    }
    else if (pos == (len + 1))
    {
        insertAtTail(head, tail, value);
    }
    else
    {
        Node *curr = head;
        while (pos != 2)
        {
            pos--;
            curr = curr->next;
        }
        Node *newNode = new Node(value);
        newNode->next = curr->next;
        curr->next->prev = newNode;
        newNode->prev = curr;
        curr->next = newNode;
    }
}
int searchDLL(Node *head, int target)
{
    int position = 1;
    while (head != NULL)
    {
        if (head->data == target)
        {
            return position;
        }
        else
        {
            position++;
        }
        head = head->next;
    }
    return -1;
}
void deletion(Node *&head, Node *&tail, int position)
{
    if (head == NULL && tail == NULL)
    {
        cout << "Node is empty";
        return;
    }
    else if (head == tail)
    {
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
    }
    else if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        // tail = NULL;
        delete temp;
    }
    else
    {
        Node *prev = head;
        int traverser = 2;
        while (traverser != position)
        {
            traverser++;
            prev = prev->next;
        }
        Node *curr = prev->next;
        if (curr == tail)
        {                // Deleting the last node
            tail = prev; // qki curr to delete ho jayega na
            tail->next = NULL;
        }
        else
        {
            Node *forward = curr->next;
            forward->prev = prev;
            prev->next = forward;
        }
        curr->prev = NULL;
        curr->next = NULL;
        delete curr;
    }
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void printReverse(Node *&tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 4);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 6);
    insertAtTail(head, tail, 7);
    insertAtPosition(head, tail, 3, 100, getLength(head));
    print(head);
    // printReverse(tail);
    deletion(head, tail, 9);
    // int lenght=getLength(head);
    // if(searchDLL(head,4)==(-1)){
    //     cout<<"Not Found"<<endl;
    // }else{
    //     cout<<"found on the position:"<<searchDLL(head,4)<<endl;
    // }
    print(head);
    return 0;
}