//
//  ArrivalTimeLinedListDataNode.cpp
//  Advanced OS - Final
//
//  Created by Dr. Tevon Wallace  on 12/24/23.
//  Copyright © 2023 Tevon Wallace. All rights reserved.
//

#include "ArrivalTimeLinkedListDataNode.hpp"

ArrivalTimeLinkedListDataNode :: ArrivalTimeLinkedListDataNode() {
    this->processID = "";
    this->arrivalTime = 0;
    this->burstTime = 0;
    this->timeCompleted = 0;
    this->waitingTime = 0.0;
    this->turnAroundTime = 0.0;
}

// MARK: - Calculating Waiting and Turn Around Time
void ArrivalTimeLinkedListDataNode :: calculateWaitingAndTurnAroundTime(int timeCompleted) {
    this->turnAroundTime = timeCompleted - this->arrivalTime;
    this->waitingTime = this->turnAroundTime - this->burstTime;
    
    this->setTimeCompleted(timeCompleted);
}

// MARK: - Mutators
void ArrivalTimeLinkedListDataNode :: setProcessID(string processID) {
    this->processID = processID;
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
string ArrivalTimeLinkedListDataNode :: getProcessID() const {
    return this->processID;
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
