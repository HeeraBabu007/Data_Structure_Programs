#include<iostream>
using namespace std;
class sum
{
private: int a,b,c;
public:
void add()
{
cout<<"Enter any two numbers: ";
cin>>a>>b;
c=a+b;
cout<<"Sum: "<<c;
}
};

int main()
{
sum s;
s.add();
return 0;
}
