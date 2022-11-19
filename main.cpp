#include <math.h> /* fabs */

#include <iomanip> /* setprecision & setw */
#include <iostream>
using namespace std;

// Fungsi f(x): x^3 + 2x^2 + 10 x = 20
#define f(x) pow(x, 3) + pow(2 * x, 2) + 10 * x - 20

// Turunan fungsi f(x) sebagai g(x): 3x^2 + 4x + 10
#define g(x) pow(3 * x, 2) + 4 * x + 10

void newtonRaphson() {
    float x0, x1, f0, f1, g0, e;
    int iterasi = 1, N;

    // 6 digit dibelakang koma
    cout << setprecision(6) << fixed;

    cout << "=======================================" << endl;
    cout << "======== Metode Newton-Raphson ========" << endl;
    cout << "=======================================" << endl;

    // Input
    cout << "Masukkan nilai x0: ";
    cin >> x0;
    cout << "Masukkan toleransi error: ";
    cin >> e;
    cout << "Masukkan maksimum iterasi: ";
    cin >> N;

    do {
        g0 = g(x0);
        if (g0 == 0.0) {
            cout << "Error";
            return;
        }

        f0 = f(x0);

        // Metode Newton Raphson Xn+1 = Xn - {f(Xn)/f'(Xn)}
        x1 = x0 - f0 / g0;

        cout << "Iterasi ke-" << iterasi << ":\tx =" << setw(10);
        cout << x1 << " dan f(x) =" << setw(10) << f(x1) << endl;

        x0 = x1;

        iterasi++;

        if (iterasi > N) {
            cout << "Tidak konvergen (tidak mendekati titik temu).";
            return;
        }

        f1 = f(x1);
    } while (fabs(f1) > e);
}

void secant() {
    float x0, x1, x2, f0, f1, f2, e;
    int step = 1, N;

    cout << setprecision(6) << fixed;

    cout << "Masukkan x0 atau x(i-1): ";
    cin >> x0;
    cout << "Masukkan x1 atau x(i): ";
    cin >> x1;
    cout << "Masukkan error: ";
    cin >> e;
    cout << "Masukkan maksimum iterasi: ";
    cin >> N;

    cout << endl << "================" << endl;
    cout << "Metode Secant" << endl;
    cout << "================" << endl;

    do {
        f0 = f(x0);  // f(x())
        f1 = f(x1);
        if (f0 == f1) {
            cout << "Error";
            return;
        }

        x2 = x1 - ((x1 - x0) * f1) / (f1 - f0);
        f2 = f(x2);

        cout << "Iterasi ke-" << step << ":\tx2 = " << setw(10) << x2
             << " dan f(x2) = " << setw(10) << f(x2) << endl;
        // jadikan baru
        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;
        step++;

        if (step > N) {
            cout << "Tidak konvergen.";
            return;
        }
    } while (fabs(f2) > e);
    cout << endl << "Akarnya adalah: " << x2;
}

#define SIZE 10

void gauss() {
    float a[SIZE][SIZE], x[SIZE], ratio;
    int i, j, k, n;

    cout << setprecision(3) << fixed;

    cout << "Enter number of unknowns: ";
    cin >> n;

    cout << "Masukkan koefisien: " << endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n + 1; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    for (i = 1; i <= n - 1; i++) {
        if (a[i][i] == 0.0) {
            cout << "Error";
            return;
        }
        for (j = i + 1; j <= n; j++) {
            ratio = a[j][i] / a[i][i];
            for (k = 1; k <= n + 1; k++) {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }

    x[n] = a[n][n + 1] / a[n][n];

    for (i = n - 1; i >= 1; i--) {
        x[i] = a[i][n + 1];
        for (j = i + 1; j <= n; j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    cout << endl << "Solution: " << endl;
    for (i = 1; i <= n; i++) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }
}

void inverseGauss() {
    float a[SIZE][SIZE], x[SIZE], ratio;
    int i, j, k, n;

    cout << setprecision(3) << fixed;

    cout << "Masukkan ordo matriks (nxn): ";
    cin >> n;

    cout << "Masukkan koefisien: " << endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n + 1; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    // Augmentasi Matriks Identitas dari Ordo n x n
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) {
                a[i][j + n] = 1;
            } else {
                a[i][j + n] = 0;
            }
        }
    }

    // Aplikasikan Eleminasi Gauss-Jordan
    for (i = 1; i <= n; i++) {
        if (a[i][i] == 0.0) {
            cout << "Error";
            return;
        }
        for (j = 1; j <= n; j++) {
            if (i != j) {
                ratio = a[j][i] / a[i][i];
                for (k = 1; k <= 2 * n; k++) {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }

    // Operasikan baris untuk diagonal 1
    for (i = 1; i <= n; i++) {
        for (j = n + 1; j <= 2 * n; j++) {
            a[i][j] = a[i][j] / a[i][i];
        }
    }

    // Tampilkan Matriks Inverse
    cout << endl << "Matriks Inverse:" << endl;

    for (i = 1; i <= n; i++) {
        for (j = n + 1; j <= 2 * n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << "-" << endl;
    }
}

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
#define f1(w, x, y, z) 10 - 2 * x - 3 * y + z
#define f2(w, x, y, z) (8 - 2 * w - 4 * y - 8 * z) / 5
#define f3(w, x, y, z) (-2 - 4 * w - 2 * x - z) / 2
#define f4(w, x, y, z) (4 - 6 * w - 4 * x + y) / -2

void jacobi() {
    float w0 = 0.0, x0 = 0.0, y0 = 0.0, z0 = 0.0;
    float w1, x1, y1, z1, e1, e2, e3, e4, e;
    int iterasi = 1;

    // Presisi 6 digit desimal di belakang koma
    cout << setprecision(6) << fixed;

    // Input Error
    cout << "Masukkan error: ";
    cin >> e;

    // Judul
    cout << endl << "Iterasi\tw\t\tx\t\ty\t\tz" << endl;

    // Proses Iterasi Jacobi
    do {
        w1 = f1(w0, x0, y0, z0);
        x1 = f2(w0, x0, y0, z0);
        y1 = f3(w0, x0, y0, z0);
        z1 = f4(w0, x0, y0, z0);
        cout << iterasi << "\t" << w1 << "\t" << x1 << "\t" << y1 << "\t" << z1
             << endl;

        e1 = fabs(w0 - w1);
        e2 = fabs(x0 - x1);
        e3 = fabs(y0 - y1);
        e4 = fabs(z0 - z1);

        iterasi++;

        w0 = w1;
        x0 = x1;
        y0 = y1;
        z0 = z1;

    } while (e1 > e && e2 > e && e3 > e);
    cout << endl << "Akar Persamaan:" << endl;
    cout << "w = " << w1 << endl << "x = " << x1 << endl;
    cout << "y = " << y1 << endl << "z = " << z1;
}

int main() {
    cout << "\n\n******** START ********";
    while (true) {
        cout << "\n\n---- Menu -----\n\n"
             << "\n1. Newton-Raphson"
             << "\n2. Secant"
             << "\n3. Gauss-Jordan"
             << "\n4. Inverse with Gauss-Jordan"
             << "\n5. Jacobi"
             << "\n6. Quit";

        cout << "\n\nChoose(1 - 6): ";
        int choice;
        cin >> choice;

        while (choice < 1 or choice > 6) {
            cout << "\n\nInvalid option. Choose from (1 - 6)!!!";
            cout << "\n\nChoose(1 - 6): ";
            cin >> choice;
        }

        if (choice == 6) {
            cout << "\n\n******** END ***********\n";
            break;
        }

        switch (choice) {
            case 1:
                newtonRaphson();
                break;
            case 2:
                secant();
                break;
            case 3:
                gauss();
                break;
            case 4:
                inverseGauss();
                break;
            case 5:
                jacobi();
                break;
        }
    }
    return 0;
}
