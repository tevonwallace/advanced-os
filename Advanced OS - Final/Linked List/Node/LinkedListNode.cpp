//
//  LinkedListNode.cpp
//  Advanced OS - Final
//
//  Created by Dr. Tevon Wallace  on 12/24/23.
//  Copyright © 2023 Tevon Wallace. All rights reserved.
//

#include "LinkedListNode.hpp"

LinkedListNode :: LinkedListNode(): data() {
    nextNode = NULL;
}

LinkedListNode :: LinkedListNode(LinkedListDataNode data, LinkedListNode *nextNode) {
    this->data = data;
    this->nextNode = nextNode;
}

// MARK: - Mutators
void LinkedListNode :: setData(LinkedListDataNode data) {
    this->data = data;
}

void LinkedListNode :: setNextNode(LinkedListNode *nextNode) {
    this->nextNode = nextNode;
}

// MARK: Accessors
LinkedListDataNode LinkedListNode :: getData() const {
    return this->data;
}

LinkedListNode* LinkedListNode :: getNextNode() const {
    return this->nextNode;
}
