#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

class Queue {
    Node *front, *rear;
    int size;
    const int maxSize;

public:
    Queue(int maxSize) : front(0), rear(0), size(0), maxSize(maxSize) {}

    void Enqueue(int data) {
        if (size >= maxSize) {
            cout << "Queue Overflow: Unable to enqueue " << data << endl;
            return;
        }

        Node *newnode = new Node;
        newnode->value = data;
        newnode->next = 0;

        if (front == 0) {
            front = rear = newnode;
        } else {
            rear->next = newnode;
            rear = newnode;
        }
        size++;
    }

    void DeQueue() {
        if (front == 0) {
            cout << "Queue is Empty" << endl;
            return;
        }

        Node *temp = front;
        front = front->next;
        delete temp;
        size--;
    }

    void Display() {
        Node *temp = front;
        while (temp != 0) {
            cout << temp->value << "\t";
            temp = temp->next;
        }
        cout << endl;
    }

    int getSize() {
        return size;
    }
};

int main() {
    const int maxQueueSize = 4;
    Queue q(maxQueueSize);

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50); 

    cout << "Queue after Enqueue:" << endl;
    q.Display();

    q.DeQueue();
    cout << "Queue after Dequeue:" << endl;
    q.Display();

    return 0;
}

