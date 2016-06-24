#include<iostream>
#include <vector>

using namespace std;
int main() {
  int n = 1;
  vector<int> p(1000000, 0);
  p[0] = p[1] = 1;
  do {
    n += 1;
    int i = 0;
    int m1,m2;
    do {
      i += 1;
      m1 = n - i * (3 * i - 1) / 2;
      m2 = n - i * (3 * i + 1) / 2;
      cout<<m1<<"\t"<<m2<<"\t"<<endl;
      int s = 1;
      if(i%2) s = -1;
      if(m1>=0)p[n] += s * p[m1];
      if(m2 >= 0) p[n] += s * p[m2];
      cout<<m1<<"\t"<<m2<<"\t"<<endl;
    } while(!(m1 < 0 && m2 < 0));

    cout<<"n:"<<n<<"\t"<<"p[n]:"<<p[n]<<endl;
    p[n] = p[n] % 1000000;
  } while(p[n] != 0);
  cout<<(n)<<endl;
  return 0;
}
