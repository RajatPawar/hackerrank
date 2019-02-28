#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* next;
    int data;
};

struct Node* cnode(int data) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    return temp;
}

int add_nums(struct Node* head1, struct Node* head2, int *call) {
    if(!head1->next) {
        int add = (head1->data + head2->data);
        head1->data = add % 10;
        return add/10;
    }    

    *call++;
    int now_sum = head1->data + head2->data + add_nums(head1->next, head2->next, call);

    if(call) {
        head1->data = now_sum % 10;
        return now_sum/10;
    }
    else head1->data = now_sum;
    return;
}

void print_lists(struct Node* list) {
    while(list) {
        printf("%d ", list->data);
        list = list->next;
    }
}

int main() {
    struct Node *head1 = NULL, *head2 = NULL;

    head1 = cnode(6);
    head1->next = cnode(5);
    head1->next->next = cnode(2);
    head1->next->next->next = NULL;

    head2 = cnode(2);
    head2->next = cnode(7);
    head2->next->next = cnode(8);
    head2->next->next->next = NULL;
    int c;
    c = 0;
    print_lists(head1);
    printf("\n");
    print_lists(head2);
    add_nums(head1, head2, &c);

    printf("\nResult: ");
    print_lists(head1);
    printf("\n");
    return 0;
}
