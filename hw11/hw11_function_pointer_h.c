#include <stdio.h>
#include <stdlib.h>
#define SWAP(a,b) {a^=b^=a^=b;}
typedef struct{
    void (*func)(void *);
    void *argument;
}Task;
typedef struct{
    int* arr;
    int lower;
    int upper;
}Data;
typedef struct{
    Task **tasks;
    int size;
}Task_List;

void job1(void* argument){
    Data* data = (Data*) argument;
    for(int i = data->lower ,j = data->upper; i <= j ; i++, j--)
        if(data->arr[i] != data->arr[j]) SWAP(data->arr[i], data->arr[j]);
}
void job2(void* argument){
    Data* data = (Data*) argument;
    for(int i = data->lower ; i <= data->upper ; i++)
        data->arr[i] = -data->arr[i];
}
void job3(void* argument){
    Data* data = (Data*) argument;
    for(int i = data->lower ; i <= data->upper ; i++)
        data->arr[i] *= 2;
}
void initTask(Task* task, void(*func)(void*),void* argument){
    task->argument = argument;
    task->func = func;
}
void executeTasks(Task_List *task_list){
    for(int i = 0 ; i < task_list->size ; i++)
        task_list->tasks[i]->func(task_list->tasks[i]->argument);
}
