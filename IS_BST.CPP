#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

int isBSTUtil(struct node* node, int min, int max);

int isBST(struct node* node)
{
     return(isBSTUtil(node, INT_MIN, INT_MAX));
}

int isBSTUtil(struct node* node, int min, int max)
{
     if (node==NULL)
     {
	  return 1;
     }
     if (node->data < min || node->data > max)
     {
	  return 0;
     }
     return isBSTUtil(node->left, min, node->data-1) &&
	    isBSTUtil(node->right, node->data+1, max);
}
struct node* newNode(int data)
{
     struct node* node1 = new node;
     node1->data = data;
     node1->left = NULL;
     node1->right = NULL;

     return(node1);
}
int main()
{
     clrscr();
     struct node *root = newNode(4);
     root->left        = newNode(2);
     root->right       = newNode(5);
     root->left->left  = newNode(1);
     root->left->right = newNode(3);
     if(isBST(root))
     {
	  cout<<"Is BST";
     }
     else
     {
	  cout<<"Not a BST";
     }
     getch();
     return 0;
}