#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    string name;
    Node* next; //memory address of the next node

    Node(string n) {
        name = n;
        next = nullptr;
    }
};
class LinkedList {
public:
    Node* head; //address of the first node

    LinkedList() {
        head = nullptr; //empty list
    }

    void insertEnd(string name) { //insert at the end
        Node* newNode = new Node(name);

        if (head == nullptr) {
            //meaning that the list is empty
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void insertAfter(string afterName, string newName) {
        Node* current = head;

        while (current != nullptr && current->name != afterName) {
            current = current->next;
            //find the position to be inserted
        }

        if (current == nullptr) {
            cout << afterName << "not found." << endl;
            return;
        }

        Node* newNode = new Node(newName);
        newNode->next = current->next;
        //Ali points to what Anjana is pointing
        current->next = newNode;
        //Anjana now points to Ali
    }

    //delete a node by the name
    void deleteByName (string name) {
        if (head == nullptr) {
            return; //empty list
        }
        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        // search the rest of the list
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->name == name) {
                Node* temp = current->next; //using this mean assigned the address to temp
                current->next = temp->next;
                delete temp;
                return;
            }
            current = current->next; //keep looping to find the matching name
        }
    }

    //display the linked list
    void display() {
        Node* current = head;
        if (current == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        while (current != nullptr) {
            cout << current->name << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;

    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

     cout << "Initial list:" << endl;
    list.display();

    list.insertAfter("Anjana","Ali");

    // insert Ahmad at the end
    list.insertEnd("Ahmad");

    // delete Anjana
    list.deleteByName("Jessy");

    cout << "\nFinal list:" << endl;
    list.display();
}
