#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;

struct Node {
    char *word;
    int count;
    Node *left;
    Node *right;
};

void insertNodeLeft(Node *root, char *word){
    root->left = (Node*)malloc(sizeof(Node));
    root->left->left = NULL;
    root->left->right = NULL;
    root->left->word = (char*)malloc(strlen(word) + 1);
    strcpy(root->left->word, word);
    root->left->count = 1;
}

void insertNodeRight(Node *root, char *word){
    root->right = (Node*)malloc(sizeof(Node));
    root->right->left = NULL;
    root->right->right = NULL;
    root->right->word = (char*)malloc(strlen(word) + 1);
    strcpy(root->right->word, word);
    root->right->count = 1;
}

void findAndInsert (Node *tree, char *word){
    if(strcmp(word, tree->word) < 0) {
        if (tree->left != NULL) findAndInsert(tree->left, word);
        else insertNodeLeft(tree, word);
    } else if (strcmp(word, tree->word) > 0) {
        if (tree->right != NULL) return findAndInsert(tree->right, word);
        else insertNodeRight(tree, word);
    } else ++(tree->count);
}

void deleteNode(Node *root){
    if(root->left != NULL) deleteNode(root->left);
    if(root->right != NULL) deleteNode(root->right);
    if(root->word != NULL) {
        free(root->word);
        root->word = NULL;
    }
    free(root);
    root = NULL;
}

void printTree(Node *root, FILE* fo){
    if(root->left != NULL) printTree(root->left, fo);
    fprintf(fo, "%s: %i\n", root->word, root->count);
    printf("%s occurs %i times.\n", root->word, root->count);
    if(root->right != NULL) printTree(root->right, fo);
}

int main(int argc, char **argv) {
    printf("%s\n", argv[0]);
    FILE *fi, *fo;
    char buffer [100];/*Imposed word limit needed here.*/
    fi = fopen(argv[1], "input02.txt");/*Open input file*/
    if(fi == NULL){
        printf("File not found.");
        exit(1);
    }
    char *delim = "myoutput";/*We need to append index.txt to this*/
    char *newString = &argv[1][5];/*Point to everything after input*/
    printf("%s\n", newString);
    char *finalString = malloc(strlen(newString) + 8);/*Enough space for newString + delim*/
    strcpy(finalString, delim);/*Copies the delimiter to our string that will contain the output file name*/
    strcat(finalString, newString);/*Appends index.txt to it*/
    printf("%s\n", finalString);
    fo = fopen(finalString, "w");/*Open output file*/
    if(fo == NULL){
        printf("File not found.");
        exit(1);
    }
    Node *tree = (Node*)malloc(sizeof(Node));/*Initialize initial node*/
    tree->word = NULL;
    tree->left = NULL;
    tree->right = NULL;
    tree->count = 0;
    fscanf(fi, "%s\0", buffer);/*Put first word in*/
    tree->word = (char *)malloc(strlen(buffer) + 1);
    strcpy(tree->word, buffer);
    ++(tree->count);
    while (fscanf(fi, "%s\0", buffer) != EOF) {/*Put in the rest of the words*/
        printf("%s\n", buffer);
        findAndInsert(tree, buffer);
    }
    printTree(tree, fo);/*Prints words and writes to file*/
    deleteNode(tree);/*Free allocated memory*/
    free(finalString);
    free(fi);
    free(fo);
    exit(0);
}