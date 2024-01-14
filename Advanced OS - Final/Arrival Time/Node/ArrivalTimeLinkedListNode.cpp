//
//  ArrivalTimeLinkedListNode.cpp
//  Advanced OS - Final
//
//  Created by Tevon Wallace  on 12/24/23.
//  Copyright © 2023 Tevon Wallace. All rights reserved.
//

#include "ArrivalTimeLinkedListNode.hpp"

ArrivalTimeLinkedListNode :: ArrivalTimeLinkedListNode(): data() {
    this->nextNode = NULL;
}

ArrivalTimeLinkedListNode :: ArrivalTimeLinkedListNode(ArrivalTimeLinkedListDataNode data, ArrivalTimeLinkedListNode *nextNode) {
    this->data = data;
    this->nextNode = nextNode;
}

// MARK: - Mutators
void ArrivalTimeLinkedListNode :: setWaitingAndTurnAroundTime(int completedTime) {
    this->data.calculateWaitingAndTurnAroundTime(completedTime);
}

void ArrivalTimeLinkedListNode :: setData(ArrivalTimeLinkedListDataNode data) {
    this->data = data;
}

void ArrivalTimeLinkedListNode :: setNextNode(ArrivalTimeLinkedListNode *nextNode) {
    this->nextNode = nextNode;
}

// MARK: - Accessors
ArrivalTimeLinkedListDataNode ArrivalTimeLinkedListNode :: getData() {
    return this->data;
}

ArrivalTimeLinkedListNode* ArrivalTimeLinkedListNode :: getNextNode() {
    return this->nextNode;
}
