#include"bigint.h"
using namespace std;
int main()
{int size=10000;
  BigInt* barr=new BigInt[size];
BigInt* carr=new BigInt[size];
int** checkarr=new int*[size];
for(int i=0;i<size;i++)
checkarr[i]=new int[10];
for(int i=0;i<size;i++)
for(int j=0;j<10;j++)
checkarr[i][j]=0;
for(int i=2;i<size;i++)
{//cout<<i<<endl;
  BigInt c(i);
  barr[i]=c.power(3);
  c='0';
  for(int j=0;j<barr[i].noOfDigits();j++)
  {//cout<<j<<endl;
    checkarr[i][barr[i][j]-'0']++;
  }
  
  }
for(int i=2;i<size;i++)
{int t=0;
  for(int j=i+1;j<size;j++)
  {int chk=0;
    for(int k=0;k<10;k++)
    {//if(i==5704)
    //cout<<k<<" "<<checkarr[i][k]<<"\t"<<checkarr[j][k]<<endl;
      if(checkarr[i][k]!=checkarr[j][k])
    {chk=1;break;}
    }
    //if(j==384||j==406)
    //cout<<endl;
    if(chk==0)
    {
      //cout<<barr[i]<<"\t"<<barr[j]<<endl;
      t++;}
  }
  if(t==4)
  cout<<barr[i]<<endl;
}

return 0;
}
