function C(n,r)
{
  return fact(n)/(fact(r)*fact(n-r));
}

function fact(n)
{
  if(n<2)
    return 1;
  return n*fact(n-1);
}

var x = C(70,20);
var y = C(60,20);
//var ans = (C(7,2) + C(7,3)*C(30,20) + C(7,4)*C(40,20) + C(7,5)*C(50,20) + C(7,6)*C(60,20) + x)/(7*x);
var ans = 7*(1-(y/x))
console.log(ans);