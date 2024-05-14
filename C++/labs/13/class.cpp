#include "header.h"
#include <algorithm> // for sort (check equality)
#include <cstring> // for memcpy

IntSet::IntSet() : size(0), capacity(10) {
    elements = new int[capacity];
}

IntSet::~IntSet() {
    delete[] elements;
}

IntSet::IntSet(const IntSet& other) : size(other.size), capacity(other.capacity) {
    elements = new int[capacity];
    std::memcpy(elements, other.elements, size * sizeof(int));
}

IntSet& IntSet::operator=(const IntSet& other) {
    if (this == &other) return *this;
    delete[] elements;
    size = other.size;
    capacity = other.capacity;
    elements = new int[capacity];
    std::memcpy(elements, other.elements, size * sizeof(int));
    return *this;
}

void IntSet::resize(int newCapacity) {
    int* newElements = new int[newCapacity];
    std::memcpy(newElements, elements, size * sizeof(int));
    delete[] elements;
    elements = newElements;
    capacity = newCapacity;
}

void IntSet::add(int num) {
    if (!contains(num)) {
        if (size == capacity) {
            resize(2 * capacity);
        }
        elements[size++] = num;
    }
}

void IntSet::remove(int num) {
    for (int i = 0; i < size; ++i) 
        if (elements[i] == num) {
            for (int j = i; j < size - 1; ++j) 
                elements[j] = elements[j + 1];
            size--;
            break;
        }
}

bool IntSet::contains(int num) const {
    for (int i = 0; i < size; ++i) 
        if (elements[i] == num) 
            return true;
    return false;
}

void IntSet::print() const {
    std::cout << "{";
    for (int i = 0; i < size; i++) {
        if (i == (size - 1)) {
            std::cout << elements[i];
            break;
        }
        std::cout << elements[i] << ", ";
    }
    std::cout << "}" << std::endl;
}

IntSet IntSet::operator+(const IntSet& other) const {
    IntSet result = *this;
    for (int i = 0; i < other.size; ++i)
        result.add(other.elements[i]);
    return result;
}

IntSet& IntSet::operator+=(const IntSet& other) {
    for (int i = 0; i < other.size; ++i)
        add(other.elements[i]);
    return *this;
}

IntSet IntSet::operator-(const IntSet& other) const {
    IntSet result;
    for (int i = 0; i < size; ++i)
        if (!other.contains(elements[i]))
            result.add(elements[i]);
    return result;
}

IntSet& IntSet::operator-=(const IntSet& other) {
    for (int i = 0; i < size; ++i)
        if (other.contains(elements[i]))
            remove(elements[i]);
    return *this;
}

bool IntSet::operator==(const IntSet& other) const {
    if (size != other.size)
        return false;
    IntSet sorted_this = *this;
    IntSet sorted_other = other;
    std::sort(sorted_this.elements, sorted_this.elements + sorted_this.size);
    std::sort(sorted_other.elements, sorted_other.elements + sorted_other.size);
    for (int i = 0; i < size; ++i)
        if (sorted_this.elements[i] != sorted_other.elements[i])
            return false;
    return true;
}

bool IntSet::operator!=(const IntSet& other) const {
    return !(*this == other);
}

bool IntSet::operator>(const IntSet& other) const {
    return size > other.size;
}

bool IntSet::operator<(const IntSet& other) const {
    return size < other.size;
}

bool IntSet::operator>=(const IntSet& other) const {
    return size >= other.size;
}

bool IntSet::operator<=(const IntSet& other) const {
    return size <= other.size;
}

IntSet IntSet::operator*(const IntSet& other) const {
    IntSet result;
    for (int i = 0; i < size; ++i)
        if (other.contains(elements[i]))
            result.add(elements[i]);
    return result;
}

IntSet IntSet::operator+(int num) const {
    IntSet result = *this;
    result.add(num);
    return result;
}

IntSet IntSet::operator-(int num) const {
    IntSet result = *this;
    result.remove(num);
    return result;
}

const int* IntSet::getElements() const {
    return elements;
}

int IntSet::getSize() const {
    return size;
}

std::ostream& operator<<(std::ostream& os, const IntSet& set) {
    os << "{";
    for (int i = 0; i < set.size; ++i) {
        if (i == set.size - 1)
            os << set.elements[i];
        else
            os << set.elements[i] << ", ";
    }
    os << "}";
    return os;
}

std::istream& operator>>(std::istream& is, IntSet& set) {
    int num;
    is >> num;
    set.add(num);
    return is;
}