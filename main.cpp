#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int factorial(int x) {
    if (x == 0)
        return 1;
    else
        return x * factorial(x - 1);
}

double **squarematrix(int n, float x) {
    double **arr = new double *[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new double[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i > j) || (i < j)) {
                if (i > j)
                    arr[i][j] = pow(x, i) / (pow(factorial(j), i));
                else if (i < j)
                    arr[i][j] = pow(-x, i) / (pow(factorial(j), i));
            } else
                arr[i][j] = 1;
        }
    }
    return arr;
}

double **rectanglematrix(int n, int m, float x) {
    double **arr = new double *[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new double[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i > j) || (i < j)) {
                if (i > j)
                    x = pow(x, i) / (pow(factorial(j), i));
                else if (i < j)
                    x = pow(-x, i) / (pow(factorial(j), i));
            } else
                x = 1;
            arr[i][j] = x;
        }
    }
    return arr;
}

double **matrixB() {
    double **arr = new double *[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = new double[10];
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = i * 10 + j;
        }
    }
    return arr;
}

void printmatrixA(double **arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << fixed << setw(16) << setprecision(8) << scientific << arr[i][j] << " ";
        cout << endl;
    }
}

void printmatrixB(double **arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << fixed << setw(4) << setprecision(0) << arr[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int n;
    float x;
    cout << "Введите размер матрицы " << endl;
    cin >> n;
    cout << "Введите значение x " << endl;
    cin >> x;
    double **A = squarematrix(n, x);
    printmatrixA(A, n, n);
    cout << endl;
    double **B = matrixB();
    printmatrixB(B, 10, 10);
    cout << endl;
    delete[]A;
    cout << B << "  " << B[0] << "  " << B[2] << endl;
    cout << B[0][0] << "  " << **B << "  " << *B[0] << endl; //
    cout << *(*(B + 1)) << "  " << *B[1] << endl;
    cout << *(B[0] + 1) << "  " << *(*B + 1) << endl;
    cout << B[0][20] << "  " << *(B[0] + 20) << "  " << *B[2] << endl;
    delete[]B;
    return 0;
}
