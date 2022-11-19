<h1 align="center">Numerical Methods</h1>
A special repository for Numerical Methods course from my uni in April 2022.
All of the code written in C/C++, there are five methods included. 


Two of them are Newthon-Raphson method and Secant method.
Both are used for finding the roots of given equations.

Three of them are Gaussian Elimination, Inverse with Gauss-Jordan, and Jacobian. 
These methods are used for determining the solutions for the system of linear equations in numerical linear algebra.

## Newton-Raphson
The Newton-Raphson method (also known as Newton's method) is a way to quickly find a good approximation for the root of a real-valued function $f(x) = 0$. 
It uses the idea that a continuous and differentiable function can be approximated by a straight line tangent to it.


### Formula
$$X_{n+1} = X_n + \dfrac{f(X_n)}{f'(X_n)}$$

Here is a picture to demonstrate what Newton's method actually does:
<div align="center">
  <img src="https://ds055uzetaobb.cloudfront.net/brioche/uploads/7KrMvNiT7l-newtons-method.png?width=1200" width="400px">
</div>


## Secant
The secant method is a root-finding procedure in numerical analysis that uses a series of roots of secant lines to better approximate a root of a function.

The tangent line to the curve of y = f(x) with the point of tangency (x<sub>0</sub>, f(x<sub>0</sub>) was used in Newton’s approach. Th
e graph of the tangent line about x = α is essentially the same as the graph of y = f(x) when x<sub>0</sub> ≈ α. 
The root of the tangent line was used to approximate α.
Consider employing an approximating line based on ‘interpolation’. Let’s pretend we have two root estimations of root α, say, x<sub>0</sub> and x<sub>1</sub>. Then, we have a linear function

$$q(x) = a_0 + a_1 x$$

Using $$q(x_0) = f(x_0), q(x_1) = f(x_1)$$

This line is also known as a secant line. Its formula is as follows:
$$q(x) = \dfrac{f(x_0)(x_1-x) + f(x_1)(x-x_0)}{x_1 - x_0}$$


### Formula
$$X_n = X_{n-1} - f(X_{n-1}) \dfrac{(X_{n-1} - X_{n-2})}{(f_{n-1} - f_{n-2})}$$

### Applied Formula
$$X_2 = X_1 - \dfrac{(X_1 - X_0) \times f_1}{(f_1 - f_0)}$$


## Gaussian Elimination
In mathematics, the Gaussian elimination method is known as the row reduction algorithm for solving linear equations systems. It consists of a sequence of operations performed on the corresponding matrix of coefficients. We can also use this method to estimate either of the following:

- The rank of the given matrix
- The determinant of a square matrix
- The inverse of an invertible matrix

To perform row reduction on a matrix, we have to complete a sequence of elementary row operations to transform the matrix till we get 0s (i.e., zeros) on the lower left-hand corner of the matrix as much as possible. That means the obtained matrix should be an upper triangular matrix. 

There are three types of elementary row operations:
- Swapping two rows and this can be expressed using the notation ↔, for example, $R_2$ ↔ $R_3$
- Multiplying a row by a nonzero number, for example, $R_1 → kR_2$ where k is some nonzero number
- Adding a multiple of one row to another row, for example, $R_2 → R_2 + 3R_1$

## Inverse with Gauss-Jordan Elimination
Gauss-Jordan Elimination is an algorithm that can be used to solve systems of linear equations and to find the inverse of any invertible matrix. It relies upon three elementary row operations one can use on a matrix:

- Swap the positions of two of the rows.
- Multiply one of the rows by a nonzero scalar.
- Add or subtract the scalar multiple of one row to another row.

### Reduced-row echelon form
The purpose of Gauss-Jordan Elimination is to use the three elementary row operations to convert a matrix into reduced-row echelon form. 
A matrix is in **reduced-row echelon form**, also known as **row canonical form**, if the following conditions are satisfied:

1. All rows with only zero entries are at the bottom of the matrix
2. The  first nonzero entry in a row, called the **leading entry** or the **pivot**, of each nonzero row is to the right of the leading entry of the row above it.
3. The leading entry, also known as the pivot, in any nonzero row is 1.
4. All other entries in the column containing a leading 1 are zeroes.

### Example
$$A = \begin{bmatrix}
1 &0  &0 \\ 
0 &1  &3 \\ 
0 &0  &0 
\end{bmatrix}$$

$$B = \begin{bmatrix} 
1 &0 &0 \\ 
0 &1 &0 \\ 
0 &0 &1 
\end{bmatrix}$$

$$C = \begin{bmatrix} 
0 &7 &3 \\ 
1 &0 &0 \\ 
0 &0 &0 
\end{bmatrix}
$$

$$D = \begin{bmatrix} 
1 &7 &3 \\ 
0 &1 &0 \\ 
0 &0 &1 
\end{bmatrix}
$$

Matrices A and B are in reduced-row echelon form, but matrices C and D are not. 
C is not in reduced-row echelon form because it violates conditions two and three. 
D is not in reduced-row echelon form because it violates condition four. 
In addition, the elementary row operations can be used to reduce matrix D into matrix B.

### Algorithm
1. Swap the rows so that all rows with all zero entries are on the bottom
2. Swap the rows so that the row with the largest, leftmost nonzero entry is on top.
3. Multiply the top row by a scalar so that top row's leading entry becomes 1.
4. Add/subtract multiples of the top row to the other rows so that all other entries in the column containing the top row's leading entry are all zero.
5. Repeat steps 2-4 for the next leftmost nonzero entry until all the leading entries are 1.
6. Swap the rows so that the leading entry of each nonzero row is to the right of the leading entry of the row above it.

## Jacobi 

