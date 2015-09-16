//n^3+n^2*p = z^3
//n^3(1+p/n)=z^3
//n*cuberoot((p+n)/n)=z
//for z to be integer p+n and n should be perfect cubes.
//p+x^3=y^3
//p=y^3-x^3


var utils = require('./utils/vam54ee.utils.js');
var finalPrimes = utils.generateSieve(1e6);
//console.log(finalPrimes.length);
var ans = 0;
for(var i = 2; i*i*i - (i-1)*(i-1)*(i-1) < 1e6;i++)
{
  for(var j = i-1 ; j > 0; j--)
  {
    if(utils.isPrime(i*i*i-j*j*j,finalPrimes))
      ans++;
  }
  console.log(i*i*i,(i-1)*(i-1)*(i-1))
}
console.log(ans);