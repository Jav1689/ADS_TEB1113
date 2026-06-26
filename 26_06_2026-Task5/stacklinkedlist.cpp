#include <iostream>
#include <string>

using namespace std;

class Stack{
public:
    string name;
    Stack* next = NULL;
    Stack* top = NULL;

    void push(string name){
        Stack* newnode = new Stack();
        newnode->name = name;
        newnode->next = top;
        top = newnode;
    }

    void pop(){
        if(top == NULL){
            cout << "Stack is empty! Cannot pop." << endl;
            return;
        }
        Stack* temp = top;
        top = top->next;
        delete temp;
    }

    string peek(){
        if(top == NULL){
            cout << "Stack is empty! Nothing to peek." << endl;
            return "";
        }
        return top->name;
    }

    void display_stack(){
        Stack* display_node = top;
        while(display_node != NULL){
            cout << display_node->name << endl;
            display_node = display_node->next;
        }
    }
};

int main() {
    Stack* stack = new Stack();

    stack->push("A");
    stack->push("B");
    stack->push("C");
    stack->push("D");

    cout << "Current stack (top to bottom):" << endl;
    stack->display_stack();

    cout << "\nPeek: " << stack->peek() << endl;

    cout << "\nPopping once:" << endl;
    stack->pop();
    stack->display_stack();

    cout << "\nPeek after pop: " << stack->peek() << endl;

    cout << "\nPopping all elements:" << endl;
    stack->pop();
    stack->pop();
    stack->pop();
    stack->display_stack();

    cout << "\nTrying to pop from empty stack:" << endl;
    stack->pop();

    cout << "\nTrying to peek empty stack:" << endl;
    stack->peek();

    delete stack;
    return 0;
}