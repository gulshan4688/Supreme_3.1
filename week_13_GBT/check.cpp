#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    this->data = val;
    left = nullptr;
    right = nullptr;
  }
  static Node *createTree() {
    cout << "enter the value of Node";
    int val;
    cin >> val;

    if (val == -1) {
      return NULL;
    } else {
      Node *root = new Node(val);
      root->left = Node::createTree();
      root->right = Node::createTree();
      return root;
    }
  }
};
void PrintPreorder(Node* root){
    if(root==NULL){
        return ;
    }
    else{
        cout<<root->data<<endl;
        PrintPreorder(root->left);
        PrintPreorder(root->right);
    }
}

int main() {
  Node *root = Node::createTree();
  PrintPreorder(root);
  return 0;
}