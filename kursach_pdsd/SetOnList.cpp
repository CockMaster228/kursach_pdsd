#include "SetOnList.h"
#include <iostream>
using namespace std;
// F1. Создание пустого множества.
SetOnList::SetOnList() {}
// F2. Пустое множество?
bool SetOnList::isEmptySet()
{
    return data.empty();
}
// F3. Проверка принадлежности элемента множеству
bool SetOnList::isElementInSet(int value)
{
    return find(data.begin(), data.end(), value) != data.end();
}
// F4. Добавление в множество 
void SetOnList::addToSet(int value) {

    if (!isElementInSet(value)) {
        data.push_front(value);
    }
}
// F5. Создание множества
void SetOnList::createSet(int size, int min, int max, string setType) {
    int firstValue;
    if (setType == "A") {
        firstValue = rand() % ((max - min) / 2 + 1) * 2 + min; // первый элемент - нечетное число
        addToSet(firstValue);
    }
    else {
        firstValue = (rand() % ((max - min) / 5 + 1)) * 5 + min; // первый элемент - число, кратное 5
        addToSet(firstValue);
    }
    int i = 1;
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
            // return set;
        }
        addToSet(value);
        // проверяем, изменился ли первый элемент
        if (data.front() != firstValue) {
            firstValue = data.front();
            i++;
        }
    }
    // return set;
}
// F6. Мощность множества
int SetOnList::getSize() {

    return data.size();
}
// F7. Вывод элементов множества
string SetOnList::printSet(char splitter) {
    string result = "";
    if (isEmptySet()) return result;
    for (int& element : data) {
        result += to_string(element) + splitter;
    }
    result.pop_back();
    return result;
}

// F8. Удаление множества
SetOnList::~SetOnList() {
    data.clear();
}
// 22. Множество А – множество нечетных чисел. Множество В – 
// множество чисел, кратных 5. 
// F9. Подмножество А-В.
bool SetOnList::isSubsetInSet(SetOnList* setB)
{
    if (isEmptySet()) {
        return true;
    }
    for (int& element : setB->data) {
        if (!isElementInSet(element)) {
            return false;
        }
    }
    return true;
}
// F10.Равенство двух множеств А - В
bool SetOnList::isEqualSet(SetOnList* setB)
{
    return isSubsetInSet(setB) && isSubsetInSet(this);
}

// F11. Объединение двух множеств
SetOnList* SetOnList::unionSets(SetOnList* setB)
{
    SetOnList* result = new SetOnList();
    for (int& element : data) {
        result->addToSet(element);
    }
    for (int& element : setB->data) {
        result->addToSet(element);
    }
    return result;
}
// F12. Пересечение двух множеств
SetOnList* SetOnList::intersectionSets(SetOnList* setB)
{
    SetOnList* result = new SetOnList();
    if (setB->isEmptySet() || isEmptySet()) return result;

    for (int& element : setB->data) {
        if (isElementInSet(element)) {
            result->addToSet(element);
        }
    }
    return result;
}
// F13. Разность множеств
SetOnList* SetOnList::subtractionSets(SetOnList* setB)
{
    SetOnList* result = new SetOnList();

    if (isEmptySet()) return result;

    for (int& element : data) {
        if (!setB->isElementInSet(element)) {
            result->addToSet(element);
        }
    }
    return result;
}
// F14. Симметричная разность
SetOnList* SetOnList::symSubstractionSets(SetOnList* setB)
{
    SetOnList* unionS = unionSets(setB);
    SetOnList* interS = intersectionSets(setB);
    SetOnList* result = unionS->subtractionSets(interS);
    return result;
}
void SetOnList::fillSet(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        addToSet(arr[i]);
    }
}
