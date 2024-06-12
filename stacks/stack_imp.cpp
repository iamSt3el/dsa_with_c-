#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

class Stack{
    private:
        int arr[MAX_SIZE];
        int pointer;

    public:
        Stack(){
            pointer = -1;
        }

        bool isEmpty(){
            return pointer == -1;
        }

        bool isFull(){
            return pointer == MAX_SIZE - 1;
        }

        int top(){
            if(!isEmpty()){
                return arr[pointer];
            }
            return 0;
        }

        void push(int number){
            if(isFull()){
                cout << "STACK OVERFOLLOW" << endl;
            }else{
                arr[++pointer] = number;
            }
        }

        void pop(){
            if(isEmpty()){
                cout << "STACK UNDERFOLLOW" << endl;
            }else{
                arr[--pointer];
            }
        }
};

int main(){
    Stack stack;
    int number;

    cout << "WELCOME" << endl;

    while(number != 4){
        cout << "-----------------\n";
        cout << "1. Add number\n";
        cout << "2. Remove number\n";
        cout << "3. Print stack\n";
        cout << "4. Exit\n";
        cout << "-----------------\n";
        cout << "\n";

        cin >> number;

        switch(number){
            case 1:
                int num;
                cout << "Enter a number: ";
                cin >> num;
                stack.push(num);
                break;
            case 2:
                stack.pop();
                cout << "DONE\n";
                break;
            case 3:
                while(!stack.isEmpty()){
                    cout << stack.top() << "  \n";
                    stack.pop(); 
                }
                break;
        }
    }

    return 0;
}