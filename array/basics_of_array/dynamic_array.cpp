#include <iostream>
#include <stdexcept>
class DynamicArr{
    private:
    int* arr;
    int capacity;
    int size;

    public:
    DynamicArr(){
        capacity = 1;
        size = 0;
        arr = new int[capacity];
    }

    ~DynamicArr(){
        delete[] arr;
    }

    void push_back(int value){
        if(size == capacity){
            capacity *= 2;

            int* newArr = new int[capacity];
            
            for(int i = 0; i < size; i++){
                newArr[i] = arr[i];
            }

            delete[] arr;
            arr = newArr;
        }

        arr[size++] = value;
    }

    int& operator[](int index){
        if(index < 0 || index >= size){
                throw std::out_of_range("Index out of range");
        }
        return arr[index];

    }

    int getSize() const{
        return size;
    }
};

int main(){

    DynamicArr arr;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);

    for(int i = 0; i < arr.getSize(); i++){
        std::cout << arr[i] << std::endl;
    }

    return 0;


}