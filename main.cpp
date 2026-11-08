#include <vector>
#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

// function prototypes
vector<vector<int>> createMatrix(int &n, int &m);
vector<vector<int>> createResult(int &rowA, int &colB);
void matmul(int &rowA, int &colA, int &colB, const vector<vector<int>> &matrixA, const vector<vector<int>> &matrixB, vector<vector<int>> resultMatrix);

int main()
{
  // initialize dimensions for matrix A and B
  int rowA, colA, rowB, colB;

  // prompt user to input number of rows and columns for A and B
  cout << "Enter number of rows for A: ";
  cin >> rowA;

  cout << "Enter number of columns for A: ";
  cin >> colA;

  cout << "Enter number of rows for B: ";
  cin >> rowB;
  while (colA != rowB)
  {
    cout << "Re-enter number of rows for B: ";
    cin >> rowB;
  }

  cout << "Enter number of columns for B: ";
  cin >> colB;

  // create matrices A, B, and result
  const vector<vector<int>> matrixA = createMatrix(rowA, colA);
  const vector<vector<int>> matrixB = createMatrix(rowB, colB);
  vector<vector<int>> resultMatrix = createResult(rowA, colB);

  // start recording time
  const auto start = chrono::steady_clock::now();

  // perform matmul
  matmul(rowA, colA, colB, matrixA, matrixB, resultMatrix);

  // stop recording time
  const auto end = chrono::steady_clock::now();

  // calculate how long the entire matmul operation took
  const double seconds = chrono::duration<double>(end - start).count();
  // each inner iteration performs one multiply and one add, so 2 operations
  // these are integer operations, so report GOP/s, not GFLOP/s.
  const double operations = 2.0 * rowA * colA * colB;
  // calculates GOP (giga operations per second)
  const double gops = seconds > 0.0 ? operations / seconds / 1e9 : 0.0;

  cout << endl;
  // print out ms (this is converted from s to ms) and throughput
  cout << fixed << setprecision(3) << "\nCompute time: " << seconds * 1000.0 << " ms\n"
       << "Throughput: " << gops << " GOP/s\n";

  return 0;
}

// after initializing row and col dimensions for matrix A and B, these will be passed by reference to the createMatrix function that construct matrix A and B
vector<vector<int>> createMatrix(int &n, int &m)
{
  int value = 1;
  vector<vector<int>> matrix;

  for (int i = 0; i < n; i++)
  {
    matrix.push_back({});
    for (int j = 0; j < m; j++)
    {
      matrix[i].push_back(value++);
    }
  }

  return matrix;
}

// after initializing row and col dimensions for matrix A and B, number of rows for A and number of columns for B will be passed by reference to createResult to build the result matrix
vector<vector<int>> createResult(int &rowA, int &colB)
{
  vector<vector<int>> result;

  for (int i = 0; i < rowA; i++)
  {
    result.push_back({});
    for (int j = 0; j < colB; j++)
    {
      result[i].push_back(0);
    }
  }

  return result;
}

// after creating matrix A and B these will be passed by reference to matmul
void matmul(int &rowA, int &colA, int &colB, const vector<vector<int>> &matrixA, const vector<vector<int>> &matrixB, vector<vector<int>> resultMatrix)
{
  for (int i = 0; i < rowA; i++)
  {
    cout << "\n";
    for (int j = 0; j < colB; j++)
    {
      for (int k = 0; k < colA; k++)
      {
        resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
      }
      cout << resultMatrix[i][j] << " ";
    }
  }
}