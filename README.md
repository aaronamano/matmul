# About
Matrix multiplication in C++ not entirely vibecoded by AI. This multiplies two matrices A and B then returns a result.

# What it does
The user enters 4 numbers: number of rows for matrix A, number of columns for matrix A, number of rows for matrix B, number of columns for matrix B. The program creates matrices A and B based on the dimensions the user inputs and a result matrix filled with 0s as placeholders. Then the program takes those matrices, A and B, performs matrix multiplication and fills in the cells for the result matrix.

The program prints out the result of each cell performed by matmul and overall prints the output as a matrix like shape.

# How to run
```
make main
./main
```

# Sample Input
```
Enter number of rows for A: 2
Enter number of columns for A: 2
Enter number of rows for B: 2
Enter number of columns for B: 2
```

# Sample Output
```
7 10 
15 22 

Compute time: 0.029 ms
Throughput: 0.001 GOP/s
```
# Profiling
- **compute time** determines how long the matrix multiplication took, measured as **ms** (milliseconds)
- **throughput** determines how many per billion artihmetic operations were performed, measured as **GOP/s** (giga operations per second)