#include "SetOnSet.h"
#include <iostream>
using namespace std;
// F1. Создание пустого множества.
SetOnSet::SetOnSet() {}
// F2. Пустое множество?
bool SetOnSet::isEmptySet()
{
    return data.empty();
}
// F3. Проверка принадлежности элемента множеству
bool SetOnSet::isElementInSet(int value)
{
    return data.find(value) != data.end();
}
// F4. Добавление в множество 
void SetOnSet::addToSet(int value) {
    if (isElementInSet(value)) data.insert(value);
}
// F5. Создание множества
void SetOnSet::createSet(int size, int min, int max, string setType) {
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
int SetOnSet::getSize() {
    return data.size();
}
// F7. Вывод элементов множества
string SetOnSet::printSet(char splitter) {
    string result = "";
    if (isEmptySet()) return result;

    for (const int& element : data) {
        result += to_string(element) + splitter;
    }
    result.pop_back();
    return result;
}
// F8. Удаление множества
SetOnSet::~SetOnSet() {
    data.clear();
}
// 22. Множество А – множество нечетных чисел. Множество В – 
// множество чисел, кратных 5. 
// F9. Подмножество В-А.
bool SetOnSet::isSubsetInSet(SetOnSet* setA)
{
    if (isEmptySet()) {
        return true;
    }
    for (const int& element : setA->data) {
        if (!isElementInSet(element)) {
            return false;
        }
    }
    return true;
}
// F10.Равенство двух множеств А - В
bool SetOnSet::isEqualSet(SetOnSet* setB)
{
    return isSubsetInSet(setB) && isSubsetInSet(this);
}
// F11. Объединение двух множеств
SetOnSet* SetOnSet::unionSets(SetOnSet* setB)
{
    SetOnSet* result = new SetOnSet();

    for (const int& element : data) {
        result->addToSet(element);
    }
    for (const int& element : setB->data) {
        result->addToSet(element);
    }
    return result;
}
// F12. Пересечение двух множеств
SetOnSet* SetOnSet::intersectionSets(SetOnSet* setB)
{
    SetOnSet* result = new SetOnSet();
    if (setB->isEmptySet() || isEmptySet()) return result;
    for (const int& element : setB->data) {
        if (isElementInSet(element)) {
            result->addToSet(element);
        }
    }
    return result;
}
// F13. Разность множеств
SetOnSet* SetOnSet::subtractionSets(SetOnSet* setB)
{
    SetOnSet* result = new SetOnSet();
    if (isEmptySet()) return result;
    for (const int& element : data) {
        if (!setB->isElementInSet(element)) {
            result->addToSet(element);
        }
    }
    return result;
}
// F14. Симметричная разность
SetOnSet* SetOnSet::symSubstractionSets(SetOnSet* setB)
{
    SetOnSet* unionS = unionSets(setB);
    SetOnSet* interS = intersectionSets(setB);
    SetOnSet* result = unionS->subtractionSets(interS);
    return result;
}
void SetOnSet::fillSet(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        addToSet(arr[i]);
    }
}
