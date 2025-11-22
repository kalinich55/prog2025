#include "DynamicArray.h"
#include <algorithm>
#include <stdexcept>

DynamicArray::DynamicArray(std::size_t size)
    : m_data(nullptr), m_size(size)
{
    if (m_size > 0) {
        m_data = new int[m_size];
        for (std::size_t i = 0; i < m_size; ++i) m_data[i] = 0;
    }
}

DynamicArray::DynamicArray(const DynamicArray &other)
    : m_data(nullptr), m_size(other.m_size)
{
    if (m_size > 0) {
        m_data = new int[m_size];
        for (std::size_t i = 0; i < m_size; ++i) m_data[i] = other.m_data[i];
    }
}

DynamicArray::~DynamicArray() {
    delete[] m_data;
}

void DynamicArray::print() const {
    std::cout << "[";
    for (std::size_t i = 0; i < m_size; ++i) {
        std::cout << m_data[i];
        if (i + 1 < m_size) std::cout << ", ";
    }
    std::cout << "]\n";
}

bool DynamicArray::set(std::size_t index, int value) {
    if (index >= m_size) {
        std::cerr << "set: index " << index << " out of bounds (size=" << m_size << ")\n";
        return false;
    }
    if (!inRange(value)) {
        std::cerr << "set: value " << value << " out of allowed range [-100,100]\n";
        return false;
    }
    m_data[index] = value;
    return true;
}

int DynamicArray::get(std::size_t index, bool &ok) const {
    if (index >= m_size) {
        std::cerr << "get: index " << index << " out of bounds (size=" << m_size << ")\n";
        ok = false;
        return 0;
    }
    ok = true;
    return m_data[index];
}

bool DynamicArray::push_back(int value) {
    if (!inRange(value)) {
        std::cerr << "push_back: value " << value << " out of allowed range [-100,100]\n";
        return false;
    }

    std::size_t newSize = m_size + 1;
    int *newBuf = new int[newSize];
    for (std::size_t i = 0; i < m_size; ++i) newBuf[i] = m_data[i];
    newBuf[m_size] = value;
    delete[] m_data;
    m_data = newBuf;
    m_size = newSize;
    return true;
}

void DynamicArray::add(const DynamicArray &other) {
    for (std::size_t i = 0; i < m_size; ++i) {
        int otherVal = (i < other.m_size) ? other.m_data[i] : 0;
    int sum = m_data[i] + otherVal;
    m_data[i] = sum;
    }
}

void DynamicArray::subtract(const DynamicArray &other) {
    for (std::size_t i = 0; i < m_size; ++i) {
        int otherVal = (i < other.m_size) ? other.m_data[i] : 0;
    int diff = m_data[i] - otherVal;
    m_data[i] = diff;
    }
}