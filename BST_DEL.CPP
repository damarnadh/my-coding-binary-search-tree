#include<conio.h>
#include<stdlib.h>
#include<iostream.h>
struct Node
{
     int key;
     Node *left ,*right;
};
Node *newNode(int item)
{
     Node *temp = new Node;
     temp->key = item;
     temp->left = temp->right = NULL;
     return temp;
}
void Print( Node* node )
{
     if( node )
     {
	  Print( node->left );
	  cout << node->key<<" " ;
	  Print( node->right );
     }
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
Node * minValueNode(Node* node)
{
    Node* current = node;
    while (current->left != NULL)
    {
	 current = current->left;
    }
    return current;
}
Node* deleteNode(Node* root, int key)
{
    if (root == NULL)
    {
	 return root;
    }
    if (key < root->key)
    {
	 root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
	 root->right = deleteNode(root->right, key);
    }
    else
    {
	 if (root->left == NULL)
	 {
	      Node *temp = root->right;
	      free(root);
	      return temp;
	 }
	 else if (root->right == NULL)
	 {
	      Node *temp = root->left;
	      free(root);
	      return temp;
	 }
	 else
	 {
	      Node* temp = minValueNode(root->right);
	      root->key = temp->key;
	      root->right = deleteNode(root->right, temp->key);
	 }
    }
    return root;
}
void main()
{
     clrscr();
     Node *root = NULL;
     cout<<"Enter elements to insert";
     int c,i;
     cin>>c;
     root=insert(root,c);
     for(i=0;i<10;i++)
     {
	  cin>>c;
	  insert(root,c);
     }
     Print(root);
     cout<<"\nenter element to delete\n";
     cin>>c;
     deleteNode(root,c);
     Print(root);
     getch();
}