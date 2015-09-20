var utils = require('./utils/vam54ee.utils.js');
//var finalPrimes = utils.generateSieve(500);
var arr = [0,1,2,3,4,5,6,7,8,9];
var finalArray =[];

function firstcb(arr1)
{
  utils.combination(arr,6,secondcb);
  function secondcb(arr2)
  {
    var c1 = check(0,1,arr1,arr2) && check(0,4,arr1,arr2)&&( check(0,9,arr1,arr2) || check(0,6,arr1,arr2));
    if(!c1)
      return;
    c1 = check(1,6,arr1,arr2) || check(1,9,arr1,arr2);
    if(!c1)
      return;
    c1 = check(2,5,arr1,arr2);
    if(!c1)
      return;
    c1 = check(3,6,arr1,arr2) || check(3,9,arr1,arr2);
    if(!c1)
      return;
    c1 = check(4,6,arr1,arr2) || check(4,9,arr1,arr2);
    if(!c1)
      return;
    c1 = check(6,4,arr1,arr2) || check(9,4,arr1,arr2);
    if(!c1)
      return;
    c1 = check(8,1,arr1,arr2) ;
    if(!c1)
      return;
    var sum = 0;
    for(var i = 0; i< arr1.length;i++)
      sum+=arr1[i];
    for(var i = 0; i< arr2.length;i++)
      sum+=arr2[i];
    finalArray.push({arr1:arr1,arr2:arr2,sum:sum});
  }
  function check(elem1,elem2,arry1,arry2)
  {
    
    if(utils.binarySearch(elem2,arry2) >= 0 && utils.binarySearch(elem1,arry1) >= 0)
      return true;
    if(utils.binarySearch(elem1,arry2) >= 0 && utils.binarySearch(elem2,arry1) >= 0)
      return true;
    return false;
    
  }
}

utils.combination(arr,6,firstcb);
function compare(a,b)
{
  return a.sum - b.sum;
}
finalArray = finalArray.sort(compare);
function arrayEquals(arr1,arr2)
{
  if(arr1.length !== arr2.length)
    return false;
  //console.log(arr1,arr2);
  for(var i = 0; i < arr1.length; i++)
    if(arr1[i]!==arr2[i])
      return false;
  return true;
}
var finalFilteredArray = finalArray.filter(function(val,ind,arry){
  //console.log(i,arry[i]);
  for(var i = ind + 1; i < arry.length && arry[i].sum === arry[ind].sum; i++)
  {//console.log(arry[i],arry[ind]);
    if(arrayEquals(arry[i].arr1,arry[ind].arr1) )
      if(arrayEquals(arry[i].arr2,arry[ind].arr2)) 
        return false;
    if(arrayEquals(arry[i].arr1,arry[ind].arr2) )
      if(arrayEquals(arry[i].arr2,arry[ind].arr1)) 
        return false;
    
    
      
  }
  return true;
});
console.log(finalFilteredArray.length);
