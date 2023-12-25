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
    this->processID = "";
    this->arrivalTime = 0; this->burstTime = 0;
}

// MARK: - Mutators
void TempLinkedListNodeData :: setProcessID(string processID) {
    this->processID = processID;
}

void TempLinkedListNodeData :: setArrivalTime(int arrivalTime) {
    this->arrivalTime = arrivalTime;
}

void TempLinkedListNodeData :: setBurstTime(int burstTime) {
    this->burstTime = burstTime;
}

// MARK: - Accessors
string TempLinkedListNodeData :: getProcessID() const {
    return this->processID;
}

int TempLinkedListNodeData :: getArrivalTime() const {
    return this->arrivalTime;
}

int TempLinkedListNodeData :: getBurstTime() const {
    return this->burstTime;
}
