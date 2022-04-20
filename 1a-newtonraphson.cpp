#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <stdlib.h>

// Fungsi f(x): x^3 + 2x^2 + 10 x = 20
#define f(x) pow(x, 3) + pow(2*x, 2) + 10*x - 20

// Turunan fungsi f(x) sebagai g(x): 3x^2 + 4x + 10
#define g(x) pow(3*x, 2) + 4*x + 10

using namespace std;

int main(){
    float x0, x1, f0, f1, g0, e;
    int iterasi = 1, N;
    
    // Setting precision and writing floating point values in fixed-point notation.
    // Presisi desimal 6 digit.
    cout << setprecision(6) << fixed;
    
    cout << "=======================================" << endl;
    cout << "======== Metode Newton-Raphson ========" << endl;
    cout << "=======================================" << endl;

    // Input
    cout << "Masukkan nilai x0: "; cin >> x0;
    cout << "Masukkan toleransi error: "; cin >> e;
    cout << "Masukkan maksimum iterasi: "; cin >> N;

    do {
        g0 = g(x0);
        f0 = f(x0);
        if (g0 == 0.0) {
            cout << "Error";
            exit(0);
        }

        x1 = x0 - f0/g0;

        cout << "Iterasi ke-" << iterasi <<":\tx =" << setw(10);
        cout << x1 << " dan f(x) =" << setw(10) << f(x1) << endl;

        x0 = x1;

        iterasi++;

        if (iterasi > N){
            cout << "Tidak konvergen (tidak mendekati satu titik temu).";
            exit(0);
        }

        f1 = f(x1);
    } while (fabs(f1)>e);
    return 0;
}