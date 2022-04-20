#include<iostream>
#include<iomanip> /* setprecision */
#include<math.h> /* fabs */

#define SIZE 10

using namespace std;

int main(){
    float a[SIZE][SIZE], x[SIZE], ratio;
    int i,j,k,n;

    cout << setprecision(3) << fixed;

    cout << "Masukkan ordo matriks (nxn): "; cin >> n;

    cout << "Masukkan koefisien: " << endl;
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n+1; j++){
            cout << "a[" << i << "][" << j << "] = "; cin >> a[i][j];
        }
    }

    // Augmentasi Matriks Identitas dari Ordo n x n
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            if (i == j){
                a[i][j+n] = 1;
            } else {
                a[i][j+n] = 0;
            }
        }
    }
    
    // Aplikasikan Eleminasi Gauss-Jordan
    for (i = 1; i <= n; i++){
        if (a[i][i] == 0.0) {
            cout << "Error";
            exit(0);
        }
        for (j = 1; j <= n; j++){
            if (i != j){
                ratio = a[j][i]/a[i][i];
                for (k = 1; k <= 2*n; k++){
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }

    // Operasikan baris untuk diagonal 1
    for (i = 1; i <= n; i++){
        for (j = n+1; j <= 2*n; j++){
            a[i][j] = a[i][j]/a[i][i];
        }
    }

    // Tampilkan Matriks Inverse
    cout << endl << "Matriks Inverse:" << endl;

    for (i = 1; i <= n; i++){
        for (j = n+1; j <= 2*n; j++){
            cout << a[i][j] << "\t";
        }
        cout << "-" << endl;
    }

    return(0);
}

// https://www.codesansar.com/numerical-methods/matrix-inverse-using-gauss-jordan-cpp-output.htm