# Numerical Methods
A special repository for Numerical Methods course from my uni in April 2022.
All of the code written in C/C++, there are five methods included. 

Two of them are Newthon-Raphson method and Secant method.
Both are used for finding the roots of given equations.

Three of them are Gaussian Elimination, Inverse with Gauss-Jordan, and Jacobian. 
These methods are used for determining the solutions for the system of linear equations in numerical linear algebra.

## Newton-Raphson
$$X_{n+1} = X_n + \dfrac{f(X_n)}{f'(X_n)}$$

## Secant
Secant Method formula:
$$X_n = X_{n-1} - f(X_{n-1}) \dfrac{(X_{n-1} - X_{n-2})}{(f_{n-1} - f_{n-2})}$$




We can simplify the equations:
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

- Swap the positions of two of the rows
- Multiply one of the rows by a nonzero scalar.
- Add or subtract the scalar multiple of one row to another row.

### Example


$$A = \begin{bmatrix}
1 &0  &0 \\ 
0 &1  &3 \\ 
0 &0  &0 
\end{bmatrix},

B = \begin{pmatrix} 
1 & 0 & 0 \\ 
0 & 1 & 0 \\ 
0 & 0 & 1 
\end{pmatrix}

$$ 


, C = \begin{pmatrix} 0 & 7 & 3 \\ 1 & 0 & 0 \\ 0 & 0 & 0 \end{pmatrix}, D = \begin{pmatrix} 1 & 7 & 3 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{pmatrix}
Matrices A and B are in reduced-row echelon form, but matrices C and D are not. 
C is not in reduced-row echelon form because it violates conditions two and three. 
D is not in reduced-row echelon form because it violates condition four. 
In addition, the elementary row operations can be used to reduce matrix D into matrix B.

## Jacobi 

