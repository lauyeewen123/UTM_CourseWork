// Lab 4 - SECJ2013 - 24251 (Lab4.cpp)
// Group Members:
// 1. LAU YEE WEN A23CS0099
// 2. GUI KAH SIN A23CS0080

#include <iostream>
#include <string>

using namespace std;

const int size = 5;

// Node class to implement circular linked-list type queue
class Node {
    private:
        char item;
        Node *next;

    public:
        Node(char c) { 
            item = c; 
            next = NULL;
        }

        void setNext(Node *n) { next = n; }
        Node *getNext() { return next; }
        char getItem() { return item; }

        ~Node() { cout << "Delete node-item " << item << "\n"; }
};

// Queue class header (array)
class Queue {
private:
    int front, rear;
    char items[size];
    int MAX_QUEUE = size; 
    int count;

public:
    void createQueue();
    void destroyQueue();
    void enQueue(char);
    char deQueue();
    bool isEmpty();
    bool isFull();
    char getFront();
    char getRear();
};

// Queue class implementation (array)
void Queue::createQueue() {
    front = 0;
    rear = -1;
}

void Queue::enQueue(char c) {
    cout << "Try to enqueue item " << c << " into the queue\n";
    
    if (!isFull()) {
        rear++;
        items[rear] = c;

    } else {
        cout << "Can't enqueue item " << c << ", queue is full!\n";
    }
}

char Queue::deQueue() {
    if (!isEmpty()) {
        char c = items[front];

        // rightward drifting
        for (int i = 1; i <= rear; i++) {
            items[i - 1] = items[i];
        }

        rear--;

        return c;

    } else {
        cout << "Can't dequeue item, queue is empty!\n";
        return ' ';
    }
}

bool Queue::isFull() {
    if (rear == size - 1)
        return true;
    else 
       return false;
}

bool Queue::isEmpty() {
    return rear < front;
}

char Queue::getFront() {
    if (!isEmpty()) {
        return items[front];
    } else {
        cout << "Can't get front item, queue is empty!\n";
        return ' ';
    }
}

char Queue::getRear() {
    if (!isEmpty()) {
        return items[rear];
    } else {
        cout << "Can't get rear item, queue is empty!\n";
        return ' ';
    }
}

// Main function section
int main() {
    Queue myQueue;

    myQueue.createQueue();

    myQueue.enQueue('A');
    myQueue.enQueue('B');
    myQueue.enQueue('C');
    myQueue.enQueue('D');
    myQueue.enQueue('E');
    myQueue.enQueue('F');
    myQueue.enQueue('G');

    cout << "\n";
    cout << "Front item: " << myQueue.getFront() << "\n";
    cout << "Rear item: " << myQueue.getRear() << "\n";
    
    cout << "\n";
    while (!myQueue.isEmpty()) {
        char delItem = myQueue.deQueue();
        cout <<  "dequeue item " << delItem << " from the queue\n";
    }

    myQueue.deQueue();

    cout << "\n";
    myQueue.enQueue('F');
    myQueue.enQueue('G');

    cout << "\n";
    cout << "Front item: " << myQueue.getFront() << "\n";
    cout << "Rear item: " << myQueue.getRear() << "\n";

    cout << "\n";
    while (!myQueue.isEmpty()) {
        char delItem = myQueue.deQueue();
        cout <<  "dequeue item " << delItem << " from the queue\n";
    }

    myQueue.deQueue();

    return 0;
}
