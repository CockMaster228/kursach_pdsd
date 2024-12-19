#pragma once
#include <string>
#include <array>
using namespace std;
class SetOnArray {
private:
    array<int,100000> data;
    int count;
public:
    SetOnArray();
    ~SetOnArray();
    bool isEmptySet();
    bool isElementInSet(int value);
    bool test(int index) const;
    void addToSet(int value);
    void createSet(int count, int min, int max, string setType);
    int getSize();
    string printSet(char splitter);
    bool isSubsetInSet(SetOnArray* setB);
    bool isEqualSet(SetOnArray* setB);
    SetOnArray* unionSets(SetOnArray* setB); // сложение множеств
    SetOnArray* intersectionSets(SetOnArray* setB);
    SetOnArray* subtractionSets(SetOnArray* setB); // вычитание множеств
    SetOnArray* symSubstractionSets(SetOnArray* setB);
    void fillSet(int arr[], int size);
};

