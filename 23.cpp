#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int sum_of_divisors(int n)
{int i=1,sum=0;
while(i<n)
{if(n%i==0)
sum=sum+i;
i++;
}
return sum;
}
int create_abundant(int *arr,int upperlimit)
{int j=0;
for(int i=12;i<upperlimit;i++)
{int x=sum_of_divisors(i);
//cout<<i<<"\t"<<x<<endl;
if(x>i)
{arr[j]=i;j++;}
}
return j;

}

int main()
{
int upl=28124;
long long int sum=0;
int *a,*b;
a=new int[upl];
b=new int [upl];
int size=create_abundant(a,upl);
   for(int i=0;i<size;i++)
  for(int j=0;j<size&&a[i]+a[j]<upl;j++)
  b[a[i]+a[j]]=1;
  
  /* for(int i=0;i<size;i++)
  cout<<a[i]<<"\t";
   cout<<endl;
   */
   for(int i=0;i<upl;i++)
   if(b[i]==0)
   sum=sum+i;
  
  cout<<sum;
 	return 0;
}
