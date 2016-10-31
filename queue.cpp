#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;

class node
{
	public:
	int data;
	node* next;
	node* prev;
};
class queue
{
	public:
		node* front;
		node* rear;
		queue()
		{
			front=NULL;
			rear=NULL;
		}
		void insertdata();
		void deldata();
		void searchdata();
		void traverse();
	
};
void queue::insertdata()
{
	int info;
	cout<<endl<<"Enter the data to be inserted into the queue :"<<endl;
	cin>>info;
	node* newnode=new node;
	node* current=new node;
	
	newnode->data=info;
	newnode->next=NULL;
	newnode->prev=NULL;
	
	if(front==NULL && rear==NULL)
	{
		front=newnode;
		rear=newnode;
		cout<<endl<<"Data succesfully inserted"<<endl;
		return;
	}
	
	for(current=front;current->prev!=NULL;current=current->prev)
	{
		if(current->data==info)
		{
			break;
		}
	}
	
	if(current->data==info)
	{
		cout<<endl<<"Duplicate values not allowed "<<endl;
		return;
	}
	else
	{
		newnode->next=rear;
		newnode->prev=NULL;
		rear->prev=newnode;
		rear=newnode;
		cout<<endl<<"Data succesfully inserted"<<endl;
		return;
	}
	
	
}
void queue::deldata()
{
	if(front==NULL && rear==NULL)
	{
		cout<<endl<<"The queue is empty"<<endl;
		return;
	}
	
     node* delnode;
     delnode=front;
     front=front->prev;
     front->next=NULL;
     cout<<endl<<"The retrieved element is : "<<delnode->data<<endl;
     delete delnode;
     
}
void queue::searchdata()
{
	int info,j;
	j=1;
	cout<<endl<<"Enter the data to be searched"<<endl;
	cin>>info;
	if(front==NULL && rear==NULL)
	{
		cout<<endl<<"The queue is empty"<<endl;
		return;
	
	}
	
	node* searchnode;
	searchnode=front;
	while(searchnode->prev!=NULL)
	{
		if(searchnode->data==info)
		{
			break;
		}
		else
		{
			searchnode=searchnode->prev;
			j++;
		}
	}
	if(searchnode->data!=info)
	{
		cout<<endl<<"The node does not exist"<<endl;
	}
	else
	{
		cout<<endl<<"Node found at position : "<<j<<endl;
	}
}

void queue::traverse()
{
	if(front==NULL && rear==NULL)
	{
		cout<<endl<<"The queue is empty"<<endl;
		return;
	}
	node* traversenode;
	traversenode=front;
	cout<<endl;
	cout<<"The queue is as follows :"<<endl;
	while(traversenode->prev!=NULL)
	{
		cout<<traversenode->data<<endl;
		traversenode=traversenode->prev;
	}
	cout<<rear->data<<endl;
}

int main()
{
	char ch;
	queue myqueue;
	while(1)
	{
		cout<<endl<<"***** Menu *****"<<endl;
		cout<<"1. Insert element into the queue"<<endl;
		cout<<"2. Retrieve element from the queue"<<endl;
		cout<<"3. Search an element in the queue"<<endl;
		cout<<"4. Traverse the queue"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<endl<<"****************************"<<endl;
		cout<<endl<<"Enter any choice between 1-5"<<endl;
		cin>>ch;
		switch(ch)
		{
			case '1':
				{
					myqueue.insertdata();
				}break;
				
			case '2':
			{
				myqueue.deldata();
			}break;	
			
			case '3':
				{
					myqueue.searchdata();
				}break;
				
			case '4':
				{
					myqueue.traverse();
				}break;
				
			case '5':
				{
					exit(0);
					
				}break;
				
				default:
					{
						cout<<"Invalid Selection ! Try again"<<endl;
					}break;
		}
	}
	return 0;
}
