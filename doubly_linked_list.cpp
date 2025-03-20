/**
 * @file doubly_linked_list.cpp
 * @brief Doubly linked list implementation.
 * @author Atharva Shrivastava
 * @date 2025-03-18
 */


#include "doubly_linked_list.h"


DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

/**
 * getSize
 * 
 * Method to get the size of the list
 * 
 * @param none
 * 
 * @return size of the list
 */
int DoublyLinkedList::getSize() {
    return size;
}

/**
 * isEmpty
 * 
 * Method to check if the list is empty
 * 
 * @param none
 * 
 * @return true if the list is empty, false otherwise
 */
bool DoublyLinkedList::isEmpty() {
    return head == nullptr;
}

/**
 * insertAtHead
 * 
 * Method to insert a new node at the head of the list
 * 
 * @param key the int key for new node, newNode the new dll node
 * 
 * @return nothing; updates doubly linked list and size
 */
void DoublyLinkedList::insertAtHead(int key, DllNode* newNode) {
    newNode->next = head;
    if (head) head->prev = newNode;
    head = newNode;
    if (!tail) tail = newNode;
    size++;
}

/**
 * insertAtTail
 * 
 * Method to insert a new node at the tail of the list
 * 
 * @param key the int key for new node, newNode the new dll node
 * 
 * @return nothing; updates doubly linked list and size
 */
void DoublyLinkedList::insertAtTail(int key, DllNode* newNode) {
    newNode->prev = tail;
    if (tail) tail->next = newNode;
    tail = newNode;
    if (!head) head = newNode;
    size++;
}

/**
 * remove
 * 
 * Method to remove a node with a specific value from the list
 * 
 * @param key
 * 
 * @return nothing; updates doubly linked list
 */
void DoublyLinkedList::remove(int key) {
    DllNode* temp = head;
    while (temp) {
        if (temp->key == key) {
            if (temp->prev) temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            if (temp == head) head = temp->next;
            if (temp == tail) tail = temp->prev;
            delete temp;
            size--;
            return;
        }
        temp = temp->next;
    }
}

/**
 * removeHeaderNode
 * 
 * Method to remove the header node (first node)
 * 
 * @param none
 * 
 * @return nothing; updates doubly linked list
 */
void DoublyLinkedList::removeHeaderNode() {
    if (!head) return;
    DllNode* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete temp;
    size--;
}

/**
 * removeTailNode
 * 
 * Method to remove the tail node (last node)
 * 
 * @param none
 * 
 * @return nothing; updates doubly linked list
 */
void DoublyLinkedList::removeTailNode() {
    if (!tail) return;
    DllNode* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete temp;
    size--;
}

/**
 * moveNodeToHead
 * 
 * Method to move a specific node to the head of the list
 * 
 * @param key
 * 
 * @return nothing; updates doubly linked list
 */
void DoublyLinkedList::moveNodeToHead(int key) {
    remove(key);
    insertAtHead(key, new DllNode(key));
}

/**
 * moveNodeToTail
 * 
 * Method to move a specific node to the tail of the list
 * 
 * @param key
 * 
 * @return nothing; updates doubly linked list
 */
void DoublyLinkedList::moveNodeToTail(int key) {
    remove(key);
    insertAtTail(key, new DllNode(key));
}

/**
 * clear
 * 
 * Method to clear the list (delete all nodes)
 * 
 * @param none
 * 
 * @return nothing; reset size to 0
 */
void DoublyLinkedList::clear() {
    while (head) removeHeaderNode();
}

/**
 * printList
 * 
 * Method to print the doubly linked list from head to tail to console and output
 * 
 * @param none
 * 
 * @return nothing; output is sent to console and to file
 */
void DoublyLinkedList::printList() {
    DllNode* temp = head;
    while (temp) {
        std::cout << "FIFO Node key: " << temp->key << std::endl;
        temp = temp->next;
    }
}

/**
 * reversePrintList
 * 
 * Method to print the doubly linked list from tail to head to console and output
 * 
 * @param none
 * 
 * @return nothing; output is sent to console and to file
 */
void DoublyLinkedList::reversePrintList() {
    DllNode* temp = tail;
    while (temp) {
        std::cout << "FIFO Node key: " << temp->key << std::endl;
        temp = temp->prev;
    }
}
