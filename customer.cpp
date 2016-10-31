#include<iostream>
using namespace std;
class Customer
{
	private:
		int billing_amount[5][2];
		public:
			void accept_details()
			{
				for(int i=0; i<5;i=i+1)
				{
					cout<<"enter mobile no";
					cin>>billing_amount[i][0];
					cout<<"enter billing amount ";
					cin>>billing_amount[i][1];
				}
			}
			void display_details()
			{
				for(int i=0; i<5;i=i+1)
				{
					cout<<"Mobile no"<<billing_amount[i][0];
					cout<<"\t Billing amount "<<billing_amount[i][1]<<endl;
			    }
			}
};
int main()
{
	Customer customerObj;
	customerObj.accept_details();
	customerObj.display_details();
}
