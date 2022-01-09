/*
 * Giovanna Borges Bottino 
 * giovannabbottino@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int key;
    struct node *left;
    struct node *right;
} Node;

Node * createNode(int key);
Node * createTree(Node * tree, int key);
Node * removeNode(Node * tree, int key);
Node * inorderSuccessor(Node * node);
void printTreeInorder(Node * node);
void printTreePreorder(Node * node);
void printTreePostorder(Node * node);

int main(){
    Node * tree = NULL;
    int arr[7] = { 20, 10, 15, 30, 25, 35, 33 };
    for (int i =0; i<7; i++){
        tree = createTree(tree, arr[i]);
    }

    printTreePreorder(tree);
    printf(".\n");
    
    printTreeInorder(tree);
    printf(".\n");
    
    printTreePostorder(tree);
    printf(".\n");

    removeNode(tree, 30);
    printTreeInorder(tree);
    printf(".\n");

    return 0;
}

Node *createNode(int key){
    Node* node = (Node *)malloc(sizeof(Node));
 
    node->key = key;
    
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *createTree(Node * node, int key){
    if (node == NULL)
        return createNode(key);
 
    if (key < node->key)
        node->left = createTree(node->left, key);
    else if (key > node->key)
        node->right = createTree(node->right, key);
 
    return node;
}

Node *removeNode(Node * node, int key){
    if (node==NULL){
        return NULL;
    } 
    if ( key < node->key){
        node->left = removeNode(node->left, key);
    } else if ( key > node->key){
        node->right = removeNode(node->right, key);
    } else {
        if(node->left == NULL){
            Node *aux =  node->right;
            free(node);
            return aux;
        } else if(node->right == NULL){
            Node *aux =  node->left;
            free(node);
            return aux;
        } else{
            Node *inorder = inorderSuccessor(node->right);

            node->key = inorder->key;

            node->right = removeNode(node->right , inorder->key);
        } 
        return node;
    }
}

Node *inorderSuccessor(Node * node) {
  while (node && node->left != NULL)
    node = node->left;

  return node;
}

void printTreeInorder(Node * node){
    if (node){ 
        printTreeInorder(node->left);
        printf("%d ", node->key);
        printTreeInorder(node->right);
    }
}
 
void printTreePreorder(Node * node){
    if (node){
        printf("%d ", node->key);
        printTreePreorder(node->left);
        printTreePreorder(node->right);
    }
}
 
void printTreePostorder(Node * node){
    if (node){
        printTreePostorder(node->left);
        printTreePostorder(node->right);
        printf("%d ", node->key);
    }
}