#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
int j=1003,k=2,carry=0;
int *a,*b,*c;
a=new int[1004];
b=new int[1004];
c=new int[1004];
a[1003]=1;
b[1003]=1;
while(j>0)
{carry=0;
for(int i=1004;i>=j;i--)
{
c[i]=b[i];
int x=b[i]+a[i]+carry;
a[i]=c[i];
b[i]=x%10;
carry=x/10;

}
if(carry>0)
{b[--j]=carry;}
k++;
/* for(int i=j;i<1001;i++)
cout<<b[i];
cout<<endl;
 *//* for(int i=j;i<1001;i++)
cout<<a[i];
cout<<endl;
 */}
/* for(int i=j;i<1001;i++)
cout<<b[i];
cout<<endl;
for(int i=j;i<1001;i++)
cout<<a[i];
 */cout<<endl<<k;
    return 0;
}
