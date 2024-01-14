//
//  ArrivalTimeLinedListDataNode.cpp
//  Advanced OS - Final
//
//  Created by Tevon Wallace  on 12/24/23.
//  Copyright © 2023 Tevon Wallace. All rights reserved.
//

#include "ArrivalTimeLinkedListDataNode.hpp"

ArrivalTimeLinkedListDataNode :: ArrivalTimeLinkedListDataNode() {
    this->processId = "";
    this->arrivalTime = this->burstTime = this->timeCompleted = this->waitingTime = this->turnAroundTime = 0.0;
}

ArrivalTimeLinkedListDataNode :: ArrivalTimeLinkedListDataNode(string processId,
                                         int arrivalTime, int burstTime) {
    this->processId = processId;
    this->arrivalTime = arrivalTime;
    this->burstTime = burstTime;
}

// MARK: - Calculating Waiting and Turn Around Time
void ArrivalTimeLinkedListDataNode :: calculateWaitingAndTurnAroundTime(int timeCompleted) {
    this->turnAroundTime = timeCompleted - this->arrivalTime;
    this->waitingTime = this->turnAroundTime - this->burstTime;
    
    this->setTimeCompleted(timeCompleted);
}

// MARK: - Mutators
void ArrivalTimeLinkedListDataNode :: setProcessId(string processId) {
    this->processId = processId;
}

void ArrivalTimeLinkedListDataNode :: setArrivalTime(int arrivalTime) {
    this->arrivalTime = arrivalTime;
}

void ArrivalTimeLinkedListDataNode :: setBurstTime(int burstTime) {
    this->burstTime = burstTime;
}

void ArrivalTimeLinkedListDataNode :: setTimeCompleted(int timeCompleted) {
    this->timeCompleted = timeCompleted;
}

// MARK: - Accessors
string ArrivalTimeLinkedListDataNode :: getProcessId() const {
    return this->processId;
}

int ArrivalTimeLinkedListDataNode :: getArrivalTime() const {
    return this->arrivalTime;
}

int ArrivalTimeLinkedListDataNode :: getBurstTime() const {
    return this->burstTime;
}

double ArrivalTimeLinkedListDataNode :: getWaitingTime() const {
    return this->waitingTime;
}

double ArrivalTimeLinkedListDataNode :: getTurnAroundTime() const {
    return this->turnAroundTime;
}

int ArrivalTimeLinkedListDataNode :: getTimeCompleted() const {
    return this->timeCompleted;
}
