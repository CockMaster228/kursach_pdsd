//#ifndef PDSD_COURSEWORK_SETONNODECLASS_H #define PDSD_COURSEWORK_SETONNODECLASS_H
//
//#include <ctime> #include <stdlib.h> #include <string>
//
//class SetOnNodeClass
//{
//private:
//	struct Node
//	{
//		Node* next; int value;
//	};
//	Node* head;
//
//public:
//	SetOnNodeClass();
//	SetOnNodeClass(const SetOnNodeClass&);
//	~SetOnNodeClass();
//
//	bool empty_check();
//	// проверка принадлежности элемента множеству bool check_element(int);
//	// добавление нового элемента в множество Node* add_element(int);
//	// создание множества
//	Node* create_set(int, int, int);
//	// мощность множества int set_size();
//	// вывод элементов множества
//	std::string create_string_from_set(const char*);
//	// удаление множества Node* delete_set();
//	// является ли первое подмножеством второго bool check_subset(SetOnNodeClass&);
//	// равенство двух множеств
//	bool equality_set(SetOnNodeClass&);
//	// объединение двух множеств SetOnNodeClass set_union(SetOnNodeClass);
//	// пересечение двух множеств
//	SetOnNodeClass set_intersection(SetOnNodeClass);
//	// разность множеств
//
//	SetOnNodeClass set_difference(SetOnNodeClass);
//	// симметричная разность
//	SetOnNodeClass set_symmetrical_difference(SetOnNodeClass);
//};
//
//#endif //PDSD_COURSEWORK_SETONNODECLASS_H
#pragma once
#include <string>
using namespace std;
class SetOnNodeClass {
private:
    struct Node {
    public:
        int data;
        Node* next;
        Node();
        Node(int data) {
            this->data = data;
            next = nullptr;
        }
    };
    Node* head;
public:
    SetOnNodeClass();
    ~SetOnNodeClass();
    bool isEmptySet();
    bool isElementInSet(int value);
    void addToSet(int value);
    void createSet(int count, int min, int max, string setType);
    int getSize();
    string printSet(char splitter);
    bool isSubsetInSet(SetOnNodeClass* setB);
    bool isEqualSet(SetOnNodeClass* setB);
    SetOnNodeClass* unionSets(SetOnNodeClass* setB); // сложение множеств
    SetOnNodeClass* intersectionSets(SetOnNodeClass* setB);
    SetOnNodeClass* subtractionSets(SetOnNodeClass* setB); // вычитание множеств
    SetOnNodeClass* symSubstractionSets(SetOnNodeClass* setB);
    void fillSet(int arr[], int size);
};
