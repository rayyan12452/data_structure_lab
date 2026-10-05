#include <iostream>
using namespace std;

#define MAX 100


class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow\n";
        }
        else {
            if (front == -1)
                front = 0;

            rear++;
            arr[rear] = value;

            cout << value << " inserted into queue\n";
        }
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
        }
        else {
            cout << arr[front] << " deleted from queue\n";
            front++;
        }
    }

    void peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
        }
        else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
        }
        else {
            cout << "Queue: ";

            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }
};




class CircularQueue {
private:
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX - 1) ||
               (rear + 1 == front);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Circular Queue Overflow\n";
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % MAX;
        }

        arr[rear] = value;

        cout << value << " inserted into circular queue\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue Underflow\n";
            return;
        }

        cout << arr[front] << " deleted from circular queue\n";

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % MAX;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Circular Queue is empty\n";
        }
        else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Circular Queue is empty\n";
            return;
        }

        cout << "Circular Queue: ";

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }

        cout << endl;
    }
};



class Deque {
private:
    int arr[MAX];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX - 1) ||
               (front == rear + 1);
    }

   
    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else if (front == 0) {
            front = MAX - 1;
        }
        else {
            front--;
        }

        arr[front] = value;

        cout << value << " inserted at front\n";
    }


    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else if (rear == MAX - 1) {
            rear = 0;
        }
        else {
            rear++;
        }

        arr[rear] = value;

        cout << value << " inserted at rear\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }

        cout << arr[front] << " deleted from front\n";

        if (front == rear) {
            front = rear = -1;
        }
        else if (front == MAX - 1) {
            front = 0;
        }
        else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }

        cout << arr[rear] << " deleted from rear\n";

        if (front == rear) {
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = MAX - 1;
        }
        else {
            rear--;
        }
    }

    void getFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
        }
        else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void getRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
        }
        else {
            cout << "Rear element: " << arr[rear] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deque: ";

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }

        cout << endl;
    }
};


class PriorityQueue {
private:

    struct Element {
        int data;
        int priority;
    };

    Element arr[MAX];
    int size;

public:

    PriorityQueue() {
        size = 0;
    }

    void enqueue(int data, int priority) {

        if (size == MAX) {
            cout << "Priority Queue Overflow\n";
            return;
        }

        arr[size].data = data;
        arr[size].priority = priority;

        size++;

        cout << data << " inserted with priority "
             << priority << endl;
    }

    void dequeue() {

        if (size == 0) {
            cout << "Priority Queue Underflow\n";
            return;
        }

       
        int highest = 0;

        for (int i = 1; i < size; i++) {
            if (arr[i].priority > arr[highest].priority) {
                highest = i;
            }
        }

        cout << arr[highest].data
             << " deleted from priority queue\n";

        
        for (int i = highest; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    void peek() {

        if (size == 0) {
            cout << "Priority Queue is empty\n";
            return;
        }

        int highest = 0;

        for (int i = 1; i < size; i++) {
            if (arr[i].priority > arr[highest].priority) {
                highest = i;
            }
        }

        cout << "Highest priority element: "
             << arr[highest].data << endl;

        cout << "Priority: "
             << arr[highest].priority << endl;
    }

    void display() {

        if (size == 0) {
            cout << "Priority Queue is empty\n";
            return;
        }

        cout << "\nPriority Queue:\n";

        for (int i = 0; i < size; i++) {

            cout << "Data: "
                 << arr[i].data
                 << " | Priority: "
                 << arr[i].priority
                 << endl;
        }
    }
};



int main() {

    cout << "========== SIMPLE QUEUE ==========\n";

    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.peek();

    q.dequeue();

    q.display();


 
    cout << "\n========== CIRCULAR QUEUE ==========\n";

    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);

    cq.display();

    cq.dequeue();

    cq.display();

    cq.peek();


    cout << "\n========== DEQUE ==========\n";

    Deque dq;

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);

    dq.display();

    dq.getFront();
    dq.getRear();

    dq.deleteFront();
    dq.deleteRear();

    dq.display();


    
    cout << "\n========== PRIORITY QUEUE ==========\n";

    PriorityQueue pq;

    pq.enqueue(10, 2);
    pq.enqueue(20, 1);
    pq.enqueue(30, 3);

    pq.display();

    pq.peek();

    pq.dequeue();

    pq.display();

    return 0;
}