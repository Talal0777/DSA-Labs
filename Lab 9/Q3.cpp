#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

class Queue {
    Node *front, *rear;

public:
    Queue() : front(0), rear(0) {}

    void Enqueue(int data) {
        Node *newnode = new Node;
        newnode->value = data;
        newnode->next = 0;

        if (front == 0) {
            front = rear = newnode;
        } else {
            rear->next = newnode;
            rear = newnode;
        }
    }

    void DeQueue() {
        if (front == 0) {
            cout << "Queue is Empty" << endl;
            return;
        }

        Node *temp = front;
        front = front->next;
        delete temp;
    }

    void Display() {
        Node *temp = front;
        while (temp != 0) {
            cout << temp->value << "\t";
            temp = temp->next;
        }
        cout << endl;
    }

    void Clear() {
        while (front != 0) {
            DeQueue();
        }
        rear = 0;
        cout << "Queue has been cleared." << endl;
    }
};

int main() {
    Queue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    
    cout << "Queue after Enqueue:" << endl;
    q.Display();

    q.DeQueue();
    cout << "Queue after Dequeue:" << endl;
    q.Display();

    q.Clear();
    cout << "Queue after Clear:" << endl;
    q.Display();

    return 0;
}

