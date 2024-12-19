#include "SetOnArray.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// F1. �������� ������� ���������.
SetOnArray::SetOnArray() : count(0) {
    for (int i = 0; i < data.size(); i++) data[i] = i;
    srand(static_cast<unsigned int>(time(0))); // ������������� ���������� ��������� �����
}

// F2. ������ ���������?
bool SetOnArray::isEmptySet() {
    return count == 0;
}

// F3. �������� �������������� �������� ���������
bool SetOnArray::isElementInSet(int value) {
    return find(data.begin(), data.begin() + count, value) != data.begin() + count;
}

// ����� ��� �������� ������� ������� � �������� �������
bool SetOnArray::test(int index) const {
    if (index >= 10000) {
        throw std::out_of_range("Index exceeds maximum allowed value of 9999");
    }
    return data[index] != 0;
}

// F4. ���������� � ��������� 
void SetOnArray::addToSet(int value) {
    if (!isElementInSet(value)) {
        data[count++] = value;
    }
}

// F5. �������� ���������
void SetOnArray::createSet(int size, int min, int max, string setType) {
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
            throw runtime_error("��� ��������� �� ���������");
        }
        if (!isElementInSet(value)) {
            addToSet(value);
            i++;
        }
    }
}

// F6. �������� ���������
int SetOnArray::getSize() {
    return count;
}

// F7. ����� ��������� ���������
string SetOnArray::printSet(char splitter) {
    string result = "";
    if (isEmptySet()) return result;
    for (int i = 0; i < count; i++) {
        result += to_string(data[i]) + splitter;
    }
    if (!result.empty()) result.pop_back();
    return result;
}

// F8. �������� ���������
SetOnArray::~SetOnArray() {
    data.fill(0);
    count = 0;
}

// F9. ������������ �-�.
bool SetOnArray::isSubsetInSet(SetOnArray* setB) {
    if (isEmptySet()) {
        return true;
    }
    for (int i = 0; i < count; i++) {
        if (!setB->isElementInSet(data[i])) {
            return false;
        }
    }
    return true;
}

// F10. ��������� ���� ��������
bool SetOnArray::isEqualSet(SetOnArray* setB) {
    return isSubsetInSet(setB) && setB->isSubsetInSet(this);
}

// F11. ����������� ���� ��������
SetOnArray* SetOnArray::unionSets(SetOnArray* setB) {
    SetOnArray* result = new SetOnArray();
    for (int i = 0; i < count; i++) {
        result->addToSet(data[i]);
    }
    for (int i = 0; i < setB->getSize(); i++) {
        result->addToSet(setB->data[i]);
    }
    return result;
}

// F12. ����������� ���� ��������
SetOnArray* SetOnArray::intersectionSets(SetOnArray* setB) {
    SetOnArray* result = new SetOnArray();
    if (setB->isEmptySet() || isEmptySet()) return result;
    for (int i = 0; i < setB->getSize(); i++) {
        if (isElementInSet(setB->data[i])) {
            result->addToSet(setB->data[i]);
        }
    }
    return result;
}

// F13. �������� ��������
SetOnArray* SetOnArray::subtractionSets(SetOnArray* setB) {
    SetOnArray* result = new SetOnArray();
    if (isEmptySet()) return result;
    for (int i = 0; i < count; i++) {
        if (!setB->isElementInSet(data[i])) {
            result->addToSet(data[i]);
        }
    }
    return result;
}

// F14. ������������ ��������
SetOnArray* SetOnArray::symSubstractionSets(SetOnArray* setB) {
    SetOnArray* unionS = unionSets(setB);
    SetOnArray* interS = intersectionSets(setB);
    SetOnArray* result = unionS->subtractionSets(interS);
    delete unionS;
    delete interS;
    return result;
}

// ���������� ��������� �� �������
void SetOnArray::fillSet(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        addToSet(arr[i]);
    }
}
