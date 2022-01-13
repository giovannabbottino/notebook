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
Hash_table * push(Node * node, Hash_table * hash_table);
void erase(Hash_table* hash_table);
void printHashTable(Hash_table * hash_table);

int main(){

    Hash_table * hash_table = createHashTable();
    Node * node = createNode(1, 1);

    hash_table = push(node, hash_table);

    node = createNode(1, 2);

    hash_table = push(node, hash_table);

    printHashTable(hash_table);

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

Hash_table * push(Node * node, Hash_table * hash_table){
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
        hash_table = push(node, hash_table);
    }
    return hash_table;
}
// falta o pop e search
void pop(Hash_table * hash_table, Node * node) {
    int index = hashing(node->key);
    Node * node = hash_table->array[index];
    int i = 1;
    while (node != NULL) {
        if (node != &HT_DELETED_ITEM) {
            if (strcmp(node->key, key) == 0) {
                free(node);
                hash_table->items[index] = &HT_DELETED_ITEM;
            }
        }
        index = hashing(node->key, hash_table->size, i);
        node = hash_table->array[index];
        i++;
    } 
    hash_table->size--;
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
     for(int i=0; i<=hash_table->size; i++){
        Node * at_pos = hash_table->array[i];
        if (at_pos != NULL)
            printf("%d\t%d\t%d\n", i, hash_table->array[i]->key, hash_table->array[i]->data);
     }
 }