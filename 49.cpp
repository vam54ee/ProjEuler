#include<iostream>
#include<cmath>
using namespace std;
int b[100001];
int j=3;
int max1=0;

int same(int x,int y,int z)
{int g=x,h=y;
       int *p=new int[10],*q=new int[10],*r=new int[10];
       p[0]=q[0]=r[0]=0;
    for(int i=0;i<4;i++)
    {p[x%10]++;q[y%10]++;r[z%10]++;
    x=x/10;y=y/10;z=z/10;
            }
            if(g==1487&&h==4817)
            for(int i=0;i<10;i++)
             cout<<h<<"\t"<<p[i]<<q[i]<<r[i]<<endl;
            
            for(int i=0;i<10;i++)
            if(p[i]!=q[i]||p[i]!=r[i])
            return 0;
            return 1;
    
    }

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
       
        // cout<<b[2]<<"\t"<<k<<endl;
        }
    
     
  for(int i=168;i<j;i++)
  {
       for(int f=i+1;f<j;f++)
  {if(b[f]-b[i]>3000&&isprime(b[f]+(b[f]-b[i])))
  if(same(b[i],b[f],b[f]+(b[f]-b[i])))
  cout<<b[i]<<"\t"<<b[f]<<"\t"<<(b[f]+(b[f]-b[i]))<<endl;
          
          }   
      
          }   
  
  
    cout<<j<<"\t"<<b[j-1];
system("pause");
    return 0;
    }
