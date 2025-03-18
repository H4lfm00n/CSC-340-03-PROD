/**
 * @file cache_manager.cpp
 * @brief Cache manager implementation.
 * @author Atharva Shrivastava
 * @date 2025-03-18
 * 
 */

/*

    cache_manager.cpp – implementation file that contains the following 
    methods: 
    1. getTable - return the hash table 
    2. getList - return the FIFO list 
    3. isEmpty - Check if the HashTable is empty 
    4. getSize - return the number of items in the CacheManager 
    5. add - adds a new node to the CacheManager and to doublyLinkedList  
    6. remove – remove node with key value 
    7. clear - remove all entries from the CacheManager 
    8. getItem - retrieve item from the CacheManager, and moves node to the 
    head of doublyLinkedList 
    9. getMaxCacheSize - retrieve max size of cache from the CacheManager 
    10.  contains - check if a node with key exists in the table, and moves node to 
    the head of doublyLinkedList, if true 
    11.  printCache - print out the cache information

*/

#include "cache_manager.h"
