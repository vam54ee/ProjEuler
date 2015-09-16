var fs = require('fs');
var ans = 0;

function sum(str)
{
  var ret = 0;
  for(var i = 0; i< str.length;i++)
  {
    ret+=(str[i].charCodeAt(0) - 'A'.charCodeAt(0));
  }
  return ret;
}

function isAnagram(str1,str2)
{
  if(str1.length!== str2.length)
    return false;
  var arr1 = [];
  var arr2 = [];
  for(var i = 0; i < str1.length;i++)
  {
    if(arr1[(str1[i].charCodeAt(0))] === undefined)
      arr1[(str1[i].charCodeAt(0)) ] = 0;
    arr1[(str1[i].charCodeAt(0)) ]++;
    if(arr2[(str2[i].charCodeAt(0))] === undefined)
      arr2[(str2[i].charCodeAt(0))] = 0;
    arr2[(str2[i].charCodeAt(0)) ]++;
  }
  for(var i = 0; i < arr1.length;i++)
  {
    if(arr1[i]!==arr2[i])
      return false;
  }
  return true;
  
}

function checkAnagramNum(str1,num,str2)
{
  var arr = [];
  var arr1=[];
  var numstr = num.toString();
  for(var i = 0; i < str1.length;i++)
  {
    var tmp = str1[i].charCodeAt(0);
    if(arr[tmp]!==undefined)
    {
      if(arr[tmp]!==parseInt(numstr[i]))
      {
        return false;
      }
      else
      {
        continue;
      }
    }
    else
    {
      var tmp1 = numstr[i].charCodeAt(0);
      if(arr1[tmp1] !== undefined)
      {
        if(arr1[tmp1] !== str1[i])
        {
          return false;
        }
        else
        {
          continue;
        }
      }
      else
      {
        arr[tmp]= parseInt(numstr[i]);
        arr1[tmp1] = str1[i];
      }
      
    }
  }
  var ret = 0;
  for(var i = 0; i < str2.length; i++)
  {
    var tmp = str2[i].charCodeAt(0);
    ret=(ret*10+arr[tmp]);
  }
  return ret;
}


fs.readFile('98.txt', function (err, data) {
  if (err) throw err;
  var str = data.toString();
  var words = str.replace(/"/g,'').split(',');
  var filtered = [];
  for(var i = 0; i < words.length;i++)
  {
    if(words[i].length === 1)
      words.splice(i,1);
    //console.log(words[i],words[i].length);
  }
  for(var i = 0; i < words.length;i++)
  {
    if(filtered[words[i].length] === undefined)
      filtered[words[i].length]=[];
    filtered[words[i].length].push({word:words[i],sum:sum(words[i])});
  }
  var filteredArray=[];
  for(var i = 2; i < filtered.length;i++)
  {filteredArray[i]=[];
    for(var j = 0; j < filtered[i].length;j++)
    {
      var flag = 0;
      for(var k = j+1; k < filtered[i].length;k++)
      {
        if(filtered[i][j].sum === filtered[i][k].sum &&k!==j)
        {
          if(isAnagram(filtered[i][j].word,filtered[i][k].word))
          {
            console.log(filtered[i][j],filtered[i][k]);
            filteredArray[i].push({one:filtered[i][j],two:filtered[i][k]});
          }
        }
      }
      
    }
  }
  var flag = 1;
  var ans = 0;
  for(var i = filteredArray.length-1; i >=0 && flag ;i--)
  {
    for(var j = Math.ceil(Math.sqrt(Math.pow(10,i-1))); j < Math.ceil(Math.sqrt(Math.pow(10,i))); j++)
    {
      for(var k = 0; k < filteredArray[i].length && flag;k++)
      {
        var ret = checkAnagramNum(filteredArray[i][k].one.word,j*j,filteredArray[i][k].two.word);
        console.log(j*j,filteredArray[i][k].one,filteredArray[i][k].two,ret);
        if(Math.pow(Math.floor(Math.sqrt(ret)),2) === ret)
        {
          if(ret.toString().length === i)
          {
            ans = ret;
            flag = 0;
            break;
          }
        }
      }
    }
  }
  console.log(ans);
  //console.log(filteredArray);
  //console.log(isAnagram('COMMUNICATION','UNDERSTANDING'));
});
