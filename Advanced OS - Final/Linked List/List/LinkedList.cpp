//
//  LinkedList.cpp
//  Advanced OS - Final
//
//  Created by Dr. Tevon Wallace  on 12/24/23.
//  Copyright © 2023 Tevon Wallace. All rights reserved.
//

#include "LinkedList.hpp"

// MARK: - Constructor
LinkedList :: LinkedList() {
    this->head = this->tail = NULL;
    this->count = 0;
}

// MARK: - Insertions
void LinkedList :: insertAtFront(LinkedListDataNode data) {
    LinkedListNode *temp = new LinkedListNode(data, NULL);
    
    if(temp != NULL) {
        if(this->isEmpty()) {
            this->head = temp;
            this->tail = temp;
            this->count++;
        }
        else {
            temp->setNextNode(this->head);
            this->head = temp;
            this->count++;
        }
    }
    else {
        cout << "Error inserting Node, Out of Memory"<<endl;
    }
}

void LinkedList :: insertAtBack(LinkedListDataNode data) {
    LinkedListNode *temp = new LinkedListNode(data, NULL);
    
    if(temp != NULL) {
        if(this->isEmpty()) {
            this->head = temp;
            this->tail = temp;
            this->count++;
        }
        else {
            this->tail->setNextNode(temp);
            this->tail = temp;
            this->count++;
        }
    } else
    {
        cout << "Error inserting node at back"<<endl;
    }
}

void LinkedList :: insertAtMiddle(LinkedListDataNode data) {
    LinkedListNode *previousNode, *nextNode, *temp = new LinkedListNode(data, NULL);
    int nodeSize;
    
    previousNode = this->head;
    nextNode = this->head;
    
    if(temp != NULL) {
        while(previousNode != NULL) {
            nextNode = previousNode->getNextNode();
            
            if(nextNode != NULL) {
                nodeSize = nextNode->getData().getArrivalTime();
                
                if(data.getArrivalTime() <= nodeSize) {
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
        cout << "Error inserting Node, Out of Memory"<<endl;
    }
}

// MARK: - Deleting a Node
void LinkedList :: deleteNode(string processId) {  // Change this to delete by ProcessID and (BurstTime - ArrivalTime)
    LinkedListNode *current, *prevNode, *temp;
    int counter = 0;
    
    current = this->head;
    prevNode = this->head;
    
    if(!this->isEmpty()) {
        if(this->head->getData().getProcessId() == processId) {
            temp = this->head;
            
            if(this->head->getNextNode() == NULL) {
                this->head = NULL;
                this->tail = NULL;
            }
            else {
                this->head = this->head->getNextNode();
            }
            delete temp;
            this->count--;
        }
        else if(this->tail->getData().getProcessId() == processId) {
            temp = this->head;
            
            while(temp->getData().getProcessId() != this->tail->getData().getProcessId()) {
                prevNode = temp;
                temp = temp->getNextNode();
            }
            prevNode->setNextNode(NULL);
            this->tail = prevNode;
            this->count--;
            delete temp;
        }
        else {
            while(current->getNextNode() != NULL) {
                counter++;
                temp = current;
                current = current->getNextNode();
                
                if(temp->getData().getProcessId() == processId) {
                    prevNode->setNextNode(current);
                    delete temp;
                    this->count--;
                    break;
                }
                
                if(counter > 1) {
                    prevNode = prevNode->getNextNode();
                }
            }
        }
    }
    else {
        cout << "\nList is empty"<<endl;
    }
}

// MARK: - Check if Empty
bool LinkedList :: isEmpty() const {
    return this->head == NULL;
}

// MARK: - Head and Tail Accessors
LinkedListDataNode LinkedList :: getHead() const {
    LinkedListDataNode data;
    
    if (!this->isEmpty()) {
        data =  this->head->getData();
    }
    return data;
}

LinkedListDataNode LinkedList :: getTail() const {
    LinkedListDataNode data;
    
    if(this->tail != NULL) {
        data = this->tail->getData();
    }
    return data;
}

// MARK: - Organizing LinkedList
void LinkedList :: organize(LinkedListDataNode data) {
    if(this->isEmpty()) {
        this->insertAtBack(data);
    }
    else {
        int headSize = this->getHead().getArrivalTime();
        int tailSize = this->getTail().getArrivalTime();
        
        if((data.getArrivalTime() >= headSize) && (data.getArrivalTime() >= tailSize)) {
            this->insertAtBack(data);
        }
        else if((data.getArrivalTime() >= headSize) && (data.getArrivalTime() <= tailSize)) {
            this->insertAtMiddle(data);
        }
        else if(data.getArrivalTime() < headSize) {
            this->insertAtFront(data);
        }
    }
}

void LinkedList :: initialize(Algorithm algorithm) {
    this->algorithm = algorithm;
    this->display((algorithm == Algorithm::nonPreemptivePriority || algorithm == Algorithm::preemptivePriority) ? 4: 3);
    
    this->newTempLinkedList = new TempLinkedList();
    this->waitingAndTurnAroundTime = new WaitingAndTurnAroundTime();
    
    if (algorithm == Algorithm::roundRobin) {
        this->queue = new Queue();
    }
}

string LinkedList :: getAlgorithm() const {
    switch (algorithm) {
        case fcfs:
            return "FCFS";
        case sjf:
            return "SJF";
        case srtf:
            return "SRTF";
        case nonPreemptivePriority:
            return "Non-Preemptive Priority";
        case preemptivePriority:
            return "Preemptive Priority";
        case Algorithm::roundRobin:
            return "Round Robin";
    }
}

// MARK: - Displaying the contents of the list
void LinkedList :: display(int headerCount) {
    LinkedListNode *temp = this->head;
    
    string dashes = "";
    
    for (int index = 0; index < headerCount; index++) {
        dashes += "--------";
    }
    
    dashes = dashes.substr(0, dashes.length()-1);
    
    cout << "|" << dashes << "|" << endl;
    
    string tab = "\t";
    
    while (temp != NULL) {
        LinkedListDataNode data = temp->getData();
        
        cout << "|" << tab << data.getProcessId() << tab << "|" << tab << data.getArrivalTime()
        << tab << "|" << tab << data.getBurstTime() << tab << "|";
        
        if (headerCount == 4) {
            cout << tab << data.getPriority() << tab << "|" << endl;
        }
        else {
            cout << endl;
        }
        
        temp = temp->getNextNode();
    }
    
    cout << "|" << dashes << "|\n" << endl;
}

void LinkedList :: displayCharts(int activateWaitingAndTurnAroundTimeForAllProcesses,
                                 ArrivalTimeLinkedList *arrivalList) {
    this->destroy();
    this->newTempLinkedList->display();
    
    if ((this->algorithm == Algorithm::fcfs)
        || (this->algorithm == Algorithm::sjf)
        || (this->algorithm == Algorithm::nonPreemptivePriority)) {
        this->waitingAndTurnAroundTime->display(activateWaitingAndTurnAroundTimeForAllProcesses);
    }
    else {
        this->newTempLinkedList->calculateWaitingAndTurnAroundTime(arrivalList, activateWaitingAndTurnAroundTimeForAllProcesses);
    }
    
    this->newTempLinkedList->destroy();
    
    if (this->algorithm == Algorithm::roundRobin) {
        this->queue->destroy();
    }
}

// MARK: - Destroying LinkedList
void LinkedList :: destroy() {
    LinkedListNode *temp;
    
    while(!this->isEmpty()) {
        temp = this->head;
        this->head = this->head->getNextNode();
        delete temp;
    }
}

// MARK: - Find Arrival Times
string LinkedList :: findArrivalTime(int burstTime, string processId,
                                     int remainingBurstTime) {
    LinkedListNode *temp = this->head, *nextTemp = NULL;
    LinkedListDataNode data;
    data.setProcessId(processId);
    int reached = 0;
    
    while(temp != NULL) {
        if(temp->getData().getProcessId() == processId) {
            reached = 1;
        }
        else if((reached == 1) && (temp->getData().getArrivalTime() <= burstTime)) {
            data = temp->getData();
            this->queue->enqueue(data);
        }
        temp = temp->getNextNode();
    }
    
    if(data.getProcessId() == processId && remainingBurstTime == 0) {
        if(this->queue->isEmpty()) {
            if(!this->isEmpty()) {
                nextTemp = this->head->getNextNode();

                if(nextTemp != NULL) {
                    this->queue->enqueue(nextTemp->getData());
                    processId = nextTemp->getData().getProcessId();
                }
            }
        }
        return processId;
    }
    else {
        return data.getProcessId();
    }
}

// MARK: - Find Smallest Burst Time
LinkedListDataNode LinkedList :: findSmallestBurstTime(int burstTime) {
    LinkedListDataNode data;
    LinkedListNode *temp = this->head;
    data.setProcessId("");
    
    while(temp != NULL) {
        if(temp->getData().getArrivalTime() > burstTime) {
            break;
        }
        else if(temp->getData().getProcessId() == this->head->getData().getProcessId()) {
            data = temp->getData();
        }
        else if(temp->getData().getBurstTime() < data.getBurstTime()) {
            data = temp->getData();
        }
        temp = temp->getNextNode();
    }
    return data;
}

// MARK: - Find Highest Priority
LinkedListDataNode LinkedList :: findHighestPriority(int burstTime, int priorityLevel) {
    LinkedListNode *temp = this->head;
    LinkedListDataNode data;
    data.setProcessId("");
    
    while(temp != NULL) {
        if(temp->getData().getArrivalTime() > burstTime) {
            break;
        }
        else if(temp->getData().getProcessId() == this->head->getData().getProcessId()) {
            data = temp->getData();
        }
        else if((priorityLevel == 1) && (temp->getData().getPriority() < data.getPriority())) { // Lowest Number - Highest Priority
            data = temp->getData();
        }
        else if((priorityLevel == 2) && (temp->getData().getPriority() > data.getPriority())) { // Highest Number - Highest Priority
            data = temp->getData();
        }
        
        temp = temp->getNextNode();
    }
    return data;
}

// MARK: - First Come First Serve Scheduling
void LinkedList :: FCFS(int burstTime, bool ran) {
    bool shouldSkip = false;
    
    if(!this->isEmpty()) {
        LinkedListNode *temp = this->head;
        
        if(ran == 0) {
            burstTime = temp->getData().getArrivalTime();
        }
        
        if(temp->getData().getArrivalTime() > burstTime) {
            shouldSkip = true;
        }
        
        if (shouldSkip) {
            this->newTempLinkedList->insertAtBack(TempLinkedListNodeData("-", burstTime, (burstTime + 1)));
            burstTime += 1;
        }
        else {
            TempLinkedListNodeData data = TempLinkedListNodeData(temp->getData().getProcessId(), burstTime, (burstTime + temp->getData().getBurstTime()));
            burstTime += temp->getData().getBurstTime();
            
            this->newTempLinkedList->insertAtBack(data);
            
            WaitingAndTurnAroundTimeDataNode waitingAndTurnAroundData = WaitingAndTurnAroundTimeDataNode(temp->getData().getProcessId(), temp->getData().getArrivalTime(), temp->getData().getBurstTime());
            waitingAndTurnAroundData.calculateWaitingAndTurnAroundTime(burstTime);
            this->waitingAndTurnAroundTime->insertAtBack(waitingAndTurnAroundData);
            
            this->deleteNode(data.getProcessId());
        }
        
        this->FCFS(burstTime, true);
    }
}

// MARK: - Shortest Job First Scheduling
void LinkedList :: SJF(int burstTime, bool ran) {
    LinkedListDataNode data;
    TempLinkedListNodeData tempData;
    bool shouldSkip = false;
    
    if(!this->isEmpty()) {
        LinkedListNode *temp = this->head;
        
        if(ran == false) {
            burstTime = temp->getData().getArrivalTime();
        }
        
        data = this->findSmallestBurstTime(burstTime);
        
        if(data.getProcessId() == "") {
            shouldSkip = true;
        }
        
        if (shouldSkip) {
            this->newTempLinkedList->insertAtBack(TempLinkedListNodeData("-", burstTime, (burstTime + 1)));
            burstTime += 1;
        }
        else {
            this->newTempLinkedList->insertAtBack(TempLinkedListNodeData(data.getProcessId(), burstTime, (burstTime + data.getBurstTime())));
            
            burstTime += data.getBurstTime();
            
            WaitingAndTurnAroundTimeDataNode waitingAndTurnAroundData = WaitingAndTurnAroundTimeDataNode(data.getProcessId(), data.getArrivalTime(), data.getBurstTime());
            waitingAndTurnAroundData.calculateWaitingAndTurnAroundTime(burstTime);
            this->waitingAndTurnAroundTime->insertAtBack(waitingAndTurnAroundData);
            
            this->deleteNode(data.getProcessId());
        }
        
        this->SJF(burstTime, true);
    }
}

// MARK: - Shortest Remaining Time First Scheduling
void LinkedList :: SRTF(int burstTime, int arrivalTime, bool ran) {
    LinkedListDataNode data;
    
    bool shouldSkip = false;
    
    if(!this->isEmpty()) {
        LinkedListNode *temp = this->head;
        
        if(ran == false) {
            data = temp->getData();
            arrivalTime = burstTime = data.getArrivalTime();
        }
        
        LinkedListDataNode data2 = this->findSmallestBurstTime(burstTime);
        
        if(data2.getProcessId() == "") {
            shouldSkip = true;
        }
        
        if (!shouldSkip) {
            while(temp != NULL) {
                if(temp->getData().getProcessId() == data2.getProcessId()) {
                    data = temp->getData();
                    break;
                }
                temp = temp->getNextNode();
            }
        }
        
        if (shouldSkip) {
            data.setArrivalTime(burstTime);
            
            burstTime += 1;
            data.setBurstTime(burstTime);
            data.setProcessId("-");
            
            this->newTempLinkedList->insertAtBack(TempLinkedListNodeData(data.getProcessId(), data.getArrivalTime(), data.getBurstTime()));
        }
        else {
            int tempBurstTime = data.getBurstTime();
            
            for(int i = 0; i < tempBurstTime; i++) {
                burstTime++;
                data.setBurstTime(data.getBurstTime()-1);
                temp->setData(data);
                data2 = this->findSmallestBurstTime(burstTime);
                
                if(data.getProcessId() != data2.getProcessId()) {
                    break;
                }
            }
            
            this->newTempLinkedList->insertAtBack(TempLinkedListNodeData(data.getProcessId(), arrivalTime, burstTime));
            arrivalTime = burstTime;
            
            if(temp->getData().getBurstTime() == 0) {
                this->deleteNode(temp->getData().getProcessId());
            }
        }
        
        this->SRTF(burstTime, arrivalTime, true);
    }
}

// MARK: - Non-Preemptive Priority Scheduling
void LinkedList :: nonPreEmptivePriority(int priorityLevel, int burstTime) {
    LinkedListDataNode data;
    TempLinkedListNodeData tempData;
    bool shouldSkip = false;
    
    if(!this->isEmpty()) {
        data = this->findHighestPriority(burstTime, priorityLevel);
        
        if(data.getProcessId() == "") {
            shouldSkip = true;
        }
        
        if (shouldSkip) {
            this->newTempLinkedList->insertAtBack(TempLinkedListNodeData("-", burstTime, (burstTime + 1)));
            burstTime += 1;
        }
        else {
            this->newTempLinkedList->insertAtBack(TempLinkedListNodeData(data.getProcessId(), burstTime, (burstTime + data.getBurstTime())));
            
            burstTime += data.getBurstTime();
            
            WaitingAndTurnAroundTimeDataNode waitingAndTurnAroundData = WaitingAndTurnAroundTimeDataNode(data.getProcessId(), data.getArrivalTime(), data.getBurstTime());
            waitingAndTurnAroundData.calculateWaitingAndTurnAroundTime(burstTime);
            this->waitingAndTurnAroundTime->insertAtBack(waitingAndTurnAroundData);
            
            this->deleteNode(data.getProcessId());
        }
        this->nonPreEmptivePriority(priorityLevel, burstTime);
    }
}

// MARK: - Preemptive Priority Scheduling
void LinkedList :: preEmptivePriority(int priorityLevel, int burstTime, int arrivalTime){
    if(!this->isEmpty()) {
        LinkedListNode *temp = this->head;
        
        LinkedListDataNode data = this->findHighestPriority(burstTime, priorityLevel);
        
        if(data.getProcessId() == "") {
            data = this->head->getData();
        }
        
        while(temp != NULL) {
            if(temp->getData().getProcessId() == data.getProcessId()) {
                data = temp->getData();
                break;
            }
            temp = temp->getNextNode();
        }
        
        for(int index = 0; index < data.getBurstTime(); index++) {
            burstTime++;
            data.setBurstTime(data.getBurstTime()-1);
            temp->setData(data);
            
            if(this->findHighestPriority(burstTime, priorityLevel).getProcessId() != data.getProcessId()) {
                break;
            }
        }
        
        this->newTempLinkedList->insertAtBack(TempLinkedListNodeData(temp->getData().getProcessId(), arrivalTime, burstTime));
        arrivalTime = burstTime;
        
        if(temp->getData().getBurstTime() == 0) {
            this->deleteNode(temp->getData().getProcessId());
        }
        this->preEmptivePriority(priorityLevel, burstTime, arrivalTime);
    }
}

// MARK: - Round Robin Scheduling
void LinkedList :: roundRobin(string processId, int timeQuantum, int burstTime,
                              int arrivalTime, bool ran) {
    LinkedListDataNode data;
    
    if(!this->isEmpty()) {
        LinkedListNode *temp = this->head;
        
        if(ran == false) {
            data = temp->getData();
            burstTime = arrivalTime = data.getArrivalTime();
        }
        else {
            data = this->queue->dequeue();
            
            if(data.getArrivalTime() > burstTime) {
                this->newTempLinkedList->insertAtBack(TempLinkedListNodeData("-", burstTime, (burstTime + 1)));
                burstTime += 1;
            }
            
            while(temp != NULL) {
                if(temp->getData().getProcessId() == data.getProcessId()) {
                    data = temp->getData();
                    break;
                }
                temp = temp->getNextNode();
            }
        }
        
        int subtractedValue = data.getBurstTime() - timeQuantum;
        
        if(subtractedValue <= 0) {
            burstTime += data.getBurstTime();
            data.setBurstTime(0);
        }
        else {
            data.setBurstTime(subtractedValue);
            burstTime += timeQuantum;
        }
        
        this->newTempLinkedList->insertAtBack(TempLinkedListNodeData(data.getProcessId(), arrivalTime, burstTime));
        
        arrivalTime = burstTime;
        
        temp->setData(data);
        
        processId = this->findArrivalTime(burstTime, processId, temp->getData().getBurstTime());
            
        if(temp->getData().getBurstTime() > 0) {
            this->queue->enqueue(temp->getData());
        }
        else if(temp->getData().getBurstTime() == 0) {
            this->deleteNode(temp->getData().getProcessId());
        }
        
        this->roundRobin(processId, timeQuantum, burstTime, arrivalTime, true);
    }
}
