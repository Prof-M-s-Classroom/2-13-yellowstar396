#include <iostream>
using namespace std;

class student {
public:
    string name;
    int age;

    student(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void print() { cout << name << " " << age << endl; }
};

template <typename T> class Node {
public:
    T *value;
    Node<T> *next;
    Node(T *value) {
        this->value = value;
        this->next = NULL;
    }
    void print() { value->print(); }
};

template <typename T> class LinkedList {
private:
    int length;
    Node<T> *head;

public:
    LinkedList(T *value) {
        this->length = 1;
        this->head = new Node<T>(value);
    }
    ~LinkedList() {
        Node<T>* current = this->head;
        while (head) {
            head = head->next;
            delete current;
            current = head;
        }
    }
    void add(T *value) {
        Node<T> *newNode = new Node<T>(value);
        Node<T> *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        length++;
    }

    void addhead(T *value) {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        length++;
    }

    void delfirst() {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void dellast() {
        Node<T> *temp = head;
        while (temp->next!=NULL)
            temp = temp->next;
        delete temp;
        length--;
    }

    //TODO:Write the function to delete at the given index. Reuse the pre-written functions for edge cases. Account for missing index.
    void deleteNode(int index) {
        if (index<0 || index>this->length) {
            cout<<"index out of range"<<endl;
            throw "index out of bounds";
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        Node<T>* temp2 = temp;
        temp = temp->next;
        delete temp2;
        length--;
    }

    //TODO:Write a function to insert a new node at a give index. Reuse the pre-written functions for edge cases. Account for missing index
    void insert(int index, T *value) {
        if (index<0 || index>this->length) {
            cout<<"index out of range"<<endl;
            throw "index out of bounds";
        }
        if (length==0) {
            head = new Node<T>(value);
            length++;
            return;
        }
        if (index==0) {
            this->prepend(value); //length++
            return;
        }
        Node<T>* curr = this->get(index-1);
        this->insertAfter(value, curr); //length++
    }

    //returns the Node at the given index
    Node<T>* get(int index) {
        if (index<0 || index>=this->length) {
            return nullptr;
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp;
    }

    void prepend(T *value) {
        if (length==0) {
            head = new Node<T>(value);
            length++;
            return;
        }
        Node<T>* newNode = new Node<T>(value);
        newNode->next = this->head;
        head = newNode;
        length++;
    }

    //TODO:Write a function to reverse the list using the logic from the slide.
    void reverselist() {
        Node<T>* prev = nullptr;
        Node<T>* curr = head;
        Node<T>* next;
        curr=this->head;
        while (curr!=NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void print() {
        cout << "Printing List.." << endl;
        Node<T> *temp = head;
        while (temp != NULL) {
            temp->print();
            temp = temp->next;
        }
    }

private:
    //private method to add a value after a given node
    void insertAfter(T* value, Node<T>* node) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = node->next;
        node->next = newNode;
        length++;
    }


};

int main() {
    student *s1 = new student("A", 20);
    student *s2 = new student("B", 21);
    student *s3 = new student("C", 22);
    LinkedList<student> *ll = new LinkedList<student>(s1);
    ll->add(s2);
    ll->addhead(s3);
    ll->print();
    ll->delfirst();
    ll->print();
    ll->prepend(s3);
    ll->print();
    ll->reverselist();
    ll->print();
}