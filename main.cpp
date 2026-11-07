#include <vector>
#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

// function prototypes
vector<vector<int>> createA(int& rowA, int& colA);
vector<vector<int>> createB(int& rowB, int& colB);
vector<vector<int>> createResult(int& rowA, int& colB);
void matmul(int& rowA, int& colA, int& colB, const vector<vector<int>>& matrixA, const vector<vector<int>>& matrixB, vector<vector<int>> resultMatrix);

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
  const vector<vector<int>> matrixA = createA(rowA, colA);
  const vector<vector<int>> matrixB = createB(rowB, colB);
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

// after initializing row and col dimensions for matrix A and B, these will be passed by reference to the functions that construct matrix A, B, and result instead of copying the dimensions

vector<vector<int>> createA(int& rowA, int& colA)
{
  int value = 1;
  vector<vector<int>> A;

  for (int i = 0; i < rowA; i++)
  {
    A.push_back({});
    for (int j = 0; j < colA; j++)
    {
      A[i].push_back(value++);
    }
  }

  return A;
}

vector<vector<int>> createB(int& rowB, int& colB)
{
  int value = 1;
  vector<vector<int>> B;

  for (int i = 0; i < rowB; i++)
  {
    B.push_back({});
    for (int j = 0; j < colB; j++)
    {
      B[i].push_back(value++);
    }
  }

  return B;
}

vector<vector<int>> createResult(int& rowA, int& colB)
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

// after creating matrix A and B these will be passed by reference to matmul instead of copying matrix A and B
void matmul(int& rowA, int& colA, int& colB, const vector<vector<int>>& matrixA, const vector<vector<int>>& matrixB, vector<vector<int>> resultMatrix)
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