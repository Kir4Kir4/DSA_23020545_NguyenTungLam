#include <iostream>
using namespace std;

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
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

    insertionSort(a, n);

    cout << "Day sau khi sap xep:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    delete[] a;
    return 0;
}