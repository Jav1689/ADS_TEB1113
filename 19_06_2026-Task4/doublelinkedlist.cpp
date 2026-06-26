#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node* prev;

    Node(string n) {
        name = n;
        next = NULL;
        prev = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Insert at the end
    void insertEnd(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    // Insert after a specific node
    void insertAfter(string afterName, string newName) {
        Node* current = head;

        while (current != NULL && current->name != afterName) {
            current = current->next;
        }

        if (current == NULL) {
            cout << afterName << " not found!" << endl;
            return;
        }

        Node* newNode = new Node(newName);
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    // Display forward
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* current = head;
        while (current != NULL) {
            cout << current->name;
            if (current->next != NULL) {
                cout << " <-> ";
            }
            current = current->next;
        }
        cout << endl;
    }

    // Display reverse
    void displayReverse() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        // Go to the last node
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        // Traverse backwards
        while (current != NULL) {
            cout << current->name;
            if (current->prev != NULL) {
                cout << " <-> ";
            }
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

    cout << "Initial list:" << endl;
    list.display();

    cout << "\nAfter inserting Ali after Anjana:" << endl;
    list.insertAfter("Anjana", "Ali");
    list.display();

    cout << "\nAfter inserting Jane at the end:" << endl;
    list.insertEnd("Jane");
    list.display();

    cout << "\nReverse list:" << endl;
    list.displayReverse();

    cout << "\nFinal list (in order):" << endl;
    list.display();

    return 0;
}