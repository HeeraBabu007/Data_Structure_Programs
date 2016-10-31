#include<iostream>
#include<cstdlib>
#include<conio.h>
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
		list()
		{
			start=NULL;
		}
	    void addnode();
		bool listempty();
		void traverse();
		void search();
		void reverse();
		void delnode();
	
};

void list::addnode()
{
	 int info;
	cout<<"***** Enter the data to be inserted in the node *****"<<endl;
	cin>>info;
	cout<<endl;
	node *newnode=new node;
	if(start==NULL || info==start->data)
	{
		if(start!=NULL && info==start->data)
		{
			cout<<"***** Duplicate values not allowed *****"<<endl;
			return;
		}
		newnode->data=info;
		newnode->next=NULL;
		start=newnode;
		cout<<"***** Data element succesfully inserted *****"<<endl;
		cout<<endl;
	}
	else
	{
		node *previous=new node;
		node *current=new node;
		previous=start;
		current=start;
		while(current!=NULL)
		{
			if(info==current->data)
			{
				cout<<"***** Duplicate values not allowed ******";
				return;
			}
			else
			{
				previous=current;
				current=current->next;
			} 
			
		}
		newnode->data=info;
		newnode->next=current;
		previous->next=newnode;
		cout<<"***** Data element succesfully inserted *****"<<endl;
		cout<<endl;
	}
	
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

void list::search()
{
	int info;
	cout<<"***** Enter the data element to be searched *****"<<endl;
	cin>>info;
	cout<<endl;
	node *searchnode;
	int i=0,j=0;
	for(searchnode=start;searchnode!=NULL;searchnode=searchnode->next)
	{     j++;
		if(searchnode->data==info)
		{
			i++;
			break;
		}
	}
	if(i==0)
	{
		cout<<"***** Node does not exist ******"<<endl;
		cout<<endl;
	}
	if(i==1)
	{
		cout<<"***** Node found at position : "<<j<<" *****"<<endl;
		cout<<endl;
	}
	
}
void list::reverse()
{
	node *node1,*node2,*node3;
	node1=start;
	node2=node1->next;
	node3=node2->next;
	node1->next=NULL;
	node2->next=node1;

	while(node3!=NULL)
	{
		node1=node2;
		node2=node3;
		node3=node3->next;
		node2->next=node1;
	}
	start=node2;
	cout<<"list has been reversed"<<endl;
	
}
void list::traverse()
{
	node *currentnode;
	if(listempty()==true)
	{
		cout<<"***** list is empty *****"<<endl;
	}
	else
	{
		cout<<"***** The contents of the list are : *****"<<endl;
		for(currentnode=start;currentnode!=NULL;currentnode=currentnode->next)
		{
			cout<<currentnode->data;
			cout<<endl;
		}cout<<endl;
	}
	
}
void list::delnode()
{
	node *currentnode,*prevnode,*delnode;
	int info;
	cout<<"**** Enter the data element which needs to be deleted ****"<<endl;
	cout<<endl;
	cin>>info;
	currentnode=start;
	prevnode=start;
	if(start==NULL)
	{
		cout<<"**** The list is empty ****"<<endl;
		cout<<endl;
		return;
	}
	
	while(currentnode!=NULL)
	{
		if(currentnode->data==info)
		{
			break;
		}
	
		prevnode=currentnode;
		currentnode=currentnode->next;
		
	}
	if(currentnode==start)
	{
		delnode=currentnode;
		currentnode=currentnode->next;
		start=currentnode;
		prevnode=start;
		cout<<"**** The data element "<<delnode->data<<" has been deleted ****"<<endl;
		delete delnode;
		return;
	}
	delnode=currentnode;
	currentnode=currentnode->next;
	prevnode->next=currentnode;
	cout<<"**** The data element "<<delnode->data<<" has been deleted ****"<<endl;
	cout<<endl;
	delete delnode;
	
	
}
int main()
{
	list mylist;
	char ch;
	while(1)
{
	cout<<endl;
	cout<<"***** Select any option from the menu between 1-6 *****"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"***************** Menu ********************"<<endl;
	cout<<"**** 1. Add a node to the list ************"<<endl;
	cout<<"**** 2. Search a node *********************"<<endl;
	cout<<"**** 3. Traverse the list *****************"<<endl;
	cout<<"**** 4. Reverse the list ******************"<<endl;
	cout<<"**** 5. Delete a node from the list *******"<<endl;
	cout<<"**** 6. Exit ******************************"<<endl;
	cout<<endl;
	cin>>ch;
	cout<<endl;
	
	switch(ch)
	{
		case '1':
			{
				mylist.addnode();
			}break;
			
		case '2':
		{
			mylist.search();
		}break;
		
		case '3':
		{
			mylist.traverse();
			}break;
		case '4':
		{
			mylist.reverse();
		}break;	
		
		case '5':
			{
				mylist.delnode();
			}break;
			
		case '6':
		{
			exit(0);
		}break;
			
		default:
		{
			cout<<"invalid option"<<endl;
				}break;		
	}
}
return 0;
}
