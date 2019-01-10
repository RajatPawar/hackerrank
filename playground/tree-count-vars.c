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
    //printf("\nSTRSUB: %s == %s", s1, s2);
    int count = 0;
    while(*s1++ == *s2++)
        count++;
    if(count == common) 
        return count;
    else if(*(s1 - 1) < *(s2 - 1)) return INT_MIN;
    return INT_MAX;
}

int curr_line_index = 0;

int getword(char *word, int limit, char *line) {
    char *orig = word;

    if(curr_line_index == strlen(line) - 1) return '\n';

    while((isspace(line[curr_line_index]) || line[curr_line_index] == '(' || line[curr_line_index] == ')') && (line[curr_line_index] != '\n' && line[curr_line_index] != EOF))
    {
        curr_line_index++;
    }
    
    while(!isspace(line[curr_line_index]) && (line[curr_line_index] != '(') && (line[curr_line_index] != ')') && line[curr_line_index] != '\n' && line[curr_line_index] != EOF)
    {
        *(word++) = line[curr_line_index++];
    }


    *word = '\0';
    word = orig;

    //curr_line_index++;
    return *word;
}

int istypedef(char *word) {
    char *types[] = {
        "int",
        "float",
        "long",
        "double",
        "short",
        "char",
        "unsigned"
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
    int word_index;
    struct tnode *left;
    struct tnode *right;
} *tree;

struct tnode* talloc() {
    return (struct tnode *) malloc(sizeof(struct tnode));
}


void taddnode(struct tnode **t, char *word, int len) {
    //printf("\nDEBUG: Tree %x", *t);

    if(*t == NULL) {
        struct tnode *temp = talloc();
        temp->left = NULL;
        temp->right = NULL;
        temp->word_index = 0;
        temp->words[temp->word_index] = (char *) malloc(sizeof(*word));
        strcpy(temp->words[temp->word_index], word);
        temp->word_index++;
        *t = temp;
    }
    else {
        //printf("\nDEBUG: Trying to alloc mem in else");
        //printf("\nDEBUG: Adding new word %s to tree to root word %s & word_index = %d", word, (*t)->words[(*t)->word_index - 1], (*t)->word_index);
        //printf("\nRANJANDEBUG: %s",(*t)->words[0]);
         
        if(strsub((*t)->words[0], word, COMMON_CHARS) == INT_MIN) {
            //printf("\nDEBUG: %s < %s", (*t)->words[0], word);
            taddnode(&((*t)->right), word, len);
        }
        else if(strsub((*t)->words[0], word, COMMON_CHARS) == INT_MAX) {
            //printf("\nDEBUG: %s > %s", (*t)->words[0], word);
            taddnode(&((*t)->left), word, len);
        }
        else {
            //printf("\nDEBUG: s1 == s2");
            if((*t)->word_index > MAX_SAME_VARS) printf("\nOverflow");
            (*t)->words[(*t)->word_index++] = (char *) malloc(sizeof(word));
            strcpy((*t)->words[(*t)->word_index - 1], word);
            // Add to words list
        }  
    }
    
}

void traverse(char *buff, int len) {
    char wordbuff[MAX_WORD_SIZE];
    int store_next = 0;
    int result;
    
    //printf("\nDEBUG: Entered traverse()");
    while((result = getword(wordbuff, MAX_WORD_SIZE, buff)) != '\n') {
        //printf("\nCurrent word: %s | Result: %d", wordbuff, result);
        if(istypedef(wordbuff))
        {
            //printf("\nDEBUG: This is a declarator, so store next!");
            store_next = YES;
            continue;
        }

        if(store_next) {
            store_next = !store_next;
            //printf("\nDEBUG: Storing: %s", wordbuff);
            taddnode(&tree, wordbuff, MAX_WORD_SIZE);
        }
    } 
}

void tprint(struct tnode *t) {
    
    if(t != NULL) {
        
        tprint(t->left);

        printf("\nGROUP: ");
        for(int i = 0; i < t->word_index; i++) 
            printf(" %s ", t->words[i]);
        
        tprint(t->right);
    }
}

int main(int argc, char *argv[]) {

    char c;
    char *filename;
    tree = NULL;

    if(argc !=  3) {
        return printf("\nUSAGE: tree-count-vars [file-name] [commonchars]\n");
    }
    FILE *prog = fopen(filename = *(++argv), "r");
    COMMON_CHARS = isdigit(c = *(++argv)[0]) ? c - '0': 6;

    if(prog != NULL) {
        printf("\nOpened file: %s\nCommon: %d\n", filename, COMMON_CHARS);    

        while(fgets(buffer, MAX_CHAR, prog) != NULL) {
            //printf("\nTraversing: %s", buffer);
            traverse(buffer, MAX_CHAR);
            curr_line_index = 0;
        } 
        //printf("\nDEBUG: Closed file");    
        tprint(tree);
    }

    return 0;
}
