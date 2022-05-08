#include <iostream>
#include <stdio.h>

typedef struct HashTable{
    int id;
    struct HashTable *next;
}HashTable;

const int SIZEHASH  = 9;

int hashKey(int key);
void hashIndex(int index, HashTable *hashTable[SIZEHASH], int key);
void freeHash(HashTable *hashTable[SIZEHASH]);
void printHash(HashTable *hashTable[SIZEHASH]);

int main(){
    HashTable *hashTable[SIZEHASH] = {NULL};
    int index;

    index = hashKey(5);
    hashIndex(index, hashTable, 5);

    index = hashKey(2);
    hashIndex(index, hashTable, 2);

    index = hashKey(3);
    hashIndex(index, hashTable, 3);

    index = hashKey(8);
    hashIndex(index, hashTable, 8);

    index = hashKey(10);
    hashIndex(index, hashTable, 10);

    index = hashKey(14);
    hashIndex(index, hashTable, 14);

    index = hashKey(28);
    hashIndex(index, hashTable, 28);

    index = hashKey(21);
    hashIndex(index, hashTable, 21);

    index = hashKey(24);
    hashIndex(index, hashTable, 24);

    index = hashKey(19);
    hashIndex(index, hashTable, 19);

    printHash(hashTable);
    //liberando minha hash
    freeHash(hashTable);
    return 0;
}

int hashKey(int key){
    //hash my key
	int hashNumber = key;
    hashNumber = hashNumber % SIZEHASH;

    return hashNumber;
}

void hashIndex(int index, HashTable *hashTable[SIZEHASH], int key){

    HashTable *hashValue = (HashTable*)malloc(sizeof(HashTable*));

    hashValue -> id = key;
    hashValue -> next = NULL;
	
	//caso a lista esteja vazia
    if(hashTable[index] == NULL){
        hashTable[index] = hashValue;
        hashValue -> next = NULL;
    }
    else{
        hashValue -> next = hashTable[index];
        hashTable[index] = hashValue;
    }
    //Hash value se tornou o primeiro elemento da lista
}

void freeHash(HashTable *hashTable[SIZEHASH]){
    HashTable *cursor;
    HashTable *freeValue;
    int i;
	//free without lost my point
    for(i = 0; i < SIZEHASH; i++){

        cursor = hashTable[i] -> next;

        while(cursor != NULL){
            freeValue = cursor;
            cursor = cursor -> next;
            free(freeValue);
        }
    }
}

void printHash(HashTable *hashTable[SIZEHASH]){
    int i, verificador = 0, verificador1 = 0;
    HashTable *cursor;
	//print hash as exercice
    for(i = 0; i < SIZEHASH; i++){

        for(cursor = hashTable[i]; cursor != NULL;){

            if(cursor != NULL)
            {
                if(verificador1 == 0){
                    std::cout <<i<<" -> ";
                    verificador1 = 1;
                }
                std::cout <<cursor -> id<<" ";
                cursor = cursor -> next;
                verificador = 1;
            }
        }
        if(verificador == 1){
            std::cout << std::endl;
            verificador = 0;
            verificador1 = 0;
        }
    }
}

