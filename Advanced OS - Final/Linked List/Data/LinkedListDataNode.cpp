//
//  LinkedListDataNode.cpp
//  Advanced OS - Final
//
//  Created by Dr. Tevon Wallace  on 12/24/23.
//  Copyright © 2023 Tevon Wallace. All rights reserved.
//

#include "LinkedListDataNode.hpp"

LinkedListDataNode :: LinkedListDataNode() {
    this->processId = "";
    this->arrivalTime = this->burstTime = this->priority = 0;
}

// MARK: - Mutators
void LinkedListDataNode :: setProcessID(string processId) {
    this->processId = processId;
}

void LinkedListDataNode :: setArrivalTime(int arrivalTime) {
    this->arrivalTime = arrivalTime;
}

void LinkedListDataNode :: setBurstTime(int burstTime) {
    this->burstTime = burstTime;
}

void LinkedListDataNode :: setPriority(int priority) {
    this->priority = priority;
}

// MARK: - Accessors
string LinkedListDataNode :: getProcessId() const {
    return this->processId;
}

int LinkedListDataNode :: getArrivalTime() const {
    return this->arrivalTime;
}

int LinkedListDataNode :: getBurstTime() const {
    return this->burstTime;
}

int LinkedListDataNode :: getPriority() const {
    return this->priority;
}
