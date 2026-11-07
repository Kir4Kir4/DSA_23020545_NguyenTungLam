#include <iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;

    if (n <= 0) {
        cout << "So phan tu khong hop le!";
        return 0;
    }

    int *a = new int[n];

    cout << "Nhap day so:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bubbleSort(a, n);

    cout << "Day sau khi sap xep:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    delete[] a;
    return 0;
}