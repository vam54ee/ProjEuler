var util = require('./vam54ee.utils.js');

var lim = 1e14;
var finalPrimes = util.generateSieve(1e8);
var ans = 0,x=[];
var harshad = [1,2,3,4,5,6,7,8,9];
var strongRightHarshad = [];

for(var start = 0, end = harshad.length - 1;harshad[end]*10 <= lim ;start = end+1,end = harshad.length-1)
{
  for(var i = start; i <= end ; i++ )
  {
    for(var j = 0; j < 10 ; j++ )
    {
      if(util.isHarshad(harshad[i]*10+j))
        harshad.push(harshad[i]*10+j);
    }
  } 
}

for(var i = 0; i < harshad.length; i++)
{
  var p = harshad[i]/util.sumOfDigits(harshad[i]);
  if(util.isInteger(p) && util.isPrime(p,finalPrimes))
  {
    strongRightHarshad.push(harshad[i]);
  }
}

console.log(strongRightHarshad);
primesH = [];
for(var i = 0; i < strongRightHarshad.length && strongRightHarshad[i] <= lim/10; i++)
{
  for(var j = 1;j < 10; j += 2)
  {
    var num = (strongRightHarshad[i]*10+j);
    if(num < lim && util.isPrime(num,finalPrimes))
    {console.log(i,strongRightHarshad.length,strongRightHarshad[i],num,ans);//console.log(num,strongRightHarshad[i],i,j);
      //primesH.push(num);
      ans+=(num)
    }
  }
}
/*for(var i = 1; i < 1e8; i+=1)
{
   
    if(util.isRightTruncHarshad(i))
    {
      x.push(i);
      continue;
    }
}*/

/*
l=[];ans1 = 0;
for(var i = 3; i < lim; i+=2)
{//console.log(i);
  
  if(util.isPrime(i,finalPrimes))
  {
   var a = Math.floor(i/10);
   var b = a/util.sumOfDigits(a);
    if(util.isInteger(b) && util.isRightTruncHarshad(a) && util.isPrime(b,finalPrimes))
    {l.push(i);
      ans1+=i;
      continue;
    }
  }
}
*/


console.log(ans);
