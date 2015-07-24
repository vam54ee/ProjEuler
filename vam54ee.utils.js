//limit should be greater than 10;
function generateSieve(lim)
{
  var primes = new Buffer(lim+1);
  var finalPrimes = [];
  primes[2] = 1;
  primes[3] = 1;
  primes[5] = 1;
  primes[7] = 1;
  for(var i = 11; i < lim; i++)
  {
    if(i%2 === 1)
      primes.writeUInt8(1,i);
    else
      primes.writeUInt8(0,i);
  }

  for(var i = 3; i < lim/2; )
  {
    for(var j= 3; i*j < lim; j+=2)
    {
      primes[i*j] = 0;
    }
    i+=2;
    for(;primes[i] === 0;i+=2);
    //console.log(i);
  }
  console.log("done");
  for (var i = 0; i < primes.length;i++)
  {
    if(primes[i] === 1)
      finalPrimes.push(i);
  }
  console.log("done with final primes with length",finalPrimes.length);
  return finalPrimes;
}


function binarySearch(value,arr)
{
  var start = 0;
  var end = arr.length - 1;
  if(arr[start] === value)
    return start;
  if(arr[end] === value)
    return end;
  
  
  for(var i = start, j = end; i < j; )
  {
    var mid = Math.floor((i+j)/2);
    if(arr[mid] === value)
      return mid;
    if(j-i === 1)
      return -1;
    if(arr[mid] > value)
      j = mid;
    else
      i = mid;
  }
  return -1;
}


module.exports = {
  generateSieve:generateSieve,
  binarySearch:binarySearch
}