#include<stdio.h>
#include<stdlib.h>
typedef struct _Node {
    int data;
    struct _Node *next;
} Node;
Node* createNode(int val) {
	Node *ret = (Node*)malloc(sizeof(Node));
	ret->data = val, ret->next = NULL;
	return ret;
}
Node* Partial_sort(Node* head, int x){
    Node *front = Create_Node(-1), *back = Create_Node(-1);
    Node *frontcurr = front, *backcurr = back;
    for(; head != NULL; head = head->next){
        if(head->data < x){
            frontcurr->next = Create_Node(head->data);
            frontcurr = frontcurr->next;
        } else if(head->data >= x){
            backcurr->next = Create_Node(head->data);
            backcurr = backcurr->next;
        }
    }
    frontcurr->next = back->next;
    return front->next;
}

Node* Split_and_Swap(Node* head, int a, int b){
    Node *ptra = NULL, *ptrb = NULL;
    Node *temp = head;
    for(int i = 0; temp->next != NULL; i++, temp = temp->next){
        if(i == a) ptra = temp;
        if(i == b - 1) ptrb = temp;
    }
    if(ptra == ptrb){
        temp->next = head;
        temp = ptrb->next, ptra->next = NULL;
    } else {
        temp->next = ptra->next, ptra->next = NULL;
        temp = ptrb->next, ptrb->next = head;
    }
    return temp;
}
