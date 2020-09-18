//Probem description
//https://www.youtube.com/watch?v=FO7VXDfS8Gk&t=406s
var Arr=[
  [1,1,0,1,0],
  [0,1,1,1,0],
  [1,1,1,1,0],
  [0,1,1,1,1]
];
var clone=[
  [1,1,0,1,0],
  [0,1,1,1,0],
  [1,1,1,1,0],
  [0,1,1,1,1]
];
function getMaxOneMatrixOrder(){
  var maxOrder=0;
  for(var i=0;i<Arr.length;i++){
    for(var j=0;j<Arr[i].length;j++){
      if(i==0 || j==0){
        clone[i][j]=Arr[i][j];
      }
      else if (Arr[i][j]>0){
        clone[i][j]=1+Math.min(clone[i-1][j-1],clone[i-1][j],clone[i][j-1]);
      }
      if(clone[i][j]>maxOrder){
        maxOrder=clone[i][j];
      }
    }
  }
  return maxOrder;
}
console.log(getMaxOneMatrixOrder());
