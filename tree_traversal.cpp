#include <iostream>
#include <stack>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};


class BinaryTree {
private:
    Node* root;

public:
    
    BinaryTree() {
        root = nullptr;
    }

    
    void insert(int value) {
        Node* newNode = new Node(value);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;

        while (true) {
            if (value < current->data) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    return;
                }
                current = current->left;
            }
            else {
                if (current->right == nullptr) {
                    current->right = newNode;
                    return;
                }
                current = current->right;
            }
        }
    }

    void inorder() {
        if (root == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }

        stack<Node*> st;
        Node* current = root;

        while (current != nullptr || !st.empty()) {

            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }

            current = st.top();
            st.pop();

            cout << current->data << " ";

            current = current->right;
        }

        cout << endl;
    }


    void preorder() {
        if (root == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }

        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {

            Node* current = st.top();
            st.pop();

            cout << current->data << " ";

            
            if (current->right != nullptr)
                st.push(current->right);


            if (current->left != nullptr)
                st.push(current->left);
        }

        cout << endl;
    }

    void postorder() {
        if (root == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }

        stack<Node*> st1, st2;

        st1.push(root);

        while (!st1.empty()) {

            Node* current = st1.top();
            st1.pop();

            st2.push(current);

            if (current->left != nullptr)
                st1.push(current->left);

            if (current->right != nullptr)
                st1.push(current->right);
        }

        while (!st2.empty()) {
            cout << st2.top()->data << " ";
            st2.pop();
        }

        cout << endl;
    }
};

int main() {

    BinaryTree tree;

    int choice;
    int value;

    do {
        cout << "\n========== TREE MENU ==========\n";
        cout << "1. Insert Node\n";
        cout << "2. Inorder Traversal (Non-Recursive)\n";
        cout << "3. Preorder Traversal (Non-Recursive)\n";
        cout << "4. Postorder Traversal (Non-Recursive)\n";
        cout << "5. Exit\n";
        cout << "===============================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            tree.insert(value);
            cout << "Node inserted successfully.\n";
            break;

        case 2:
            cout << "Inorder Traversal: ";
            tree.inorder();
            break;

        case 3:
            cout << "Preorder Traversal: ";
            tree.preorder();
            break;

        case 4:
            cout << "Postorder Traversal: ";
            tree.postorder();
            break;

        case 5:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}