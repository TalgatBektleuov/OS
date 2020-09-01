#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

void push(struct Node* head, struct Node* new_node, struct Node* prev_node) {
    struct Node* current = head;
    while (current != prev_node) {
        current = current->next;
        if (current == NULL) {
            printf("A node with value %d does not exist to add node with value %d after it\n", prev_node->data, new_node->data);
            break;
        }
    }
    if (current == prev_node) {
        new_node->next = current->next;
        current->next = new_node;
        printf("Node with value %d was added after node with value %d\n", new_node->data, prev_node->data);
    }

}
void delete(struct Node* head, struct Node* node_to_delete) {

    struct Node* current = head;
    if (current == node_to_delete) {
        *head = *(node_to_delete->next);
        printf("A node with value %d deleted\n", node_to_delete->data);
        return;
    }
    while (current->next != node_to_delete) {
        current = current->next;
        if (current->next == NULL) {
            printf("A node with value %d does not exist to delete\n", node_to_delete->data);

            break;
        }
    }

    if (current->next == node_to_delete) {
        printf("A node with value %d deleted\n", node_to_delete->data);
        current->next = node_to_delete->next;
    }
}
void print_list(struct Node* head) {
    struct Node* current = head;
    printf("Current values in a linked list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main(void) {
    struct Node* n1 = NULL;
    struct Node* n2 = NULL;
    struct Node* n3 = NULL;
    struct Node* n4 = NULL;

    n1 = (struct Node*)malloc(sizeof(struct Node));
    n2 = (struct Node*)malloc(sizeof(struct Node));
    n3 = (struct Node*)malloc(sizeof(struct Node));
    n4 = (struct Node*)malloc(sizeof(struct Node));

    n1->data = 1;
    n2->data = 2;
    n3->data = 3;
    n4->data = 4;


    push(n1, n2, n1);
    print_list(n1);
    push(n1, n2, n3);
    push(n1, n3, n4);
    push(n1, n3, n2);
    print_list(n1);
    delete(n1, n2);
    print_list(n1);
    delete(n1, n4);
    delete(n1, n1);
    print_list(n1);
    return 0;
}
