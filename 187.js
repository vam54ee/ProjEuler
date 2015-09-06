var utils = require('./vam54ee.utils.js');

var lim = 1e8;
var finalPrimes = utils.generateSieve(lim);

var ans = 0;

for(var i = 0; i < finalPrimes.length && finalPrimes[i] < Math.floor(lim/finalPrimes[i]); i++)
{
  ans += (utils.binarySearch(Math.floor(lim/finalPrimes[i]),finalPrimes,"left")) - i + 1;
  console.log(ans , (utils.binarySearch(Math.floor(lim/finalPrimes[i]),finalPrimes,"left")));
}

console.log(finalPrimes.length,ans);