#include <iostream>
using namespace std;

// Cấu trúc Node cho cả Stack và Queue
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// STACK 
class StackLinkedList {
private:
    Node* head;

public:
    StackLinkedList() : head(nullptr) {}

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int top() {
        if (head) return head->data;
        return -1; 
    }
};

// QUEUE 
class QueueLinkedList {
private:
    Node* head; 
    Node* tail; 

public:
    QueueLinkedList() : head(nullptr), tail(nullptr) {}

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void dequeue() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (!head) tail = nullptr; 
        delete temp;
    }

    int front() {
        if (head) return head->data;
        return -1;
    }
};

int main() {
    cout << " Kiem tra Stack " << endl;
    StackLinkedList myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    
    cout << "Phan tu tren cung (top): " << myStack.top() << endl;
    myStack.pop(); 
    cout << "Top sau khi pop: " << myStack.top() << endl;       


    cout << "\n Kiem tra Queue " << endl;
    QueueLinkedList myQueue;
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    
    cout << "Phan tu dau hang (front): " << myQueue.front() << endl; 
    myQueue.dequeue(); 
    cout << "Front sau khi dequeue: " << myQueue.front() << endl;    

    return 0;
}

// Stack:
// 	Thêm phần tử (push): O(1) - Chèn Node mới vào đầu danh sách (vị trí head).
// 	Xóa phần tử (pop): O(1) - Xóa Node hiện tại ở đầu danh sách (head).
// 	Xem phần tử trên cùng (top): O(1) - Truy cập trực tiếp giá trị của con trỏ head.

// Queue:
// 	Thêm phần tử (enqueue): O(1) - Nhờ có con trỏ tail, việc chèn một Node mới vào cuối danh sách liên kết không cần phải duyệt qua toàn bộ các phần tử.
// 	Xóa phần tử (dequeue): O(1) - Xóa Node ở đầu danh sách (head).
// 	Xem phần tử đầu tiên (front): O(1) - Truy cập trực tiếp giá trị của con trỏ head.
