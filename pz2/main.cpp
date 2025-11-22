#include <iostream>
#include "DynamicArray.h"

int main() {
    std::cout << "Demo DynamicArray pz2" << std::endl;

    std::size_t size;
    std::cout << "Enter array size: ";
    std::cin >> size;

    DynamicArray a(size); 
    std::cout << "Created array: ";
    a.print();

    std::cout << "Enter " << size << " array elements:" << std::endl;
    for (std::size_t i = 0; i < a.size(); ++i) {
        int value;
        std::cout << "Element [" << i << "]: ";
        std::cin >> value;
        
        while (!a.set(i, value)) {
            std::cout << "Error! Enter value from -100 to 100: ";
            std::cin >> value;
        }
    }
    
    std::cout << "Array after input: ";
    a.print();

    int newValue;
    std::cout << "Enter value to push back: ";
    std::cin >> newValue;
    
    while (!a.push_back(newValue)) {
        std::cout << "Error! Enter value from -100 to 100: ";
        std::cin >> newValue;
    }
    std::cout << "Array after push_back: ";
    a.print();

    DynamicArray b = a;
    std::cout << "Array copy (b): ";
    b.print();

    std::size_t index;
    int changeValue;
    std::cout << "Enter index to modify in copy: ";
    std::cin >> index;
    std::cout << "Enter new value: ";
    std::cin >> changeValue;
    
    if (b.set(index, changeValue)) {
        std::cout << "Copy after modification: ";
        b.print();
    }
    
    std::cout << "Original remains: ";
    a.print();

    std::cout << "Create second array for operations:" << std::endl;
    std::cout << "Enter second array size: ";
    std::cin >> size;
    
    DynamicArray c(size);
    std::cout << "Enter " << size << " elements for second array:" << std::endl;
    for (std::size_t i = 0; i < c.size(); ++i) {
        int value;
        std::cout << "Element [" << i << "]: ";
        std::cin >> value;
        
        while (!c.set(i, value)) {
            std::cout << "Error! Enter value from -100 to 100: ";
            std::cin >> value;
        }
    }
    
    std::cout << "Second array (c): ";
    c.print();

    a.add(c);
    std::cout << "Result of a.add(c): ";
    a.print();

    a.subtract(c);
    std::cout << "Result of a.subtract(c): ";
    a.print();

    std::cout << "Enter index to get element: ";
    std::cin >> index;
    
    bool success;
    int value = a.get(index, success);
    if (success) {
        std::cout << "Element [" << index << "] = " << value << std::endl;
    } else {
        std::cout << "Error! Index out of bounds!" << std::endl;
    }

    std::cout << "Demo completed!" << std::endl;
    return 0;
}