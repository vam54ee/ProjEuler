#include"bigint.h"
using namespace std;
int fact(int x)
{if(x==0||x==1) return 1;
return x*fact(x-1);
}
int main()
{int a[37],b[37];
    for(int i=0;i<37;i++)
    {a[i]=0;b[i]=0;}
    
    for(int i=9;i>=0;i--)
    {
    for(int j=9-i;j>=0;j--)
    {
    for(int k=9-i-j;k>=0;k--)
    {int l=9-i-j-k,m=i+2*j+3*k+4*l;
    if(m>8&&m<37)
    a[m]+=fact(9)/(fact(i)*fact(j)*fact(k)*fact(l));
    }
    }
    }
    
    
    
    
    
    for(int i=6;i>=0;i--)
    {
    for(int j=6-i;j>=0;j--)
    {
    for(int k=6-i-j;k>=0;k--)
    {
    for(int l=6-i-j-k;l>=0;l--)
    {
    for(int m=6-i-j-k-l;m>=0;m--)
    {        
    int n=6-i-j-k-l-m,o=i+2*j+3*k+4*l+5*m+6*n;
    if(o>5&&o<37)
    b[o]+=fact(6)/(fact(i)*fact(j)*fact(k)*fact(l)*fact(m)*fact(n));
    }
}
}
    }
    }
    
    BigInt num;
    
    for(int i=9;i<37;i++)
    {
    for(int j=i-1;j>5;j--)
    {num+=(BigInt(a[i])*BigInt(b[j]));
    }
    }
    cout<<num;
    //divide by 4^9*6^6 to get answer
    system("pause");
    return 0;
}
