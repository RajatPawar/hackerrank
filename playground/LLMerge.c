#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

typedef struct SinglyLinkedListNode SinglyLinkedListNode;
typedef struct SinglyLinkedList SinglyLinkedList;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

struct SinglyLinkedList {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
};

SinglyLinkedListNode* create_singly_linked_list_node(int node_data) {
    SinglyLinkedListNode* node = malloc(sizeof(SinglyLinkedListNode));

    node->data = node_data;
    node->next = NULL;

    return node;
}

void insert_node_into_singly_linked_list(SinglyLinkedList** singly_linked_list, int node_data) {
    SinglyLinkedListNode* node = create_singly_linked_list_node(node_data);

    if (!(*singly_linked_list)->head) {
        (*singly_linked_list)->head = node;
    } else {
        (*singly_linked_list)->tail->next = node;
    }

    (*singly_linked_list)->tail = node;
}

void print_singly_linked_list(SinglyLinkedListNode* node, char* sep, FILE* fptr) {
    while (node) {
        fprintf(fptr, "%d", node->data);

        node = node->next;

        if (node) {
            fprintf(fptr, "%s", sep);
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

 SinglyLinkedListNode* minnode(SinglyLinkedListNode* h1, SinglyLinkedListNode* h2, int lowest) {
 
     if(h1 == NULL && h2) return h2;
     if(h1 && h2 == NULL) return h1;
     if(h1 == NULL && h2 == NULL) return NULL;
     int h1diff = abs(h1->data - lowest),
         h2diff = abs(h2->data - lowest);
 
     return (h1diff >= h2diff) ? h2 : h1;
 }

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if(!head1) return head2;
    if(!head2) return head1;

    SinglyLinkedListNode *itr = (head1->data <= head2->data) ? head1 : head2;
    SinglyLinkedListNode *head = itr;

    if(itr == head1) head1 = head1->next;
    else head2 = head2->next;

    while(itr) {
        itr->next = minnode(head1, head2, itr->data);
        
        if(itr->next != NULL) {
            if(itr->next == head1) head1 = head1->next;
            else head2 = head2->next;
            itr = itr->next;
        }
        else break;
    }

    return head;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* tests_endptr;
    char* tests_str = readline();
    int tests = strtol(tests_str, &tests_endptr, 10);

    if (tests_endptr == tests_str || *tests_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist1 = malloc(sizeof(SinglyLinkedList));
        llist1->head = NULL;
        llist1->tail = NULL;

        char* llist1_count_endptr;
        char* llist1_count_str = readline();
        int llist1_count = strtol(llist1_count_str, &llist1_count_endptr, 10);

        if (llist1_count_endptr == llist1_count_str || *llist1_count_endptr != '\0') { exit(EXIT_FAILURE); }

        for (int i = 0; i < llist1_count; i++) {
            char* llist1_item_endptr;
            char* llist1_item_str = readline();
            int llist1_item = strtol(llist1_item_str, &llist1_item_endptr, 10);

            if (llist1_item_endptr == llist1_item_str || *llist1_item_endptr != '\0') { exit(EXIT_FAILURE); }

            insert_node_into_singly_linked_list(&llist1, llist1_item);
        }
      
      	SinglyLinkedList* llist2 = malloc(sizeof(SinglyLinkedList));
        llist2->head = NULL;
        llist2->tail = NULL;

        char* llist2_count_endptr;
        char* llist2_count_str = readline();
        int llist2_count = strtol(llist2_count_str, &llist2_count_endptr, 10);

        if (llist2_count_endptr == llist2_count_str || *llist2_count_endptr != '\0') { exit(EXIT_FAILURE); }

        for (int i = 0; i < llist2_count; i++) {
            char* llist2_item_endptr;
            char* llist2_item_str = readline();
            int llist2_item = strtol(llist2_item_str, &llist2_item_endptr, 10);

            if (llist2_item_endptr == llist2_item_str || *llist2_item_endptr != '\0') { exit(EXIT_FAILURE); }

            insert_node_into_singly_linked_list(&llist2, llist2_item);
        }

        SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);

        char *sep = " ";

        print_singly_linked_list(llist3, sep, fptr);
        fprintf(fptr, "\n");

        free_singly_linked_list(llist3);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

