#include <iostream>
using namespace std;

int partition(int a[], int l, int r) {
    int pivot = a[r], i = l - 1;
    for (int j = l; j < r; j++)
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quickSort(int a[], int l, int r) {
    if (l >= r) return;
    int p = partition(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}

int main() {
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    if (n <= 0) return 0;

    int *a = new int[n];
    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    quickSort(a, 0, n - 1);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";

    delete[] a;
    return 0;
}