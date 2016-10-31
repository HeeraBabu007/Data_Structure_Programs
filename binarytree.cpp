#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;
class node
{
	public:
		int data;
		node *lchild;
		node *rchild;
};
class binarytree
{
	public:
		node *root;
		binarytree()
		{
			root=NULL;
		}
		void addnode(int info);
		void insertnode(int info,node* ptr);
		void inorder(node *ptr);
		void preorder(node *ptr);
		void postorder(node *ptr);
		
};
void binarytree::addnode(int info)
{
	
	insertnode(info,root);
}
void binarytree::insertnode(int info,node* ptr)
{
	node* newnode=new node;
	newnode->data=info;
	newnode->lchild=NULL;
	newnode->rchild=NULL;
	if(root==NULL)
	{
		root=newnode;
	}
	else if(info<ptr->data)
	{
		if(ptr->lchild!=NULL)
		{
			insertnode(info,ptr->lchild);
		}
		else
		{
			ptr->lchild=newnode;
		}
	}
	else if(info>ptr->data)
	{
		if(ptr->rchild!=NULL)
		{
			insertnode(info,ptr->rchild);
		}
		else
		{
			ptr->rchild=newnode;
		}
	}
	else
	{
		cout<<"Duplicate values not allowed"<<endl;
		cout<<endl;
	}
	
	
}
void binarytree::inorder(node *ptr)
{
	
	if(root==NULL)
	{
		cout<<"Tree is empty"<<endl;
		cout<<endl;
		return;
	}
	if(ptr!=NULL)
	{
		
		cout<<endl;
		inorder(ptr->lchild);
		cout<<endl<<ptr->data<<endl;
		inorder(ptr->rchild);
	}
}
void binarytree::postorder(node *ptr)
{
	if(root==NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	if(ptr!=NULL)
	{
		cout<<endl;
		postorder(ptr->lchild);
		cout<<endl;
		postorder(ptr->rchild);
		cout<<endl;
		cout<<ptr->data<<endl;
		
	}
}
void binarytree::preorder(node *ptr)
{
	if(root==NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	if(ptr!=NULL)
	{
		cout<<ptr->data<<endl;
		preorder(ptr->lchild);
		cout<<endl;
		preorder(ptr->rchild);
		cout<<endl;
	}
}
int main()
{
	char ch;
	binarytree mytree;
	while(1)
	{
	
    	cout<<"Menu"<<endl;
		cout<<"1. Insert node into the tree"<<endl;
		cout<<"2. inorder traversal"<<endl;
		cout<<"3. postorder traversal"<<endl;
		cout<<"4. preorder traversal"<<endl;
		cout<<"5. exit"<<endl;
		cout<<"Enter any of the above options"<<endl;
		cin>>ch;
		
		switch(ch)
		{
			    case'1':
				{
					int info;
					cout<<"Enter the data to be inserted :"<<endl;
					cin>>info;
					mytree.addnode(info);
				}break;
				
			    case'2':
			    {
				mytree.inorder(mytree.root);
			    }break;
			
			    case'3':
			    {
				mytree.postorder(mytree.root);
				}break;
				
				case'4':
				{
					mytree.preorder(mytree.root);
				}break;
				
				case'5':
				{
				    exit(0);
				}break;
				
				default:
				{
					cout<<"invalid selection"<<endl;
				}break;	
		}
    }
	
	
		
	
}

