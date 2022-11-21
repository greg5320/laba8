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
//    double arr[n][n];
    double **arr = new double *[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new double[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
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

void printmatrix(double **arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << fixed << setprecision(8) << scientific << arr[i][j] << " ";
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
    double **tempA = squarematrix(n, x);
    printmatrix(tempA, n, n);
    cout << endl;
    double **tempB = matrixB();
    printmatrix(tempB, 10, 10);
    delete[]tempA;
    delete[]tempB;
    return 0;
}