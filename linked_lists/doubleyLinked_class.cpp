#include <iostream>
using namespace std;


class Node{
    public:
        int data;
        Node* next;
        Node* prev;

    Node(int value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList{
    private:
        Node* head;
        Node* tail;

    public:
        LinkedList(){
            head = nullptr;
            tail = nullptr;
        }

        void append(int value){
            Node* currentNode = new Node(value);
            if(head == nullptr){
                head = currentNode;
                tail = currentNode;
                return ;
            }
            tail -> next = currentNode;
            currentNode -> prev = tail;
            tail = currentNode;
            
        }

        void printForward(){
            Node* temp = head;

            while(temp != nullptr){
                cout << temp -> data << endl;
                temp = temp -> next;
            }

            cout << endl;
        }

        void printBackwords(){
            Node* temp = tail;

            while(temp != nullptr){
                cout << temp -> data << endl;
                temp = temp -> prev;
            }

            cout << endl;
        }
};

int main(){
    LinkedList ll;
    ll.append(1);
    ll.append(2);
    ll.append(3);

    ll.printBackwords();
    return 0;

}