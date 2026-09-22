#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }
    static Node *createTree()
    {
        cout << "enter the value of first Node" << endl;
        int val;
        cin >> val;
        if (val == -1)
        {
            return NULL;
        }
        else
        {
            Node *root = new Node(val);
            // cout << "adding node to left " << val << endl;
            root->left = createTree();
            // cout << "adding node to right " << val << endl;
            root->right = createTree();
            return root;
        }
    }
};
//------------------------NLR
void preOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << root->data << " " << endl;
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
// -----------------------LNR
void inOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inOrderTraversal(root->left);
        cout << root->data << " " << endl;
        inOrderTraversal(root->right);
    }
}
// ---------------------- LRN
void postOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " " << endl;
    }
}
void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    } 
    queue<Node *> q;
    q.push(root); //! level complete hone ke baad NULL laga diya taki coutt<<endl ho jaye jab level complete ho
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front(); //! save the Node
        q.pop();                 // ! pop the Node
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " "; //! print the Node
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}
int main()
{
    Node *root = Node::createTree();
    // 10 50 40 -1 -1 -1 30 20 -1 -1 -1
    // cout << "printing value of root " << root->data << endl;
    // levelOrderTraversal(root);
    preOrderTraversal(root);
    return 0;
}