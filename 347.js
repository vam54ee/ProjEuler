var util = require('./vam54ee.utils.js');
util.start();
var lim = 1e7;
var finalPrimes = util.generateSieve(lim);

function m(p,q,n)
{
  var x = Math.log(n)/Math.log(p);
  var y = Math.log(n)/Math.log(q);
  var max = 0;
  for(var i = Math.floor(x); i > 0; i--)
  {
    for(var j = 1; j < y && Math.pow(p,i)*Math.pow(q,j) <= n; j++)
    {
      var x = Math.pow(p,i)*Math.pow(q,j);
      if(x > max)
        max = x;
    }
  }
  return max;
}

var ans = 0;
for(var i = 0; i < finalPrimes.length; i++)
{
  for(var j = i+1; finalPrimes[i]*finalPrimes[j] <= lim; j++)
  {
    ans += m(finalPrimes[i],finalPrimes[j],lim);
    if( i%10000 === 0 && j%10000 === 0)
    console.log(i,j,finalPrimes[i],finalPrimes[j]);
  }
}

console.log(ans,util.now());
//console.log(m(2,3,100),m(3,5,100),m(2,73,100));