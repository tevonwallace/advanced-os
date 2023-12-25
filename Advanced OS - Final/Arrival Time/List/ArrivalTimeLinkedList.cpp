//
//  ArrivalTimeLinkedList.cpp
//  Advanced OS - Final
//
//  Created by Dr. Tevon Wallace  on 12/24/23.
//  Copyright © 2023 Tevon Wallace. All rights reserved.
//

#include "ArrivalTimeLinkedList.hpp"

ArrivalTimeLinkedList :: ArrivalTimeLinkedList() {
    this->head = this->tail = NULL;
    this->waitingTime = 0.0;
    this->turnAroundTime = 0.0;
    this->count = 0;
}

//MARK: Insertions
void ArrivalTimeLinkedList :: insertAtFront(ArrivalTimeLinkedListDataNode data) {
    ArrivalTimeLinkedListNode *temp = new ArrivalTimeLinkedListNode(data, NULL);
    
    if (temp != NULL) {
        if (this->isEmpty()) {
            this->head = temp;
            this->tail = temp;
            this->count++;
        }
        else {
            temp->setNextNode(head);
            this->head = temp;
            this->count++;
        }
    }
    else {
        cout << "Error inserting Node, Out of Memory" << endl;
    }
}

void ArrivalTimeLinkedList :: insertAtBack(ArrivalTimeLinkedListDataNode data) {
    ArrivalTimeLinkedListNode *temp = new ArrivalTimeLinkedListNode(data, NULL);
    
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

void ArrivalTimeLinkedList :: insertAtMiddle(ArrivalTimeLinkedListDataNode data)
{
    ArrivalTimeLinkedListNode *previousNode, *nextNode, *temp = new ArrivalTimeLinkedListNode(data, NULL);
    int nodeSize;
    
    previousNode = this->head;
    nextNode = this->head;
    
    if (temp != NULL) {
        while (previousNode != NULL) {
            nextNode = previousNode->getNextNode();
            
            if (nextNode != NULL) {
                nodeSize = nextNode->getData().getArrivalTime();
                
                if (data.getArrivalTime() <= nodeSize) {
                    previousNode->setNextNode(temp);
                    temp->setNextNode(nextNode);
                    this->count++;
                    break;
                }
                previousNode = previousNode->getNextNode();
            }
            else {
                break;
            }
        }
    }
    else {
        cout << "Error inserting Node, Out of Memory" << endl;
    }
}

// MARK: - Head and Tail Accessors
ArrivalTimeLinkedListDataNode ArrivalTimeLinkedList :: getHead() const {
    ArrivalTimeLinkedListDataNode data;
    
    if (this->head != NULL) {
        data = this->head->getData();
    }
    return data;
}

ArrivalTimeLinkedListDataNode ArrivalTimeLinkedList :: getTail() const {
    ArrivalTimeLinkedListDataNode data;
    
    if (this->tail != NULL) {
        data = this->tail->getData();
    }
    return data;
}

// MARK: - Organizing List
void ArrivalTimeLinkedList :: organize(ArrivalTimeLinkedListDataNode data) {
    if (this->isEmpty()) {
        this->insertAtBack(data);
    }
    else {
        int headSize = this->getHead().getArrivalTime();
        int tailSize = this->getTail().getArrivalTime();
        
        if ((data.getArrivalTime() >= headSize) && (data.getArrivalTime() >= tailSize)) {
            this->insertAtBack(data);
        }
        else if ((data.getArrivalTime() >= headSize) && (data.getArrivalTime() <= tailSize)) {
            this->insertAtMiddle(data);
        }
        else if (data.getArrivalTime() < headSize) {
            this->insertAtFront(data);
        }
    }
}

// MARK: - Check If Empty
bool ArrivalTimeLinkedList :: isEmpty() {
    if (this->head == NULL) {
        return true;
    }
    return false;
}

// MARK: - Mutators
void ArrivalTimeLinkedList :: setWaitingTime(double waitingTime) {
    this->waitingTime += waitingTime;
}

void ArrivalTimeLinkedList :: setTurnAroundTime(double turnAroundTime) {
    this->turnAroundTime += turnAroundTime;
}

// MARK: - Accessors
double ArrivalTimeLinkedList :: getWaitingTime() const {
    return this->waitingTime;
}

double ArrivalTimeLinkedList :: getTurnAroundTime() const {
    return this->turnAroundTime;
}

int ArrivalTimeLinkedList :: getCount() const {
    return this->count;
}

double ArrivalTimeLinkedList :: calculateWaitingTime() const {
    return (this->getWaitingTime()/this->getCount());
}

double ArrivalTimeLinkedList :: calculateTurnAroundTime() const {
    return (this->getTurnAroundTime()/this->getCount());
}

// MARK: - Destroy Arrival Time LinkedList
void ArrivalTimeLinkedList :: destroy(string schedulingAlgorithm) {
    ArrivalTimeLinkedListNode *temp;
    
    while (!this->isEmpty()) {
        temp = this->head;
        this->head = this->head->getNextNode();
        delete temp;
        this->count--;
    }
}

// MARK: - Calculate Waiting & Turn Around Time
void ArrivalTimeLinkedList :: calculateWaitingAndTurnAroundTime(string processId, int completedTime, bool activateWaitingAndTurnAroundTimeForAllProcesses) {
    ArrivalTimeLinkedListNode *temp = this->head;
    
    while (temp != NULL) {
        if (temp->getData().getProcessId() == processId) {
            
            temp->setWaitingAndTurnAroundTime(completedTime);
            this->setWaitingTime(temp->getData().getWaitingTime());
            this->setTurnAroundTime(temp->getData().getTurnAroundTime());
            
            if (activateWaitingAndTurnAroundTimeForAllProcesses) {
                
                cout << temp->getData().getProcessId() << "\t\t\t" << temp->getData().getTurnAroundTime() << " - " << temp->getData().getBurstTime() << " = " <<temp->getData().getWaitingTime() << "\t\t"
                << temp->getData().getTimeCompleted() << " - " << temp->getData().getArrivalTime() << " = " << temp->getData().getTurnAroundTime() << endl;
            }
            break;
        }
        temp = temp->getNextNode();
    }
}
