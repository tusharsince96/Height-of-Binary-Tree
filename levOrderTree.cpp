//LevelOrderTraversal Using Queue
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newnode(int data)
{
	struct node *node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}
void inorder(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
//level Order Traversal
 struct node *queue[MAX];
 int front=-1,rear=-1;
 void insert_queue(struct node *item)
 {
 	
 	if(rear==MAX-1)
 	{
 		printf("Queue overflow\n");
 		return;
	}
	 if(front==-1)
	 front=0;
	 rear=rear+1;
	 queue[rear]=item;
 }
 struct node *del_queue()
 {
 	if(front==-1 || front==rear+1)
 	{
 		printf("Queue Underflow\n");
 		return 0;
	 }
	 struct node *item;
	 item=queue[front];
	 front=front+1;
	 return item;
 }
 int que_empty()
 {
 	if(front==-1 || front==rear+1)
 	return 1;
 	else
 	return 0;
 }
 void level_order(struct node *root)
 {
 	struct node *ptr=root;
 	if(ptr==NULL)
 	{
 		printf("Tree is Empty \n");
 		return;
	 }
	 insert_queue(ptr);
	 while(!que_empty())
	 {
	 	ptr=del_queue();
	 	printf("%d ",ptr->data);
	 	if(ptr->left!=NULL)
	 	insert_queue(ptr->left);
	 	if(ptr->right!=NULL)
	 	insert_queue(ptr->right);
	 }
	 printf("\n");
 	
 }
 int height(struct node *ptr)
 { 
 int h_left,h_right;
 	if(ptr==NULL)
 	return 0;
	 h_left=height(ptr->left); 
	 h_right=height(ptr->right);
	 if(h_left > h_right)
	 return 1 + h_left;
	 else
	 return 1 + h_right;
	 
 }
 
main()
{
	struct node *root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	inorder(root);
	printf("\n");
	level_order(root);
	printf("\nHeight of this tree is %d ",	height(root));

}
