#include<iostream>
#include<cstdlib>
using namespace std;
class node
{
	public:
		int data;
		node *next;
};
class stack
{
	public:
		node *top;
		stack()
		{
			top=NULL;
		}
		void push();
		void pop();
		void traverse();
};
void stack::push()
{
	int info;
	node *newnode=new node;
	cout<<"Enter data to be pushed into the stack"<<endl;
	cin>>info;
	cout<<endl;
	
	if(top==NULL || info==top->data)
	{
		if(top!=NULL && info==top->data)
		{
			cout<<endl;
			cout<<"Duplicate values not allowed"<<endl;
			cout<<endl;
			return;
		}
		newnode->data=info;
		newnode->next=top;
		top=newnode;
	}
	else 
	{
		newnode->data=info;
		newnode->next=top;
		top=newnode;
	}
	cout<<"Data succesfully pushed into the stack"<<endl;
	cout<<endl;
}
void stack::pop()
{
	if(top==NULL)
	{
		cout<<endl;
		cout<<" ! Stack Underflow : Stack is empty "<<endl;
		return;
	}
	node *newnode,*delnode;
	
	delnode=top;
	top=top->next;
	cout<<endl;
	cout<<" The popped element is : "<<endl;
	cout<<delnode->data<<endl;
	cout<<endl;
	delete delnode;

	
	
}
void stack::traverse()
{
	cout<<endl;
	node *currentnode;
	if(top==NULL)
	{
		cout<<" ! Stack Underflow : Stack is empty "<<endl;
		cout<<endl;
		return;
	}
	cout<<"The contents of the stack are :"<<endl;
	cout<<endl;
	for(currentnode=top;currentnode!=NULL;currentnode=currentnode->next)
	{
		cout<<currentnode->data<<endl;
	}
}
int main()
{
	char ch;
	stack mystack;
	while(1)
	{
		cout<<"Menu"<<endl;
		cout<<"1. push element into the stack"<<endl;
		cout<<"2. pop out element from the stack"<<endl;
		cout<<"3. view the stack"<<endl;
		cout<<"4. exit"<<endl;
		cout<<endl;
		cout<<"Enter any of the above choices"<<endl;
		cin>>ch;
		switch(ch)
		{
			case '1':
				{
					mystack.push();
					cout<<endl;
				}break;
				
			case '2':
			{
				mystack.pop();
				cout<<endl;
				
			}break;
			
			case '3':
			{
				mystack.traverse();
				cout<<endl;
				}break;
				
				case '4':
				{
					exit(0);
					cout<<endl;
					}break;
					
					default:
					{
						cout<<"! invalid choice try again"<<endl;
						cout<<endl;
						}break;	
		}
		
	}
	return 0;
}
