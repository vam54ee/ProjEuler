function generateSumOfSquaresOfDivisorsSieve(num){
  var arr = Array(num + 1).fill(1);
  arr[0] = 0;
  for (var i = 2; i <= (num); i++) {
    for (var j = 1; j * i <= num; j++) {
      arr[i * j] += (i*i);
    }
  }
  return arr;
}

arr = generateSumOfSquaresOfDivisorsSieve(64000000);
var ans = 0;
// for (var i = 0; i < arr.length; i++) {
// }
console.log(arr);
