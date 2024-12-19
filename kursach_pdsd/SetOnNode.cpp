#include "SetOnNode.h"
#include <iostream>
using namespace std;

// F1. �������� ������� ���������
Node* createEmptySet()
{
    return nullptr;
}

// F2. ������ ���������?
bool isEmptySet(Node* set)
{
    return set == nullptr;
}
// F3. �������� �������������� �������� ���������
bool isElementInSet(Node* set, int value)
{
    Node* current = set;
    if (isEmptySet(current)) return false;
    while (current != nullptr) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}
// F4. ���������� � ��������� 
void addToSet(Node*& set, int value) {
    if (!isElementInSet(set, value)) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = set;
        set = newNode;
    }
}
// F5. �������� ���������
Node* createSet(int size, int min, int max, string setType) {
    Node* set = createEmptySet();

    // �������� ����������� �������� ��������� � ��������� �����������
    if (size <= 0 || (max - min + 1) < size) {
        throw runtime_error("���������� ������� ��������� � ��������� �����������");
        return set;
    }
    if (setType != "A" && setType != "B") {
        throw invalid_argument("��� ��������� �� ���������");
    }
    for (int i = 0; i < size; ++i) {
        int value = rand() % (max - min + 1) + min;
        while (isElementInSet(set, value)) {
            value = rand() % (max - min + 1) + min;
        }
        addToSet(set, value);
    }
    return set;
}
// F6. �������� ���������
int getSize(Node* set) {
    int count = 0;
    Node* current = set;
    if (isEmptySet(current)) return count;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// F7. ����� ��������� ���������
string printSet(Node* set, char splitter) {
    string result = "";
    Node* current = set;
    if (isEmptySet(current)) return result;
    while (current != nullptr) {
        result += to_string(current->data);
        result += splitter;
        current = current->next;
    }
    result = result.substr(0, result.length() - 1);
    return result;
}
// F8. �������� ���������
void deleteSet(Node*& set) {
    while (set != nullptr) {
        Node* temp = set;
        set = set->next;
        delete temp;
    }
    set = nullptr;
}
// 22. ��������� � � ��������� �������� �����. ��������� � � 
// ��������� �����, ������� 5. 
// F9. ������������ �-�.
bool isSubsetInSet(Node* setA, Node* setB)
{
    Node* currentA = setA;
    if (isEmptySet(setA)) {
        return true;
    }

    while (currentA != nullptr) {
        if (!isElementInSet(setB, currentA->data)) {
            return false;
        }
        currentA = currentA->next;
    }
    return true;
}
// F10.��������� ���� �������� � - �
bool isEqualSet(Node* setA, Node* setB)
{
    return isSubsetInSet(setA, setB) && isSubsetInSet(setB, setA);
}
// F11. ����������� ���� ��������
Node* unionSets(Node* setA, Node* setB)
{
    Node* result = createEmptySet();
    Node* currentA = setA;
    Node* currentB = setB;
    while (currentA != nullptr) {
        addToSet(result, currentA->data);
        currentA = currentA->next;
    }
    while (currentB != nullptr) {
        addToSet(result, currentB->data);
        currentB = currentB->next;
    }
    return result;
}
// F12. ����������� ���� ��������
Node* intersectionSets(Node* setA, Node* setB)
{
    Node* result = createEmptySet();
    Node* currentA = setA;
    if (isEmptySet(setB) || isEmptySet(setA)) return result;
    while (currentA != nullptr) {
        if (isElementInSet(setB, currentA->data)) {
            addToSet(result, currentA->data);
        }
        currentA = currentA->next;
    }
    return result;
}
// F13. �������� ��������
Node* subtractionSets(Node* setA, Node* setB)
{
    Node* result = createEmptySet();
    Node* currentA = setA;
    if (isEmptySet(setA)) return result;
    while (currentA != nullptr) {
        if (!isElementInSet(setB, currentA->data)) {
            addToSet(result, currentA->data);
        }
        currentA = currentA->next;
    }
    return result;
}

// F14. ������������ ��������
Node* symSubstractionSets(Node* setA, Node* setB)
{
    Node* result = createEmptySet();
    result = subtractionSets(unionSets(setA, setB), intersectionSets(setA, setB));
    return result;
}
// �������� �������� �� ���������
void removeFromSet(Node*& set, int value) {
    if (set == nullptr) return;
    if (set->data == value) {
        Node* temp = set;
        set = set->next;
        delete temp;
        return;
    }
    Node* current = set;
    while (current->next != nullptr) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }
        current = current->next;
    }
}
Node* fillSet(int arr[], int size) {
    Node* set = createEmptySet();
    for (int i = 0; i < size; i++) {
        addToSet(set, arr[i]);
    }
    return set;
}
