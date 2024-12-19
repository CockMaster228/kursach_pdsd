#include <string>
#include <ctime>
#include "SetOnNode.h"
#include "SetOnNodeClass.h"
#include "SetOnList.h"
#include "SetOnSet.h"
#include "SetOnVector.h"
#include "SetOnArray.h"
#include <iostream>

using namespace std;
// Функция для вывода строки таблицы с заданными данными
void displayRows(string, string, string, string, string, string, string);
// Функция для ровных столбцов таблицы
string gapCount(string);
int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int countA = 0, countB = 0;
    do {
        cout << "Введите размер для множества А (от 1000 до 10 000): ";
        cin >> countA;
        if (cin.fail() || countA < 1000 || countA > 10000) {
            cout << "Введено неверное значение. Попробуйте снова." << endl;
            cin.clear(); // Очищаем флаг ошибки ввода
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
        }
    } while (cin.fail() || countA < 1000 || countA > 10000);
    do {
        cout << "Введите размер для множества B (от 1000 до 10 000): ";
        cin >> countB;
        if (cin.fail() || countB < 1000 || countB > 10000) {
            cout << "Введено неверное значение. Попробуйте снова." << endl;
            cin.clear(); // Очищаем флаг ошибки ввода
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
        }
    } while (cin.fail() || countB < 1000 || countB > 10000);
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    displayRows("", "Односвязный список", "Класс 'Список'", "List", "Set", "Vector", "Array");

    // Выделяем память под массивы
    int* arrayA = new int[countA];
    int* arrayB = new int[countB];
    // Переменные для хранения времени (положительные значения)
    unsigned int t1, t2, t3, t4, t5, t6;
    // Генерируем случайные числа
    for (int i = 0; i < countA; i++) {
        arrayA[i] = rand() % (countA);
    }
    for (int i = 0; i < countB; i++) {
        arrayB[i] = rand() % (countB);
    }
    // Замеряем время для выполнения операций
    // Односвязный список
    int startTime = clock();
    Node* setNodeA = fillSet(arrayA, countA); // Создаем и заполняем множество
    t1 = clock() - startTime;
    Node* setNodeB = fillSet(arrayB, countB);
    // Класс "Список"
    startTime = clock();
    SetOnNodeClass* setNodeClassA = new SetOnNodeClass();
    setNodeClassA->fillSet(arrayA, countA);
    t2 = clock() - startTime;
    SetOnNodeClass* setNodeClassB = new SetOnNodeClass();
    setNodeClassB->fillSet(arrayB, countB);
    // List
    startTime = clock();
    SetOnList* setListA = new SetOnList();
    setListA->fillSet(arrayA, countA);
    t3 = clock() - startTime;
    SetOnList* setListB = new SetOnList();
    setListB->fillSet(arrayB, countB);
    // Set
    startTime = clock();
    SetOnSet* setSetA = new SetOnSet();
    setSetA->fillSet(arrayA, countA);
    t4 = clock() - startTime;
    SetOnSet* setSetB = new SetOnSet();
    setSetB->fillSet(arrayB, countB);
    // BitSet
    startTime = clock();
    SetOnArray* setArrayA = new SetOnArray();
    setArrayA->fillSet(arrayA, countA);
    t5 = clock() - startTime;
    SetOnArray* setArrayB = new SetOnArray();
    setArrayB->fillSet(arrayB, countB);
    //Unordered_Set
    startTime = clock();
    SetOnVector* setVectorA = new SetOnVector();
    setVectorA->fillSet(arrayA, countA);
    t6 = clock() - startTime;
    SetOnVector* setVectorB = new SetOnVector();
    setVectorB->fillSet(arrayB, countB);
    // Строка с созданием множества
    displayRows("1. Создание", to_string(t1), to_string(t2), to_string(t3), to_string(t4), to_string(t5), to_string(t6));
    // Мощность множества
    // Переменная для хранения значений операций (в данном случае для мощности)
    int power;
    // Односвязный список
    startTime = clock();
    power = getSize(setNodeA);
    t1 = clock() - startTime;
    // Класс "Список"
    startTime = clock();
    power = setNodeClassA->getSize();
    t2 = clock() - startTime;
    // List
    startTime = clock();
    power = setListA->getSize();
    t3 = clock() - startTime;
    // Set
    startTime = clock();
    power = setSetA->getSize();
    t4 = clock() - startTime;
    // BitSet
    startTime = clock();
    power = setArrayA->getSize();
    t5 = clock() - startTime;
    // Unordered_Set
    startTime = clock();
    power = setVectorA->getSize();
    t6 = clock() - startTime;
    displayRows("2. Мощность", to_string(t1), to_string(t2), to_string(t3), to_string(t4), to_string(t5), to_string(t6));
    bool res;
    // Подмножество A-B
    // Односвязный список
    startTime = clock();
    power = isSubsetInSet(setNodeA, setNodeB);
    t1 = clock() - startTime;
    // Класс "Список"
    startTime = clock();
    power = setNodeClassA->isSubsetInSet(setNodeClassB);
    t2 = clock() - startTime;
    // List
    startTime = clock();
    power = setListA->isSubsetInSet(setListB);
    t3 = clock() - startTime;
    // Set
    startTime = clock();
    power = setSetA->isSubsetInSet(setSetB);
    t4 = clock() - startTime;
    // BitSet
    startTime = clock();
    power = setArrayA->isSubsetInSet(setArrayB);
    t5 = clock() - startTime;
    // Unordered_Set
    startTime = clock();
    power = setVectorA->isSubsetInSet(setVectorB);
    t6 = clock() - startTime;
    displayRows("3. Подмножество A-B", to_string(t1), to_string(t2), to_string(t3), to_string(t4), to_string(t5), to_string(t6));
    // Подмножество A-A
    // Односвязный список
    startTime = clock();
    power = isSubsetInSet(setNodeA, setNodeA);
    t1 = clock() - startTime;
    // Класс "Список"
    startTime = clock();
    power = setNodeClassA->isSubsetInSet(setNodeClassA);
    t2 = clock() - startTime;
    // List
    startTime = clock();
    power = setListA->isSubsetInSet(setListA);
    t3 = clock() - startTime;
    // Set
    startTime = clock();
    power = setSetA->isSubsetInSet(setSetA);
    t4 = clock() - startTime;
    // BitSet
    startTime = clock();
    power = setArrayA->isSubsetInSet(setArrayA);
    t5 = clock() - startTime;
    // Unordered_Set
    startTime = clock();
    power = setVectorA->isSubsetInSet(setVectorA);
    t6 = clock() - startTime;
    displayRows("4. Подмножество А-А", to_string(t1), to_string(t2), to_string(t3), to_string(t4), to_string(t5), to_string(t6));
    // Равенство A-A
    // Односвязный список
    startTime = clock();
    power = isEqualSet(setNodeA, setNodeA);
    t1 = clock() - startTime;
    // Класс "Список"
    startTime = clock();
    power = setNodeClassA->isEqualSet(setNodeClassA);
    t2 = clock() - startTime;
    // List
    startTime = clock();
    power = setListA->isEqualSet(setListA);
    t3 = clock() - startTime;
    // Set
    startTime = clock();
    power = setSetA->isEqualSet(setSetA);
    t4 = clock() - startTime;
    // BitSet
    startTime = clock();
    power = setArrayA->isEqualSet(setArrayA);
    t5 = clock() - startTime;
    // Unordered_Set
    startTime = clock();
    power = setVectorA->isEqualSet(setVectorA);
    t6 = clock() - startTime;
    displayRows("5. Равенство А-А", to_string(t1), to_string(t2), to_string(t3), to_string(t4), to_string(t5), to_string(t6));
    // Равенство B-A
    // Односвязный список
    startTime = clock();
    power = isEqualSet(setNodeB, setNodeA);
    t1 = clock() - startTime;
    // Класс "Список"
    startTime = clock();
    power = setNodeClassB->isEqualSet(setNodeClassA);
    t2 = clock() - startTime;
    // List
    startTime = clock();
    power = setListB->isEqualSet(setListA);
    t3 = clock() - startTime;
    // Set
    startTime = clock();
    power = setSetB->isEqualSet(setSetA);
    t4 = clock() - startTime;
    // BitSet
    startTime = clock();
    power = setArrayB->isEqualSet(setArrayA);
    t5 = clock() - startTime;
    // Unordered_Set
    startTime = clock();
    power = setVectorB->isEqualSet(setVectorA);
    t6 = clock() - startTime;
    displayRows("6. Равенство B-А", to_string(t1), to_string(t2), to_string(t3), to_string(t4), to_string(t5), to_string(t6));
    // Объединение множеств
    // Односвязный список
    startTime = clock();
    // Указатель, который хранит результат операции для оценки
    Node* interNode = intersectionSets(setNodeA, setNodeB);
    t1 = clock() - startTime;
    // Класс "Список"
    startTime = clock();
    SetOnNodeClass* interNodeClass = setNodeClassA->intersectionSets(setNodeClassB);
    t2 = clock() - startTime;
    // List
    startTime = clock();
    SetOnList* interList = setListA->intersectionSets(setListB);
    t3 = clock() - startTime;
    // Set
    startTime = clock();
    SetOnSet* interSet = setSetA->intersectionSets(setSetB);
    t4 = clock() - startTime;
    // BitSet
    startTime = clock();
    SetOnArray* interBit = setArrayA->intersectionSets(setArrayB);
    t5 = clock() - startTime;
    // Unordered_Set
    startTime = clock();
    SetOnVector* interUnSet = setVectorA->intersectionSets(setVectorB);
    t6 = clock() - startTime;
    displayRows("7. Объединение", to_string(t1), to_string(t2), to_string(t3), to_string(t4), to_string(t5), to_string(t6));
    // Пересечение
    // Односвязный список
    startTime = clock();
    Node* uniNode = unionSets(setNodeA, setNodeB);
    t1 = clock() - startTime;

    // Класс "Список"
    startTime = clock();
    SetOnNodeClass* uniNodeClass = setNodeClassA->unionSets(setNodeClassB);
    t2 = clock() - startTime;
    // List
    startTime = clock();
    SetOnList* uniList = setListA->unionSets(setListB);
    t3 = clock() - startTime;
    // Set
    startTime = clock();
    SetOnSet* uniSet = setSetA->unionSets(setSetB);
    t4 = clock() - startTime;
    // BitSet
    startTime = clock();
    SetOnArray* uniBit = setArrayA->unionSets(setArrayB);
    t5 = clock() - startTime;
    // Unordered_Set
    startTime = clock();
    SetOnVector* uniUnSet = setVectorA->unionSets(setVectorB);
    t6 = clock() - startTime;
    displayRows("8. Пересечение", to_string(t1), to_string(t2), to_string(t3), to_string(t4), to_string(t5), to_string(t6));
    // Разность A-B
    // Односвязный список
    startTime = clock();
    Node* subNode = subtractionSets(setNodeA, setNodeB);
    t1 = clock() - startTime;
    // Класс "Список"
    startTime = clock();
    SetOnNodeClass* subNodeClass = setNodeClassA->subtractionSets(setNodeClassB);
    t2 = clock() - startTime;
    // List
    startTime = clock();
    SetOnList* subList = setListA->subtractionSets(setListB);
    t3 = clock() - startTime;
    // Set
    startTime = clock();
    SetOnSet* subSet = setSetA->subtractionSets(setSetB);
    t4 = clock() - startTime;
    // BitSet
    startTime = clock();
    SetOnArray* subBit = setArrayA->subtractionSets(setArrayB);
    t5 = clock() - startTime;
    // Unordered_Set
    startTime = clock();
    SetOnVector* subUnSet = setVectorA->subtractionSets(setVectorB);
    t6 = clock() - startTime;
    displayRows("9. Разность A-B", to_string(t1), to_string(t2), to_string(t3), to_string(t4), to_string(t5), to_string(t6));

    // Разность B-A
    // Односвязный список
    startTime = clock();
    Node* subNodeBA = subtractionSets(setNodeB, setNodeA);
    t1 = clock() - startTime;
    // Класс "Список"
    startTime = clock();
    SetOnNodeClass* subNodeClassBA = setNodeClassB->subtractionSets(setNodeClassA);
    t2 = clock() - startTime;
    // List
    startTime = clock();
    SetOnList* subListBA = setListB->subtractionSets(setListA);
    t3 = clock() - startTime;
    // Set
    startTime = clock();
    SetOnSet* subSetBA = setSetB->subtractionSets(setSetA);
    t4 = clock() - startTime;
    // BitSet
    startTime = clock();
    SetOnArray* subBitBA = setArrayB->subtractionSets(setArrayA);
    t5 = clock() - startTime;
    // Unordered_Set
    startTime = clock();
    SetOnVector* subUnSetBA = setVectorB->subtractionSets(setVectorA);
    t6 = clock() - startTime;
    displayRows("10. Разность B-A", to_string(t1), to_string(t2), to_string(t3), to_string(t4), to_string(t5), to_string(t6));
    // Симметричная разность
    // Односвязный список
    startTime = clock();
    Node* symNode = symSubstractionSets(setNodeA, setNodeB);
    t1 = clock() - startTime;
    // Класс "Список"
    startTime = clock();
    SetOnNodeClass* symNodeClass = setNodeClassA->symSubstractionSets(setNodeClassB);
    t2 = clock() - startTime;
    // List
    startTime = clock();
    SetOnList* symList = setListA->symSubstractionSets(setListB);
    t3 = clock() - startTime;
    // Set
    startTime = clock();
    SetOnSet* symSet = setSetA->symSubstractionSets(setSetB);
    t4 = clock() - startTime;
    // BitSet
    startTime = clock();
    SetOnArray* symMap = setArrayA->symSubstractionSets(setArrayB);
    t5 = clock() - startTime;
    // Set
    startTime = clock();
    SetOnVector* symUnSet = setVectorA->symSubstractionSets(setVectorB);
    t6 = clock() - startTime;

    displayRows("11. Симм. разность", to_string(t1), to_string(t2), to_string(t3), to_string(t4), to_string(t5), to_string(t6));
}

// Функция для вывода строки таблицы с заданными данными
void displayRows(string s1, string s2, string s3, string s4, string s5, string s6, string s7) {
    cout << s1 + gapCount(s1) + s2 + gapCount(s2) + s3 + gapCount(s3) + s4 + gapCount(s4) + s5 + gapCount(s5) + s6 + gapCount(s6) + s7 + gapCount(s7) << endl;
    for (int i = 0; i < 147; i++) {
        cout << "-";
    }
    cout << endl;
}
// Функция для ровных столбцов таблицы
string gapCount(string s) {
    int count = 20 - s.length();
    string res = "";
    for (int i = 0; i < count; i++) {
        res += " ";
    }
    res += "|";
    return res;
}
