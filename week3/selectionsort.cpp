#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
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

    selectionSort(a, n);

    cout << "Day sau khi sap xep:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    delete[] a;
    return 0;
}