#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;
class adjvertex
{
	public:
		char vertexname[15];
		int cost;
		adjvertex *nextadjvertex;
};
class vertex
{
	public:
		char vertexname[15];
		vertex *nextvertex;
		adjvertex *nextadjvertex;

};

class linkgraph
{
	public:
		vertex *start;
		linkgraph()
		{
			start=NULL;
		}
		void addvertex();
		void addedge();
		void display();
		void shortdistance();		
};
void linkgraph::addvertex()
{
	vertex *newvertex = new vertex;
	vertex *current = new vertex;
	current=start;
	char vname[15];
	cout<<endl<<"Enter the name of the new vertex : "<<endl;
	cin>>vname;
	if(start==NULL)
	{
		strcpy(newvertex->vertexname,vname);
		newvertex->nextvertex=start;
		start=newvertex;
		start->nextadjvertex=NULL;
		cout<<endl<<"Vertex inserted successfully"<<endl;
		return;
	}
	else
	{
		while(current->nextvertex!=NULL)
		{
			if(strcmp(vname,current->vertexname)!=0)
				current=current->nextvertex;
			else
			{
				cout<<endl<<"Duplicte values not allowed"<<endl;
				return;
			}
				
		}
		if(current->nextvertex==NULL && strcmp(vname,current->vertexname)==0)
		{
			cout<<endl<<"Duplicte values not allowed"<<endl;
				return;
		}
		else
		{
			strcpy(newvertex->vertexname,vname);
			current->nextvertex=newvertex;
			newvertex->nextvertex=NULL;
			newvertex->nextadjvertex=NULL;
			cout<<endl<<"Vertex inserted successfully"<<endl;
		}
	}
}
void linkgraph::addedge()
{
	if(start==NULL)
	{
		cout<<"No vertices exist"<<endl;
		return;
	}
	adjvertex *newadjvertex= new adjvertex;
	adjvertex *current;
	vertex *current1;
	vertex *current2;
	current1=start;
	current2=start;
	int weight;
	char name1[15],name2[15];
	cout<<"Enter the source vertex name"<<endl;
	cin>>name1;
	while(strcmp(name1,current1->vertexname)!=0 && current1->nextvertex!=NULL)
	{
		current1=current1->nextvertex;
	}
	if(current1->nextvertex==NULL && (strcmp(name1,current1->vertexname)!=0) )
	{
		cout<<endl<<"Source vertex not found"<<endl;
		return;
	}
	cout<<"Enter the destination vertex"<<endl;
	cin>>name2;
	while(strcmp(name2,current2->vertexname)!=0 && current2->nextvertex!=NULL)
	{
		current2=current2->nextvertex;
	}
	if(current2->nextvertex==NULL && (strcmp(name2,current2->vertexname)!=0))
	{
		cout<<endl<<"Destination vertex not found"<<endl;
		return;
	}
	cout<<endl<<"Enter the weight to the edge: "<<endl;
	cin>>weight;
	if(current1->nextadjvertex==NULL)
	{
		current1->nextadjvertex=newadjvertex;
		strcpy(newadjvertex->vertexname,current2->vertexname);
		newadjvertex->cost=weight;
		newadjvertex->nextadjvertex=NULL;
		cout<<endl<<"Edge created successfully"<<endl;
		return;
	}
	else
	{
		current=current1->nextadjvertex;
		while(current->nextadjvertex!=NULL)
		{
			if(strcmp(name2,current1->vertexname)!=0)
			{
				current=current->nextadjvertex;
			}
			else
			{
				cout<<"Edge already exists"<<endl;
				return;
			}
		}
		current->nextadjvertex=newadjvertex;
		strcpy(newadjvertex->vertexname,current2->vertexname);
		newadjvertex->cost=weight;
		newadjvertex->nextadjvertex=NULL;
		cout<<endl<<"Edge created successfully"<<endl;
	}
	
}
void linkgraph::display()
{
	vertex *current;
	adjvertex *adjcurrent;
	current=start;
	if(start==NULL)
	{
		cout<<"No vertices exist"<<endl;
	}
	else
	{
	
		cout<<"The vertices are:"<<endl;
		while(current!=NULL)
		{
			cout<<endl<<current->vertexname<<endl;
			cout<<"The edges to the vertex "<<current->vertexname<<" are:"<<endl;
			adjcurrent=current->nextadjvertex;
			if(adjcurrent==NULL)
			{
				cout<<endl<<"No edges exists"<<endl;
			}
			else if(adjcurrent!=NULL)
			{
				while(adjcurrent!=NULL)
				{
					cout<<endl<<current->vertexname<<" -> "<<adjcurrent->vertexname<<" = "<<adjcurrent->cost<<endl;
					adjcurrent=adjcurrent->nextadjvertex;
				}
			}
			
			current=current->nextvertex;
		}
	}
}
/*
void linkgraph::shortdistance()
{
	if(start==NULL)
	{
		return;
	}
	vertex *source;
	vertex *begin=new vertex;
	begin=start;
	source=start->nextvertex;
	while(source!=NULL)
	{
		vertex *newvertex=new vertex;
		strcpy(newvertex->vertexname,source->vertexname);
		if(source==start->nextvertex)
		{
			begin->nextvertex=newvertex;
		}
		
		newvertex->nextvertex=NULL;
		newvertex->nextadjvertex=NULL;
		source=source->nextvertex;
	}
	source=start;
	adjvertex *current;
	int weight;
	while(source!=NULL)
	{
		while(source->nextadjvertex!=NULL)
		{
			source->nextvertex=NULL;
		}
		
	}
	
	
*/	

int main()
{
	linkgraph mygraph;
	char ch;
	do
		{
			cout<<endl<<"menu"<<endl;
			cout<<"1. Add a vertex"<<endl;
			cout<<"2. Add an edge"<<endl;
			cout<<"3. Display"<<endl;
			cout<<"4. exit"<<endl;
			cout<<endl<<"Enter your option b/w 1-4"<<endl;
			cin>>ch;
			switch(ch)
			{
				case'1': mygraph.addvertex();break;
				case'2': mygraph.addedge();break;
				case'3': mygraph.display();break;
				case'4':break;
				default: cout<<endl<<"Invalid choice"<<endl;
			}
		}while(ch!='4');
		return 0;
}
