#include<iostream>
#include<cmath>
using namespace std;

class game
{
	public:
		 
		int gameplay();
};
int game::gameplay()
{

	int i;
	int n;
	int a[n];
	cin>>n; 
		for(i=0;i<=n;i++)
		{
			cin>>a[i];
		}
		
		
	int j;
	int count;
	int score=0;
	for(i=1;i<=n;i++)
	{
		count=0;
		for(j=0;j<(i-1);j++)
		{
			score= pow(2,n+1-i)*a[i]*a[j] + score;
			count++;
		}
		score = score + (pow(2,n)-count*pow(2,n+1-i))*a[i]*a[i-1];
	}
	cout<<endl;
	cout<<score<<endl;
	return 0;
}


int main()
{
	int i,t;
	game rgame;
	cin>>t;
	for(i=0;i<t;i++)
	{
		rgame.gameplay();
	}
	
return 0;
	
}

