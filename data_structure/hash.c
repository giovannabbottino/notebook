/*
 * Giovanna Borges Bottino 
 * giovannabbottino@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10

typedef struct node
{
  int key;
  int data;
}Node;

typedef struct hash_table
{
  int capacity;
  int size;
  struct node **array;
}Hash_table;

int attempt = 0;

int hashing(int key);
Node * createNode(int key, int data);
Hash_table * createHashTable();
Hash_table * push(Hash_table * hash_table, Node * node);
void pop(Hash_table * hash_table, Node * node);
Node * search(Hash_table * hash_table, int key);
void erase(Hash_table* hash_table);
void printHashTable(Hash_table * hash_table);

int main(){

    Hash_table * hash_table = createHashTable();
    Node * node = createNode(1, 1);

    hash_table = push(hash_table, node);

    node = createNode(1, 2);

    hash_table = push(hash_table, node);

    node = createNode(4, 3);

    hash_table = push(hash_table, node);
    printHashTable(hash_table);

    Node * searchNode = search(hash_table, node->key);

    printf("Key: %d\tData: %d\n", searchNode->key, searchNode->data);

    printHashTable(hash_table);

    pop(hash_table, node);

    printHashTable(hash_table);

    erase(hash_table);

    return 0;
}

int hashing(int key){
	return (key % CAPACITY);
}

Node * createNode(int key, int data){
    Node* node = (Node *)malloc(sizeof(Node));
 
    node->key = key;
    node->data = data;
    return node;

}

Hash_table * createHashTable(){
    Hash_table* hash_table = (Hash_table *)malloc(sizeof(Hash_table));

    hash_table->size = 0;
    hash_table->capacity = CAPACITY;
    hash_table->array = calloc((size_t)hash_table->capacity, sizeof(Node*));

    return hash_table;
}

Hash_table * push(Hash_table * hash_table, Node * node){
    int index = hashing(node->key) + (hashing(node->key) * attempt);

    Node * at_pos = hash_table->array[index];

    if (at_pos == NULL){

        hash_table->array[index] = node;
        hash_table->size++;
        attempt = 0;
    } else if (hash_table->capacity == attempt){
        printf("There isnt space left\n");
    } else{
        attempt++;
        hash_table = push(hash_table, node);
    }
    return hash_table;
}

void pop(Hash_table * hash_table, Node * node) {
    int index = hashing(node->key) + (hashing(node->key) * attempt);
    Node * closestNode = hash_table->array[index];
    while (closestNode != NULL) {
        if (closestNode->key == node->key &&  closestNode->data == node->data) {
            free(closestNode);
            hash_table->array[index] = NULL;
            attempt = 0;
            break;
        }
        attempt++;
        index = hashing(node->key) + (hashing(node->key) * attempt);
        closestNode = hash_table->array[index];
    } 
    hash_table->size--;
}

Node * search(Hash_table * hash_table, int key) {
    int index = hashing(key) + (hashing(key) * attempt);
    Node * closestNode = hash_table->array[index];
    while (closestNode != NULL) {
        if (closestNode->key == key) {
            attempt = 0;
            return closestNode;
        }
        attempt++;
        index = hashing(key) + (hashing(key) * attempt);
        closestNode = hash_table->array[index];
    }
}

void erase(Hash_table* hash_table) {
    for (int i = 0; i < hash_table->size; i++) {
        Node * node = hash_table->array[i];
        if (node != NULL) {
            free(node);
        }
    }
    free(hash_table->array);
    free(hash_table);
}

void printHashTable(Hash_table * hash_table){
     printf("size: %d\nindex\tkey\tdata\n", hash_table->size);
     for(int i=0; i<hash_table->capacity; i++){
        Node * at_pos = hash_table->array[i];
        if (at_pos != NULL)
            printf("%d\t%d\t%d\n", i, hash_table->array[i]->key, hash_table->array[i]->data);
     }
 }