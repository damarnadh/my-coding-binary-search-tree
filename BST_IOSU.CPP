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
Node * minValue(Node* node)
{
    Node* current = node;
    while (current->left != NULL)
    {
	 current = current->left;
    }
    return current;
}
Node* inorderSuccessor(Node* root, Node* temp)
{
    if (temp->right != NULL)
    {
	 return minValue(temp->right);
    }
    Node *succ =NULL;
    while (root!=NULL)
    {
	 if (temp->key < root->key)
	 {
	      succ = root;
	      root = root->left;
	 }
	 else if (temp->key > root->key)
	 {
	      root = root->right;
	 }
	 else
	 {
	      break;
	 }
    }
    return succ;
}
void main()
{
     clrscr();
     Node *root = NULL,*temp,*succ;
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
     temp=root->left->left;
     succ=inorderSuccessor(root,temp);
     if(succ!=NULL)
     {
	  cout<<"\ninorder successor of"
	      <<temp->key<<"is"<<succ->key;
     }
     getch();
}