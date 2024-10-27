#include <iostream>
#include "TStack.h"

void runStackTests() {
    int total_tests = 0;
    int passed_tests = 0;

    // Тест базового конструктора
    try {
        TStack<int> stack;
        std::cout << "Создан пустой стек\n";
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Ошибка при тестировании базового конструктора\n";
    }

    // Тест конструктора с заданной вместимостью
    try {
        TStack<int> stack(100);
        std::cout << "Создан пустой стек с вместимостью 100\n";
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Ошибка при тестировании конструктора с заданной вместимостью\n";
    }

    // Тест добавления элементов в стек (push)
    try {
        TStack<int> stack;
        stack.push(10);
        stack.push(20);
        stack.push(30);
        std::cout << "Стек после добавления элементов: ";
        stack.print(); // Ожидаемый вывод: 10 20 30
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Ошибка при тестировании операции push\n";
    }

    // Тест получения верхнего элемента (top)
    try {
        TStack<int> stack;
        stack.push(10);
        stack.push(20);
        int topElement = stack.top();
        std::cout << "Верхний элемент стека: " << topElement << "\n"; // Ожидаемый вывод: 20
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Ошибка при тестировании операции top\n";
    }

    // Тест получения верхнего элемента (константная версия top)
    try {
        const TStack<int> stack = []() { TStack<int> s; s.push(100); s.push(200); return s; }();
        int topElement = stack.top();
        std::cout << "Верхний элемент константного стека: " << topElement << "\n"; // Ожидаемый вывод: 200
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Ошибка при тестировании константной версии top\n";
    }

    // Тест удаления верхнего элемента (pop)
    try {
        TStack<int> stack;
        stack.push(10);
        stack.push(20);
        stack.pop();
        std::cout << "Стек после удаления верхнего элемента: ";
        stack.print(); // Ожидаемый вывод: 10
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Ошибка при тестировании операции pop\n";
    }

    // Тест pop для пустого стека
    try {
        TStack<int> stack;
        stack.pop();
        std::cout << "Ошибка: операция pop для пустого стека не вызвала исключение\n";
        total_tests++;
    }
    catch (const std::underflow_error&) {
        std::cout << "Ожидаемое исключение при попытке удалить элемент из пустого стека\n";
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Неожиданная ошибка при тестировании операции pop для пустого стека\n";
    }

    // Тест проверки на пустоту (empty)
    try {
        TStack<int> stack;
        bool isEmpty = stack.empty();
        std::cout << "Стек пуст: " << (isEmpty ? "истина" : "ложь") << "\n"; // Ожидаемый вывод: истина
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Ошибка при тестировании операции empty\n";
    }

    // Тест очистки стека (clear)
    try {
        TStack<int> stack;
        stack.push(10);
        stack.push(20);
        stack.clear();
        bool isEmpty = stack.empty();
        std::cout << "Стек после очистки пуст: " << (isEmpty ? "истина" : "ложь") << "\n"; // Ожидаемый вывод: истина
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Ошибка при тестировании операции clear\n";
    }

    // Тест получения текущего размера стека (size)
    try {
        TStack<int> stack;
        stack.push(10);
        stack.push(20);
        stack.push(30);
        size_t stackSize = stack.size();
        std::cout << "Текущий размер стека: " << stackSize << "\n"; // Ожидаемый вывод: 3
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Ошибка при тестировании операции size\n";
    }

    // Дополнительные граничные тесты

    // Тест добавления элемента при превышении вместимости
    try {
        TStack<int> stack(2);
        stack.push(1);
        stack.push(2);
        stack.push(3); // Проверка расширения вместимости
        std::cout << "Добавление элемента при превышении вместимости прошло успешно\n";
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Ошибка при добавлении элемента при превышении вместимости\n";
    }

    // Тест удаления всех элементов и последующего добавления
    try {
        TStack<int> stack;
        stack.push(10);
        stack.push(20);
        stack.clear();
        stack.push(30);
        stack.push(40);
        std::cout << "Стек после очистки и добавления новых элементов: ";
        stack.print(); // Ожидаемый вывод: 30 40
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Ошибка при тестировании повторного добавления после очистки\n";
    }

    // Вывод общего количества тестов и количества успешных тестов
    std::cout << "\nОбщее количество тестов: " << total_tests << "\n";
    std::cout << "Количество успешных тестов: " << passed_tests << "\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    runStackTests();
    return 0;
}
