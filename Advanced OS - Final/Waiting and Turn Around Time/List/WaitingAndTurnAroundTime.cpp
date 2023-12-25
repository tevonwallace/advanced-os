//
//  WaitingAndTurnAroundTime.cpp
//  Advanced OS - Final
//
//  Created by Dr. Tevon Wallace  on 12/25/23.
//  Copyright © 2023 Tevon Wallace. All rights reserved.
//

#include "WaitingAndTurnAroundTime.hpp"

// MARK: - Constructor
WaitingAndTurnAroundTime :: WaitingAndTurnAroundTime() {
    this->count = 0;
    this->head = this->tail = NULL;
}

// MARK: - Insert At Back
void WaitingAndTurnAroundTime :: insertAtBack(WaitingAndTurnAroundTimeDataNode data) {
    WaitingAndTurnAroundTimeNode *temp = new WaitingAndTurnAroundTimeNode(data, NULL);
    
    if (temp != NULL) {
        if (this->isEmpty()) {
            this->head = temp;
            this->tail = temp;
            this->count++;
        }
        else {
            this->tail->setNextNode(temp);
            this->tail = temp;
            this->count++;
        }
    }
    else {
        cout << "Error inserting node at back" << endl;
    }
}

// MARK: - Check if Empty
bool WaitingAndTurnAroundTime :: isEmpty() {
    if(this->head == NULL) {
        return true;
    }
    return false;
}

// MARK: - Display Waiting & Turn Around Time
void WaitingAndTurnAroundTime :: display(bool activateWaitingAndTurnAroundTimeForAllProcesses, string schedulingAlgorithm) {
    WaitingAndTurnAroundTimeNode *temp = this->head;
    double waitingTime = 0.0, turnAroundTime = 0.0;
    
    if (activateWaitingAndTurnAroundTimeForAllProcesses) {
        cout << "\nWaiting and Turn Around Time for Individual Processes" << endl;
        cout << "\nProcessID\tWaiting Time\tTurn Around Time" << endl;
    }
    
    while(temp != NULL) {
        waitingTime += temp->getData().getWaitingTime();
        turnAroundTime += temp->getData().getTurnAroundTime();
        
        if (activateWaitingAndTurnAroundTimeForAllProcesses) {
            cout << temp->getData().getProcessId() << "\t\t\t" << temp->getData().getTurnAroundTime() << " - " << temp->getData().getBurstTime() << " = " << temp->getData().getWaitingTime() << "\t\t"
            << temp->getData().getTimeCompleted() << " - " << temp->getData().getArrivalTime() << " = " << temp->getData().getTurnAroundTime() << endl;
        }
        
        temp = temp->getNextNode();
    }
    
    cout << "Count: "<<this->count<<endl;
    cout << "Average Waiting Time: " << (waitingTime / this->count) << endl;
    cout << "Average Turn Around Time: " << (turnAroundTime / this->count) << "\n" << endl;
    
    this->destroy(schedulingAlgorithm);
}

void WaitingAndTurnAroundTime :: destroy(string schedulingAlgorithm) {
    WaitingAndTurnAroundTimeNode *temp;
    
    while(!this->isEmpty()) {
        temp = this->head;
        this->head = this->head->getNextNode();
        delete temp;
        this->count--;
    }
}
