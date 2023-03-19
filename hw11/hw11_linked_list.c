#include <stdio.h>
#include <stdlib.h>
#define SWAP(a, b) {a^=b^=a^=b;}
typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node* createList(int *a, int size);
void push_front(Node** head, int val);
Node* copyList(Node* head);
void deleteElementByIdx(Node** head, int idx);
void SwapElementByIdx(Node** head, int idx1, int idx2);

Node* createList(int *a, int size){
    Node *start, *curr;
    for(int i = 0; i < size ; i++){
        if(i == 0) start = curr = (Node*)calloc(1, sizeof(Node));
        else curr = curr->next = (Node*)calloc(1, sizeof(Node));
        curr->data = a[i];
    }
    return start;
}
void push_front(Node** head, int val){
    Node *start;
    start = (Node*)calloc(1, sizeof(Node));
    start->data = val;
    start->next = *head;
    *head = start;
}
Node* copyList(Node* head){
    Node *otherhead, *curr = NULL;
    while(head != NULL){
        if(curr == NULL) otherhead = curr = (Node*)calloc(1, sizeof(Node));
        else curr = curr->next = (Node*)calloc(1, sizeof(Node));
        curr->data = head->data;
        head = head->next;
    }
    return otherhead;
}
void deleteElementByIdx(Node** head, int idx){
    Node *curr = *head, *tofree;
    if(idx == 0){
        tofree = *head;
        *head = (*head)->next;
    } else {
        idx--;
        while(idx-- && curr->next != NULL) curr = curr->next;
        if(curr->next == NULL) return ;
        tofree = curr->next;
        curr->next = curr->next->next;
    }
    free(tofree);
}
void SwapElementByIdx(Node** head, int idx1, int idx2){
    Node *curr = *head, *m1, *m2;
    if(idx1 > idx2) SWAP(idx1, idx2);
    for(int i = 0; curr != NULL && i <= idx2; i++, curr = curr->next){
        if(i == idx1) m1 = curr;
        else if(i == idx2) m2 = curr;
    }
    if(m1->data != m2->data) SWAP(m1->data, m2->data);
}

void traversal(Node* head);
int main(){

    int T,M,inst,i;
    int val,idx1,idx2;
    scanf("%d%d", &T,&M);
    Node* head = NULL;
    int *array = (int*)malloc(sizeof(int)*M);
    for(i=0; i<M; ++i){
        scanf("%d",&array[i]);
    }
    if(M > 0){
        head = createList(array, M);
        traversal(head);
    }
    while(T--){
        scanf("%d",&inst);
        if(inst == 0){ // insert
            scanf("%d",&val);
            push_front(&head, val);
        }else if(inst == 1){ // copy link list
            Node* otherHead = copyList(head);
            /* free original list*/
            while(head != NULL){
                Node* temp = head;
                head = head->next;
                free(temp);
            }
            head = otherHead;
        }else if(inst == 2){ // delete element
            scanf("%d",&val);
            deleteElementByIdx(&head, val);
        }else if(inst == 3){ // swap link element
            scanf("%d%d",&idx1, &idx2);
            SwapElementByIdx(&head,idx1,idx2);
        }
        traversal(head);
    }

    /* free linked list*/
    while(head != NULL){
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
void traversal(Node* head){
    if(head == NULL)
        return;
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }printf("\n");
}
