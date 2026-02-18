#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include "study_group.h"

// Структура элемента двусвязного списка
typedef struct QueueNode {
    StudyGroup data;           // Данные (объект StudyGroup) - по значению
    struct QueueNode* next;    // Указатель на следующий элемент
    struct QueueNode* prev;    // Указатель на предыдущий элемент
} QueueNode;

// Прототипы функций
QueueNode* enqueue(QueueNode* tail, const StudyGroup* group);
QueueNode* dequeue(QueueNode* tail, StudyGroup* result);
QueueNode* delete_queue(QueueNode* tail);
void print_queue(const QueueNode* tail);
int is_queue_empty(const QueueNode* tail);

#endif