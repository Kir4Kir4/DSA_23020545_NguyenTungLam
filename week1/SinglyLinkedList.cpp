#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;
    
    // Đệ quy hỗ trợ duyệt ngược
    void traverseBackwardHelper(Node* node) {
        if (!node) return;
        traverseBackwardHelper(node->next);
        cout << node->data << " ";
    }

public:
    SinglyLinkedList() : head(nullptr) {}

    // 1. Truy cập - O(n)
    int access(int i) {
        Node* temp = head;
        for (int j = 0; temp != nullptr && j < i; j++) temp = temp->next;
        if (!temp) throw out_of_range("Lỗi: Vị trí không hợp lệ");
        return temp->data;
    }

    // 2. Thêm vào đầu - O(1)
    void insertFirst(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // 3. Thêm vào cuối - O(n)
    void insertLast(int val) { 
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // 4. Thêm vào vị trí i - O(n)
    void insertAt(int i, int val) { 
        if (i == 0) { insertFirst(val); return; }
        Node* temp = head;
        for (int j = 0; temp != nullptr && j < i - 1; j++) temp = temp->next;
        if (!temp) throw out_of_range("Lỗi: Vị trí không hợp lệ");
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // 5. Xóa đầu - O(1)
    void deleteFirst() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // 6. Xóa cuối - O(n)
    void deleteLast() { 
        if (!head) return;
        if (!head->next) { delete head; head = nullptr; return; }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    // 7. Xóa khỏi vị trí i - O(n)
    void deleteAt(int i) { 
        if (!head) return;
        if (i == 0) { deleteFirst(); return; }
        Node* temp = head;
        for (int j = 0; temp != nullptr && j < i - 1; j++) temp = temp->next;
        if (!temp || !temp->next) throw out_of_range("Lỗi: Vị trí không hợp lệ");
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // 8. Duyệt xuôi - O(n)
    void traverseForward() {
        Node* temp = head;
        while (temp) { cout << temp->data << " "; temp = temp->next; }
        cout << endl;
    }

    // 9. Duyệt ngược - O(n)
    void traverseBackward() { 
        traverseBackwardHelper(head);
        cout << endl;
    }
};