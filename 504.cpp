#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool isPerfectSquare(int num) {
  double sq = sqrt(num);
  return sq == (int)sq;
}
int main() {
  int m = 100;
  long long ans = 0;
  for (int a = 1; a <= m; a++) {
    for (int b = 1; b <= m; b++) {
      for (int c = 1; c <= m; c++) {
        for (int d = 1; d <= m; d++) {
          int noOfLatticePoints = a + b + c + d - 3;
          for (int i = 1; i <= a; i++) {
            double x = b - (b*1.0/a)*i;
            double y = d - (d*1.0/a)*i;
            if(x > 0) noOfLatticePoints += (x == (int)x) ? x - 1 : floor(x);
            if(y > 0) noOfLatticePoints += (y == (int)y) ? y - 1 : floor(y);
          }
          for (int i = 1; i <= c; i++) {
            double x = b - (b*1.0/c)*i;
            double y = d - (d*1.0/c)*i;
            if(x > 0) noOfLatticePoints += (x == (int)x) ? x - 1 : floor(x);
            if(y > 0) noOfLatticePoints += (y == (int)y) ? y - 1 : floor(y);
          }
          if(a%10 == 1) cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<noOfLatticePoints<<endl;
          if(isPerfectSquare(noOfLatticePoints)) ans++;
        }
      }
    }
  }

  cout<<ans<<endl;

  return 0;
}
