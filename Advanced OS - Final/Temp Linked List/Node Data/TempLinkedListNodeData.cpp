//
//  TempLinkedListNodeData.cpp
//  Advanced OS - Final
//
//  Created by Dr. Tevon Wallace  on 12/25/23.
//  Copyright © 2023 Tevon Wallace. All rights reserved.
//

#include "TempLinkedListNodeData.hpp"

// MARK: - Constructor
TempLinkedListNodeData :: TempLinkedListNodeData() {
    this->processId = "";
    this->arrivalTime = this->burstTime = 0;
}

TempLinkedListNodeData :: TempLinkedListNodeData(string processId, int arrivalTime, int burstTime) {
    this->processId = processId;
    this->arrivalTime = arrivalTime;
    this->burstTime = burstTime;
}

// MARK: - Mutators
void TempLinkedListNodeData :: setProcessId(string processId) {
    this->processId = processId;
}

void TempLinkedListNodeData :: setArrivalTime(int arrivalTime) {
    this->arrivalTime = arrivalTime;
}

void TempLinkedListNodeData :: setBurstTime(int burstTime) {
    this->burstTime = burstTime;
}

// MARK: - Accessors
string TempLinkedListNodeData :: getProcessId() const {
    return this->processId;
}

int TempLinkedListNodeData :: getArrivalTime() const {
    return this->arrivalTime;
}

int TempLinkedListNodeData :: getBurstTime() const {
    return this->burstTime;
}
