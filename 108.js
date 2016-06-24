/*
1/x + 1/y = 1/n the value of n for which we can no of solutions of (x,y) is greater than 1000.
n = (xy)/(x+y)
let x = n + a y = n + b
n(2n+a+b) = n^2 + (a+b)n + ab
n^2=ab
no of divisors of n^2 is no of distinct solution of (x,y) but x<y so a<b
so noOfDivisors(n^2) > 2000
so for nSquared = 2^4 * 3^4 * 5^4 * 7 * 11 * 13 * 17 noOf divisors exceeds 1000
so for n = ceil(sqrt(nSquared)) so n starts from 117405S
*/

var utils = require('../utils/vam54ee.utils.js');
var finalPrimes = utils.generateSieve(1e6);
console.log(finalPrimes[0]);
function noOfDivisors(num) {
  var exponentArray = {};
  var num1 = num;
  for (var i = 1; i < finalPrimes.length && finalPrimes[i] <= Math.sqrt(num); i++) {
    if(num1 % finalPrimes[i] === 0) {
      if(exponentArray[finalPrimes[i]] === undefined) exponentArray[finalPrimes[i]] = 0;
      for (; num1 % finalPrimes[i] === 0; num1 /= finalPrimes[i]) {
        exponentArray[finalPrimes[i]]++;
      }
    }
  }
  var numberOfDivisors = 1;
  for (key in exponentArray) {
    numberOfDivisors *= (exponentArray[key] + 1);
  }
  // console.log(num,exponentArray);
  return numberOfDivisors;
}
for (var i = 117405; i < 1e6 ; i++) {
  var nod = noOfDivisors(i*i);
  // console.log(i, nod);
  if(nod > 2000) {
    console.log(i);
    break;
  }
}
