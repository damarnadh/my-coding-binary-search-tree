#include<conio.h>
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
     getch();
}