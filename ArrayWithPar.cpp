#include<iostream>
using namespace std;
class ArrayWithPar
{
	public:
		void printarray(int arg[], int length)
		{
			for(int n=0; n<length; n++)
			{
				cout<<arg[n]<<" "<<endl;
			}
		}
};
int main()
{
	ArrayWithPar obj;
	int farray[]={5,10,15};
	int sarray[]={3,5,6,8,9};
	obj.printarray(farray,3);
	obj.printarray(sarray,5);
	return 0;

}
