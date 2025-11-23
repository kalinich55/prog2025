#pragma once
#include <cstddef>
#include <iostream>

class DynamicArray {
public:
    explicit DynamicArray(std::size_t initialCapacity = 0);
    DynamicArray(const DynamicArray& sourceArray);
    ~DynamicArray();

    void displayContents() const;
    bool assignValue(std::size_t position, int newValue);
    int retrieveValue(std::size_t position, bool& operationStatus) const;
    bool appendElement(int newValue);

    void combineArrays(const DynamicArray& otherArray);
    void subtractArrays(const DynamicArray& otherArray);

    std::size_t getLength() const { return currentLength; }

private:
    int* arrayData;
    std::size_t currentLength;

    static bool isValidValue(int valueToCheck) { 
        return valueToCheck >= -100 && valueToCheck <= 100; 
    }
};