#include "SetOnVector.h"
#include <iostream>
using namespace std;
// F1. �������� ������� ���������.
SetOnVector::SetOnVector() {}
// F2. ������ ���������?
bool SetOnVector::isEmptySet()
{
    return data.empty();
}
// F3. �������� �������������� �������� ���������
bool SetOnVector::isElementInSet(int value)
{
    return data.empty();
}
// F4. ���������� � ��������� 
void SetOnVector::addToSet(int value) {
    if (!isElementInSet(value)) {
        data.push_back(value);
    }
}
// F5. �������� ���������
void SetOnVector::createSet(int size, int min, int max, string setType) {
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
int SetOnVector::getSize() {

    return data.size();
}
// F7. ����� ��������� ���������
string SetOnVector::printSet(char splitter) {
    string result = "";
    if (isEmptySet()) return result;
    for (const int& element : data) {
        result += to_string(element) + splitter;
    }
    result.pop_back();
    return result;
}
// F8. �������� ���������
SetOnVector::~SetOnVector() {
    data.clear();
}
// F9. ������������ �-�.
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
// F10. ��������� ���� �������� �-�
bool SetOnVector::isEqualSet(SetOnVector* setB)
{
    return setB->isSubsetInSet(this) && isSubsetInSet(setB);
}
// F11. ����������� ���� ��������
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
// F12. ����������� ���� ��������
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
// F13. �������� ��������
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
// F14. ������������ ��������
SetOnVector* SetOnVector::symSubstractionSets(SetOnVector* setB)
{
    SetOnVector* unionS = unionSets(setB);
    SetOnVector* interS = intersectionSets(setB);
    SetOnVector* result = unionS->subtractionSets(interS);
    return result;
}
void SetOnVector::fillSet(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        data.push_back(arr[i]); // ���������� ����� insert ��� ���������� ��������� � unordered_set
    }
}
