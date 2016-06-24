function generateNoOfDivisorsSieve(num){
  var arr = Array(num + 1).fill(2);
  arr[0] = 0,arr[1] = 1;
  for (var i = 2; i <= (num)/2; i++) {
    for (var j = 2; j * i <= num; j++) {
      arr[i * j] ++;
    }
  }
  return arr;
}
function findMax(arr,i,j) {
  var maxIndex = 0;
  var max = -1;
  for (var k = i; k <= j; k++) {
    if(max < arr[k]){
      max = arr[k];
      maxIndex = k;
    }
  }
  return maxIndex;
}

arr = generateNoOfDivisorsSieve(1e8 + 1);
var u = 100000000;
var k = 100000;
var maxIndex = findMax(arr, 1, k);
var maxSum = arr[maxIndex];
for (var n = 2; n <= u - k + 1; n++) {
  if(arr[maxIndex] === arr[n-1]) {
    var maxIndex = findMax(arr, n, n + k - 1);
  }
  else {
    if(arr[maxIndex] < arr[n+k-1]) {
      maxIndex = n+k-1;
    }
  }
  maxSum += arr[maxIndex];
}

console.log(maxSum);
