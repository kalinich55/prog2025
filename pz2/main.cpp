#include <iostream>
#include "DynamicArray.h"

int main() {
    std::cout << "=== Демонстрация работы класса DynamicArray ===\n" << std::endl;

    std::size_t userArraySize;
    std::cout << "Введите размер массива: ";
    std::cin >> userArraySize;

    DynamicArray mainArray(userArraySize);
    std::cout << "Создан массив: ";
    mainArray.displayContents();

    std::cout << "Введите " << userArraySize << " элементов массива:" << std::endl;
    for (std::size_t i = 0; i < mainArray.getLength(); ++i) {
        int userInput;
        std::cout << "Элемент [" << i << "]: ";
        std::cin >> userInput;
        
        while (!mainArray.assignValue(i, userInput)) {
            std::cout << "Ошибка! Введите значение от -100 до 100: ";
            std::cin >> userInput;
        }
    }
    
    std::cout << "Массив после ввода данных: ";
    mainArray.displayContents();

    int valueToAppend;
    std::cout << "Введите значение для добавления в конец массива: ";
    std::cin >> valueToAppend;
    
    while (!mainArray.appendElement(valueToAppend)) {
        std::cout << "Ошибка! Введите значение от -100 до 100: ";
        std::cin >> valueToAppend;
    }
    std::cout << "Массив после добавления элемента: ";
    mainArray.displayContents();

    DynamicArray copiedArray = mainArray;
    std::cout << "Копия массива: ";
    copiedArray.displayContents();

    std::size_t indexToModify;
    int newValueForElement;
    std::cout << "Введите индекс для изменения в копии: ";
    std::cin >> indexToModify;
    std::cout << "Введите новое значение: ";
    std::cin >> newValueForElement;
    
    if (copiedArray.assignValue(indexToModify, newValueForElement)) {
        std::cout << "Копия после изменения: ";
        copiedArray.displayContents();
    }
    
    std::cout << "Оригинальный массив остался без изменений: ";
    mainArray.displayContents();

    std::cout << "\nСоздание второго массива для операций:" << std::endl;
    std::cout << "Введите размер второго массива: ";
    std::cin >> userArraySize;
    
    DynamicArray secondArray(userArraySize);
    std::cout << "Введите " << userArraySize << " элементов для второго массива:" << std::endl;
    for (std::size_t i = 0; i < secondArray.getLength(); ++i) {
        int userInput;
        std::cout << "Элемент [" << i << "]: ";
        std::cin >> userInput;
        
        while (!secondArray.assignValue(i, userInput)) {
            std::cout << "Ошибка! Введите значение от -100 до 100: ";
            std::cin >> userInput;
        }
    }
    
    std::cout << "Второй массив: ";
    secondArray.displayContents();

    mainArray.combineArrays(secondArray);
    std::cout << "Результат сложения массивов: ";
    mainArray.displayContents();

    mainArray.subtractArrays(secondArray);
    std::cout << "Результат вычитания массивов: ";
    mainArray.displayContents();

    std::size_t indexToRetrieve;
    std::cout << "Введите индекс для получения элемента: ";
    std::cin >> indexToRetrieve;
    
    bool retrievalSuccess;
    int retrievedValue = mainArray.retrieveValue(indexToRetrieve, retrievalSuccess);
    if (retrievalSuccess) {
        std::cout << "Элемент [" << indexToRetrieve << "] = " << retrievedValue << std::endl;
    } else {
        std::cout << "Ошибка! Индекс выходит за границы массива!" << std::endl;
    }

    std::cout << "\n=== Демонстрация завершена ===" << std::endl;
    return 0;
}