var utils = require('./vam54ee.utils.js');

var finalPrimes = utils.generateSieve(1e6);
finalPrimes.unshift(0);

for(var i = 1; i < finalPrimes.length; i+=2)
{
 
  if((2*(i)*finalPrimes[i]) > 1e10)
  {
    console.log(i,finalPrimes[i]);
    break;
  }
  
}
console.log(finalPrimes[1]);