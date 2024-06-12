#include <iostream>

int main(){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int elementToFound = 10;
    int i;
    for(i = 0; i < 10; i ++){
        if(elementToFound == arr[i]){
            std::cout << "Element found at index " << i << std::endl;
            break;
        }
    }

    if(i == 10){
        std::cout << "Element no found" << std::endl;
    }   
}