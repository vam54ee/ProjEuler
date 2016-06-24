var utils = require('../utils/vam54ee.utils.js');

var finalPrimes = utils.generateSieve(1e8);
function nCr(n,r) {
  var numerator = n;
  var denominator = 1;
  for (var i = n - 1; i > n - r ; i--) {
    numerator *= i;
  }
  for (var i = 2; i <= r; i++) {
    denominator *= i;
  }
  return Math.round(numerator/denominator);
}

var uniqueArr = {1: true};
for (var i = 2; i <= 50; i++) {
  for(var j = 1; j <= i/2; j++) {
    var elem = nCr(i,j);
    if(!uniqueArr[elem]) {
      uniqueArr[elem] = true;
    }
  }
}
var uniq = Object.keys(uniqueArr);
var ans = [];
for (var i = 0; i < uniq.length; i++) {
  var isFree = true;
  for(var j = 0; j < Math.sqrt(uniq[i]); j++) {
    if(uniq[i]%(finalPrimes[j]*finalPrimes[j]) === 0){
      isFree = false;
      break;
    }
  }
  if(isFree) {
    ans.push(uniq[i]);
  }
}
var ansSum = 0;
ans.forEach(function(item){ansSum += parseInt(item);})
console.log(ans.length,ansSum);
// console.log(uniqueArr, Object.keys(uniqueArr).length);
