#include <vector>
#include <iostream>
using namespace std;

int main()
{
  // initialize result matrix
  vector<vector<int>> A;
  vector<vector<int>> B;
  vector<vector<int>> result;

  // initialize dimensions for matrix A and B
  int rowA, colA, rowB, colB;

  cout << "Enter number of rows for A: ";
  cin >> rowA;

  cout << "Enter number of columns for A: ";
  cin >> colA;

  cout << "Enter number of rows for B: ";
  cin >> rowB;
  while (colA != rowB){
    cout << "Re-enter number of rows for B: ";
    cin >> rowB;
  }

  cout << "Enter number of columns for B: ";
  cin >> colB;

  // initialize value variable to fill for matrix A and B
  int value;

  // create matrices A, B, and result
  value = 1;
  for (int i=0; i<rowA; i++){
    A.push_back({});
    for (int j=0; j<colA; j++){
      A[i].push_back(value++);
    }
  }

  value = 1;
  for (int i=0; i<rowB; i++){
    B.push_back({});
    for (int j=0; j<colB; j++){
      B[i].push_back(value++);
    }
  }

  for (int i=0; i<rowA; i++){
    result.push_back({});
    for (int j=0; j<colB; j++){
      result[i].push_back(0);
    }
  }

  // perform matmul
  for (int i=0; i<rowA; i++){
    cout << "\n";
    for (int j=0; j<colB; j++){
      for (int k=0; k<colA; k++){
        result[i][j] += A[i][k] * B[k][j];
      }
      cout << result[i][j] << " ";
    }
  }
  cout << "\n";
  return 0;
}
