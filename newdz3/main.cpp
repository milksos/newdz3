#include <iostream>
#include "TStack.h"

void runStackTests() {
    int total_tests = 0;
    int passed_tests = 0;

    // ���� �������� ������������
    try {
        TStack<int> stack;
        std::cout << "������ ������ ����\n";
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "������ ��� ������������ �������� ������������\n";
    }

    // ���� ������������ � �������� ������������
    try {
        TStack<int> stack(100);
        std::cout << "������ ������ ���� � ������������ 100\n";
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "������ ��� ������������ ������������ � �������� ������������\n";
    }

    // ���� ���������� ��������� � ���� (push)
    try {
        TStack<int> stack;
        stack.push(10);
        stack.push(20);
        stack.push(30);
        std::cout << "���� ����� ���������� ���������: ";
        stack.print(); // ��������� �����: 10 20 30
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "������ ��� ������������ �������� push\n";
    }

    // ���� ��������� �������� �������� (top)
    try {
        TStack<int> stack;
        stack.push(10);
        stack.push(20);
        int topElement = stack.top();
        std::cout << "������� ������� �����: " << topElement << "\n"; // ��������� �����: 20
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "������ ��� ������������ �������� top\n";
    }

    // ���� ��������� �������� �������� (����������� ������ top)
    try {
        const TStack<int> stack = []() { TStack<int> s; s.push(100); s.push(200); return s; }();
        int topElement = stack.top();
        std::cout << "������� ������� ������������ �����: " << topElement << "\n"; // ��������� �����: 200
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "������ ��� ������������ ����������� ������ top\n";
    }

    // ���� �������� �������� �������� (pop)
    try {
        TStack<int> stack;
        stack.push(10);
        stack.push(20);
        stack.pop();
        std::cout << "���� ����� �������� �������� ��������: ";
        stack.print(); // ��������� �����: 10
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "������ ��� ������������ �������� pop\n";
    }

    // ���� pop ��� ������� �����
    try {
        TStack<int> stack;
        stack.pop();
        std::cout << "������: �������� pop ��� ������� ����� �� ������� ����������\n";
        total_tests++;
    }
    catch (const std::underflow_error&) {
        std::cout << "��������� ���������� ��� ������� ������� ������� �� ������� �����\n";
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "����������� ������ ��� ������������ �������� pop ��� ������� �����\n";
    }

    // ���� �������� �� ������� (empty)
    try {
        TStack<int> stack;
        bool isEmpty = stack.empty();
        std::cout << "���� ����: " << (isEmpty ? "������" : "����") << "\n"; // ��������� �����: ������
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "������ ��� ������������ �������� empty\n";
    }

    // ���� ������� ����� (clear)
    try {
        TStack<int> stack;
        stack.push(10);
        stack.push(20);
        stack.clear();
        bool isEmpty = stack.empty();
        std::cout << "���� ����� ������� ����: " << (isEmpty ? "������" : "����") << "\n"; // ��������� �����: ������
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "������ ��� ������������ �������� clear\n";
    }

    // ���� ��������� �������� ������� ����� (size)
    try {
        TStack<int> stack;
        stack.push(10);
        stack.push(20);
        stack.push(30);
        size_t stackSize = stack.size();
        std::cout << "������� ������ �����: " << stackSize << "\n"; // ��������� �����: 3
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "������ ��� ������������ �������� size\n";
    }

    // �������������� ��������� �����

    // ���� ���������� �������� ��� ���������� �����������
    try {
        TStack<int> stack(2);
        stack.push(1);
        stack.push(2);
        stack.push(3); // �������� ���������� �����������
        std::cout << "���������� �������� ��� ���������� ����������� ������ �������\n";
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "������ ��� ���������� �������� ��� ���������� �����������\n";
    }

    // ���� �������� ���� ��������� � ������������ ����������
    try {
        TStack<int> stack;
        stack.push(10);
        stack.push(20);
        stack.clear();
        stack.push(30);
        stack.push(40);
        std::cout << "���� ����� ������� � ���������� ����� ���������: ";
        stack.print(); // ��������� �����: 30 40
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "������ ��� ������������ ���������� ���������� ����� �������\n";
    }

    // ����� ������ ���������� ������ � ���������� �������� ������
    std::cout << "\n����� ���������� ������: " << total_tests << "\n";
    std::cout << "���������� �������� ������: " << passed_tests << "\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    runStackTests();
    return 0;
}
