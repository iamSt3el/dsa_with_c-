#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *current = head;

        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    void deleteNode(int value)
    {
        if (head == nullptr)
        {
            return;
        }

        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;

            delete temp;
            return;
        }

        Node *current = head;
        while (current->next != nullptr)
        {
            if (current->next->data == value)
            {
                Node *temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    void print()
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void addAtStart(int value)
    {
        Node* newCurrent = new Node(value);
        if(head == nullptr){
            head = newCurrent;
            return;
        }

        Node* temp = head;

        head = newCurrent;
        newCurrent -> next = temp;

    }

    void addAtPosition(int value, int position){
        Node* newCurrent = new Node(value);
        if(head == nullptr){  
            head = newCurrent;
            return;
        }

        if(position == 0){
            newCurrent -> next = head;
            head = newCurrent;
            return ;
        }
        Node* temp = head;
        int count = 0;

        while(temp -> next != nullptr && count < position - 1){
            count ++;
            temp = temp -> next;
        }

        newCurrent -> next = temp ->next;
        temp -> next = newCurrent;
       
    }

    int size()
    {
        int count = 0;
        Node *current = head;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }

        return count;
    }
};

int main()
{
    LinkedList ll;

    int number = 0;
    int element;

    while(number != 6){
        cout << "----------------------------------\n";
        cout << "WELCOME\n";
        cout << "1.Add number at end.\n";
        cout << "2.Add number at start.\n";
        cout << "3.Add number at any position\n";
        cout << "4.Print the linked list\n";
        cout << "5.Delete the node\n";
        cout << "6.Exit\n";

        cout << "----------------------------------\n";

        cin >> number;
        switch(number){
            case 1:
                cout << "Enter the number";
                cin >> element;

                ll.insertAtEnd(element);
                cout << "Added\n\n";
                break;
            case 2:
                cout << "Enter the number";
                cin >> element;

                ll.addAtStart(element);
                cout << "Added\n\n";
                break;
            case 3:
                int position;
                cout << "Enter the number";
                cin >> element;
                cout << "Enter the position:";
                cin >> position;

                ll.addAtPosition(element, element);
                cout << "Added\n\n";
                break;

            case 4:
                cout << endl;
                ll.print();
                break;
            case 5:
                cout << "Enter value to delete:";
                cin >> element;
                ll.deleteNode(element);
                cout << "Node deleted\n";
                break;


        }
    }

    return 0;
}