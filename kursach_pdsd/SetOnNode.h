#pragma once
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* createEmptySet();
bool isEmptySet(Node* set);
bool isElementInSet(Node* set, int value);
void addToSet(Node*& set, int value);
Node* createSet(int count, int min, int max, string setType);
int getSize(Node* set);
string printSet(Node* set, char splitter);
void deleteSet(Node*& set);
bool isSubsetInSet(Node* setA, Node* setB);
bool isEqualSet(Node* setA, Node* setB);
Node* unionSets(Node* setA, Node* setB);
Node* intersectionSets(Node* setA, Node* setB);
Node* subtractionSets(Node* setA, Node* setB);
Node* symSubstractionSets(Node* setA, Node* setB);
Node* fillSet(int arr[], int size);
