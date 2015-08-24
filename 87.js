var util = require('./vam54ee.utils.js');

var prlim = 1e4;
var ans = [];
var lim = 5e7;
var finalPrimes = util.generateSieve(prlim);

for(var i = 0; i < finalPrimes.length; i++)
{
  for(var j = 0; j < finalPrimes.length; j++)
  {
    for(var k = 0; k < finalPrimes.length;k++)
    {
      var a = finalPrimes[i], b = finalPrimes[j], c = finalPrimes[k];
      //if(b < 5 && c < 5)
      //console.log(a,b,c,a*a + b*b*b + c*c*c*c)
      var x = a*a + b*b*b + c*c*c*c;
      if(x < lim)
      {
        //if(b < 5 && c < 5)
        //if(ans.length % 10000 ===0)
        //if(c === 84)
        //console.log(a,b,c,x,ans.length);
        //if(util.binarySearch(x,ans) < 0)
          ans.push(x);
      }
      else 
        break;
    }
    if(a*a + b*b*b >= lim)
    {
      console.log(a,b,c,x,5e7);
      break;
    }
  }
  if(a*a >= lim)
    break;
  
}


function compare(aa, bb) {
  if (aa < bb) {
    return -1;
  }
  if (aa > bb) {
    return 1;
  }
  // a must be equal to b
  return 0;
}

ans.sort(compare);
uniqueArray = ans.filter(function(item, pos, self) {
    return util.binarySearch(item,self) === pos;
});
console.log(uniqueArray.length);