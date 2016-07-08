var utils = require('../utils/vam54ee.utils.js');
utils.start();
var num = 2000000;
var divisors = utils.generateSumOfDivisorsSieve(num);
var maxLengthChain = {
  length: 0
};
// convert sum of divisors to sum of proper divisors

for (var i = 1; i < divisors.length; i++) divisors[i]-=i;
var chains = [];

for (var i = 2; i < divisors.length; i++) {
  // console.log('i',i,divisors[i]);
  if(divisors[i] === null) continue;
  if(divisors[i] === i) {
    chains.push({
      length: 1,
      chain: [i]
    });
    continue;
  }
  var tmp = divisors[i];
  var chain = [i];
  for (var j = tmp; j !== null && j <= num; j = tmp) {
    tmp = divisors[j];
    chain.push(j);
    divisors[j] = null;
  }
  // console.log(chain);
  var last = chain.pop();
  var length = 0;
  if(chain.indexOf(last) >= 0) {
    length = chain.length - chain.indexOf(last)
  }
  chains.push({
    length: length,
    chain: chain,
    last: last
  });
  if(maxLengthChain.length < length) {
    maxLengthChain = {
      length: length,
      chain: chain,
      last: last
    };
  }

}
var least = Infinity;
for (var i = maxLengthChain.chain.indexOf(maxLengthChain.last); i < maxLengthChain.chain.length; i++) {
  if(least > maxLengthChain.chain[i]) least = maxLengthChain.chain[i];
}
console.log(maxLengthChain,least,utils.now());
