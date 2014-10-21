#include<iostream>
#include<fstream>
using namespace std;
int* x;
void pan(int i)
{x=new int[10];
int j=i*2;
i=i*100000;
i+=j;
int c=i;
for(;i>0;i/=10)
{
x[i%10]++;
if(x[i%10]>1)
return;
}
cout<<c<<endl;
}
int main()
{
for(int i=9876;i>9000;i--)
pan(i);
  return 0;
}
