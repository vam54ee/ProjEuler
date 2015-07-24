var limit = 100000000;

function reverse(n)
{
  var ret = 0;
  while(n)
  {
    ret = ret*10 + n%10;
    n=Math.floor(n/10);
  }
  return ret;
}

function checkOddDigits(n)
{
  while(n)
  {
    if((n%10)%2 === 0)
      return false;
    n=Math.floor(n/10);
  }
  return true;
}

ans = 0;var dt = (new Date()).getTime();
for(var i = 1;i < limit;i++)
{
  //if(i%10000 === 0)
    //console.log(i,ans,((new Date()).getTime() - dt)/60000);
  if(i % 10 === 0)
    continue;
  if(checkOddDigits(i+reverse(i)))
    ans++;
}
console.log(ans);