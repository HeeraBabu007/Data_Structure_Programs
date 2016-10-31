#include<iostream>
using namespace std;
enum Days{saturday=1, sunday, monday, tuesday,wednesday, thursday,friday};
int main()
{
	enum Days today=saturday;
	switch(today)
	{
		case 1:
			cout<<"It's sunday"<<endl;
			break;
		default:
			cout<<"It's not sunday"<<endl;
			break;
	}
	cout<<"today value is "<<today<<endl;

}
