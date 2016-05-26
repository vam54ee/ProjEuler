var utils = require('../utils/vam54ee.utils.js');

for(var n = 20; ; n++)
{
  var finalPrimes = utils.generateSieve(n);
  var noOfWays = Array(n+1).fill(0);
  noOfWays[0] = 1;
  // console.log(finalPrimes);
  for(var i = 0; i < finalPrimes.length; i++)
  {

    for(var j = finalPrimes[i] ; j <= n; j++){
      noOfWays[j] += noOfWays[j - finalPrimes[i]];
      // console.log(noOfWays[j],j,i);
    }
  }
  console.log(noOfWays[n], n);
  // console.log('inside',noOfWays[n], n);
  // console.log(finalPrimes,noOfWays[n], n);
  if(noOfWays[n] > 5000) break;
}
// console.log(noOfWays[n], n);
