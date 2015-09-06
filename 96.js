var fs = require('fs');
var su = require('./sudoku.js');
var ans = 0;

fs.readFile('p096_sudoku.txt', function (err, data) {
  if (err) throw err;
  var allData = data.toString().split('\n');
  
  //var ans = 0;
  for(var num = 0; allData.length !== 0; num++)
  {
    
    allData.splice(0,1);
    var ret = su.solveSudoku(allData.splice(0,9));
    ans+=(ret[0][0]*100+ret[0][1]*10+ret[0][2]);
    console.log(ret);
  }
  console.log(ans);
});
