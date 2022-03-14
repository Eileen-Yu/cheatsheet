#include<iostream>
#include<vector>

int fib(int k){
  std::vector<int> fibArr = std::vector<int>(k + 1);
  fibArr[0] = 0;
  fibArr[1] = 1;

  for(int i = 2; i <= k; i++){
    fibArr[i] = fibArr[i - 2] + fibArr[i - 1];
  }

  return fibArr[k];

/*
  if (k==0){
    return 0;
  }

  if (k==1){
    return 1;
  }
  

  return fib(k-1) + fib(k-2);
*/
}

int main(){
  std::cout<<fib(40)<<"\n";
}
