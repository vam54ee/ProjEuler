var fs = require('fs');
function coor(x,y)
{
  this.x = x;
  this.y = y;
}

function area(a,b,c)
{
  return Math.abs((a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/2);
}

fs.readFile('p102_triangles.txt', function (err, data) {
  if (err) throw err;
  var allData = data.toString().split('\n');
  //console.log(allData);
  var ans = 0;
  for(var i = 0; i < allData.length; i++)
  {
    var coordinates = allData[i].split(',');
    var origin = new coor(0,0);
    var a = new coor(coordinates[0],coordinates[1]);
    var b = new coor(coordinates[2],coordinates[3]);
    var c = new coor(coordinates[4],coordinates[5]);
    var abc = area(a,b,c);
    var oab = area(origin,a,b);
    var obc = area(origin,b,c);
    var oca = area(origin,c,a);
    if(abc === oab+obc+oca)
    {
      //console.log(i,coordinates)
      ans++;
    }
  }
  console.log(ans);
  
});