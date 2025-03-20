/**
 * @file cache_manager.cpp
 * @brief Cache manager implementation.
 * @author Atharva Shrivastava
 * @date 2025-03-18
 * 
 */

#include "hash_table.h"
#include <iostream>


/**
 * getSize
 * @brief Method to return the size of the hash table
 * 
 * @param none
 * @return Size of the hash table
 */
int HashTable::getSize() {
    return numberOfBuckets;
}

/**
 * calculateHashCode
 * @brief Method to calculate the hash code
 * 
 * @param currentKey Key to calculate hash code
 * @return Hash code
 */
int HashTable::calculateHashCode(int currentKey) {
    return currentKey % numberOfBuckets;
}

/**
 * isEmpty
 * @brief Method to check if the hash table is empty
 * 
 * @param none
 * @return true if the table has zero entries, false otherwise
 */
bool HashTable::isEmpty() {
    return numberOfItems == 0;
}

/**
 * getNumberOfItems
 * @brief Method to return number of items in the hash table
 * 
 * @param none
 * @return Number of items in the table
 */
int HashTable::getNumberOfItems() {
    return numberOfItems;
}

/**
 * add
 * @brief Method to add a node to the hash table
 * 
 * @param curKey Key for this node
 * @param myNode New node to add to the table
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
 * @brief Method to remove node with key value
 * 
 * @param curKey Key of node to remove
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
 * @brief Method to remove all entries from the table
 * 
 * @param none
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
 * @brief Method to retrieve item from the table
 * 
 * @param curKey Retrieve node from table with curKey value
 * @return HashNode* Node with the key value
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
 * getMaxCacheSize
 * @brief Method to retrieve max size of cache from the CacheManager
 * 
 * @param none
 * @return Max size of cache
 */
bool HashTable::contains(int curKey) {
    return getItem(curKey) != nullptr;
}

/**
 * printTable
 * @brief Method to print the hash table
 * 
 * @param none
 * @return nothing, but will print the table
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
 * @brief Method to return the hash table
 * 
 * @param none
 * @return Pointer to the hash table array
 */
HashNode** HashTable::getTable() {
    return table;
}
