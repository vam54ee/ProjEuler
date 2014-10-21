#include<iostream>
using namespace std;
int calc(int a,int b=-1)
{//cout<<a<<"\t"<<b<<endl;
if(b==1||b==0)
return 1;
int x=0;
if(b==-1)
{
for(int i=a;i>=1;i--)
{x+=calc(i,a-i);
//cout<<x<<"\t"<<a<<"\t"<<b<<endl;
}return x;

}
if(a>=b)
{
for(int i=b;i>=1;i--)
{x+=calc(i,b-i);
//cout<<x<<"\t"<<a<<"\t"<<b<<endl;
}return x;
}
else
{
for(int i=a;i>=1;i--)
{x+=calc(i,b-i);
//cout<<x<<"\t"<<a<<"\t"<<b<<endl;
}return x;
}
}
int main()
{
cout<<calc(100);
return 0;
}
  