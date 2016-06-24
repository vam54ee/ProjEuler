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

arr = generateNoOfDivisorsSieve(1e7 + 1)
var ans = 0;
for (var i = 0; i <= 1e7; i++) {
  if (arr[i] === arr[i+1]) ans++;
}
console.log(ans);
