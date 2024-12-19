#pragma once
#include <string>
#include <list>
using namespace std;
class SetOnList {
private:
    list<int> data;
public:
    SetOnList();
    ~SetOnList();
    bool isEmptySet();
    bool isElementInSet(int value);
    void addToSet(int value);
    void createSet(int count, int min, int max, string setType);
    int getSize();
    string printSet(char splitter);
    bool isSubsetInSet(SetOnList* setB);
    bool isEqualSet(SetOnList* setB);
    SetOnList* unionSets(SetOnList* setB); // �������� ��������
    SetOnList* intersectionSets(SetOnList* setB);
    SetOnList* subtractionSets(SetOnList* setB); // ��������� ��������
    SetOnList* symSubstractionSets(SetOnList* setB);
    void fillSet(int arr[], int size);
};
