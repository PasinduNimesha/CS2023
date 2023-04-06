#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    private:
        Node* top;

    public:
        Stack() {
            top = nullptr;
        }

        void push(int x) {
            Node* newNode = new Node();
            newNode->data = x;
            newNode->next = top;
            top = newNode;
        }

        int pop() {
            if (isEmpty()) {
                cout << "Stack Underflow" << endl;
                return -1;
            }

            int poppedValue = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return poppedValue;
        }

        int peek() {
            if (isEmpty()) {
                cout << "Stack is Empty" << endl;
                return -1;
            }

            return top->data;
        }

        bool isEmpty() {
            return top == nullptr;
        }

        void display() {
            Node* current = top;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
};

int main() {
    auto start = high_resolution_clock::now();
    Stack s;

    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}