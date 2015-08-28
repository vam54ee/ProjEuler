// I am proud of myself for this thought.

var utils = require('./utils/vam54ee.utils.js');

var  msi = Number.MAX_SAFE_INTEGER;
var nod = utils.noOfDigits(msi);
var arr = [];
console.log(msi,nod);
for(var i = 2,k = 0; i <= nod*9; i++)
{
  for(var j = 1; Math.pow(i,j) < msi ; j++)
  {
    console.log(i,j,++k,Math.pow(i,j));
    arr.push(Math.pow(i,j));
  }
  
}
utils.sort(arr);
console.log(arr,arr.length);
filteredArray = arr.filter(function(item, pos, self) {
    return utils.binarySearch(item,self) === pos;
});
console.log(filteredArray,filteredArray.length);
var ans = [];
for(var i = 0;i < filteredArray.length; i++)
{
  var x = Math.log(filteredArray[i])/Math.log(utils.sumOfDigits(filteredArray[i]));
  var y = Math.round(x);
  if(Math.abs(x - y) < 0.000000000001 && filteredArray[i]>10)
  {
    ans.push(filteredArray[i]);
    console.log(x,y,x-y);
  }
}
console.log(ans,ans.length,ans[29]);