#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool isPerfectSquare(int num) {
  double sq = sqrt(num);
  return sq == (int)sq;
}

vector<int> generateNoOfDivisorsSieve(int num){
  vector<int> arr = vector<int>(num+1,2);
  arr[0] = 0,arr[1] = 1;
  for (int i = 2; i <= (num * num)/2; i++) {
    for (int j = 2; j * i <= num * num; j++) {
      if(isPerfectSquare(i*j)) arr[(int)sqrt(i * j)] ++;
    }
  }
  return arr;
}

void printVector(vector<int> vec){
  for (size_t i = 0; i < vec.size(); i++) {
    cout<<vec[i]<<"\t";
  }
  cout<<endl;
}

int main() {
  int n = 40000;
  vector<int> noOfDivisors = generateNoOfDivisorsSieve(n);
  int max = 0;
  for (size_t i = 2; i < n; i++) {
    if(noOfDivisors[i] > max) {
      max = noOfDivisors[i];
    }
    if(noOfDivisors[i] > 1000){
      cout<<i<<endl;
      break;
    }
  }
  // printVector(noOfDivisors);
  cout<<max<<endl;
  return 0;
}
