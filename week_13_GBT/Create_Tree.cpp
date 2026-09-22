#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    this->data = val;
    left = NULL;
    right = NULL;
  }
  static Node *createTree() {
    cout << "enter the value of first Node" << endl;
    int val;
    cin >> val;
    if (val == -1) {
      return NULL;
    } else {
      Node *root = new Node(val);
      cout << "adding node to left " << val << endl;
      root->left = createTree();
      cout << "adding node to right " << val << endl;
      root->right = createTree();
      return root;
    }
  }
};
int main() {
  Node *root = Node::createTree();
  // root = createTree();
  cout << "printing value of root " << root->data << endl;

  return 0;
}