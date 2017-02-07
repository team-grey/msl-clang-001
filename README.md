##Word Count Binary Search Tree:

Description:  This programs takes words from an input file and organizes them into a binary search tree (BST).  Every time a word re-occurs, the
count of that word is incremented in the BST.  Once all words are recorded, the words are then printed out and written to an output file with their
counts.  It takes the filename as the command-line argument, and uses the index to create the corresponding output file.

###Structures:

struct Node: Used to create the BST
####Variables:
char *word - Holds the word
int count - Holds the number of occurrences of the word in the file.
Node *left - Holds a pointer to the left node.
Node *right - Holds a pointer to the right node.

###Functions:
void findAndInsert - Looks for the node that contains the word in the tree.  If the word cannot be found (it reaches a null
pointer in the tree), calls the corresponding insertNode function to place the new word in.  Takes a Node* (tree) and a
char* (word) as an argument

void insertNodeLeft - Creates a node to contain the new word in the left pointer of the node received by this function.
Takes a Node* (the node with a null pointer to the left of it) and a char* (word) as an argument.

void insertNodeRight - Creates a node to contain the new word in the right pointer of the node received by this function.
Takes a Node* (the node with a null pointer to the right of it) and a char* (word) as an argument.

void printTree - Prints the results of the tree in alphabetic order, as well as writing the results to a file.  Takes
a Node* (tree) and a FILE* (output file) as arguments.

void deleteNode - Frees memory of all the nodes in the BST and the word inside each node.  Takes a Node* (tree) as an argument.