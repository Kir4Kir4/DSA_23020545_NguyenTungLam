#include <iostream>
#include <stdexcept>
using namespace std;

class ArrayList {
private:
    int* arr;
    int capacity;
    int size;

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
    }

public:
    ArrayList(int cap = 10) : capacity(cap), size(0) { arr = new int[capacity]; }
    ~ArrayList() { delete[] arr; }

    // 1. Truy cập - O(1)
    int access(int i) {
        if (i < 0 || i >= size) throw out_of_range("Lỗi: Vị trí không hợp lệ");
        return arr[i]; 
    }

    // 2. Thêm vào đầu - O(n)
    void insertFirst(int val) { 
        if (size == capacity) resize();
        for (int i = size; i > 0; i--) arr[i] = arr[i - 1];
        arr[0] = val;
        size++;
    }

    // 3. Thêm vào cuối - O(1) / O(n) khi đầy
    void insertLast(int val) { 
        if (size == capacity) resize();
        arr[size++] = val;
    }

    // 4. Thêm vào vị trí i - O(n)
    void insertAt(int i, int val) { 
        if (i < 0 || i > size) throw out_of_range("Lỗi: Vị trí không hợp lệ");
        if (size == capacity) resize();
        for (int j = size; j > i; j--) arr[j] = arr[j - 1];
        arr[i] = val;
        size++;
    }

    // 5. Xóa đầu - O(n)
    void deleteFirst() { 
        if (size == 0) return;
        for (int i = 0; i < size - 1; i++) arr[i] = arr[i + 1];
        size--;
    }

    // 6. Xóa cuối - O(1)
    void deleteLast() { 
        if (size == 0) return;
        size--;
    }

    // 7. Xóa khỏi vị trí i - O(n)
    void deleteAt(int i) { 
        if (i < 0 || i >= size) throw out_of_range("Lỗi: Vị trí không hợp lệ");
        for (int j = i; j < size - 1; j++) arr[j] = arr[j + 1];
        size--;
    }

    // 8. Duyệt xuôi - O(n)
    void traverseForward() { 
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }

    // 9. Duyệt ngược - O(n)
    void traverseBackward() { 
        for (int i = size - 1; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
    }
};