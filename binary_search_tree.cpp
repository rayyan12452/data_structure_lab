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



class BST {
private:
    Node* root;

    Node* deleteNode(Node* node, int value) {

        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        }

        else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        }

    
        else {

            
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }

            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            
            else {

                Node* successor = node->right;

                while (successor->left != nullptr) {
                    successor = successor->left;
                }

                
                node->data = successor->data;

                node->right =
                    deleteNode(node->right, successor->data);
            }
        }

        return node;
    }

public:

    
    BST() {
        root = nullptr;
    }



    void insert(int value) {

        Node* newNode = new Node(value);

        if (root == nullptr) {
            root = newNode;
            cout << "Node inserted successfully.\n";
            return;
        }

        Node* current = root;

        while (true) {


            if (value < current->data) {

                if (current->left == nullptr) {
                    current->left = newNode;
                    cout << "Node inserted successfully.\n";
                    return;
                }

                current = current->left;
            }


            else if (value > current->data) {

                if (current->right == nullptr) {
                    current->right = newNode;
                    cout << "Node inserted successfully.\n";
                    return;
                }

                current = current->right;
            }

            
            else {
                cout << "Duplicate value not allowed.\n";
                delete newNode;
                return;
            }
        }
    }


    
    void search(int value) {

        Node* current = root;

        while (current != nullptr) {

            if (value == current->data) {
                cout << value << " found in BST.\n";
                return;
            }

            else if (value < current->data) {
                current = current->left;
            }

            else {
                current = current->right;
            }
        }

        cout << value << " not found in BST.\n";
    }



    void deleteValue(int value) {

        if (root == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }

        
        Node* current = root;

        while (current != nullptr) {

            if (current->data == value) {
                root = deleteNode(root, value);
                cout << value << " deleted successfully.\n";
                return;
            }

            else if (value < current->data) {
                current = current->left;
            }

            else {
                current = current->right;
            }
        }

        cout << value << " not found in BST.\n";
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

        stack<Node*> st1;
        stack<Node*> st2;

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

    BST tree;

    int choice;
    int value;

    do {

        cout << "\n=====================================\n";
        cout << "       BINARY SEARCH TREE MENU       \n";
        cout << "=====================================\n";
        cout << "1. Insert Node\n";
        cout << "2. Search Node\n";
        cout << "3. Delete Node\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Exit\n";
        cout << "=====================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value to insert: ";
            cin >> value;

            tree.insert(value);
            break;


        case 2:
            cout << "Enter value to search: ";
            cin >> value;

            tree.search(value);
            break;


        case 3:
            cout << "Enter value to delete: ";
            cin >> value;

            tree.deleteValue(value);
            break;


        case 4:
            cout << "Inorder Traversal: ";
            tree.inorder();
            break;


        case 5:
            cout << "Preorder Traversal: ";
            tree.preorder();
            break;


        case 6:
            cout << "Postorder Traversal: ";
            tree.postorder();
            break;


        case 7:
            cout << "Program terminated.\n";
            break;


        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}