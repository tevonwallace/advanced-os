//
//  TempLinkedListNode.cpp
//  Advanced OS - Final
//
//  Created by Tevon Wallace  on 12/25/23.
//  Copyright © 2023 Tevon Wallace. All rights reserved.
//

#include "TempLinkedListNode.hpp"

// MARK: - Constructors
TempLinkedListNode :: TempLinkedListNode(): data() {
    this->nextNode = NULL;
}

TempLinkedListNode :: TempLinkedListNode(TempLinkedListNodeData data, TempLinkedListNode *nextNode) {
    this->data = data;
    this->nextNode = nextNode;
}

// MARK: - Mutators
void TempLinkedListNode :: setData(TempLinkedListNodeData data) {
    this->data = data;
}

void TempLinkedListNode :: setNextNode(TempLinkedListNode *nextNode) {
    this->nextNode = nextNode;
}

// MARK: - Accessors
TempLinkedListNodeData TempLinkedListNode :: getData() const {
    return this->data;
}

TempLinkedListNode* TempLinkedListNode :: getNextNode() const {
    return this->nextNode;
}
