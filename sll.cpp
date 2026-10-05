#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:

    
    SinglyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int val) {

        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            newNode->next = head;
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
        temp->next = newNode;
    }
    void deleteAtBeginning() {

        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node* temp = head;

        head = head->next;

        delete temp;
    }

    void deleteAtEnd() {

        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;

        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;

        temp->next = nullptr;
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

        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Invalid position." << endl;
            return;
        }

        Node* nodeToDelete = temp->next;

        temp->next = nodeToDelete->next;

        delete nodeToDelete;
    }

    void reverseList() {

        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;

        while (current != nullptr) {

            nextNode = current->next;

            
            current->next = prev;

           
            prev = current;

            
            current = nextNode;
        }


        head = prev;
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
                cout << " -> ";
            }

            temp = temp->next;
        }

        cout << endl;
    }
};


int main() {

    SinglyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);

    list.insertAtBeginning(5);

    list.insertAtEnd(30);

    cout << "Original List: ";
    list.display();

    list.insertAtPosition(15, 3);

    cout << "After inserting 15 at position 3: ";
    list.display();


    list.deleteAtBeginning();

    cout << "After deleting at beginning: ";
    list.display();


    list.deleteAtEnd();

    cout << "After deleting at end: ";
    list.display();


    
    list.deleteAtPosition(2);

    cout << "After deleting position 2: ";
    list.display();


    list.reverseList();

    cout << "After reversing the list: ";
    list.display();


    return 0;
}