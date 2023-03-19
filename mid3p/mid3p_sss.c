#include<stdio.h>
#include<stdlib.h>
typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node* Create_Node(int val)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    return node;
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


void Print_list(Node* head);
int main() {
    int N,target,split_start,split_end,val;
    scanf("%d %d %d %d",&N,&target,&split_start,&split_end);

    Node* head = NULL;
    Node* cur_node = NULL;
    for(int i=0; i<N; i++){
        scanf("%d",&val);
        Node* new_node = Create_Node(val);
        if(head==NULL){
            head = new_node;
            cur_node = new_node;
        }
        else{
            cur_node->next = new_node;
            cur_node = new_node;
        }
    }

    head = Partial_sort(head, target);
    head = Split_and_Swap(head, split_start, split_end);
    Print_list(head);

	return 0;
}

void Print_list(Node* head)
{
    Node *temp = head;
	while(temp!=NULL){
        if(temp->next==NULL) printf("%d\n", temp->data);
		else printf("%d ", temp->data);
		temp = temp->next;
	}
}
