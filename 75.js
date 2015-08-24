var utils = require('./vam54ee.utils.js');

var ans = 0;
for(var n = 12; n < 1500000 ; n+=2)
{
  var count = 0;
  var y = Math.ceil(n/(2+Math.sqrt(2)));
  do
  {
    var z = (2*y*y-2*n*y+n*n)/(2*n-2*y);
    var x = 0;
    if(utils.isInteger(z))
    {
      x = Math.sqrt(z*z - y*y);
      if(x < y && y < z && x+y+z === n)
      {
        count++;
        if(n% 100000 === 0)
        console.log(x,y,z,n);
      }
    }
    y++;
    //console.log(y);
  }while(y + z < n);
  if(count === 1)
    ans++;
}
console.log(ans);