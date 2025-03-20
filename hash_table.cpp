/**
 * @file hash_table.cpp
 * @brief Hash table implementation.
 * @author Atharva Shrivastava
 * @date 2025-03-18
 */


#include "hash_table.h"
#include <iostream>

/**
 *  getsize
 * 
 * Method to return the size of the hash table
 * 
 * @param none
 * 
 * @return size of the hash table
 */
int HashTable::getSize() {
    return numberOfBuckets;
}

/**
 * calculateHashCode
 * 
 * Method to calculate the hashCode
 * 
 * @param currentKey     hash table size
 * 
 * @return hashcode for currentKey
 */
int HashTable::calculateHashCode(int currentKey) {
    return currentKey % numberOfBuckets;
}

/**
 * isEmpty
 * 
 * Method to check if HashTable is empty
 * 
 * @param none
 * 
 * @return true if the table has zero entries, false otherwise
 */
bool HashTable::isEmpty() {
    return numberOfItems == 0;
}

/**
 * getNumberOfItems
 * 
 * Method to return number of items in the hash table
 * 
 * @param none
 * 
 * @return number of items in the table
 */
int HashTable::getNumberOfItems() {
    return numberOfItems;
}
/**
 * add
 * 
 * Method to add a node to the hash table
 * 
 * @param curKey    key for this node
 * @param myNode    new node to add to the table
 * 
 * @return true if success, false otherwise
 */
bool HashTable::add(int curKey, HashNode* myNode) {
    int hashIndex = calculateHashCode(curKey);
    myNode->next = table[hashIndex];
    table[hashIndex] = myNode;
    numberOfItems++;
    return true;
}

/**
 * remove
 * 
 * Method to remove node with curKey
 * 
 * @param key     key of node to remove
 * 
 * @return true if success, false otherwise
 */
bool HashTable::remove(int curKey) {
    int hashIndex = calculateHashCode(curKey);
    HashNode* temp = table[hashIndex];
    HashNode* prev = nullptr;
    
    while (temp && temp->key != curKey) {
        prev = temp;
        temp = temp->next;
    }
    
    if (!temp) return false;
    
    if (prev) prev->next = temp->next;
    else table[hashIndex] = temp->next;
    
    delete temp;
    numberOfItems--;
    return true;
}

/**
 * clear
 * 
 * Method to remove all entries from the table
 * 
 * @param none
 * 
 * @return nothing, but will delete all entries from the table
 */
void HashTable::clear() {
    for (int i = 0; i < numberOfBuckets; i++) {
        HashNode* temp = table[i];
        while (temp) {
            HashNode* next = temp->next;
            delete temp;
            temp = next;
        }
        table[i] = nullptr;
    }
    numberOfItems = 0;
}

/**
 * getItem
 * 
 * Method to return pointer to the HashNode
 * 
 * @param curKey    key of node to find
 * 
 * @return pointer to the HashNode
 */
HashNode* HashTable::getItem(int curKey) {
    int hashIndex = calculateHashCode(curKey);
    HashNode* temp = table[hashIndex];
    while (temp) {
        if (temp->key == curKey) return temp;
        temp = temp->next;
    }
    return nullptr;
}

/**
 * contains
 * 
 * Method to check if a node with key exists in the table
 * 
 * @param curKey    key to check
 * 
 * @return true if node with key exists, false otherwise
 */
bool HashTable::contains(int curKey) {
    return getItem(curKey) != nullptr;
}

/**
 * printTable
 * 
 * Method to print out contents of hash table to console and output file
 * 
 * @param none
 * 
 * @return nothing, but will print out contents of hash table
 */
void HashTable::printTable() {
    for (int i = 0; i < numberOfBuckets; i++) {
        std::cout << "Bucket " << i << ": ";
        HashNode* temp = table[i];
        while (temp) {
            std::cout << temp->key << " -> ";
            temp = temp->next;
        }
        std::cout << "Empty\n";
    }
}

/**
 * getTable
 * 
 * Method to return the hash table
 * 
 * @param none
 * 
 * @return the hash table
 */
HashNode** HashTable::getTable() {
    return table;
}
