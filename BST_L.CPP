#include<conio.h>
#include<iostream.h>
struct Node
{
    int key;
    Node *left, *right;
};
Node *newNode(int item)
{
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
Node * largest(Node *root)
{
    Node* current = root;
    while (current->right != NULL)
    {
	 current = current->right;
    }
    return current;
}
Node* insert(Node* node, int key)
{
    if (node == NULL)
    {
	 return newNode(key);
    }
    if (key < node->key)
    {
	node->left  = insert(node->left, key);
    }
    else if (key > node->key)
    {
	node->right = insert(node->right, key);
    }
    return node;
}
void main()
{
    clrscr();
    Node *root = NULL,*large;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    large=largest(root);
    cout<<"Largest element is"<<large->key;
    getch();
}