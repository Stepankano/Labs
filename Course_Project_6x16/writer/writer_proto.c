#include <stdio.h>
#include <stdlib.h>
#define __NAME__ "database123"
#define prev previous
#define next next
#define select_type data

typedef struct datainside
{
    int key;
    struct datainside *next, *prev;
} data;

void extract(select_type **head, select_type **tail)
{                                   //получает двойной указатель на голову и хвост списка, меняет их позже
    int size = sizeof(select_type); //размер нужной структуры
    FILE *stream;
    if ((stream = fopen(__NAME__, "r")) == NULL)
    {
        printf("Не удалось открыть файл"); //заменить на перрор
        return;
    }
    select_type *current, *previous1;
    int identyOfEnd = 0;
    current = malloc(size);
    fread(current, size, 1, stream); //считываем перую структуру
    current->prev = NULL;            //зануляем указатель на предыдущую ячейку
    previous1 = current;
    (*head) = previous1; //меняем реальный указатель на начало списка
    while (!feof(stream) && current->next != NULL)
    { //пока ксть файл или элемент не обозначен как последний
        current = malloc(size);
        fread(current, size, 1, stream); //считываем, связываем с предыдущим
        previous1->next = current;
        current->prev = previous1;
        previous1 = current;
    }
    previous1->next = NULL; //следующий у последнего зануляем
    (*tail) = previous1;    //меняем реальный указатель на конец списка
    fclose(stream);
}

void createDataBase(select_type **root, int newkey)
{
    select_type *temp = malloc(sizeof(temp));
    temp->key = newkey;
    temp->next = NULL;
    temp->prev = NULL;
    (*root) = temp;
}

void addDataElement(data **last, int newkey)
{
    select_type *current = malloc(sizeof(current));
    (*last)->next = current;
    current->prev = (*last);
    current->key = newkey;
    current->next = NULL;
    (*last) = current;
}

void printData(select_type *root)
{
    printf("%d", root->key);
    if (root->next != NULL)
    {
        printData(root->next);
    }
}

void zapic(select_type *head)
{
    FILE *stream;
    if ((stream = fopen(__NAME__, "w")) == NULL)
    {
        printf("Не удалось открыть файл");
        return;
    }
    int size = sizeof(select_type);
    while (head)
    {
        fwrite(head, size, 1, stream);
        head = head->next;
    }
    fclose(stream);
}

int main()
{ //создание, запись
    select_type *first, *last;
    int a;
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        createDataBase(&first, 4);
        last = first;
        addDataElement(&last, 3);
        addDataElement(&last, 1);
        addDataElement(&last, 7);
        printData(first);
        printf("\n");
        zapic(first);
        break;
    default:
        extract(&first, &last);
        printData(first);
        printf("\n");
        break;
    }
}