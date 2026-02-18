#ifndef MY_LIST_H
#define MY_LIST_H

#include "study_group.h"

// Структура элемента односвязного списка
typedef struct Node {
    StudyGroup data;        // Данные
    struct Node* next;      // Указатель на следующий элемент
} Node;

// Прототипы функций
Node* push(Node* head, const StudyGroup* group);
Node* pop(Node* head);
void print_list(const Node* head);
void delete_list(Node* head);

#endif