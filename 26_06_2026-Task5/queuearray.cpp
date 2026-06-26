#include <iostream>
#include <string>

using namespace std;

class Queue {
public:
    string name;
    Queue* next = NULL;
    Queue* front = NULL;
    Queue* rear = NULL;

    void enqueue(string name) {
        Queue* newnode = new Queue();
        newnode->name = name;
        newnode->next = NULL;

        if (rear == NULL) {
            front = rear = newnode;
        } else {
            rear->next = newnode;
            rear = newnode;
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        Queue* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }
    string peek() {
        if (front == NULL) {
            cout << "Queue is empty! Nothing to peek." << endl;
            return "";
        }
        return front->name;
    }

    void display_queue() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Queue* display_node = front;
        cout << "Queue (front to rear): ";
        while (display_node != NULL) {
            cout << display_node->name;
            if (display_node->next != NULL) {
                cout << " -> ";
            }
            display_node = display_node->next;
        }
        cout << endl;
    }
};

int main() {
    Queue* queue = new Queue();

    cout << "\nEnqueuing"<< endl;
    queue->enqueue("A");
    queue->enqueue("B");
    queue->enqueue("C");
    queue->enqueue("D");
    queue->display_queue();

    cout << "\nPeek (front element): " << queue->peek() << endl;
    
    cout << "\nDequeuing once:" << endl;
    queue->dequeue();
    queue->display_queue();

    cout << "\nPeek after dequeue: " << queue->peek() << endl;

    cout << "\nDequeuing all elements:" << endl;
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    queue->display_queue();

    delete queue;
    return 0;
}