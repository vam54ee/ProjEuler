#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<long long> generateSumOfSquaresOfDivisorsSieve(long long num){
  vector<long long> arr = vector<long long>(num+1,1);
  arr[0] = 0;
  for (long long i = 2; i <= (num); i++) {
    for (long long j = 1; j * i <= num; j++) {
      arr[i * j] += (i*i);
    }
  }
  return arr;
}
int main() {
  vector<long long> arr = generateSumOfSquaresOfDivisorsSieve(64000000);
  // for (size_t i = 0; i < arr.size(); i++) {
  //   cout<<arr[i]<<endl;
  // }
  long long ans = 0;
  for (size_t i = 0,x=0; i < arr.size(); i++) {
    double sqrti = sqrt(arr[i] * 1.0);
    if(sqrti == (long long)sqrti * 1.0) {
      if(x < 100) cout<<x++<<"\t"<<i<<"\t"<<arr[i]<<endl;
      ans += i;
    }
  }
  cout<<ans<<endl;
  // for (size_t i = arr.size(); i > arr.size() - 100; i--) {
  //   cout<<arr[i]<<endl;
  // }

  return 0;
}
