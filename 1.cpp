#include<iostream>
using namespace std;
int main()
{
int j=0;
for(int i=3;i<1000;i++)
{
if(i%3==0||i%5==0)
j=j+i;
}
cout<<j;
    return 0;
}
