#include <stdio.h>
#include <stdlib.h>

typedef struct node* NodePtr;

typedef struct node {

    enum {
       // PHONE = 0,
        MOBILE = 1
    } ob;

} node_object;


struct test {
    int b;
    long int a;
} teto;

NodePtr nalloc_st_name() {
    return (NodePtr) malloc(sizeof(struct node));
}

NodePtr nalloc_ob_name() {
    return (NodePtr) malloc(sizeof(node_object));
}
int main() {

    struct node *temp = nalloc_st_name();
    struct node *tempother = nalloc_ob_name();

    //printf("\nsize of struct object direct: %ld", sizeof(node_object));
    //printf("\nsize of struct nalloc() (sizeof(struct)): %ld", sizeof(*temp));
    //printf("\nsize of struct nalloc() (sizeof(object)): %ld\n", sizeof(*tempother));
    printf("\nSizeof test: %ld", sizeof(struct test));
    return 0;
}
