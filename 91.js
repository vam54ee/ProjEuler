var ans = 0;
var lim = 500;
for(var x1 = 0; x1 <= lim; x1++)
{
  for(var y1 = 0; y1 <= lim; y1++)
  {
    for(var x2 = x1; x2 <= lim; x2++)
    {
      for(var y2 = (x2===x1)?y1+1:0; y2 <= lim; y2++)
      {
        var a = x1*x1+y1*y1,b = x2*x2+y2*y2,c = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        //if(x1*y2 !== y1*x2 && (x1*x2 === y1*y2 || (x2-x1)*x1 === (y2-y1)*y1 || (x1-x2)*x2 === (y1-y2)*y2))
        if(x1*y2 !== y1*x2 && (a+b === c || a+c === b || b+c === a))
        {
          console.log(x1,y1,x2,y2);
          ans++;
        }
        //console.log(x1,y1,x2,y2);
          
      }  

    }  
    
  }  
}
console.log(ans);