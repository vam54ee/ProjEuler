var fs = require('fs');
var arry = [0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9];
//var arry = [0,1,2,3,4,5,6,7,8,9]



function Combination(arr,len,cb)
{
  var subset = [];
  function nextElement(arr,index,count)
  {
    if(count === len -1)
    {
      for(var j = index; j < arr.length ;j++)
      {
        subset.push(arr[j]);
        cb(subset.slice());
        subset.pop();
      }
    }
    else
    {
      for(var j = index; j <= arr.length - len+count ;j++)
      {
        subset.push(arr[j]);
        nextElement(arr,j+1,count+1);
        subset.pop();
      }
    }
  }
  for(var i = 0; i <= arr.length - len; i++)
  {
    subset.push(arr[i]);
    nextElement(arry,i+1,1);
    subset.pop();
  }
  //return subsetArray;
}

var sumArray = [];
function isEqual(arr,arr1)
{
  if(arr.length !== arr1.length)
    return false;
  for(var i = 0; i < arr.length;i++)
    if(arr[i] !== arr1[i])
      return false;
  return true;
}
var prev = [];
function sum (arr)
{
  //if(isEqual(arr,prev))
    //return;
  //console.log(arr,prev);
  var arr1 = [0,0,0,0,0,0,0,0,0,0],x = 0,y = 0,sumAll = 0;
  for(var i = 0;i < arr.length; i++)
  {
    arr1[arr[i]]++;
    sumAll += arr[i];
  }
  for(var i = 0;i < arr1.length; i++)
  {
    if(arr1[i] === 0)y++;
    if(arr1[i] === 2)x++;
  }
  var tmp ={sum:sumAll,x:x,y:y,noOfZeroes:arr1[0],str:arr.join('')};
  sumArray.push(tmp);
  prev = arr.slice();
  
}

function compare(a,b)
{
  return a.str - b.str;
}

var ans = 0;
Combination(arry,10,sum);
var x = sumArray.sort(compare);
var prev = '';
var filteredArray = x.filter(function(value,index,arr){
  //console.log(value , index);
  if(arr[index].str === '')
    return false;
var ret = arr[index].str !== prev;
  prev = arr[index].str;
  return ret;
})
console.log(filteredArray.length,filteredArray.slice(0,10));
var filtered = filteredArray.filter(function(value)
{
  //console.log(value);
  return Math.abs(90 - 2*value.sum)%11 === 0;
});
//console.log(sumArray.length,filtered.length);

var ansArray =[];
var productArray =[];
for(var i = 0; i< filtered.length;i++)
{
  var product = 1,fact9 = 9*8*7*6*5*4*3*2*1,fact10 = fact9*10;
  if(filtered[i].noOfZeroes === 0)
  {
    product*=fact10;
  }
  else if (filtered[i].noOfZeroes === 1)
  {
    product*=(9*fact9);
  }
  else 
  {
    product *=(8*fact9);
  }
  product/=(Math.pow(2,filtered[i].x)*Math.pow(2,filtered[i].y));
  product*=fact10;
  productArray.push(product);
  ans += product;
  console.log(filtered[i],product);
  
  /*if(ans>1e10)
  {
    ansArray.push(ans);
    ans = 0;
  }*/
}


console.log(ans,ansArray,productArray.length);