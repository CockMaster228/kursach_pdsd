#pragma once
#include <string>
#include <vector>
using namespace std;
class SetOnVector {
private:
    vector<int> data;
public:
    SetOnVector();
    ~SetOnVector();
    bool isEmptySet();
    bool isElementInSet(int value);
    void addToSet(int value);
    void createSet(int count, int min, int max, string setType);
    int getSize();
    string printSet(char splitter);
    bool isSubsetInSet(SetOnVector* setB);
    bool isEqualSet(SetOnVector* setB);
    SetOnVector* unionSets(SetOnVector* setB); // сложение множеств
    SetOnVector* intersectionSets(SetOnVector* setB);
    SetOnVector* subtractionSets(SetOnVector* setB); // вычитание множеств
    SetOnVector* symSubstractionSets(SetOnVector* setB);
    void fillSet(int arr[], int size);
}; 
