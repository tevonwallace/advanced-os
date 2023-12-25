//
//  QueueNode.cpp
//  Advanced OS - Final
//
//  Created by Dr. Tevon Wallace  on 12/24/23.
//  Copyright © 2023 Tevon Wallace. All rights reserved.
//

#include "QueueNode.hpp"

// MARK: - Constructors
QueueNode :: QueueNode(): data() {
    this->prevNode = this->nextNode = NULL;
}

QueueNode :: QueueNode(LinkedListDataNode data, QueueNode *prevNode, QueueNode *nextNode) {
    this->data = data;
    this->prevNode = prevNode;
    this->nextNode = nextNode;
}

// MARK: - Mutators
void QueueNode :: setData(LinkedListDataNode data) {
    this->data = data;
}

void QueueNode :: setPrevNode(QueueNode *prevNode) {
    this->prevNode = prevNode;
}

void QueueNode :: setNextNode(QueueNode *nextNode) {
    this->nextNode = nextNode;
}

// MARK: - Accessors
LinkedListDataNode QueueNode :: getData() const {
    return this->data;
}

QueueNode* QueueNode :: getPrevNode() const {
    return this->prevNode;
}

QueueNode* QueueNode :: getNextNode() const {
    return this->nextNode;
}
