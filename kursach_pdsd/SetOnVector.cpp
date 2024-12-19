#include "SetOnVector.h"
#include <iostream>
using namespace std;
// F1. Создание пустого множества.
SetOnVector::SetOnVector() {}
// F2. Пустое множество?
bool SetOnVector::isEmptySet()
{
    return data.empty();
}
// F3. Проверка принадлежности элемента множеству
bool SetOnVector::isElementInSet(int value)
{
    return data.empty();
}
// F4. Добавление в множество 
void SetOnVector::addToSet(int value) {
    if (!isElementInSet(value)) {
        data.push_back(value);
    }
}
// F5. Создание множества
void SetOnVector::createSet(int size, int min, int max, string setType) {
    int i = 0;
    while (i < size) {
        int value;
        if (setType == "A") {
            value = rand() % ((max - min) / 2 + 1) * 2 + min; // генерация нечетных чисел
        }
        else if (setType == "B") {
            value = (rand() % ((max - min) / 5 + 1)) * 5 + min; // генерация чисел, кратных 5
        }
        else {
            throw runtime_error("Тип множества не определен");
        }

        if (!isElementInSet(value)) {
            addToSet(value);
            i++;
        }
    }
}
// F6. Мощность множества
int SetOnVector::getSize() {

    return data.size();
}
// F7. Вывод элементов множества
string SetOnVector::printSet(char splitter) {
    string result = "";
    if (isEmptySet()) return result;
    for (const int& element : data) {
        result += to_string(element) + splitter;
    }
    result.pop_back();
    return result;
}
// F8. Удаление множества
SetOnVector::~SetOnVector() {
    data.clear();
}
// F9. Подмножество А-В.
bool SetOnVector::isSubsetInSet(SetOnVector* setB)
{
    if (isEmptySet()) {
        return true;
    }
    for (const int& element : setB->data) {
        if (!isElementInSet(element)) {
            return false;
        }
    }
    return true;
}
// F10. Равенство двух множеств В-А
bool SetOnVector::isEqualSet(SetOnVector* setB)
{
    return setB->isSubsetInSet(this) && isSubsetInSet(setB);
}
// F11. Объединение двух множеств
SetOnVector* SetOnVector::unionSets(SetOnVector* setB)
{
    SetOnVector* result = new SetOnVector();
    for (const int& element : data) {
        result->addToSet(element);
    }
    for (const int& element : setB->data) {
        result->addToSet(element);
    }
    return result;
}
// F12. Пересечение двух множеств
SetOnVector* SetOnVector::intersectionSets(SetOnVector* setB)
{
    SetOnVector* result = new SetOnVector();

    if (setB->isEmptySet() || isEmptySet()) return result;

    for (const int& element : setB->data) {
        if (isElementInSet(element)) {
            result->addToSet(element);
        }
    }
    return result;
}
// F13. Разность множеств
SetOnVector* SetOnVector::subtractionSets(SetOnVector* setB)
{
    SetOnVector* result = new SetOnVector();

    if (isEmptySet()) return result;

    for (const int& element : data) {
        if (!setB->isElementInSet(element)) {
            result->addToSet(element);
        }
    }
    return result;
}
// F14. Симметричная разность
SetOnVector* SetOnVector::symSubstractionSets(SetOnVector* setB)
{
    SetOnVector* unionS = unionSets(setB);
    SetOnVector* interS = intersectionSets(setB);
    SetOnVector* result = unionS->subtractionSets(interS);
    return result;
}
void SetOnVector::fillSet(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        data.push_back(arr[i]); // Используем метод insert для добавления элементов в unordered_set
    }
}
