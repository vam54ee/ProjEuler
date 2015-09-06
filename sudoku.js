// original file exist at vam54ee/sudoku.

var fs = require('fs');

function copy2D(arr)
{
  var ret = [];
  for(var i = 0; i< arr.length;i++)
  {
    ret.push(arr[i].slice());
  }
  return ret;
}


function copy3D(arr)
{
  var ret = [];
  for(var i = 0; i< arr.length;i++)
  {ret.push([]);
    for(var j = 0; j< arr[i].length;j++)
    {
      ret[i].push(arr[i].slice());
    }
  }
  return ret;
}


function boxNo(row,col){
  return Math.floor(row/3)*3+Math.floor(col/3);
}

function generateSudoku(arr){
  if(!arr || arr.length != 9)
  {
    //log("generateSudoku", "error in input" ,arr);
    return;
  }
  
  
  for(var i = 0; i < 9; i++)
  {
    sudoku[i]=[];
    estimate[i]=[];
    triedElements[i]=[];
    
    for(var j = 0; j < 9; j++)
    {
      //assuming all inputs are digits
      var temp = sudoku[i][j] = parseInt(arr[i][j]);
      estimate[i][j] = [1,2,3,4,5,6,7,8,9];
      triedElements[i][j] = false;
      if(temp != 0)
      {
        if(rows[i].indexOf(temp) < 0)
        rows[i].push(temp);
        if(cols[j].indexOf(temp) < 0)
        cols[j].push(temp);
        if(boxes[boxNo(i,j)].indexOf(temp) < 0)
        boxes[boxNo(i,j)].push(temp);
        estimate[i][j] = [];
      }
    }
  
  }
  
}

function removeFromRow(i)
{
  for(var j = 0; j < 9 ; j++)
  {
    for(var k = 0; k < rows.length; k++)
    {
      var temp = estimate[i][j].indexOf(rows[i][k]);
      if(temp >= 0)
        estimate[i][j].splice(temp,1);
    }
  }
}


function removeFromCol(j)
{
  for(var i = 0; i < 9 ; i++)
  {
    for(var k = 0; k < cols.length; k++)
    {
      var temp = estimate[i][j].indexOf(cols[j][k]);
      if(temp >= 0)
        estimate[i][j].splice(temp,1);
    }
  }
}


function removeFromBox()
{
  for(var i = 0; i < 9 ; i++)
  {
    for(var j = 0; j < 9; j++)
    {
      for(var k = 0; k < boxes.length; k++)
      {
      var temp = estimate[i][j].indexOf(boxes[boxNo(i,j)][k]);
      if(temp >= 0)
        estimate[i][j].splice(temp,1);
      }
    }
  }
}

function fill(i,j,val)
{
  var temp = estimate[i][j].indexOf(val);
  
  //if( sudoku[i][j] !== 0 || rows[i].indexOf(val) > 0 || cols[j].indexOf(val) > 0 || boxes[boxNo(i,j)].indexOf(val) > 0 || temp < 0)
  if( sudoku[i][j] !== 0 || temp < 0)
  {
    //log("fill","something wrong with estimate or sudoku",i,j,val,temp,estimate[i][j],rows[i],cols[j],boxes[boxNo(i,j)]);
    return;
  }
  sudoku[i][j] = val;
  rows[i].push(val);
  cols[j].push(val);
  boxes[boxNo(i,j)].push(val);
  if(temp >= 0)
  estimate[i][j]=[];
}

function checkSingles()
{
  for(var i = 0; i < 9; i++)
  {
    for(var j = 0; j < 9; j++)
    {
      if(estimate[i][j].length === 1)
      {
        //log("checkSingles inserted at (i,j)=("+i+","+j+") value = "+estimate[i][j][0])
        fill(i,j,estimate[i][j][0]);
        singlesFlag = 1;
      }
    }
  }
}

function findUniqueRow(i){
  var count = [0,0,0,0,0,0,0,0,0,0];
  var index = [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1];
  for(var j = 0; j < 9; j++)
  {
    for(var k = 0; k < estimate[i][j].length; k++)
    {
      count[estimate[i][j][k]]++;
      index[estimate[i][j][k]] = j;
    }
      
  }
  
  for(var j = 0; j < 9; j++)
  {
    if(count[j] === 1)
    {
      //log("findUNiqueRow inserted at (i,j)=("+i +","+index[j]+") value = "+j);
      fill(i,index[j],j);
      uniqueRowFlag = 1;
    }
  }
}

function findUniqueCol(j){
  var count = [0,0,0,0,0,0,0,0,0,0];
  var index = [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1];
  for(var i = 0; i < 9; i++)
  {
    for(var k = 0; k < estimate[i][j].length; k++)
    {
      count[estimate[i][j][k]]++;
      index[estimate[i][j][k]] = i;
    }
      
  }
  
  for(var i = 0; i < 9; i++)
  {
    if(count[i] === 1)
    {
      //log("findUNiqueCol inserted at (i,j)=("+index[i]+","+j+") value = "+i);
      fill(index[i],j,i);
      uniqueColFlag = 1;
    }
  }
}



function findUniqueBox(boxNo){
  
  var row = Math.floor(boxNo/3)*3;
  var col = (boxNo%3)*3;
  var count = [0,0,0,0,0,0,0,0,0,0];
  var rowIndex = [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1];
  var colIndex = [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1];
  for(var i = row; i < row + 3; i++)
  {
    for(var j = col; j < col + 3; j++)
    {
      for(var k = 0; k < estimate[i][j].length; k++)
      {
        count[estimate[i][j][k]]++;
        rowIndex[estimate[i][j][k]] = i;
        colIndex[estimate[i][j][k]] = j;
      }
    }
      
  }
  
  for(var i = 0; i < 10; i++)
  {
    if(count[i] === 1)
    {
      //log("findUNiqueBox inserted at (i,j)=("+rowIndex[i]+","+colIndex[i]+") value = "+i);
      fill(rowIndex[i],colIndex[i],i);
      uniqueBoxFlag = 1;
    }
  }
}




function removeFromEstimate()
{
  for(var i = 0; i < 9;i++)
    {
      removeFromRow(i);
      removeFromCol(i);
    }
    removeFromBox();
}

function log(){
  var args = Array.prototype.slice.call(arguments);
  for(var i = 0; i < args.length; i++)
  console.log(args[i]);
}

function generateEstimateByNoOfElements()
{estimateByNoOfElements = [[],[],[],[],[],[],[],[],[]];
  for(var i = 0; i < 9; i++)
  {
    for(var j = 0; j < 9; j++)
    {
      var len = estimate[i][j].length;
      if(len > 1 && triedElements[i][j] !== true)
      {
        var tempObj = {i:i,j:j};
        estimateByNoOfElements[len].push(tempObj);
      }
    }
  }
}
function guess()
{
  //console.log("guess",estimate);
  generateEstimateByNoOfElements();
  //console.log("guess",estimate);
  var tempObj = {
    rows:JSON.parse(JSON.stringify(rows)),
    cols:JSON.parse(JSON.stringify(cols)),
    boxes:JSON.parse(JSON.stringify(boxes)),
    sudoku:JSON.parse(JSON.stringify(sudoku)),
    estimate:JSON.parse(JSON.stringify(estimate)),
    previousEstimateSum:previousEstimateSum,
    previousSum:previousSum,
    estimateByNoOfElements:JSON.parse(JSON.stringify(estimateByNoOfElements))
  };
  stack.push(tempObj);
  //console.log("guess",estimate,estimateByNoOfElements,triedElements);
  
  for(var i = 2; i < 9; i++)
  {
    for(var j = 0;j < estimateByNoOfElements.length; j++)
    {//console.log(i,j,estimateByNoOfElements[i][j],estimate[i][j]);
      if(estimateByNoOfElements[i][j] !== undefined )
      {
        var tempi = estimateByNoOfElements[i][j].i;
        var tempj = estimateByNoOfElements[i][j].j;
        triedGuesses = [];
        currentGuessIndex = {i:tempi,j:tempj};
        currentGuess = estimate[tempi][tempj][0];
        fill(tempi,tempj,currentGuess);
        //console.log("Guessed at i, j , val,estimate at i,j ",tempi,tempj,currentGuess,estimate[tempi][tempj]);
        return;
      }
    }
  }
  
}


function checkSudoku()
{
  var sum = 0, estimateSum = 0;
  var falseFlag = false;
  for (var i = 0; i < 9;i++)
  {
    for(var j = 0; j < 9; j++)
    {
      if(sudoku[i][j] === 0 )
      {
        if(estimate[i][j].length === 0)
        return WRONG;
        falseFlag = true;
      }
      sum += ((i+1)*(j+1)*sudoku[i][j]);
      estimateSum += ((i+1)*(j+1)*estimate[i][j].length);
      
    }
  }
  if(!falseFlag)
  return DONE;
  if(previousSum === sum && previousEstimateSum === estimateSum)
    return STUCK;
  previousSum = sum;
  previousEstimateSum = estimateSum;
  return INC;
}

function solve()
{
  for(var tmp = 0; tmp < 200; tmp++)
  {
    var check = checkSudoku();
    if(check === DONE)
    {
      //log("done with sudoku in "+tmp+" steps. Sudoku",sudoku);
      return DONE;
    }
    else if(check === WRONG || check === STUCK)
      return check;
    removeFromEstimate();
    singlesFlag = 0;
    checkSingles();
    if(singlesFlag)
      removeFromEstimate();
    for(var i = 0; i < 9; i++)
    {
      uniqueRowFlag = 0;
      findUniqueRow(i);
      if(uniqueRowFlag)
      removeFromEstimate();
      
      uniqueColFlag = 0;
      findUniqueCol(i);
      if(uniqueColFlag)
      removeFromEstimate();
      
      uniqueBoxFlag = 0;
      findUniqueBox(i);
      if(uniqueBoxFlag)
      removeFromEstimate();
    }
    
  }
}

var rows = [[],[],[],[],[],[],[],[],[]],
      cols = [[],[],[],[],[],[],[],[],[]],
      boxes = [[],[],[],[],[],[],[],[],[]],
      sudoku =[],
      estimate = [];
  var singlesFlag = 0,
      uniqueRowFlag = 0,
      uniqueColFlag = 0,
      uniqueBoxFlag = 0;
  var previousSum = 0, previousEstimateSum = 0;
  var currentGuessIndex = {},currentGuess = 0,triedGuesses = [],stack = [],estimateByNoOfElements = [[],[],[],[],[],[],[],[],[]],triedElements=[[]];

  var WRONG = "WRONG", INC = "INCOMPLETE", DONE = "DONE", STUCK = "STUCK";


function solveSudoku(allData)
{
  rows = [[],[],[],[],[],[],[],[],[]],
  cols = [[],[],[],[],[],[],[],[],[]],
  boxes = [[],[],[],[],[],[],[],[],[]],
  sudoku =[],
  estimate = [];
  singlesFlag = 0,
  uniqueRowFlag = 0,
  uniqueColFlag = 0,
  uniqueBoxFlag = 0;
  previousSum = 0, previousEstimateSum = 0;
  currentGuessIndex = {},currentGuess = 0,triedGuesses = [],stack = [],estimateByNoOfElements = [[],[],[],[],[],[],[],[],[]],triedElements=[[]];

  WRONG = "WRONG", INC = "INCOMPLETE", DONE = "DONE", STUCK = "STUCK";
  generateSudoku(allData.splice(0,9));
  var solveValue = solve();
  //console.log(solveValue,estimate);
  var x =100;
  //if(stack[stack.length-1])
  //console.log("first",stack[stack.length-1].estimate);
  while(solveValue !== DONE )
  {
    //console.log(solveValue);
    if(solveValue === STUCK)
    {
      //if(stack[stack.length-1])
      //console.log("stuckguess1",stack[stack.length-1].estimate,stack.length);
      guess();
      //console.log(currentGuess,currentGuessIndex,estimateByNoOfElements,triedGuesses,triedElements);
      //console.log("stuckguess",stack[stack.length-1].estimate,stack.length);
    }
    else if(solveValue === WRONG)
    {//console.log("second",stack[stack.length-1].estimate,stack.length,triedGuesses);
      var tempObj = stack[stack.length-1];
      rows = JSON.parse(JSON.stringify(tempObj.rows)),
      cols = JSON.parse(JSON.stringify(tempObj.cols)),
      boxes = JSON.parse(JSON.stringify(tempObj.boxes)),
      sudoku = JSON.parse(JSON.stringify(tempObj.sudoku)),
      estimate = JSON.parse(JSON.stringify(tempObj.estimate)),
      previousEstimateSum = tempObj.previousEstimateSum,
      previousSum = tempObj.previousSum,
      estimateByNoOfElements = JSON.parse(JSON.stringify(tempObj.estimateByNoOfElements));

      var estimateOfCurrentGuess = estimate[currentGuessIndex.i][currentGuessIndex.j];
      if(triedGuesses.length !== estimateOfCurrentGuess.length - 1)
      {//console.log("hi",triedGuesses.length);
        triedGuesses.push(currentGuess);
        currentGuess = estimateOfCurrentGuess[triedGuesses.length];
        fill(currentGuessIndex.i,currentGuessIndex.j,currentGuess);
       //console.log("filled at i,j,val",currentGuessIndex.i,currentGuessIndex.j,currentGuess);
      }
      else 
      {//console.log("hi2",estimate[currentGuessIndex.i][currentGuessIndex.j],tempObj)
        stack.pop();
        triedElements[currentGuessIndex.i][currentGuessIndex.j] = true;
        //console.log("hi2",triedElements,currentGuessIndex);
        currentGuess = 0;
        currentGuessIndex ={};
        triedGuesses=[];
        guess();
      }

    }


    //console.log(solveValue);
    //console.log("third",stack[stack.length-1].estimate,stack.length);
    solveValue = solve();
    //console.log("third",stack[stack.length-1].estimate,stack.length);

  }
  //log("rows", rows,"cols", cols,"boxes", boxes,"sudoku",sudoku,"estimate", estimate);

return sudoku;
}
/*fs.readFile('test.txt', function (err, data) {
    if (err) throw err;
    var allData = data.toString().split('\r\n');
    solveSudoku(allData.splice(0,9));});*/
module.exports={solveSudoku:solveSudoku}