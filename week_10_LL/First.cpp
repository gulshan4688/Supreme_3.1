#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};
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
void insertAthead(Node *&head, Node *&tail, int d)
{
    if (head == NULL && tail == NULL)
    {
        Node *newNode = new Node(d);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(d);
        newNode->next = head;
        head = newNode;
    }
}
void inserAtTial(Node *&tail, Node *&head, int d)
{
    // first case is that LL is empty
    if (tail == NULL && head == NULL)
    {
        Node *newNode = new Node(d);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // create that Node
        Node *newNode = new Node(d);
        // add to the tail
        tail->next = newNode;
        // tail ko last mei laga do
        tail = newNode;
    }
}
void insertAtPosition(Node *&head, Node *&tail, int pos, int d)
{
    int length = getLength(head);
    Node *temp = head;
    if (pos == 1)
    {
        insertAthead(head, tail, d);
    }
    else if (pos == (length + 1))
    {
        inserAtTial(tail, head, d);
    }
    else if (pos > length || pos < 1)
    {
        cout << "invalid positionXXX" << endl;
    }
    else
    {
        Node *temp = head;
        // insertion in betweeen
        // create the node
        while (pos != 2)
        {
            temp = temp->next;
            pos--;
        }
        Node *newNode = new Node(d);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
// now we have to find the element
void deleteNode(Node *&head, Node *&tail, int pos)
{
    if (head == NULL && tail == NULL)
    {
        cout << endl
             << "Linked list is empty";
        return;
    }
    if (head == tail)
    {
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    else
    {
        // for deleteing first node
        if (pos == 1)
        {
            Node *temp = head;
            head = temp->next;
            temp->next = NULL;
            delete temp;
            return;
        }
        // we are deleting on a position
        // so fisrt we have to go on postion whihc we are specifying
        Node *temp = head;
        if (temp == NULL || temp->next == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }
        Node *nodeToDelete = temp->next;

        int currentPosition = 1;
        // Traverse to the (pos-1)th node
        while (temp != NULL && currentPosition < pos - 1)
        {
            temp = temp->next;
            currentPosition++;
        }

        temp->next = nodeToDelete->next;
        nodeToDelete->next = NULL;
        delete nodeToDelete;
        // return;
    }
}
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
        else
        {
            position++;
        }
        temp = temp->next;
    }
    return -1;
}

void print(Node *head)
{
    // Node *temp = head;
    // head = temp;
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL";
    cout << endl;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    // Node *First = new Node(10);
    // First->data = 10;
    // cout<<First->data;
    // cout<<First->next;
    // Node *Sec = new Node(11);
    insertAthead(head, tail, 11);
    insertAthead(head, tail, 12);
    insertAthead(head, tail, 13);
    // print(head);
    inserAtTial(tail, head, 10);
    // print(head);
    inserAtTial(tail, head, 9);
    inserAtTial(tail, head, 8);
    print(head);
    insertAtPosition(head, tail, 3, 7);
    print(head);
    int pos = searchLL(head, 8);
    cout << "postion --" << pos;
    deleteNode(head, tail, 4);
    print(head);
    cout << "length= " << getLength(head);
    return 0;
}