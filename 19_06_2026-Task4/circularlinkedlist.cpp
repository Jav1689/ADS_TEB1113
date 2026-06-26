#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string name;
    Node* next = NULL;
    Node* prev = NULL;

    Node(string n) {
        name = n;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr; //empty list
    }

    void insertEnd(string name) { //insert at the end
        Node* newNode = new Node(name);

        if (head == nullptr) { //Empty list
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }
        Node* tail = head->prev;

        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    void insertAfter(string afterName, string newName) {
        Node* current = head;

        while (current != nullptr && current->name != afterName) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << afterName << "not found." << endl;
            return;
        }

        Node* newNode = new Node(newName);
        newNode->next = current->next;

        newNode->prev = current;

        if (current->next != head) {
            current->next->prev = newNode;

        }
        current->next = newNode;
    }

    void deleteByName (string name) {
        if (head == nullptr) {
            return; //empty list
        }
        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }

            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != head) {
            if (current->next->name == name) {
                Node* temp = current->next;
                current->next = temp->next;

                if (temp->next != head) {
                    temp->next->prev = current;

                }
                else {
                    head->prev = current;
                }
                delete temp;
                return;
            }
            current = current->next;
        }
    }
    //display the linked list
    void display() {
        Node* current = head;
        if (current == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        do {
            cout << current->name << endl;
            current = current->next;
        } while (current != head);
    }

    void displayReverse() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* current = head->prev;
        do {
            cout << current->name << endl;
            current = current->prev;
        } while (current != head->prev);
    }
};

int main() {
    LinkedList list;
    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");
    cout << "\nInitial list:" << endl;
    list.display();
    cout << "\nAfter inserting Ali after Anjana:" << endl;
    list.insertAfter("Anjana","Ali");
    list.display();
    cout << "\nAfter inserting Jane at the end:" << endl;
    list.insertEnd("Jane");
    list.display();
    cout << "\nAfter deleting Jessy:" << endl;
    list.deleteByName("Jessy");
    list.display();
    cout << "\nReverse linkedlist:" << endl;
    list.displayReverse();
    cout << "\nFinal list (in order):" << endl;
    list.display();
}
