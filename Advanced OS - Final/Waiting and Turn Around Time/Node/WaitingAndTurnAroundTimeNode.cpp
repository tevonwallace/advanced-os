//
//  WaitingAndTurnAroundTimeNode.cpp
//  Advanced OS - Final
//
//  Created by Tevon Wallace  on 12/25/23.
//  Copyright © 2023 Tevon Wallace. All rights reserved.
//

#include "WaitingAndTurnAroundTimeNode.hpp"

// MARK: - Constructors
WaitingAndTurnAroundTimeNode :: WaitingAndTurnAroundTimeNode() : data() {
    this->nextNode = NULL;
}

WaitingAndTurnAroundTimeNode :: WaitingAndTurnAroundTimeNode(WaitingAndTurnAroundTimeDataNode data, WaitingAndTurnAroundTimeNode *nextNode) {
    this->data = data;
    this->nextNode = nextNode;
}

// MARK: - Mutators
void WaitingAndTurnAroundTimeNode :: setData(WaitingAndTurnAroundTimeDataNode data) {
    this->data = data;
}

void WaitingAndTurnAroundTimeNode :: setNextNode(WaitingAndTurnAroundTimeNode *nextNode) {
    this->nextNode = nextNode;
}

// MARK: - Accessors
WaitingAndTurnAroundTimeDataNode WaitingAndTurnAroundTimeNode :: getData() const {
    return this->data;
}

WaitingAndTurnAroundTimeNode* WaitingAndTurnAroundTimeNode :: getNextNode() const {
    return this->nextNode;
}
