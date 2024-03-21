#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left, *right;
};
node *create()
{
    node *newNode;
    newNode = new node;
    int x;
    cout << "Enter the number but (-1) for no node ";
    cin >> x;
    if (x == -1)
        return 0;
    newNode->data = x;
    cout << "Enter data for the left node \n";
    newNode->left = create();
    cout << "Enter data for the right node \n";
    newNode->right = create();
    return newNode;
}
void preOrder(node *root)
{
    if (root == 0)
        return;
    cout << root->data << "\t";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{
    node *root;
    root = create();
    cout << "Output in case of preorder is " << endl;
    preOrder(root);
    return 0;
}