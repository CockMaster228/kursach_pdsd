#include "SetOnList.h"
#include <iostream>
using namespace std;
// F1. �������� ������� ���������.
SetOnList::SetOnList() {}
// F2. ������ ���������?
bool SetOnList::isEmptySet()
{
    return data.empty();
}
// F3. �������� �������������� �������� ���������
bool SetOnList::isElementInSet(int value)
{
    return find(data.begin(), data.end(), value) != data.end();
}
// F4. ���������� � ��������� 
void SetOnList::addToSet(int value) {

    if (!isElementInSet(value)) {
        data.push_front(value);
    }
}
// F5. �������� ���������
void SetOnList::createSet(int size, int min, int max, string setType) {
    int firstValue;
    if (setType == "A") {
        firstValue = rand() % ((max - min) / 2 + 1) * 2 + min; // ������ ������� - �������� �����
        addToSet(firstValue);
    }
    else {
        firstValue = (rand() % ((max - min) / 5 + 1)) * 5 + min; // ������ ������� - �����, ������� 5
        addToSet(firstValue);
    }
    int i = 1;
    while (i < size) {
        int value;
        if (setType == "A") {
            value = rand() % ((max - min) / 2 + 1) * 2 + min; // ��������� �������� �����
        }
        else if (setType == "B") {
            value = (rand() % ((max - min) / 5 + 1)) * 5 + min; // ��������� �����, ������� 5
        }
        else {
            throw runtime_error("��� ��������� �� ���������");
            // return set;
        }
        addToSet(value);
        // ���������, ��������� �� ������ �������
        if (data.front() != firstValue) {
            firstValue = data.front();
            i++;
        }
    }
    // return set;
}
// F6. �������� ���������
int SetOnList::getSize() {

    return data.size();
}
// F7. ����� ��������� ���������
string SetOnList::printSet(char splitter) {
    string result = "";
    if (isEmptySet()) return result;
    for (int& element : data) {
        result += to_string(element) + splitter;
    }
    result.pop_back();
    return result;
}

// F8. �������� ���������
SetOnList::~SetOnList() {
    data.clear();
}
// 22. ��������� � � ��������� �������� �����. ��������� � � 
// ��������� �����, ������� 5. 
// F9. ������������ �-�.
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
// F10.��������� ���� �������� � - �
bool SetOnList::isEqualSet(SetOnList* setB)
{
    return isSubsetInSet(setB) && isSubsetInSet(this);
}

// F11. ����������� ���� ��������
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
// F12. ����������� ���� ��������
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
// F13. �������� ��������
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
// F14. ������������ ��������
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
