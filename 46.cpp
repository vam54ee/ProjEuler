#include<iostream>
#include<cmath>
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
    for( int k=7;k<10000;k+=2)
    {int l=0;
         for(int i=0;i<j;i++)
         if(k%b[i]==0)
        {l=1;break;}
        if(!l)
         {b[j]=k;
         j++;}
         else
         {int u=0;
             for(int i=0;i<j;i++)
             {int c=k-b[i];
             c/=2;
             if((int)sqrt(c)==sqrt(c))
             {u=1;break;}
                     }
                     if(u==0)
                    { cout<<k<<endl;system("pause");return 0;}
         
        // cout<<b[2]<<"\t"<<k<<endl;
        }
     }
     
     
    
    
system("pause");
    return 0;
    }
