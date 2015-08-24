#include<iostream>
using namespace std;
int main()
{int ans=0,lmax=0;
    for(int i=3;i<=1000;i++)
    {
    
    int x=2*i,i2=i*i,lx=x%(i2);
    lmax=lx;
    for(int j=2;(j*x)%i2!=0||j==2;j++)
    {if(lmax<(j*x)%i2)
    lmax=(j*x)%i2;
    //cout<<((j*x)%i2)<<endl;
    }
    ans+=lmax;
    cout<<lmax<<"\t"<<i<<endl;
    }
    cout<<ans;
    system("pause");
    return 0;
}
