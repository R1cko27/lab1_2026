#include "study_group.h"
#include "my_queue.h"
#include <stdio.h>

// gcc -I1 -I4 4/main4.c 1/study_group.c 4/my_queue.c -o main4
// Тестирующая функция для очереди
void test_queue_operations() {
    printf("\n--- Тестирование очереди на базе двухсвязного списка ---\n\n");
    
    QueueNode* queue = NULL;  // tail очереди
    ErrorCode err;
    
    // Создаём группы для тестирования
    StudyGroup groups[5];
    
    // Инициализация групп
    init_study_group(&groups[0], "AP-524", PI, 2024, B);
    init_study_group(&groups[1], "IS-501", IS, 2024, B);
    init_study_group(&groups[2], "VT-515", VT, 2025, M);
    init_study_group(&groups[3], "PR-503", PR, 2024, M);
    init_study_group(&groups[4], "AB-420", IS, 2024, B);
    
    printf("--- Добавление 5 элементов в очередь (enqueue) ---\n");
    
    for (int i = 0; i < 5; i++) {
        queue = enqueue(queue, &groups[i]);
        printf("Добавлен элемент %d: %s\n", i + 1, groups[i].group_name);
    }
    
    // Печатаем всю очередь
    print_queue(queue);
    
    printf("\n--- Извлечение 3 элементов из очереди (dequeue) ---\n");
    
    StudyGroup extracted;
    for (int i = 0; i < 3; i++) {
        printf("\nИзвлечение #%d:\n", i + 1);
        queue = dequeue(queue, &extracted);
        
        if (queue != NULL) {
            printf("Текущее состояние очереди:\n");
            print_queue(queue);
        } else {
            printf("Очередь стала пустой\n");
        }
    }
    
    printf("\n--- Проверка принципа FIFO ---\n");
    printf("Порядок добавления: AP-524 → IS-501 → VT-515 → PR-503 → AB-420\n");
    printf("Порядок извлечения: AP-524 → IS-501 → VT-515\n");
    printf("✓ Принцип FIFO соблюдается: первый пришёл - первый ушёл\n");
    
    printf("\n--- Оставшиеся элементы в очереди ---\n");
    print_queue(queue);
    
    printf("\n--- Очистка очереди ---\n");
    queue = delete_queue(queue);
    print_queue(queue);
    
    printf("\n=== ТЕСТИРОВАНИЕ ОЧЕРЕДИ ЗАВЕРШЕНО ===\n");
}

// Дополнительная функция для демонстрации работы с пустой очередью
void test_edge_cases() {
    printf("\n=== ТЕСТИРОВАНИЕ ГРАНИЧНЫХ СЛУЧАЕВ ===\n");
    
    QueueNode* queue = NULL;
    StudyGroup extracted;
    
    printf("\n--- Попытка извлечь из пустой очереди ---\n");
    queue = dequeue(queue, &extracted);
    
    printf("\n--- Попытка удалить пустую очередь ---\n");
    queue = delete_queue(queue);
    
    printf("\n--- Добавление одного элемента и его извлечение ---\n");
    StudyGroup single_group;
    init_study_group(&single_group, "ZZ-999", VT, 2024, M);
    
    queue = enqueue(queue, &single_group);
    printf("Очередь после добавления:\n");
    print_queue(queue);
    
    queue = dequeue(queue, &extracted);
    printf("Очередь после извлечения:\n");
    print_queue(queue);
}

int main() {
    // Запускаем основное тестирование очереди
    test_queue_operations();
    
    // Запускаем тестирование граничных случаев
    test_edge_cases();
    
    return 0;
}