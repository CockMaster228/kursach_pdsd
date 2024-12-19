#include "SetOnSet.h"
#include <iostream>
using namespace std;
// F1. �������� ������� ���������.
SetOnSet::SetOnSet() {}
// F2. ������ ���������?
bool SetOnSet::isEmptySet()
{
    return data.empty();
}
// F3. �������� �������������� �������� ���������
bool SetOnSet::isElementInSet(int value)
{
    return data.find(value) != data.end();
}
// F4. ���������� � ��������� 
void SetOnSet::addToSet(int value) {
    if (isElementInSet(value)) data.insert(value);
}
// F5. �������� ���������
void SetOnSet::createSet(int size, int min, int max, string setType) {
    int i = 0;
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
        }
        if (!isElementInSet(value)) {
            addToSet(value);
            i++;
        }
    }
}
// F6. �������� ���������
int SetOnSet::getSize() {
    return data.size();
}
// F7. ����� ��������� ���������
string SetOnSet::printSet(char splitter) {
    string result = "";
    if (isEmptySet()) return result;

    for (const int& element : data) {
        result += to_string(element) + splitter;
    }
    result.pop_back();
    return result;
}
// F8. �������� ���������
SetOnSet::~SetOnSet() {
    data.clear();
}
// 22. ��������� � � ��������� �������� �����. ��������� � � 
// ��������� �����, ������� 5. 
// F9. ������������ �-�.
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
// F10.��������� ���� �������� � - �
bool SetOnSet::isEqualSet(SetOnSet* setB)
{
    return isSubsetInSet(setB) && isSubsetInSet(this);
}
// F11. ����������� ���� ��������
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
// F12. ����������� ���� ��������
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
// F13. �������� ��������
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
// F14. ������������ ��������
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
