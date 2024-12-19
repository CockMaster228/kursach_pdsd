#pragma once
#include <string>
#include <set>
using namespace std;
class SetOnSet {
private:
    set<int> data;
    size_t count;
public:
    SetOnSet();
    ~SetOnSet();
    bool isEmptySet();
    bool isElementInSet(int value);
    void addToSet(int value);
    void createSet(int count, int min, int max, string setType);
    int getSize();
    string printSet(char splitter);
    bool isSubsetInSet(SetOnSet* setB);
    bool isEqualSet(SetOnSet* setB);
    SetOnSet* unionSets(SetOnSet* setB); // сложение множеств
    SetOnSet* intersectionSets(SetOnSet* setB);
    SetOnSet* subtractionSets(SetOnSet* setB); // вычитание множеств
    SetOnSet* symSubstractionSets(SetOnSet* setB);
    void fillSet(int arr[], int size);
};

