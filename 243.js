var utils = require('../utils/vam54ee.utils.js');
var n = 100;
var finalPrimes = utils.generateSieve(n);
// var totient = Array(n).fill(0);
// totient[1] = 1;
// for (var i = 0; i < finalPrimes.length; i++) {
//   for (var j = 1; Math.pow(finalPrimes[i], j) < totient.length; j++) {
//     var pow = Math.pow(finalPrimes[i], j);
//     totient[pow] = pow - pow/finalPrimes[i];
//   }
// }
//
// for (var i = 2; i < totient.length; i++) {
//   for (var j = i+1; i*j < totient.length; j++) {
//     if(utils.gcd(i,j) === 1 && totient[i*j] === 0) totient[i*j] = totient[i]*totient[j];
//   }
// }
// var min = Number.MAX_SAFE_INTEGER;
// for (var i = 2; i < totient.length; i++) {
//   if(totient[i]/(i-1) < min){
//     console.log(totient[i]/(i-1), i);
//     min = totient[i]/(i-1);
//   }
//   if(totient[i]/(i-1) < 15499/94744) {
//     console.log(i);
//     break;
//   }
// }
//
// function totientValue(p){
//
// }
// for (var i = totient.length; i < ; i++) {
//   totient[i]
// }
// // console.log(totient);
var product = 1,primeProduct = 1;
for (var i = 0; i < finalPrimes.length; i++) {
  console.log(product*=(finalPrimes[i]-1),primeProduct*=finalPrimes[i],
    (finalPrimes[i]-1)/finalPrimes[i], product/(primeProduct-1));
  if(utils.gcd( product,primeProduct-1) === 1) {
    if(product/(primeProduct-1) < 15499/94744)
    break;
  }
}
product/=(finalPrimes[i] - 1);
primeProduct /= finalPrimes[i];
console.log(product,primeProduct);
for (var j = 2; (product*j)/(primeProduct*j-1) > 15499/94744; j++) ;
console.log(j,(product*j),(product*j)/(primeProduct*j-1));

// Solution
// phi(n) = (p1-1)/p1 * (p2-1)/p2 ..... for n = p1*p2*...
// we need to find phi(n)/(n-1);
// so we get 2*3*5*7*11*13*17*19*23*29< 15499/94744
// so we try 2*3*5*7*11*13*17*19*23*x such that x is in between 2-29
// and we have phi(n*x) = phi(n) * x;
console.log('answer is primeProduct*j', primeProduct*j)
