#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
class node
{
	public:
		int data;
		node *next;
};

class list
{
	node *start;
	public:
		list();
		void addnode();
		bool search(int info, node **current, node **previous);
		bool listempty();
		bool delnode(int element);
		void traverse();
		
};

list::list()
{
	start= NULL ;
}
void list::addnode()
{
	 int info;
	cout<<"Enter the data "<<endl;
	cin>>info;
	node *newnode=new node;
	newnode->data=info;
	if(start== NULL || info<=start->data)
	{
		if(start!= NULL && info==start->data)
		{
			cout<<"Duplicate values not allowed"<<endl;
			return;
		}
		newnode->next=start;
		start=newnode;
		return;
	}
	node *previous,*current;
	previous=start;
	current=start;
	while((current!= NULL) && (info>=current->data))
	{
		if(info==current->data)
		{
			cout<<"duplicate values not allowed"<<endl;
			return;
		}
		previous = current;
		current=current->next;
		
	}
	newnode->next=current;
	previous->next=newnode;
	
}
bool list::listempty()
{
	if(start== NULL)
	return true;
	else 
	return false;
}
bool list::delnode(int element)
{
	node *current,*previous;
	if(search(info,&current,&previous)==false)
	{
		return false;
	}
	previous->next=current->next;
	if(current==start)
	{
		start=start->next;
		delete current;
		return true;
	}
}
bool list::search(int info,node **current,node **previous)
{
	*previous=start;
	*current=start;
	while(*current!=NULL && info!=*current->data)
	{
		*previous=*current;
		current =*current->next;
		
	}return (*current!=NUll);
	
	
	
}
void list::traverse()
{
	if(listempty())
	{
		cout<<"list is empty"<<endl;
	}
	else
	{
		cout<<"Record in the list are:"<<endl;
		node *currentnode;
		for(currentnode=start;currentnode!=null;currentnode=currentnode->next)
		{
			cout<<currentnode->data<<endl;
		}
		cout<<endl;
	}
	
}
void main()
{
	list mylist;
	int info;
	char ch;
	while(1)
	{
		cout<<endl<<"Menu";
		cout<<endl<<"1. Add a record to the list";
		cout<<endl<<"2. Delete a record from the list";
		cout<<endl<<"3. View all the records in the list";
		cout<<endl<<"4. Search for a record in the list";
		cout<<endl<<"5. Exit";
		cout<<endl<<"Enter a choice between (1-5)"<<endl;
		cin>>ch;
		switch(ch)
		{
			case '1':
				{
					mylist.addnode();
					
				}break;
			case '2':
			{
				if(mylist.listempty())
				{
				cout<<"list is empty"<<endl;
				break;
				}
				
				cout<<"Enter the data whose record is to be deleted "<<endl;
				cin>>info;
				if(mylist.delnode(info)==false)
				{
					cout<<"record not found"<<endl;
				}
				else 
				{
					cout<<"record with data "<<info<<"is deleted"<<endl;
				}
			}break;
			case '3':
			{
				mylist.traverse();
				
				
			}break;
			case '4':
			{
				if(mylist.listempty()==true)
				{
					cout<<"list is empty"<<endl;
					break;
				}
				node *previous,*current;
				cout<<"Enter the data to be searched"<<endl;
				cin>>info;
				if(mylist.search(info,&current,&previous)==false)
				{
					cout<<"no record found"<<endl;
					break;
				}
				else
				{
					cout<<"record found"<<endl;
					cout<<"info is "<<current->data;
					
				}
				
			}break;
			case '5':
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