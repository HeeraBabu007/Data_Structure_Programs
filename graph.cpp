#include<iostream>
#include<string.h>
using namespace std;
class graph
{
	private:
		char vertices[10][15];
		int cost[10][10];
		int n;
	
	public:
		graph()
		{
			n=0;
			for(int i=0;i<10;i++)
			{
				for(int j=0;j<10;j++)
				{
					cost[i][j]=0;
				}
			}
		}
	int edgeexists()
	{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				if(cost[i][j]!=0)
				return (1);
				else
				return (0);
			}
		}
	}
	int getindex(char *vname)
	{
		for(int i=0;i<n;i++)
		{
			if(strcmp(vertices[i],vname)==0)
			{
				return (i);
			}
			else
			{
				return (-1);
			}
		}
	}
	void addvertex()
	{
		char vname[15];
		cout<<endl<<"Enter the name of vertex :"<<endl;
		cin>>vname;
		int i=getindex(vname);
		if(i==-1)
		{
			cout<<endl<<"Vertex already exists"<<endl;
			return;
		}
		strcpy(vertices[n],vname);
		n++;
	
	}
	void addedge()
	{
		char v1[15],v2[15];
		int i1,i2;
		if(n==0)
		{
			cout<<endl<<"NO vertex exists.First add a vertex"<<endl;
			return;
		}
		while(1)
		{
			cout<<endl<<"Enter the source vertex"<<endl;
			cin>>v1;
			i1=getindex(v1);
			if(i1==-1)
			{
				cout<<endl<<"Source vertex does not exist.Try again"<<endl;
			}
			else
			{
				break;
			}
		}
		while(1)
		{
		  cout<<endl<<"Enter the destination vertex"<<endl;
		  cin>>v2;
		  i2=getindex(v2);
		  if(i2==-1)
		  {
		  	cout<<endl<<"Destination vertex does not exist.Try again"<<endl;
		  }
			else
			{
				break;
			}
		}
		cout<<endl<<"Enter the cost of the edge"<<endl;
		cin>>cost[i1][i2];
	}
	void display()
	{
		if(n==0)
		{
			cout<<endl<<"Graph does not exist"<<endl;
			return;
		}
		cout<<endl<<"Vertices:"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<vertices[i]<<endl;
			if(edgeexists())
			{
				cout<<endl<<"Edges:"<<endl;
				for(int j=0;j<n;j++)
				{
					for(int k=0;k<n;k++)
					{
						if(cost[j][k]!=0)
						{
							cout<<vertices[j]<<"->"<<vertices[k]<<" - "<<cost[j][k]<<endl;
						}
					}
				}
			}
		}
	}
};
int main()
{
	graph mygraph;
	char ch;
	do
	{
		cout<<endl<<"Menu"<<endl;
		cout<<"1. Add a vertex"<<endl;
		cout<<"2. Add an edge"<<endl;
		cout<<"3. Display"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<endl<<"Enter your choice : "<<endl;
		cin>>ch;
		switch(ch)
		{
			case '1': mygraph.addvertex();break;
			case '2': mygraph.addedge();break;
			case '3': mygraph.display();break;
			case '4': break;
		}
	} while(ch!='4');
	
	return 0;
}
