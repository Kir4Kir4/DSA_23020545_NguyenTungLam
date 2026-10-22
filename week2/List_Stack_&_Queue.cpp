#include <iostream>
using namespace std;

//  STACK 
class StackList {
private:
    int* arr;
    int capacity;
    int topIndex;

public:
    StackList(int cap = 10) : capacity(cap), topIndex(-1) {
        arr = new int[capacity];
    }
    
    ~StackList() { delete[] arr; }

    void push(int val) {
        if (topIndex == capacity - 1) { 
            capacity *= 2;
            int* newArr = new int[capacity];
            for (int i = 0; i <= topIndex; i++) newArr[i] = arr[i];
            delete[] arr;
            arr = newArr;
        }
        arr[++topIndex] = val;
    }

    void pop() {
        if (topIndex >= 0) topIndex--;
    }

    int top() {
        if (topIndex >= 0) return arr[topIndex];
        return -1; 
    }
};

// QUEUE
class QueueList {
private:
    int* arr;
    int capacity;
    int frontIdx;
    int rearIdx;
    int count;

public:
    QueueList(int cap = 10) : capacity(cap), frontIdx(0), rearIdx(-1), count(0) {
        arr = new int[capacity];
    }
    
    ~QueueList() { delete[] arr; }

    void enqueue(int val) {
        if (count == capacity) return;
        rearIdx = (rearIdx + 1) % capacity;
        arr[rearIdx] = val;
        count++;
    }

    void dequeue() {
        if (count == 0) return; 
        frontIdx = (frontIdx + 1) % capacity;
        count--;
    }

    int front() {
        if (count > 0) return arr[frontIdx];
        return -1; 
    }
};

int main() {
    cout << "Kiem tra Stack (List)" << endl;
    StackList myStack;
    myStack.push(10);
    myStack.push(20);
    cout << "Top hien tai: " << myStack.top() << endl; 
    myStack.pop();
    cout << "Top sau khi pop: " << myStack.top() << endl; 

    cout << "\nKiem tra Queue (List)" << endl;
    QueueList myQueue;
    myQueue.enqueue(100);
    myQueue.enqueue(200);
    cout << "Front hien tai: " << myQueue.front() << endl; 
    myQueue.dequeue();
    cout << "Front sau khi dequeue: " << myQueue.front() << endl; 

    return 0;
}



// Stack:
// 	Thêm (push): O(1).
// 	Xóa (pop): O(1).
// 	Xem đỉnh (top): O(1).

// Queue:
// 	Thêm (enqueue): O(1).
// 	Xóa (dequeue): O(1).
// 	Xem đầu (front): O(1).
