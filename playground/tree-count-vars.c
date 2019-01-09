#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_CHAR       1000 
#define MAX_SAME_VARS  10
#define MAX_WORD_SIZE  50
#define YES            1
#define NO             0

int COMMON_CHARS = 6;
char buffer[MAX_CHAR];


// Returns INT_MIN if s1 < s2 || INT_MAX if s1 > s2 || len if matched
int strsub(char *s1, char *s2, int common) {
    int count = 0;
    while(*s1++ == *s2++)
        count++;
    if(count >= common) 
        return count;
    else if(*s1 < *s2) return INT_MIN;
    return INT_MAX;
}


int getword(char *word, int limit) {
     int c;
     // Skipped all the whites
     while(isspace(c = getc(stdin)))
             ;
     // Get the valid token condition
     if(c != EOF)
         *word++ = c;
 
     // If it is a number, just add it to the char arr and throw it back
     if(!isalpha(c)) {
         *word = '\0';
         return c;
     }
 
     for(; --limit > 0; word++) {
         if(!isalnum(*word = getc(stdin)) && *word != '_') {
             ungetc(*word, stdin);
             break;
             // Found a space during read so break, otherwise keep reading
         }
     }
     *word = '\0';
     return word[0];
}

int istypedef(char *word) {
    char *types[] = {
        "int",
        "float",
        "long",
        "double",
        "short",
        "char"
    };
    for(int i = 0; i < sizeof(types)/sizeof(types[0]); i++) {
        if(*word != types[i][0]) continue;
        else if(!strcmp(word, types[i])) // Matching
            return 1;
    }
    return 0;
}

struct tnode {
    char *words[MAX_SAME_VARS];
    int word_index = 0;
    struct tnode *left;
    struct tnode *right;
} *tree;

struct tnode* talloc() {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

void taddnode(struct tnode *t, char *word, int len) {
    if(t == NULL) {
        t = talloc();
        t->left = NULL;
        t->right = NULL;
        t->word_index = 0;
        (*t).words[word_index] = word;
    }
    else {
        if(strsub(t->words[0], word) == INT_MIN) {

        }
        else if(strsub(t->words[0], word) == INT_MAX) {

        }
        else {
            // Add to words list
        }
        
    }
    
}

void traverse(char *buff, int len) {
    char wordbuff[MAX_WORD_SIZE];
    int store_next = 0;

    while(getword(wordbuff, MAX_WORD_SIZE) != EOF) {
        if(istypedef(wordbuff))
            store_next = YES;

        if(store_next) {
            store_next = !store_next;
            taddnode(tree, wordbuff, MAX_WORD_SIZE);
        }

        else continue;
    } 
}

int main(int argc, char *argv[]) {

    char c;
    char *filename;
    tree = NULL;

    if(argc > 3) {
        printf("\nUSAGE: tree-count-vars [file-name] [commonchars]");
    }
    FILE *prog = fopen(filename = *(++argv), "r");
    COMMON_CHARS = isdigit(c = *(++argv)[0]) ? c - '0': 6;

    if(prog != NULL) {
        printf("\nOpened file: %s\nCommon: %d\n", filename, COMMON_CHARS);    
    }

    while(fgets(buffer, MAX_CHAR, prog) != NULL) {
        traverse(buffer, MAX_CHAR);
    } 

    return 0;
}
