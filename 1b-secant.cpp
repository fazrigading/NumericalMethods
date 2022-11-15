#include<iostream>
#include<iomanip> /* setprecision */
#include<math.h> /* fabs */

// Fungsi f(x): x^3 + 2x^2 + 10 x = 20
#define f(x) pow(x, 3) + pow(2*x, 2) + 10*x - 20

using namespace std;

int main(){
    float x0, x1, x2, f0, f1, f2, e;
    int step = 1, N;

    cout << setprecision(6) << fixed;

    cout << "Masukkan x0 atau x(i-1): "; cin >> x0;
    cout << "Masukkan x1 atau x(i): "; cin >> x1;
    cout << "Masukkan error: "; cin >> e;
    cout << "Masukkan maksimum iterasi: "; cin >> N;

    cout << endl << "================" << endl;
    cout << "Metode Secant" << endl;
    cout << "================" << endl;

    do {
        f0 = f(x0); // f(x())
        f1 = f(x1);
        if (f0 == f1) {
            cout << "Error";
            exit(0);
        }

        x2 = x1 - ((x1 - x0) * f1)/(f1-f0);
        f2 = f(x2);

        cout << "Iterasi ke-" << step << ":\tx2 = " << setw(10) << x2 << " dan f(x2) = " << setw(10) << f(x2) << endl;
        // jadikan baru
        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;
        step++;

        if (step > N){
            cout << "Tidak konvergen.";
            exit(0);
        }
    } while (fabs(f2) > e);
    cout << endl << "Akarnya adalah: " << x2;
    return 0;
}
