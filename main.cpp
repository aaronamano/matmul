#include <vector>
#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

int main()
{
  // initialize result matrices
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
  while (colA != rowB)
  {
    cout << "Re-enter number of rows for B: ";
    cin >> rowB;
  }

  cout << "Enter number of columns for B: ";
  cin >> colB;

  // initialize value variable to fill for matrix A and B
  int value;

  // create matrices A, B, and result
  value = 1;
  for (int i = 0; i < rowA; i++)
  {
    A.push_back({});
    for (int j = 0; j < colA; j++)
    {
      A[i].push_back(value++);
    }
  }

  value = 1;
  for (int i = 0; i < rowB; i++)
  {
    B.push_back({});
    for (int j = 0; j < colB; j++)
    {
      B[i].push_back(value++);
    }
  }

  for (int i = 0; i < rowA; i++)
  {
    result.push_back({});
    for (int j = 0; j < colB; j++)
    {
      result[i].push_back(0);
    }
  }

  // start recording time
  const auto start = chrono::steady_clock::now();

  // perform matmul
  for (int i = 0; i < rowA; i++)
  {
    cout << "\n";
    for (int j = 0; j < colB; j++)
    {
      for (int k = 0; k < colA; k++)
      {
        result[i][j] += A[i][k] * B[k][j];
      }
      cout << result[i][j] << " ";
    }
  }

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
