#include<iostream>
using namespace std;
class tree
{
	int data ;
	tree *left, *right ,*head ;
	int lthread,rthread;
	public:
		tree* create(int);
		void insert(int);
		void inorder_tbt();
		void preorder_tbt();
		void check_head();
		tree* inorder_successor(tree *);
		tree()
		{
			head=NULL;
		}	
};
tree* tree::create(int d)
{
	tree *newnode = new tree();
	newnode->left=head;
	newnode->right=head;
	newnode->lthread=1;
	newnode->rthread=1;
	newnode->data=d;
	return newnode;
}
void tree::insert(int key)
{
	if(head==NULL)
	{
		head=create(key);
		head->rthread=0;
	}
	else
	{
		tree *curr=head;
		tree *newnode;
		newnode=create(key);	
		if(head->lthread==1)
		{
			head->left=newnode;
			head->lthread=0;
		}
		else
		{
			curr=curr->left;
			while(1)
			{
				if(key>curr->data)
				{
					if(curr->rthread==1)
					{
						newnode->right=curr->right;
						curr->right=newnode;
						curr->rthread=0;
						newnode->left=curr;
						break;
					}
					else
						curr=curr->right;
				}
				else
				{
					if(curr->lthread==1)
					{
						newnode->left=curr->left;
						curr->left=newnode;
						curr->lthread=0;
						newnode->right=curr;
						break;
					}
					else
						curr=curr->left;
				}
			}
		}
	}
}		
void tree::inorder_tbt()
{
	tree *curr=head->left;
	while(curr->lthread!=1)
		curr=curr->left;
	cout<<curr->data<<"\t";
	while(curr->right!=head)
	{
		curr=inorder_successor(curr);
		cout<<curr->data<<"\t";
	}
}
tree* tree::inorder_successor(tree* curr)
{
	tree *temp=curr->right;
	if(curr->rthread!=1)
	{
		while(temp->lthread!=1)
		{
			temp=temp->left;
		}
	}
	return temp;
}			
void tree::preorder_tbt()
{
	if(head->lthread==1)
		cout<<" Tree has no node !! ";
	tree* curr=head->left;	
	while(curr->right!=head)
	{
		cout<<curr->data<<"\t";
		if(curr->lthread==0)
			curr=curr->left;
		else if(curr->rthread==0)	
			curr=curr->right;
		else
		{
			while( curr->rthread==1)
				curr=curr->right;
			curr=curr->right;
		}				
	}
	cout<<curr->data;
}	
						
int main()
{
	tree obj;
	int n,choice;
	int ele;
	char ans;
	cout<<"Enter the no.of elements you want to insert:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		if(i==0)
			obj.insert(1212);
		cout<<"Enter the element you want to insert:";
		cin>>ele;	
		obj.insert(ele);	
	}
	do
	{
		cout<<" 1.Insert a new Element. \n 2.Apply In-order traversal. \n 3.Apply Pre-Order traversal \n Enter your choice : \n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					cout<<"Enter the element you want to insert:";
					cin>>ele;	
					obj.insert(ele);
					cout<<"Node inserted successfully !\n";
					break;
				}
			case 2:
				{
					cout<<"The In-Order Traversal is as follows : \n";
					obj.inorder_tbt();
					break;
				}
			case 3:
				{
					cout<<"The Pre-Order Traversal is as follows : \n";	
					obj.preorder_tbt();
					break;
				}	
		}	
		cout<<"\nDo you want to continue (y/n) ?";
		cin>>ans;	
	}while(ans=='Y' || ans=='y');	
	return 0;
}
