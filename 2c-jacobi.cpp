#include<iostream>
#include<iomanip> /* setprecision */
#include<math.h> /* fabs */

/*  Iterasi Jacobi merupakan salah satu metode tak langsung, 
    yaitu bermula dari sebuah hampiran penyelesaian awal 
    dan yang belakang sekali berupaya memperbaiki hampiran dalam
    tak berhingga namun langkah konvergen. */

// SPL:
// 1w + 2x + 3y - 1z = 10
// 2w + 5x + 4y + 8z = 8
// 4w + 2x + 2y + 1z = -2
// 6w + 4x - 1y - 2z = 4

// Temukan nilai per variabel
// w =  10 - 2x - 3y + z
// x = ( 8 - 2w - 4y - 8z)/5
// y = (-2 - 4w - 2x - z)/2  = -1 - 2w -  x - (1/2x)
// z = ( 4 - 6w - 4x + y)/-2 = -2 + 3w + 2x + (1/2y) 

#define f1(w,x,y,z)  10-2*x-3*y+z
#define f2(w,x,y,z)  (8-2*w-4*y-8*z)/5
#define f3(w,x,y,z)  (-2-4*w-2*x-z)/2
#define f4(w,x,y,z)  (4-6*w-4*x+y)/-2

using namespace std;

int main(){
    float w0 = 0.0, x0 = 0.0, y0 = 0.0, z0 = 0.0;
    float w1, x1, y1, z1, e1, e2, e3, e4, e;
    int iterasi = 1;

    // Presisi 6 digit desimal di belakang koma
    cout << setprecision(6) << fixed;

    // Input Error
    cout << "Masukkan error: "; cin >> e;
    
    // Judul
    cout << endl << "Iterasi\tw\t\tx\t\ty\t\tz" << endl;

    // Proses Iterasi Jacobi
    do {
        w1 = f1(w0, x0, y0, z0);
        x1 = f2(w0, x0, y0, z0);
        y1 = f3(w0, x0, y0, z0);
        z1 = f4(w0, x0, y0, z0);
        cout << iterasi << "\t" << w1 << "\t" << x1 << "\t" << y1 << "\t" << z1 << endl;

        e1 = fabs(w0-w1);
        e2 = fabs(x0-x1);
        e3 = fabs(y0-y1);
        e4 = fabs(z0-z1);

        iterasi++;

        w0 = w1;
        x0 = x1;
        y0 = y1;
        z0 = z1;
        
    } while (e1 > e && e2 > e && e3 > e);
    cout << endl << "Akar Persamaan:" << endl;
    cout << "w = " << w1 << endl << "x = " << x1 << endl;
    cout << "y = " << y1 << endl << "z = " << z1;
    return 0;
}

// https://www.codesansar.com/numerical-methods/jacobi-iteration-method-using-cpp-output.htm