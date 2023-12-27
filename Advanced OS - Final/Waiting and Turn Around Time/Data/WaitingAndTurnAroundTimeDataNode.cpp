//
//  WaitingAndTurnAroundTimeDataNode.cpp
//  Advanced OS - Final
//
//  Created by Dr. Tevon Wallace  on 12/25/23.
//  Copyright © 2023 Tevon Wallace. All rights reserved.
//

#include "WaitingAndTurnAroundTimeDataNode.hpp"

// MARK: - Constructor
WaitingAndTurnAroundTimeDataNode :: WaitingAndTurnAroundTimeDataNode() {
    this->processId = "";
    this->arrivalTime = 0;
    this->burstTime = 0;
    this->waitingTime = 0;
    this->turnAroundTime = 0;
    this->timeCompleted = 0;
}

WaitingAndTurnAroundTimeDataNode :: WaitingAndTurnAroundTimeDataNode(string processId, int arrivalTime, int burstTime) {
    this->processId = processId;
    this->arrivalTime = arrivalTime;
    this->burstTime = burstTime;
}

// MARK: - Calculating Waiting & Turn Around Time
void WaitingAndTurnAroundTimeDataNode :: calculateWaitingAndTurnAroundTime(int timeCompleted) {
    this->turnAroundTime = timeCompleted - this->arrivalTime;
    this->waitingTime = this->turnAroundTime - this->burstTime;
    
    this->setTimeCompleted(timeCompleted);
}

// MARK: - Mutators
void WaitingAndTurnAroundTimeDataNode :: setProcessID(string processId) {
    this->processId = processId;
}

void WaitingAndTurnAroundTimeDataNode :: setArrivalTime(int arrivalTime) {
    this->arrivalTime = arrivalTime;
}

void WaitingAndTurnAroundTimeDataNode :: setBurstTime(int burstTime) {
    this->burstTime = burstTime;
}

void WaitingAndTurnAroundTimeDataNode :: setTimeCompleted(int timeCompleted) {
    this->timeCompleted = timeCompleted;
}

// MARK: - Accessors
string WaitingAndTurnAroundTimeDataNode :: getProcessId() const {
    return this->processId;
}

int WaitingAndTurnAroundTimeDataNode :: getArrivalTime() const {
    return this->arrivalTime;
}

int WaitingAndTurnAroundTimeDataNode :: getBurstTime() const {
    return this->burstTime;
}

int WaitingAndTurnAroundTimeDataNode :: getTurnAroundTime() const {
    return this->turnAroundTime;
}

int WaitingAndTurnAroundTimeDataNode :: getWaitingTime() const {
    return this->waitingTime;
}

int WaitingAndTurnAroundTimeDataNode :: getTimeCompleted() const {
    return this->timeCompleted;
}
