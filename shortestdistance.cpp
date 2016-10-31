#include<iostream>
#include<cstdlib>
#include<string.h>
#define infinity 99999
using namespace std;
class shortgraph
{
	private:
		char vertices[10][15];
		int cost[10][10];
		int n;
	
	public:
		shortgraph()
		{
			n=0;
			for(int i=0;i<10;i++)
			{
				for(int j=0;j<10;j++)
				{
					if(i==j)
						cost[i][j]=0;
				
					else 
						cost[i][j]=infinity;
				}
			}	
		}
		int edgeexists()
		{
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(cost[i][j]!=0)
				return(1);
			return(0);
		}
		void addvertex()
		{
			
			char name[15];
			cout<<"Enter the vertex name"<<endl;
			cin>>name;
			int i=getindex(name);
			if(i!=-1)
			{
				cout<<endl<<"Vertex already exists."<<endl;
				return;
			}
			else
			{
				strcpy(vertices[n],name);
				cout<<endl<<"Vertex successfully inserted"<<endl;
				n++;
			}
		}
		void addedge()
		{
			char v1[15],v2[15];
			int i1,i2;
			if(n==0)
			{
				cout<<endl<<"No vertex exists you must first create a vertex"<<endl;
				return;
			}
			while(1)
			{
				cout<<endl<<"Enter the source vertex"<<endl;
				cin>>v1;
				i1=getindex(v1);
				if(i1==-1)
				{
					cout<<endl<<"Source vertex does not exist"<<endl;
					return;
				}
				else
				{
					break;
				}
			}
		
			while (1)
			{
				cout<<endl<<"Enter the destination vertex"<<endl;
				cin>>v2;
				i2=getindex(v2);
				if(i2==-1)
				{
					cout<<endl<<"The destination vertex does not exist"<<endl;
						return;
				}
				else
				{
					break;
				}	
			}
			if(strcmp(v1,v2)==0)
			{
				cout<<endl<<"The vertices are same cannot create edge"<<endl;
				return;
			}
			cout<<endl<<"Enter the cost of the edge"<<endl;
			cin>>cost[i1][i2];
			cost[i2][i1]=cost[i1][i2];
			cout<<endl<<"Edge successfully created"<<endl;
		}
	
		void display()
		{
			if(n==0)
			{
			cout<<"Graph does not exist"<<endl;
			return;
			}
			cout<<endl<<"Vertices :"<<endl;
			for(int i=0;i<n;i++)
			cout<<vertices[i]<<endl;
			if(edgeexists())
			{
				cout<<endl<<"Edges: "<<endl;
				for(int j=0;j<n;j++)
					for(int k=0;k<n;k++)
						if(cost[j][k]!=0)
						{
							if(cost[j][k]==infinity)
							cout<<vertices[j]<<"->"<<vertices[k]<<" - "<<"no path"<<endl;
							else
							{
								cout<<vertices[j]<<"->"
								<<vertices[k]<<" - "<<cost[j][k]
								<<endl;
							}
						}	
					
			}
	}
	int getindex(char *vname)
	{
		for(int i=0;i<n;i++)
			if(strcmp(vertices[i],vname)==0)
				return(i);
			return(-1);
	}
	
	void findshortestpath()
	{
		int distance[10];
		int final[10];
		char source[15];
		int src;
		if(n==0)
		{
			cout<<"Graph does not exists"<<endl;
			return;
		}
		while(1)
		{
			cout<<"Enter source vertex"<<endl;
			cin>>source;
			src=getindex(source);
			if(src==-1)
			{
				cout<<"Source vertex does not exists:"<<endl;
				return;
				
			}
			else 
			break;
			
		}
		
			for(int i=0;i<n;i++)
			{
				distance[i]=cost[src][i];
				final[i]=0;
			}
			final[src]=1;
			for(int i=1;i<n;i++)
			{
				int v=0;
				for(int j=0;j<n;j++)
				{
					if(final[j]==0)
					{
						v=j;
						break;
					}
				}
				for(int k=0;k<n;k++)
				{
					if(final[k]==0 && (distance[k]<distance[v]))
					{
						v=k;
					}
				}
				final[v]=1;
				for(int w=0;w<n;w++)
				{
					if(final[w]==0)
					{
						if(distance[v]+cost[v][w]<distance[w])
						{
							distance[w]=distance[v]+cost[v][w];
						}
					}
				}
			}
			cout<<endl<<"The shortest distance of all the vertices from vertex "<<source<<" are: "<<endl;
			for(int j=0;j<n;j++)
			{
				if(distance[j]==infinity)
				{
					cout<<source<<"-> "<<vertices[j]<<" = No path"<<endl;
				}
				else
				{
					cout<<source<<" -> "<<vertices[j]<<" = "<<distance[j]<<endl;
				}
			}
	}	
	};
	
	int main()
	{
		shortgraph g;
		char ch;
		do
		{
			cout<<endl<<"menu"<<endl;
			cout<<"1. Add a vertex"<<endl;
			cout<<"2. Add an edge"<<endl;
			cout<<"3. Display"<<endl;
			cout<<"4. Find the shortest path"<<endl;
			cout<<"5. exit"<<endl;
			cout<<endl<<"Enter your option b/w 1-5"<<endl;
			cin>>ch;
			switch(ch)
			{
				case'1': g.addvertex();break;
				case'2': g.addedge();break;
				case'3': g.display();break;
				case'4': g.findshortestpath();break;
				case'5':break;
				default: cout<<endl<<"Invalid choice"<<endl;
			}
		}while(ch!='5');
		
		return 0; 
	}	
