#include <iostream>
using namespace std;

struct Node { // Оголошення структури Node
    int data; // Поле для збереження даних
    Node* next; // Вказівник на наступний елемент
};

// Функція для перевірки наявності сусідніх пар елементів з однаковими значеннями
bool DuplicatePair(Node* head) {
    Node* current = head; // Покажчик current на початок списку
    while (current != nullptr && current->next != nullptr) { // Проходимо по списку до передостаннього елемента
        if (current->data == current->next->data) { // Перевірка чи поточний елемент має те саме значення, що й наступний
            return true; // Якщо знайдена пара з однаковими значеннями, повертаємо true
        }
        current = current->next; // Перехід до наступного елементу
    }
    return false; // Якщо жодна пара з однаковими значеннями не знайдена, повертаємо false
}

// Функція для створення списку з масиву значень
void CreateList(Node*& head, Node*& tail, int values[], int size) {
    head = nullptr; // Ініціалізація початкового та кінцевого вузла як nullptr
    tail = nullptr; // Ініціалізація кінцевого вузла як nullptr

    for (int i = 0; i < size; i++) { // Проходження по усім елементам масиву
        Node* newNode = new Node(); // 1 Створення нового вузла
        newNode->data = values[i]; // 2 Присвоєння значення вузлу з масиву
        newNode->next = nullptr; // 3 Ініціалізація вказівника на наступний вузол як nullptr

        if (head == nullptr) { // Якщо список порожній
            head = newNode; // Встановлення початкового вузла
            tail = newNode; // Встановлення кінцевого вузла
        }
        else { // Якщо список не порожній
            tail->next = newNode; // Додавання нового вузла після кінцевого вузла
            tail = newNode; // Оновлення кінцевого вузла
        }
    }
}

// Функція для виведення списку на екран
void PrintList(Node* head) {
    Node* current = head; // Покажчик current на початок списку

    while (current != nullptr) { // Проходження по усіх вузлах списку
        cout << current->data << " "; // Виведення значення поточного вузла
        current = current->next; // Перехід до наступного вузла
    }

    cout << endl; // Виведення символу нового рядка після виведення всього списку
}

int main() {
    int values[] = { 1, 2, 2, 4, 5, 2 }; // Задання масиву значень для створення списку
    int size = sizeof(values) / sizeof(values[0]); // Визначення розміру масиву

    Node* head = nullptr; // Ініціалізація початкового та кінцевого вузла як nullptr
    Node* tail = nullptr; // Ініціалізація кінцевого вузла як nullptr

    CreateList(head, tail, values, size); // Створення списку з масиву значень

    cout << "List of elements:" << endl; // Виведення тексту на екран
    PrintList(head); // Виведення списку на екран

    if (DuplicatePair(head)) { // Перевірка наявності пари елементів з однаковими значеннями
        cout << "A list contains a pair of adjacent elements with the same values." << endl; // Виведення тексту на екран
    }
    else { // Якщо пари елементів з однаковими значеннями не знайдено
        cout << "The list does not contain a pair of adjacent elements with the same values." << endl; // Виведення тексту на екран
    }

    Node* current = head; // Покажчик current на початок списку
    while (current != nullptr) { // Проходження по усіх вузлах списку
        Node* temp = current; // Тимчасове зберігання поточного вузла
        current = current->next; // Перехід до наступного вузла
        delete temp; // Видалення поточного вузла
    }

    return 0; // Повернення 0 для позначення успішного завершення програми
}