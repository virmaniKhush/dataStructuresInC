#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
    struct Node* head;
    struct Node* current;

void insert_at_end(int val){
    struct Node* tmp;
    tmp = (struct Node*)malloc(1*sizeof(struct Node));

    tmp->data = val;
    tmp->next = NULL;

    if(head->data == 0){
        head = tmp;
    }
    else if(head->next==NULL && head->data!=0){
        current = tmp;
        head->next = current;
        }
    else{
        current->next = tmp;
        current = tmp;
    }
    }
void insert_at_pos_n(int val, int pos){
    struct Node* temp_node;
    struct Node* temp;
    temp = (struct Node*)malloc(1*sizeof(struct Node));
    temp_node = (struct Node*)malloc(1*sizeof(struct Node));
    temp->data = val;
    int cntr = 1;
    if(pos == 1){
        temp->next = head;
        head = temp;
    }
    temp_node = head;
    int flag=0;
    while(temp_node != NULL){
        if(cntr == pos-1 && pos>2){
            temp->next = temp_node->next;
            temp_node->next = temp;
            // printf("\nNode inserted at position %d", cntr+1);
            flag=1;
            break;
        }
        temp_node = temp_node->next;
        cntr++;
    }
    if(flag==0){
        printf("\nPlease enter a valid position !\n");
    }
}
void printll(){
    struct Node* temp;
    temp = head;
    int cntr =1;
    while(temp!= NULL){ 
        printf("\nValue of node %d = %d", cntr, temp->data);
        cntr++;
        temp = temp->next;
    }
}

void delete_using_value(struct Node* temp, int x){
    struct Node* prev;
    while(temp!= NULL){
        if(temp->data == x){
            if(temp==head){
                head = head->next;
                break;
            }
            prev->next = temp->next;
            break;
        }
        prev = temp;
        temp = temp->next; 
    }
}

void main(){
    int n, ix, num_nodes;
    head = (struct Node*)malloc(1*sizeof(struct Node));
    current = (struct Node*)malloc(1*sizeof(struct Node));
    head->data = 0;
    head->next = NULL;
    printf("Enter number of nodes to be added : ");
    scanf("%d", &num_nodes);
    for(ix=0; ix<num_nodes; ix++){
        printf("\nEnter value : ");
        scanf("%d", &n);
        insert_at_end(n);
    }
    printf("\nHead data = %d, current data=%d\n", head->data, current->data);
    printf("\nHead next = %p\n", head->next);
    printf("\n\n");
    printll();
    printf("\n");
    delete_using_value(head, 4);
    printll();
    printf("\n");
    insert_at_pos_n(1234, 4);
    printll();
    printf("\n");
}