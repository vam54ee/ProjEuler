var utils = require('./utils/vam54ee.utils.js');
var fs = require('fs');

var lim = 1e9;
var ans =[];
for(var i = 1; Math.pow(2,i) < lim; i++)
{
  
  for(var j = 0; Math.pow(2,i)*Math.pow(3,j) < lim ; j++)
  {
    for(var k = 0; Math.pow(2,i)*Math.pow(3,j)*Math.pow(5,k) < lim && (j === 0 ? k < 1:true); k++)
    {
      for(var l = 0; Math.pow(2,i)*Math.pow(3,j)*Math.pow(5,k)*Math.pow(7,l) < lim  && (k === 0 ? l < 1:true); l++)
      {
        for(var m = 0; Math.pow(2,i)*Math.pow(3,j)*Math.pow(5,k)*Math.pow(7,l)*Math.pow(11,m) < lim  && (l === 0 ? m < 1:true); m++)
        {
          for(var n = 0; Math.pow(2,i)*Math.pow(3,j)*Math.pow(5,k)*Math.pow(7,l)*Math.pow(11,m)*Math.pow(13,n) < lim  && (m === 0 ? n < 1:true); n++)
          {
            for(var o = 0; Math.pow(2,i)*Math.pow(3,j)*Math.pow(5,k)*Math.pow(7,l)*Math.pow(11,m)*Math.pow(13,n)*Math.pow(17,o) < lim  && (n === 0 ? o < 1:true); o++)
            {
              for(var p = 0; Math.pow(2,i)*Math.pow(3,j)*Math.pow(5,k)*Math.pow(7,l)*Math.pow(11,m)*Math.pow(13,n)*Math.pow(17,o)*Math.pow(19,p) < lim  && (o === 0 ? p < 1:true); p++)
              {
                for(var q = 0; Math.pow(2,i)*Math.pow(3,j)*Math.pow(5,k)*Math.pow(7,l)*Math.pow(11,m)*Math.pow(13,n)*Math.pow(17,o)*Math.pow(19,p)*Math.pow(23,q) < lim  && (p === 0 ? q < 1:true); q++)
                {
                  var tmp  = Math.pow(2,i)*Math.pow(3,j)*Math.pow(5,k)*Math.pow(7,l)*Math.pow(11,m)*Math.pow(13,n)*Math.pow(17,o)*Math.pow(19,p)*Math.pow(23,q);
                  ans.push(tmp);
                  console.log(i,j,k,l,m,n,o,p,q,tmp);
                }
              }
            }
          }
        }
      }

    }

  }
}
utils.sort(ans);
console.log(ans.length);
fs.writeFile('admissible.txt', ans.join('\r\n'),function (err, data) {
  if (err) throw err;
  console.log('done');
});
