#ifndef SET_LIST_H
#define SET_LIST_H

#include "study_group.h"

// Структура элемента списка
typedef struct SetNode {
    StudyGroup* data;        // Указатель на данные
    struct SetNode* next;    // Указатель на следующий элемент
} SetNode;

// Прототипы функций
ErrorCode set_insert(SetNode** head, const StudyGroup* group);
ErrorCode set_remove(SetNode** head, const char* group_name);
int set_contains(const SetNode* head, const char* group_name);
SetNode* set_union(const SetNode* set1, const SetNode* set2);
SetNode* set_intersection(const SetNode* set1, const SetNode* set2);
void print_set(const SetNode* head);
void delete_set(SetNode* head);

#endif