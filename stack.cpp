#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define MAX 100

// ================= STACK CLASS =================

class Stack {
private:
    int arr[MAX];
    int top;

public:

    // CONSTRUCTOR
    Stack() {
        top = -1;
    }

    // PUSH
    void push(int val) {

        if (top == MAX - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = val;
    }

    // POP
    int pop() {

        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        int value = arr[top];
        top--;

        return value;
    }

    // PEEK
    int peek() {

        if (top == -1) {
            return -1;
        }

        return arr[top];
    }

    // CHECK EMPTY
    bool isEmpty() {
        return top == -1;
    }

    // DISPLAY
    void display() {

        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack: ";

        for (int i = top; i >= 0; i--) {
            cout << arr[i];

            if (i != 0) {
                cout << " -> ";
            }
        }

        cout << endl;
    }
};


// ================= OPERATOR PRECEDENCE =================

int precedence(char op) {

    if (op == '+' || op == '-') {
        return 1;
    }

    if (op == '*' || op == '/') {
        return 2;
    }

    if (op == '^') {
        return 3;
    }

    return 0;
}


// ================= INFIX TO POSTFIX =================

string infixToPostfix(string infix) {

    Stack s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {

        char ch = infix[i];

        // Ignore spaces
        if (ch == ' ') {
            continue;
        }

        // If operand
        if (isalnum(ch)) {

            postfix += ch;
        }

        // If opening bracket
        else if (ch == '(') {

            s.push(ch);
        }

        // If closing bracket
        else if (ch == ')') {

            while (!s.isEmpty() && s.peek() != '(') {
                postfix += char(s.pop());
            }

            if (!s.isEmpty()) {
                s.pop(); // Remove '('
            }
        }

        // If operator
        else {

            while (!s.isEmpty() &&
                   s.peek() != '(' &&
                   precedence(s.peek()) >= precedence(ch)) {

                postfix += char(s.pop());
            }

            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.isEmpty()) {
        postfix += char(s.pop());
    }

    return postfix;
}


// ================= POSTFIX EVALUATION =================

int evaluatePostfix(string postfix) {

    Stack s;

    for (int i = 0; i < postfix.length(); i++) {

        char ch = postfix[i];

        // Ignore spaces
        if (ch == ' ') {
            continue;
        }

        // If operand
        if (isdigit(ch)) {

            s.push(ch - '0');
        }

        // If operator
        else {

            int b = s.pop();
            int a = s.pop();

            int result;

            switch (ch) {

                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                default:
                    result = 0;
            }

            s.push(result);
        }
    }

    return s.pop();
}




int main() {

    Stack stack;



    cout << "===== STACK OPERATIONS =====" << endl;

    stack.push(10);
    cout << "10 pushed into stack." << endl;

    stack.push(20);
    cout << "20 pushed into stack." << endl;

    stack.push(30);
    cout << "30 pushed into stack." << endl;

    stack.push(40);
    cout << "40 pushed into stack." << endl;

    cout << endl;

    stack.display();

    cout << endl;

    cout << "Top element: " << stack.peek() << endl;

    cout << endl;

    cout << stack.pop() << " popped from stack." << endl;
    cout << stack.pop() << " popped from stack." << endl;

    cout << endl;

    stack.display();

    cout << endl;




    cout << "===== INFIX TO POSTFIX =====" << endl;

    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "Postfix expression: " << postfix << endl;

    cout << endl;




    cout << "===== POSTFIX EVALUATION =====" << endl;

    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);

    cout << "Result: " << result << endl;


    return 0;
}