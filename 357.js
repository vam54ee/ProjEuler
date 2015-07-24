var util = require('./vam54ee.utils.js');


var lim = 100000000;
var finalPrimes = util.generateSieve(lim);
var ans = 1+2;
for(var i = 4; i <= lim; i+=2)
{
  
  if(Math.sqrt(i) === Math.floor(Math.sqrt(i)))
     continue;
  var check = 1;
  for(var j = 1; j < Math.sqrt(i); j++)
  {
    if(Math.floor(i/j) === (i/j))
    {
      if(util.binarySearch(j+(i/j),finalPrimes) < 0)
      {
        check = 0;
        break;
      }
    }
  }
  if(check)
  {
    ans+=i;
  }
  if(i%1000000 === 0)
  console.log(i,ans);
}
console.log(ans);