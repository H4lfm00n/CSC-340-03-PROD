/**
 * @file cache_manager.cpp
 * @brief Cache manager implementation.
 * @author Atharva Shrivastava
 * @date 2025-03-18
 * updated 2025-04-10
 * Note: Corrected cache manager implementation in the cache_manager.cpp file.
 * 
 */
#include "cache_manager.h"
#include <iostream>

/**
 * getTable
 *
 * Method to return the hash table
 *
 * @param none
 * @return pointer to the hash table
 */
HashTable* CacheManager::getTable() {
    return hashTable;
}

/**
 * getList
 *
 * Method to return the FIFO list
 *
 * @param none
 * @return pointer to the FIFO list
 */
DoublyLinkedList* CacheManager::getList() {
    return doublyLinkedList;
}

/**
 * isEmpty
 *
 * Method to check if CacheManager is empty
 *
 * @param none
 * @return true if the CacheManager has zero entries, false otherwise
 */
bool CacheManager::isEmpty() {
    return hashTable->isEmpty();
}

/**
 * getSize
 *
 * Method to return the number of items in the CacheManager
 *
 * @param none
 * @return number of items in the CacheManager
 */
int CacheManager::getSize() {
    return hashTable->getNumberOfItems();
}

/**
 * add
 *
 * Method to add a node to the CacheManager
 *
 * @param curKey key for this node
 * @param myNode new node to add to the table
 * @return true if success, false otherwise
 */
bool CacheManager::add(int curKey, DllNode* myNode) {
    if (doublyLinkedList->getSize() >= maxCacheSize) {
        DllNode* tailNode = doublyLinkedList->tail;
        if (tailNode) {
            hashTable->remove(tailNode->key);
            doublyLinkedList->removeTailNode();
        }
    }
    doublyLinkedList->insertAtHead(curKey, myNode);
    HashNode* hashNode = new HashNode(curKey, myNode);
    return hashTable->add(curKey, hashNode);
}

/**
 * remove
 *
 * Method to remove node with curKey
 *
 * @param curKey key of node to remove
 * @return true if success, false otherwise
 */
bool CacheManager::remove(int curKey) {
    doublyLinkedList->remove(curKey);
    return hashTable->remove(curKey);
}

/**
 * clear
 *
 * Method to remove all entries from the CacheManager
 *
 * @param none
 * @return nothing
 */
void CacheManager::clear() {
    doublyLinkedList->clear();
    hashTable->clear();
}

/**
 * getItem
 *
 * Method to retrieve item from the CacheManager
 *
 * @param curKey key of the item to retrieve
 * @return pointer to the DllNode
 */
DllNode* CacheManager::getItem(int curKey) {
    if (contains(curKey)) {
        doublyLinkedList->moveNodeToHead(curKey);
        return hashTable->getItem(curKey)->getFifoNode();
    }
    return nullptr;
}

/**
 * getMaxCacheSize
 *
 * Method to retrieve max size of cache from the CacheManager
 *
 * @param none
 * @return max size of cache manager
 */
int CacheManager::getMaxCacheSize() {
    return maxCacheSize;
}

/**
 * contains
 *
 * Method to determine if a key value is in the cache
 *
 * @param curKey key to check for existence
 * @return true if exists, false otherwise
 */
bool CacheManager::contains(int curKey) {
    if (hashTable->contains(curKey)) {
        doublyLinkedList->moveNodeToHead(curKey);
        return true;
    }
    return false;
}

/**
 * printCache
 *
 * Method to print out the cache information
 *
 * @param none
 * @return nothing
 */
void CacheManager::printCache() {
    std::cout << "\n\nPrinting out the cache contents\n" << std::endl;
    std::cout << "Here are the FIFO List contents: " << std::endl;
    doublyLinkedList->printList();

    std::cout << "\nHere are the Hash Table contents (" << getSize() << " entries):" << std::endl;
    hashTable->printTable();

    std::cout << "End of cache contents\n\n" << std::endl;
}

