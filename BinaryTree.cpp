#include <iostream>
using namespace std;
struct node
{
    node *right;
    int data;
    node *left;
};
node *create();
void inOrder(node *);
void preOrder(node *);
void postOrder(node *);
int main()
{
    node *root;
    root = create();
    cout << "The output for preOrder " << endl;
    preOrder(root);
    cout << endl;
    cout << "The output for postOrder " << endl;
    postOrder(root);
    cout << endl;
    cout << "The output for inOrder " << endl;
    inOrder(root);
    return 0;
}
node *create()
{
    int x;
    node *newNode;
    newNode = new node;
    cout << "Enter the number but (-1 for no node) ==> ";
    cin >> x;
    if (x == -1)
        return 0;
    newNode->data = x;
    cout << "Data will be entered for left node " << endl;
    newNode->left = create();
    cout << "Data will be entered for right node " << endl;
    newNode->right = create();
    return newNode;
}
void inOrder(node *root)
{
    if (root == 0)
        return;
    inOrder(root->left);
    cout << root->data << "\t";
    inOrder(root->right);
}
void preOrder(node *root)
{
    if (root == 0)
        return;
    cout << root->data << "\t";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(node *root)
{
    if (root == 0)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << "\t";
}