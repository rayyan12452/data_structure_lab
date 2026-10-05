#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:

    DoublyLinkedList() {
        head = nullptr;
    }

   
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    
    void insertAtPosition(int val, int pos) {

        if (pos < 1) {
            cout << "Invalid position." << endl;
            return;
        }

      
        if (pos == 1) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position." << endl;
            return;
        }

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }

    void deleteAtBeginning() {

        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node* temp = head;

        if (head->next == nullptr) {
            head = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
    }


    void deleteAtEnd() {

        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node* temp = head;


        if (head->next == nullptr) {
            head = nullptr;
            delete temp;
            return;
        }

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->prev->next = nullptr;

        delete temp;
    }

    
    void deleteAtPosition(int pos) {

        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        if (pos < 1) {
            cout << "Invalid position." << endl;
            return;
        }

        if (pos == 1) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position." << endl;
            return;
        }

       
        temp->prev->next = temp->next;

       
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void display() {

        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        while (temp != nullptr) {

            cout << temp->data;

            if (temp->next != nullptr) {
                cout << " <-> ";
            }

            temp = temp->next;
        }

        cout << endl;
    }
};


int main() {

    DoublyLinkedList dll;


    dll.insertAtEnd(10);
    dll.insertAtEnd(20);

    dll.insertAtBeginning(5);

    dll.insertAtEnd(30);

    cout << "Original List: ";
    dll.display();


    dll.insertAtPosition(15, 3);

    cout << "After inserting 15 at position 3: ";
    dll.display();


    dll.deleteAtBeginning();

    cout << "After deleting at beginning: ";
    dll.display();


    dll.deleteAtEnd();

    cout << "After deleting at end: ";
    dll.display();


    
    dll.deleteAtPosition(2);

    cout << "After deleting position 2: ";
    dll.display();


    return 0;
}