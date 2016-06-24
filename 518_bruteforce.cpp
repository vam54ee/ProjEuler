#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<long long> generateIsPrimeArrayAndSieve(long long size, vector<bool>& primes)
{
  primes = vector<bool>(size+1, 0);
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

int main() {
  long long n = 100000000;
  long long ans = 0;
  vector <bool> primes;
  vector<long long> finalPrimes = generateIsPrimeArrayAndSieve(n, primes);
  for(long long i = 0; i < finalPrimes.size(); i++) {
    cout<<i<<endl;
    for (long long j = i + 1; j < finalPrimes.size() && sqrt((finalPrimes[i]+1)*(finalPrimes[j]+1)) - 1 < n; j++) {
      long long a = finalPrimes[i], c = finalPrimes[j];
      double b = sqrt((a+1)*(c+1)*1.0) - 1;
      // cout<<a<<"\t"<<b<<"\t"<<c<<endl;
      if(b != (long long)b) continue;
      if(primes[(long long)b]) {
        // cout<<a<<"\t"<<b<<"\t"<<c<<endl;
        ans += (a+(long long)b+c);
      }
    }
  }
  cout<<ans<<endl;

  return 0;
}
