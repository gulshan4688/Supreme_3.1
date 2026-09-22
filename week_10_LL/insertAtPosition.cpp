#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};

// Get the length of the linked list
int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// Insert at the head of the linked list
void insertAtHead(Node *&head, Node *&tail, int d)
{
    Node *newNode = new Node(d);
    if (head == NULL && tail == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

// Insert at the tail of the linked list
void insertAtTail(Node *&tail, Node *&head, int d)
{
    Node *newNode = new Node(d);
    if (tail == NULL && head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// Insert at a specific position in the linked list
void insertAtPosition(Node *&head, Node *&tail, int pos, int d)
{
    int length = getLength(head);

    if (pos < 1 || pos > length + 1)
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    if (pos == length + 1)
    {
        insertAtTail(tail, head, d);
        return;
    }

    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete a node at a specific position
void deleteNode(Node *&head, Node *&tail, int pos)
{
    // when LL is empty
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    int length = getLength(head);
    if (pos < 1 || pos > length)
    {
        cout << "Invalid position" << endl;
        return;
    }
    if (pos == 1)
    { // Delete first node
        Node *temp = head;
        head = head->next;
        if (head == NULL)
        { // List is now empty
            tail = NULL;
        }
        delete temp;
        return;
    }
    //---------------chat gpt way--------------
    // Node *temp = head;
    // for (int i = 1; i < pos - 1; i++) {
    //     temp = temp->next;
    // }

    // Node *nodeToDelete = temp->next;
    // temp->next = nodeToDelete->next;
    // if (nodeToDelete == tail) { // Deleting the last node
    //     tail = temp;
    // }
    // delete nodeToDelete;
    // ---------love babbar way ------------------
    Node *prev = head;
    for (int i = 1; i < pos - 1; i++)
    {
        prev = prev->next;
    }
    Node * curr=prev->next;
    Node * forward =curr->next;
    // deletetion process 
    prev->next=forward;
    curr->next=NULL;
    delete curr;
}

// Search for a target in the linked list
int searchLL(Node *&head, int target)
{
    Node *temp = head;
    int position = 1;

    while (temp != NULL)
    {
        if (temp->data == target)
        {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

// Print the linked list
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 11);
    insertAtHead(head, tail, 12);
    insertAtHead(head, tail, 13);
    insertAtTail(tail, head, 10);
    insertAtTail(tail, head, 9);
    insertAtTail(tail, head, 8);
    // print(head);

    insertAtPosition(head, tail, 3, 7);
    print(head);

    int pos = searchLL(head, 8);
    cout << endl
         << "Position of 8: " << pos << endl;

    deleteNode(head, tail, 7);
    print(head);

    cout << "Length: " << getLength(head) << endl;

    return 0;
}
