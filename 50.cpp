#include<iostream>
using namespace std;
int b[100001];
int j=3;
int max1=0;

int isprime(int x)
{
    for(int i=0;i<j;i++)
    if(b[i]==x)
    return 1;
    return 0;
}



int main()
{b[0]=2;b[1]=3;b[2]=5;
    for( int k=7;k<1000000;k+=2)
    {int l=0;
         for(int i=0;i<j;i++)
         if(k%b[i]==0)
        {l=1;break;}
        if(!l)
         {b[j]=k;
         j++;
        // cout<<b[2]<<"\t"<<k<<endl;
        }
     }
     
     
     for(int i=0;i<10;i++)
     { int sum=0;
             for(int z=i;z<j&&sum<1000000;z++)
             {sum+=b[z];
                     if(isprime(sum))
                     {
                     //cout<<i<<"\t"<<z<<"\t"<<b[i]<<"\t"<<b[z]<<"\t"<<sum<<endl;
                     if(max1<(z-i)&&sum<1000000)
                     {max1=z-i;cout<<i<<"\t"<<z<<"\t"<<b[i]<<"\t"<<b[z]<<"\t"<<sum<<endl;}
                                     }
                     }
             }
             cout<<j<<"\t"<<b[j-1];
    
system("pause");
    return 0;
    }
