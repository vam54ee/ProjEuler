#include<iostream>
using namespace std;
int main()
{
long long int max=10,maxc;
for (long long int i=1000000;i>=15;i--)
{long long int c=1;
for(long long int j=i;j>1;c++)
{//cout<<j<<"\t"<<i<<endl;
(j%2==0)?(j=j/2):(j=3*j+1);
}
if(c>max)
{max=c;maxc=i;//cout<<maxc<<"\t"<<max<<endl;
}
//cout<<c<<endl;
}
cout<<maxc<<"\t"<<max<<endl;
    return 0;
}
