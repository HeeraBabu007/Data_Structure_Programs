#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int main()
{
	int i,j,t;
	int n;
	int a[n];
	cout<<endl<<"Enter the number of test cases"<<endl;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cout<<endl<<"Enter the number N"<<endl;
		cin>>n;
		cout<<endl<<"Enter the elements"<<endl;
		for(j=0;j<=n;j++)
		{
			cin>>a[n];
		}
		
		int x,y,score=0;
		for(x=1;x<=n;x++)
		{
			for(y=0;y<x;y++)
			{
				score= pow(2,n+1-i)*a[x]*a[y] + score;
			}
		}
	
		cout<<endl<<"The score is :"<<score<<endl;
	}
	return 0;
}
