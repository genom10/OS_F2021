#include <stdio.h>

typedef struct nodes {
    int val;
    struct nodes* prev;
    struct nodes* next;
} node;

void print_list(node* start){
    do {
        printf("%i ", start->val);
        start = start->next;
    } while (start != NULL);
    printf("\n");
}


void insert_node(node* nod, int n){
    node* nnode = (node*) malloc (sizeof(node));
    while (nod->next != NULL)
        nod = nod->next;
    nod->next = nnode;
    nnode->val = n;
    nnode->prev = nod;
    nnode->next = NULL;
}
void delete_node(node* toDel){
    if (toDel->prev != NULL)
        toDel->prev->next = toDel->next;
    if (toDel->next != NULL)
        toDel->next->prev = toDel->prev;
    free(toDel);
}

int main(){
    node ll = {12, NULL, NULL};
    node* linkedList = &ll;
    insert_node(linkedList, 13);
    insert_node(linkedList, 14);
    insert_node(linkedList->next->next, 15);
    print_list(linkedList);
    delete_node(linkedList->next);
    print_list(linkedList);
    delete_node(linkedList->next->next);
    print_list(linkedList);
    return 0;
}