#include <stdio.h>
#include <stdlib.h>

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

void job1(void* argument); // reverse
void job2(void* argument); // minus
void job3(void* argument); // double
void initTask(Task* task, void(*func)(void*),void* argument);
void executeTasks(Task_List *task_list);

void job1(void* argument){

}
void job2(void* argument){

}
void job3(void* argument){

}
void initTask(Task* task, void(*func)(void*),void* argument){

}
void executeTasks(Task_List *task_list){

}

int global_array[25];
Task_List *task_list;
int main(){

    int n,i,upper, lower, method;
    // initial global_array
    for(i=0; i<25; ++i){
        global_array[i] = i+1;
    }
    scanf("%d", &n);
    task_list = (Task_List*)malloc(sizeof(Task_List));
    task_list->tasks = (Task**)malloc(sizeof(Task*)*n);
    task_list->size = n;
    for(i=0; i<n; ++i){
        scanf("%d%d%d",&method, &lower, &upper);
        Task *task = (Task*)malloc(sizeof(Task));
        Data *data = (Data*)malloc(sizeof(Data));
        data->arr = global_array;
        data->lower = lower;
        data->upper = upper;
        switch(method){
            case 0:
                initTask(task, job1, data);
                break;
            case 1:
                initTask(task, job2, data);
                break;
            case 2:
                initTask(task, job3, data);
                break;
            default:
                break;
        }
        task_list->tasks[i] = task;
    }
    // execute job
    executeTasks(task_list);

    // print out result
    for(i=0; i<24; ++i){
        printf("%d ", global_array[i]);
    }printf("%d\n",global_array[24]);

    for(i=0; i<n; ++i){
        free(task_list->tasks[i]->argument);
        free(task_list->tasks[i]);
    }free(task_list);
    return 0;
}