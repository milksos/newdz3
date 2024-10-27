#ifndef TSTACK_H
#define TSTACK_H

#include "TDMassive.h"
#include <iostream>
#include <stdexcept>

// ����� TStack ��� ���������� �����
// ���������� TDMassive ��� �������� ���������

template <typename T>
class TStack {
    TDMassive<T> _data; // ���������� ������ ��� �������� ������ �����

public:
    // ������������
    TStack();
    explicit TStack(size_t capacity);

    // �������� �������� �����
    void push(T value); // ���������� �������� � ����
    void pop(); // �������� �������� �������� �� �����
    T& top(); // ��������� �������� �������� �����
    const T& top() const; // ��������� �������� �������� ����� (����������� ������)

    // ��������������� ������
    bool empty() const noexcept; // ��������, ���� �� ����
    size_t size() const noexcept; // ��������� �������� ������� �����
    void clear(); // ������� �����

    // ������ ����� ��� �������
    void print() const;
};

// ���������� ������� TStack
// ����������� �� ���������
template <typename T>
TStack<T>::TStack() : _data() {}

// ����������� � �������� ������������
template <typename T>
TStack<T>::TStack(size_t capacity) : _data(capacity) {}

// ���������� �������� � ����
template <typename T>
void TStack<T>::push(T value) {
    _data.push_back(value);
}

// �������� �������� �������� �� �����
template <typename T>
void TStack<T>::pop() {
    if (_data.empty()) {
        throw std::underflow_error("���� ����, ���������� ��������� pop");
    }
    _data.remove_by_index(_data.size() - 1);
}

// ��������� �������� �������� ����� (������������ ������)
template <typename T>
T& TStack<T>::top() {
    if (_data.empty()) {
        throw std::underflow_error("���� ����, ���������� �������� top");
    }
    return _data[_data.size() - 1];
}

// ��������� �������� �������� ����� (����������� ������)
template <typename T>
const T& TStack<T>::top() const {
    if (_data.empty()) {
        throw std::underflow_error("���� ����, ���������� �������� top");
    }
    return _data[_data.size() - 1];
}

// �������� �� ������� �����
template <typename T>
bool TStack<T>::empty() const noexcept {
    return _data.empty();
}

// ��������� �������� ������� �����
template <typename T>
size_t TStack<T>::size() const noexcept {
    return _data.size();
}

// ������� �����
template <typename T>
void TStack<T>::clear() {
    _data.clear();
}

// ������ ����� ��� �������
template <typename T>
void TStack<T>::print() const {
    for (size_t i = 0; i < _data.size(); i++) {
        std::cout << _data[i] << " ";
    }
    std::cout << "\n";
}

#endif // TSTACK_H
