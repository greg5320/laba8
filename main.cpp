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

int privet(int x) {
    cout << "Привет " << x << endl;
}

int HappyNewYear(int a) {
    cout << a;
}

int main() {
    int n;
    cin >> n;
    int arr[n][n];
    float c = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i > j) || (i < j)) {
                if (i > j)
                    c = pow(c, i) / (pow(factorial(j), i));
                else if (i < j)
                    c = pow(-c, i) / (pow(factorial(j), i));
            } else
                c = 1;
            arr[i][j] = c;
            cout << fixed << setprecision(2) << c << " ";
        }
        cout << endl;
    }
    return 0;
}