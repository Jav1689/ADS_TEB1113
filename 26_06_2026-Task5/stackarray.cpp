#include <iostream>
#include <string>

using namespace std;

class Queue {
private:
    static const int MAX_SIZE = 100;
    string arr[MAX_SIZE];
    int front_index;
    int rear_index;
    int current_size;

public:
    Queue() {
        front_index = 0;
        rear_index = -1;
        current_size = 0;
    }

    void enqueue(string name) {
        if (current_size == MAX_SIZE) {
            cout << "Queue is full! Cannot enqueue." << endl;
            return;
        }
        rear_index = (rear_index + 1) % MAX_SIZE;
        arr[rear_index] = name;
        current_size++;
    }

    void dequeue() {
        if (current_size == 0) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        front_index = (front_index + 1) % MAX_SIZE;
        current_size--;
    }

    void display_queue() {
        if (current_size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue (front to rear): ";
        int count = 0;
        int index = front_index;
        while (count < current_size) {
            cout << arr[index];
            if (count < current_size - 1) {
                cout << " -> ";
            }
            index = (index + 1) % MAX_SIZE;
            count++;
        }
        cout << endl;
    }
};

int main() {
    Queue* queue = new Queue();

    queue->enqueue("A");
    queue->enqueue("B");
    queue->enqueue("C");
    queue->enqueue("D");
    queue->display_queue();

    queue->dequeue();
    queue->display_queue();

    queue->dequeue();
    queue->display_queue();

    delete queue;
    return 0;
}