#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int val;
    struct Node *left, *right;
}Node;

Node *start, *curr, *mid;
int N, T, type, dir;

Node* create_node(int val){
    Node *create_node_tmp = (Node*)calloc(1, sizeof(Node));
    create_node_tmp->val = val;
    return create_node_tmp;
}

int main(){
    scanf("%d", &N);

    start = curr = create_node(-1); // start block
    for(int i = 1, a; i <= N; i++){
        scanf("%d", &a);
        curr->right = create_node(a);
        curr->right->left = curr;
        curr = curr->right;
    }
    curr->right = create_node(-1); // end block

    curr = mid = start->right; // point to the first block
    for(int i = 1; i < (N%2 ? N/2+1 : N/2); i++) mid = mid->right;

    scanf("%d", &T);
    while(T--){        
        scanf("%d", &type);
        Node *tmp;
        switch(type){
            case 1 :
                scanf("%d", &dir);
                if(dir == -1) curr = curr->left;
                else if(dir == 1) curr = curr->right;
                break;
            case 2 :
                printf("%d\n", curr->val);
                break;
            case 3 :
                tmp = mid;
                mid = N % 2 ? mid->left : mid->right;
                if(curr == tmp) curr = curr->right;
                tmp->left->right = tmp->right;
                tmp->right->left = tmp->left;
                free(tmp);
                N--;
                break;
        }
    }
    return 0;
}