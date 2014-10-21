#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int i=2,l=0,k=0;
    double sq=sqrt(i);
    l=sqrt(i);
    sq-=l;
    for(int j=0;j<100;j++)
    {
    l=sq*10;
       k+=l;
       sq*=10;
       sq-=l;
          cout<<l<<"\t"<<k<<"\t"<<j<<"\t"<<sq<<endl;  }
            cout<<k;
    system("pause");
    return 0;
}
