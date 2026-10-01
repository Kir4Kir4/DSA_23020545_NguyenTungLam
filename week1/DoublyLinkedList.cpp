#include <iostream>
#include <stdexcept>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // 1. Truy cập - O(n)
    int access(int i) { 
        DNode* temp = head;
        for (int j = 0; temp != nullptr && j < i; j++) temp = temp->next;
        if (!temp) throw out_of_range("Lỗi: Vị trí không hợp lệ");
        return temp->data;
    }

    // 2. Thêm vào đầu - O(1)
    void insertFirst(int val) { 
        DNode* newNode = new DNode(val);
        if (!head) { head = tail = newNode; }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // 3. Thêm vào cuối - O(1)
    void insertLast(int val) { 
        DNode* newNode = new DNode(val);
        if (!tail) { head = tail = newNode; }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // 4. Thêm vào vị trí i - O(n)
    void insertAt(int i, int val) { 
        if (i == 0) { insertFirst(val); return; }
        DNode* temp = head;
        for (int j = 0; temp != nullptr && j < i - 1; j++) temp = temp->next;
        if (!temp) throw out_of_range("Lỗi: Vị trí không hợp lệ");
        if (temp == tail) { insertLast(val); return; }

        DNode* newNode = new DNode(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // 5. Xóa đầu - O(1)
    void deleteFirst() { 
        if (!head) return;
        DNode* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr; // Nếu danh sách rỗng sau khi xóa
        delete temp;
    }

    // 6. Xóa cuối - O(1)
    void deleteLast() { 
        if (!tail) return;
        DNode* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr; // Nếu danh sách rỗng sau khi xóa
        delete temp;
    }

    // 7. Xóa khỏi vị trí i - O(n)
    void deleteAt(int i) { 
        if (!head) return;
        if (i == 0) { deleteFirst(); return; }
        DNode* temp = head;
        for (int j = 0; temp != nullptr && j < i; j++) temp = temp->next;
        if (!temp) throw out_of_range("Lỗi: Vị trí không hợp lệ");
        if (temp == tail) { deleteLast(); return; }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    // 8. Duyệt xuôi - O(n)
    void traverseForward() { 
        DNode* temp = head;
        while (temp) { cout << temp->data << " "; temp = temp->next; }
        cout << endl;
    }

    // 9. Duyệt ngược - O(n)
    void traverseBackward() { 
        DNode* temp = tail;
        while (temp) { cout << temp->data << " "; temp = temp->prev; }
        cout << endl;
    }
};