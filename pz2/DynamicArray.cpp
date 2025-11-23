#include "DynamicArray.h"
#include <algorithm>
#include <stdexcept>

DynamicArray::DynamicArray(std::size_t initialCapacity)
    : arrayData(nullptr), currentLength(initialCapacity)
{
    if (currentLength > 0) {
        arrayData = new int[currentLength];
        for (std::size_t i = 0; i < currentLength; ++i) {
            arrayData[i] = 0;
        }
    }
}

DynamicArray::DynamicArray(const DynamicArray& sourceArray)
    : arrayData(nullptr), currentLength(sourceArray.currentLength)
{
    if (currentLength > 0) {
        arrayData = new int[currentLength];
        for (std::size_t i = 0; i < currentLength; ++i) {
            arrayData[i] = sourceArray.arrayData[i];
        }
    }
}

DynamicArray::~DynamicArray() {
    delete[] arrayData;
}

void DynamicArray::displayContents() const {
    std::cout << "[";
    for (std::size_t i = 0; i < currentLength; ++i) {
        std::cout << arrayData[i];
        if (i + 1 < currentLength) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

bool DynamicArray::assignValue(std::size_t position, int newValue) {
    if (position >= currentLength) {
        std::cerr << "Ошибка: позиция " << position 
                  << " выходит за границы массива (размер=" << currentLength << ")\n";
        return false;
    }
    if (!isValidValue(newValue)) {
        std::cerr << "Ошибка: значение " << newValue 
                  << " вне допустимого диапазона [-100, 100]\n";
        return false;
    }
    arrayData[position] = newValue;
    return true;
}

int DynamicArray::retrieveValue(std::size_t position, bool& operationStatus) const {
    if (position >= currentLength) {
        std::cerr << "Ошибка: позиция " << position 
                  << " выходит за границы массива (размер=" << currentLength << ")\n";
        operationStatus = false;
        return 0;
    }
    operationStatus = true;
    return arrayData[position];
}

bool DynamicArray::appendElement(int newValue) {
    if (!isValidValue(newValue)) {
        std::cerr << "Ошибка: значение " << newValue 
                  << " вне допустимого диапазона [-100, 100]\n";
        return false;
    }

    std::size_t newArrayLength = currentLength + 1;
    int* newStorage = new int[newArrayLength];
    
    for (std::size_t i = 0; i < currentLength; ++i) {
        newStorage[i] = arrayData[i];
    }
    
    newStorage[currentLength] = newValue;
    
    delete[] arrayData;
    arrayData = newStorage;
    currentLength = newArrayLength;
    
    return true;
}

void DynamicArray::combineArrays(const DynamicArray& otherArray) {
    for (std::size_t i = 0; i < currentLength; ++i) {
        int otherArrayValue = (i < otherArray.currentLength) ? otherArray.arrayData[i] : 0;
        int sumResult = arrayData[i] + otherArrayValue;
        arrayData[i] = sumResult;
    }
}

void DynamicArray::subtractArrays(const DynamicArray& otherArray) {
    for (std::size_t i = 0; i < currentLength; ++i) {
        int otherArrayValue = (i < otherArray.currentLength) ? otherArray.arrayData[i] : 0;
        int differenceResult = arrayData[i] - otherArrayValue;
        arrayData[i] = differenceResult;
    }
}