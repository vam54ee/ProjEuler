#include<vector>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

vector<long long> generateSieve(long long size)
{
  vector<long long> primes = vector<long long>(size+1, 0);
  vector<long long> finalPrimes;
  primes[2] = 1;
  primes[3] = 1;
  primes[5] = 1;
  primes[7] = 1;
  for(long long i = 8; i < size; i++)
  {
    if(i%2 == 1)
      primes[i] = 1;
    else
      primes[i] = 0;
  }

  for(long long i = 3; i < size/2; i+=2)
  {
    for(long long j= 3; i*j < size; j+=2)
    {
      primes[i*j] = 0;
    }
  }
  cout<<"done"<<endl;
  for (long long i = 0; i < size+1;i++)
  {
    if(primes[i] == 1)
      finalPrimes.push_back(i);
  }
  cout<<"done with final primes with length"<<finalPrimes.size()<<endl;
  return finalPrimes;
}

long long nCr(int n, int r) {
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}


int main()
{
  vector<long long> finalPrimes = generateSieve(100000000);
  vector<long long> uniqueArr;
  uniqueArr.push_back(1);

  for (long long i = 2; i <= 50; i++) {
    for(long long j = 1; j <= i/2; j++) {
      long long elem = nCr(i,j);
      bool found = false;
      for (size_t i = 0; i < uniqueArr.size(); i++) {
        if(uniqueArr[i] == elem) {
          found = true;
          break;
        }
      }
      if(!found) {
        uniqueArr.push_back(elem);
      }
      // cout<<elem<<endl;
    }
  }

  vector<long long> ans;

  for (long long i = 0; i < uniqueArr.size(); i++) {
    long long isFree = true;
    for(long long j = 0; j < sqrt(uniqueArr[i]); j++) {
      if(uniqueArr[i]%(finalPrimes[j]*finalPrimes[j]) == 0){
        isFree = false;
        break;
      }
    }
    if(isFree) {
      ans.push_back(uniqueArr[i]);
    }
  }
  cout<<ans.size()<<endl;
  long long ansSum = 0;
  for (size_t i = 0; i < ans.size(); i++) {
    cout<<ans[i]<<endl;
    ansSum += ans[i];
  }
  for (size_t i = 0; i < uniqueArr.size(); i++) {
    cout<<uniqueArr[i]<<endl;
  }
  cout<<ansSum<<endl;
  // ans.forEach(function(item){ansSum += parseInt(item);})
  // console.log(ans,ansSum);

  // long long uniq = Object.keys(uniqueArr);
  // long long ans = [];
  // for (long long i = 0; i < uniq.length; i++) {
  //   long long isFree = true;
  //   for(long long j = 0; j < Math.sqrt(uniq[i]); j++) {
  //     if(uniq[i]%(finalPrimes[j]*finalPrimes[j]) == 0){
  //       isFree = false;
  //       break;
  //     }
  //   }
  //   if(isFree) {
  //     ans.push(uniq[i]);
  //   }
  // }
  // long long ansSum = 0;
  // ans.forEach(function(item){ansSum += parseInt(item);})
  // console.log(ans,ansSum);
  // // console.log(uniqueArr, Object.keys(uniqueArr).length);

	return 0;
}
