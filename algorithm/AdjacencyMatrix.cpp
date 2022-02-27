// Dynamic
#include <iostream>
using namespace std;

class Matrix{
  private:
    int arraySize;
    bool** edgeArray;
    bool* vFlag; 
  
  public:
    Matrix(int size){
      arraySize = size;
      edgeArray = new bool*[arraySize]; // Create "From" dimension of matrix
      vFlag = new bool[arraySize];    // 1-dimention, mark if is traversed
     
      for (int x = 0; x < arraySize; x++){
        edgeArray[x] = new bool[arraySize];  // Create "To" dimension of matrix
      }

      for (int y = 0; y < arraySize; y++){
        vFlag[y] = false;   // Initialize all bits of flag array with false
        for (int z = 0; z < arraySize; z++){
            edgeArray[y][z] = false;
        }
      }  
    }

    void set(int i, int j){
      edgeArray[i][j] = true;
    }

    void display() {
      cout<<endl<<"From/to"<<"\t";
      for(int i = 0;i < arraySize; i++){
        if(i < 10){
          cout<<' ';
        }
        cout << i;
      }
      cout<<endl;

      for (int i = 0; i < arraySize; i++){
        cout<<endl<<i<<"\t";
        for (int j = 0; j < arraySize; j++){
          cout<<' '<<edgeArray[i][j];
        }
      }
      cout<<endl<<endl;
    }

};


int main(){
  Matrix myMatrix(10);
  myMatrix.set(1,8);
  myMatrix.set(2,4);
  myMatrix.display();
}
