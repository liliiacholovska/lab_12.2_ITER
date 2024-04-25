#include <iostream>
using namespace std;

struct Node { // ���������� ��������� Node
    int data; // ���� ��� ���������� �����
    Node* next; // �������� �� ��������� �������
};

// ������� ��� �������� �������� ������ ��� �������� � ���������� ����������
bool DuplicatePair(Node* head) {
    Node* current = head; // �������� current �� ������� ������
    while (current != nullptr && current->next != nullptr) { // ��������� �� ������ �� ��������������� ��������
        if (current->data == current->next->data) { // �������� �� �������� ������� �� �� ���� ��������, �� � ���������
            return true; // ���� �������� ���� � ���������� ����������, ��������� true
        }
        current = current->next; // ������� �� ���������� ��������
    }
    return false; // ���� ����� ���� � ���������� ���������� �� ��������, ��������� false
}

// ������� ��� ��������� ������ � ������ �������
void CreateList(Node*& head, Node*& tail, int values[], int size) {
    head = nullptr; // ����������� ����������� �� �������� ����� �� nullptr
    tail = nullptr; // ����������� �������� ����� �� nullptr

    for (int i = 0; i < size; i++) { // ����������� �� ��� ��������� ������
        Node* newNode = new Node(); // 1 ��������� ������ �����
        newNode->data = values[i]; // 2 ��������� �������� ����� � ������
        newNode->next = nullptr; // 3 ����������� ��������� �� ��������� ����� �� nullptr

        if (head == nullptr) { // ���� ������ �������
            head = newNode; // ������������ ����������� �����
            tail = newNode; // ������������ �������� �����
        }
        else { // ���� ������ �� �������
            tail->next = newNode; // ��������� ������ ����� ���� �������� �����
            tail = newNode; // ��������� �������� �����
        }
    }
}

// ������� ��� ��������� ������ �� �����
void PrintList(Node* head) {
    Node* current = head; // �������� current �� ������� ������

    while (current != nullptr) { // ����������� �� ��� ������ ������
        cout << current->data << " "; // ��������� �������� ��������� �����
        current = current->next; // ������� �� ���������� �����
    }

    cout << endl; // ��������� ������� ������ ����� ���� ��������� ������ ������
}

int main() {
    int values[] = { 1, 2, 2, 4, 5, 2 }; // ������� ������ ������� ��� ��������� ������
    int size = sizeof(values) / sizeof(values[0]); // ���������� ������ ������

    Node* head = nullptr; // ����������� ����������� �� �������� ����� �� nullptr
    Node* tail = nullptr; // ����������� �������� ����� �� nullptr

    CreateList(head, tail, values, size); // ��������� ������ � ������ �������

    cout << "List of elements:" << endl; // ��������� ������ �� �����
    PrintList(head); // ��������� ������ �� �����

    if (DuplicatePair(head)) { // �������� �������� ���� �������� � ���������� ����������
        cout << "A list contains a pair of adjacent elements with the same values." << endl; // ��������� ������ �� �����
    }
    else { // ���� ���� �������� � ���������� ���������� �� ��������
        cout << "The list does not contain a pair of adjacent elements with the same values." << endl; // ��������� ������ �� �����
    }

    Node* current = head; // �������� current �� ������� ������
    while (current != nullptr) { // ����������� �� ��� ������ ������
        Node* temp = current; // ��������� ��������� ��������� �����
        current = current->next; // ������� �� ���������� �����
        delete temp; // ��������� ��������� �����
    }

    return 0; // ���������� 0 ��� ���������� �������� ���������� ��������
}