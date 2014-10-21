#include<iostream>
#include<cmath>
using namespace std;
int main()
{
for(int i=1;i<1000;i++)
for(int j=i+1;j<1000;j++)
{
double c=sqrt((i*i+j*j)*1.0);
if((double)(1000-i-j)==c)
cout<<i<<"\t"<<j<<"\t"<<c<<endl;
}
    return 0;
}
