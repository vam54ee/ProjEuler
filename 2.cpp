#include<iostream>
using namespace std;
int main()
{
int j=0;
int a=1,c=2;
while(c<4000000)
{
if(c%2==0)
j=j+c;
int temp=a;
a=c;
c=c+temp;

}
cout<<j;
    return 0;
}
