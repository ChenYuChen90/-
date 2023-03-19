#include<stdio.h>
#include<stdlib.h>
#define SWAP(a,b) {a^=b^=a^=b;}
typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node* Merge_lists(Node*, Node*);
void sort_list(Node* head);

Node* Merge_lists(Node* x, Node* y){
    Node *start = NULL, *curr = NULL;
    sort_list(x), sort_list(y);
    int op;
    while(x != NULL || y != NULL){
        if(curr == NULL) start = curr = (Node*)calloc(1,sizeof(Node));
        else{
            while(x && x->data == curr->data) x = x->next;
            while(y && y->data == curr->data) y = y->next;
            if(x == NULL && y == NULL) break;
            curr = curr->next = (Node*)calloc(1, sizeof(Node));
        }

        if(x != NULL && y != NULL){
            if(x->data <= y->data) op = 1;
            else op = 2;
        }
        else if(x != NULL) op = 1;
        else if(y != NULL) op = 2;

        if(op == 1){
            curr->data = x->data;
            x = x->next;
        } else {
            curr->data = y->data;
            y = y->next;
        }
    }
    return start;
}

void sort_list(Node* head){
    for(Node* ny = head; ny != NULL; ny = ny->next)
        for(Node* nx = ny->next; nx != NULL; nx = nx->next)
            if(ny->data > nx->data) SWAP(ny->data, nx->data);
}

void print_list(Node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    puts("");
}

Node* Create_Node(int val);

void Print_list(Node* head);

int main() {
    int N,M,val;
    scanf("%d %d",&N,&M);

    Node* head1 = NULL;
    Node* cur_node = NULL;
    for(int i=0; i<N; i++){
        scanf("%d",&val);
        Node* new_node = Create_Node(val);
        if(head1==NULL){
            head1 = new_node;
            cur_node = new_node;
        }
        else{
            cur_node->next = new_node;
            cur_node = new_node;
        }
    }

    Node* head2 = NULL;
    cur_node = NULL;
    for(int i=0; i<M; i++){
        scanf("%d",&val);
        Node* new_node = Create_Node(val);
        if(head2==NULL){
            head2 = new_node;
            cur_node = new_node;
        }
        else{
            cur_node->next = new_node;
            cur_node = new_node;
        }
    }

    Node* merge_head = Merge_lists(head1, head2);
    Print_list(merge_head);

	return 0;
}

Node* Create_Node(int val)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    return node;
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
