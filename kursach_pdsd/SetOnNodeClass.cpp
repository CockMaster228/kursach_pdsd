#include "SetOnNodeClass.h"
#include <iostream>
using namespace std;
// F1. Создание пустого множества.
SetOnNodeClass::SetOnNodeClass() : head(nullptr) {}
// F2. Пустое множество?
bool SetOnNodeClass::isEmptySet()
{
    return head == nullptr;
}
// F3. Проверка принадлежности элемента множеству
bool SetOnNodeClass::isElementInSet(int value)
{
    Node* current = head;
    if (isEmptySet()) return false;
    while (current != nullptr) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}
// F4. Добавление в множество 
void SetOnNodeClass::addToSet(int value) {

    if (!isElementInSet(value)) {
        Node* newNode = new Node(value);
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }
}
// F5. Создание множества
void SetOnNodeClass::createSet(int size, int min, int max, string setType) {
    int i = 0;
    while (i < size) {
        int value;
        if (setType == "A") {
            value = rand() % ((max - min) / 2 + 1) * 2 + min;
        }
        else if (setType == "B") {
            value = (rand() % ((max - min) / 5 + 1)) * 5 + min;
        }
        else {
            throw runtime_error("Тип множества не определен");
            // return set;
        }
        if (!isElementInSet(value)) {
            addToSet(value);
            i++;
        }
    }
    // return set;
}
// F6. Мощность множества
int SetOnNodeClass::getSize() {
    int count = 0;
    Node* current = head;
    if (isEmptySet()) return count;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}
// F7. Вывод элементов множества
string SetOnNodeClass::printSet(char splitter) {
    string result = "";
    Node* current = head;
    if (isEmptySet()) return result;
    while (current != nullptr) {
        result += to_string(current->data);
        result += splitter;
        current = current->next;
    }
    result = result.substr(0, result.length() - 1);
    return result;
}
// F8. Удаление множества
SetOnNodeClass::~SetOnNodeClass() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}
// 22. Множество А – множество нечетных чисел. Множество В – 
// множество чисел, кратных 5. 
// F9. Подмножество А-В.
bool SetOnNodeClass::isSubsetInSet(SetOnNodeClass* setB)
{
    Node* current = setB->head;
    if (isEmptySet()) {
        return true;
    }
    while (current != nullptr) {
        if (!isElementInSet(current->data)) {
            return false;
        }
        current = current->next;
    }
    return true;
}

// F10.Равенство двух множеств А - В
bool SetOnNodeClass::isEqualSet(SetOnNodeClass* setB)
{
    return isSubsetInSet(setB) && isSubsetInSet(this);
}
// F11. Объединение двух множеств
SetOnNodeClass* SetOnNodeClass::unionSets(SetOnNodeClass* setB)
{
    SetOnNodeClass* result = new SetOnNodeClass();
    Node* current = setB->head;
    while (current != nullptr) {
        result->addToSet(current->data);
        current = current->next;
    }
    current = this->head;
    while (current != nullptr) {
        result->addToSet(current->data);
        current = current->next;
    }
    return result;
}
// F12. Пересечение двух множеств
SetOnNodeClass* SetOnNodeClass::intersectionSets(SetOnNodeClass* setB)
{
    SetOnNodeClass* result = new SetOnNodeClass();
    Node* current = setB->head;
    if (setB->isEmptySet() || isEmptySet()) return result;
    while (current != nullptr) {
        if (isElementInSet(current->data)) {
            result->addToSet(current->data);
        }
        current = current->next;
    }
    return result;
}
// F13. Разность множеств
SetOnNodeClass* SetOnNodeClass::subtractionSets(SetOnNodeClass* setB)
{
    SetOnNodeClass* result = new SetOnNodeClass();
    Node* current = this->head;
    if (isEmptySet()) return result;
    while (current != nullptr) {
        if (!setB->isElementInSet(current->data)) {
            result->addToSet(current->data);
        }
        current = current->next;
    }
    return result;
}
// F14. Симметричная разность
SetOnNodeClass* SetOnNodeClass::symSubstractionSets(SetOnNodeClass* setB)
{
    SetOnNodeClass* unionS = unionSets(setB);
    SetOnNodeClass* interS = intersectionSets(setB);
    SetOnNodeClass* result = unionS->subtractionSets(interS);
    return result;
}
void SetOnNodeClass::fillSet(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        addToSet(arr[i]);
    }
}
