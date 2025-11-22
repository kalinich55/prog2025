#pragma once
#include <cstddef>
#include <iostream>

class DynamicArray {
public:

    explicit DynamicArray(std::size_t size = 0);

    DynamicArray(const DynamicArray &other);

    ~DynamicArray();

    void print() const;

    bool set(std::size_t index, int value);

    int get(std::size_t index, bool &ok) const;

    bool push_back(int value);

    void add(const DynamicArray &other);
    void subtract(const DynamicArray &other);

    std::size_t size() const { return m_size; }

private:
    int *m_data;
    std::size_t m_size;

    static bool inRange(int v) { return v >= -100 && v <= 100; }
};