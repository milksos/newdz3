#ifndef TSTACK_H
#define TSTACK_H

#include "TDMassive.h"
#include <iostream>
#include <stdexcept>

// Класс TStack для реализации стека
// Использует TDMassive для хранения элементов

template <typename T>
class TStack {
    TDMassive<T> _data; // Внутренний массив для хранения данных стека

public:
    // Конструкторы
    TStack();
    explicit TStack(size_t capacity);

    // Основные операции стека
    void push(T value); // Добавление элемента в стек
    void pop(); // Удаление верхнего элемента из стека
    T& top(); // Получение верхнего элемента стека
    const T& top() const; // Получение верхнего элемента стека (константная версия)

    // Вспомогательные методы
    bool empty() const noexcept; // Проверка, пуст ли стек
    size_t size() const noexcept; // Получение текущего размера стека
    void clear(); // Очистка стека

    // Печать стека для отладки
    void print() const;
};

// Реализация методов TStack
// Конструктор по умолчанию
template <typename T>
TStack<T>::TStack() : _data() {}

// Конструктор с заданной вместимостью
template <typename T>
TStack<T>::TStack(size_t capacity) : _data(capacity) {}

// Добавление элемента в стек
template <typename T>
void TStack<T>::push(T value) {
    _data.push_back(value);
}

// Удаление верхнего элемента из стека
template <typename T>
void TStack<T>::pop() {
    if (_data.empty()) {
        throw std::underflow_error("Стек пуст, невозможно выполнить pop");
    }
    _data.remove_by_index(_data.size() - 1);
}

// Получение верхнего элемента стека (непостоянная версия)
template <typename T>
T& TStack<T>::top() {
    if (_data.empty()) {
        throw std::underflow_error("Стек пуст, невозможно получить top");
    }
    return _data[_data.size() - 1];
}

// Получение верхнего элемента стека (константная версия)
template <typename T>
const T& TStack<T>::top() const {
    if (_data.empty()) {
        throw std::underflow_error("Стек пуст, невозможно получить top");
    }
    return _data[_data.size() - 1];
}

// Проверка на пустоту стека
template <typename T>
bool TStack<T>::empty() const noexcept {
    return _data.empty();
}

// Получение текущего размера стека
template <typename T>
size_t TStack<T>::size() const noexcept {
    return _data.size();
}

// Очистка стека
template <typename T>
void TStack<T>::clear() {
    _data.clear();
}

// Печать стека для отладки
template <typename T>
void TStack<T>::print() const {
    for (size_t i = 0; i < _data.size(); i++) {
        std::cout << _data[i] << " ";
    }
    std::cout << "\n";
}

#endif // TSTACK_H
