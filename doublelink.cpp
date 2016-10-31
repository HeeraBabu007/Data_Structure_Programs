#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;
class node
{
	public:
		int data;
		node *prev;
		node *next;
};
class list
{
	public:
		node *start;
		list()
		{
			start=NULL;
		}
		void addnode();
		void ftraverse();
		void rtraverse();
		void search();
		bool listempty();
};
void list::addnode()
{
	int info;
	node *newnode=new node;
	cout<<"Enter the data to be inserted"<<endl;
	cin>>info;
	if(start==NULL || info==start->data)
	{
		if(start!=NULL && info==start->data)
		{
			cout<<"Duplicate values not allowed"<<endl;
		}
		newnode->data=info;
		newnode->next=start;
		newnode->prev=NULL;
		start=newnode;
		start->prev=NULL;
    }
    else 
    {
    	node *current=new node;
    	node *previous=new node;
    	current=start;
    	previous=start;
    	while(current!=NULL)
    	{
    		if(current->data==info)
    		{
    			cout<<"Duplicate values not allowed"<<endl;
    			break;
			}
			else
			{
			    previous=current;
			
			    current=current->next;
			    
			}
		}
		newnode->data=info;
		newnode->next=current;
		newnode->prev=previous;
		previous->next=newnode;
		
    }
    cout<<endl;
    
}
bool list::listempty()
{
	if(start==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void list::ftraverse()
{
	if(listempty()==true)
	{
		cout<<"list is empty"<<endl;
	}
	else
	{
		node *currentnode;
		cout<<"The contents of list in forward order are :"<<endl;
		for(currentnode=start;currentnode!=NULL;currentnode=currentnode->next)
		{
			cout<<currentnode->data;
			cout<<endl;
		}
		cout<<endl;
	}
}
void list::rtraverse()
{
	if(listempty()==true)
	{
		cout<<"The list is empty"<<endl;
	}
	node *last=new node;
	node *newnode=new node;
	newnode=start;
	while(newnode->next!=NULL)
	{
		newnode=newnode->next;
	}
	last=newnode;
	cout<<"The contents of the list in reverse order are :"<<endl;
	while(last!=NULL)
	{
		cout<<last->data;
		cout<<endl;
		last=last->prev;
	}
	cout<<endl;
	
}
int main()
{
	char ch;
	list mylist;
	while(1)
	{
		
	 cout<<endl;
	 cout<<"*********************************"<<endl;
	 cout<<"************* Menu **************"<<endl;
	 cout<<endl;
	 cout<<"1. Add node to double link list"<<endl;
	 cout<<"2. Forward traversal"<<endl;
	 cout<<"3. Reverse traversal"<<endl;
	 cout<<"4. Exit"<<endl;
	 cout<<endl;
	 cout<<"*********************************"<<endl;
	 cout<<endl;
	 cout<<"Enter any of the above choices 1-3"<<endl;
	 cout<<endl;
	 cin>>ch;
	
	
		switch(ch)
		{
			case '1':
				{
					mylist.addnode();
					
				}break;
				
			case '2':
			{
				mylist.ftraverse();
				cout<<endl;
		    }break;
		    
			case '3':
			{
				mylist.rtraverse();
				cout<<endl;
			  } break;
			 
			 case '4':
			 {
			 	exit(0);
			   } break;
			   
			   default:
			   {
			   	cout<<"invalid selection"<<endl;
			   }break; 
				
		}
	}
	return 0;
}


