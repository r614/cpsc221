#include "chain.h"
#include "chain_given.cpp"
#include <cmath>
#include <iostream>

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain()
{
    clear();
    delete head_;
    head_ = NULL;
    length_ = 0;
    height_ = 0;
    width_ = 0;
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block &ndata)
{
    Node* newNode = new Node(ndata);
    newNode->next = head_;
    Node* curr = head_->next;

    while(curr->next != head)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    length_ = length_ + 1;
    height_ = ndata.height() + height_;
    width_ = ndata.width() + width_;   
}


void Chain::deleteNode(Node* cursor){
    if (cursor->next != NULL) {
        deleteNode(cursor->next);
    }
    if (length_ >= 1)
        length_ -= 1;
    delete cursor;
    assert(length_ >= 0);
}

/**
 * Swaps the two nodes at the indexes "node1" and "node2".
 * The indexes of the nodes are 1 based.
 * assumes i and j are valid (in {1,length_} inclusive)
 * 
 */
void Chain::swap(int i, int j)
{
    Node* first = Chain::walk(head_, i);
    Node* second = Chain::walk(head_, j);
    
    Node* placeholder = first->next;
    first->next = second->next;
    second->next = placeholder;
}

/**
 * Reverses the chain
 */
void Chain::reverse()
{
    Node* current = head_->next; 
    Node *prev = NULL, *next = NULL; 
  
    while (current != head_) 
    { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
}

/*
* Modifies the current chain by "rotating" every group of k nodes by one position.
* In every k-node sub-chain, remove the first node, and place it in the last 
* position of the sub-chain. If the last sub-chain has length less than k,
* then don't change it at all. 
* Some examples with the chain a b c d e:
*   k = 1: a b c d e
*   k = 2: b a d c e
*   k = 3: b c a d e
*   k = 4: b c d a e
*/
void Chain::rotate(int k)
{
    for(int i = 1; i < length_-k; i++)
    {
        swap(i, i+k);
    }
}

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::clear()
{
    if (head_->next == head_){
        return;
    }
    else{
        deleteNode(head_->next);
        head_->next = head_;
        length_ = 0;
    }
}

/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const &other)
{
    height_ = other.height_;
    width_ = other.width_;
    length_ = other.length_;

    Node* otherNode = other.head_;
    Node *current = head_;

    while (otherNode != NULL) 
    {
        current->next = new Node(otherNode->data);
        current = current->next;
        otherNode = otherNode->next;
    }
    current->next = head_;
}