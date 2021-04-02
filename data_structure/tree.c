/*Giovanna Borges Bottino giovannabbottino@gmail.com*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data);
Node *createTree(Node *tree, int data);
Node *removeNode(Node *tree, int data);
void printTreeInorder(Node *node);
void printTreePreorder(Node *node);
void printTreePostorder(Node *node);

int main(){
    Node * tree = NULL;
    int data;

    while(scanf(" %d", &data) != EOF){
        tree = createTree(tree, data);
    }
    printTreePreorder(tree);
    printf(".\n");
    printTreeInorder(tree);
    printf(".\n");
    printTreePostorder(tree);
    printf(".\n");

    return 0;
}

Node *createNode(int data){
    Node* node = (Node *)malloc(sizeof(Node));
 
    node->data = data;
    
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *createTree(Node *node, int data){
    if (node == NULL)
        return createNode(data);
 
    if (data < node->data)
        node->left = createTree(node->left, data);
    else if (data > node->data)
        node->right = createTree(node->right, data);
 
    return node;
}

Node *removeNode(Node *node, int data){
    if (node==NULL){
        return NULL;
    } else if ( data < node->data){
        node->left = removeNode(node, data);
    } else if ( data > node->data){
        node->right = removeNode(node, data);
    } else {
        if (node->left == NULL & node->right == NULL){
            free(node);
            node = NULL;
        } else if(node->left == NULL){
            Node *aux = node;
            node = node->right;
            free(aux);

        } else if(node->right == NULL){
            Node *aux = node;
            node = node->left;
            free(aux);
        }
    }
}

// Inorder 
void printTreeInorder(Node *node){
    if (node){
        /*
        *       15
        *     /    \
        *    10     50
        *          /
        *         20
        * printf = 10 15 20 50
        */     
        printTreeInorder(node->left);
        printf("%d ", node->data);
        printTreeInorder(node->right);
    }
}

// Preorder  
void printTreePreorder(Node *node){
    if (node){
        /*
        *       15
        *     /    \
        *    10     50
        *          /
        *         20
        * printf = 15 10 50 20
        */     
        printf("%d ", node->data);
        printTreePreorder(node->left);
        printTreePreorder(node->right);
    }
}

// Postorder   
void printTreePostorder(Node *node){
    if (node){
        /*
        *       15
        *     /    \
        *    10     50
        *          /
        *         20
        * printf = 10 20 50 15
        */     
        printTreePostorder(node->left);
        printTreePostorder(node->right);
        printf("%d ", node->data);
    }
}