#include"bigint.h"
using namespace std;
int main()
{int ans=0;
for(int i=1;i<10000;i++)
{BigInt b(i);
for(int j=0;j<50;j++)
{b+=b.reverse();
  //cout<<i<<"\t"<<b<<"\t"<<j<<endl;

  if(b.isPalindrome())
  break;
   
}
if(!b.isPalindrome())
{ans++;
  cout<<i<<"\t"<<b<<endl;
}
}
cout<<ans;
return 0;
}
