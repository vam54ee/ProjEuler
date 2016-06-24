#include<iostream>
#include <vector>

using namespace std;
int main() {
  int n = 100000;
    vector<int> noOfWays(n+1, 0);
    noOfWays[0] = 1;
    for(int i = 1; i <= n; i++)
    {

      for(int j = i ; j <= n; j++){
        noOfWays[j] += noOfWays[j - i];
        noOfWays[j] %= 1000000;
        // console.log(noOfWays[j],j,i);
      }

    }
    // console.log('inside',noOfWays[n], n);
    // console.log(finalPrimes,noOfWays[n], n);
    for(int i = 0; i <= n; i++){
      cout<<(noOfWays[i])<<"\t"<<i<<endl;
      if(noOfWays[i]%1000000 == 0)break;
    }
  return 0;
}
