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
    
    if(this->head != NULL) {
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
                if(counter <= 1) {
                    /* Do Nothing */ }
                else {
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
bool LinkedList :: isEmpty() {
    if(this->head == NULL) {
        return true;
    }
    return false;
}

// MARK: - Head and Tail Accessors
LinkedListDataNode LinkedList :: getHead() const {
    LinkedListDataNode data;
    
    if(this->head != NULL) {
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
void LinkedList :: organizeDataInLinkedList(LinkedListDataNode data) {
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

// MARK: - Displaying the contents of the list
void LinkedList :: display(int headerCount) {
    LinkedListNode *temp = this->head;
    
    string dashes = "";
    
    for (int index = 0; index < headerCount; index++) {
        dashes += "--------";
    }
    
    dashes = dashes.substr(0, dashes.length()-1);
    
    cout << "|" << dashes << "|" << endl;
    
    while (temp != NULL) {
        LinkedListDataNode data = temp->getData();
        string tab = "\t";
        
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

// MARK: - Destroying LinkedList
void LinkedList :: destroy(string schedulingAlgorithm) {
    LinkedListNode *temp;
    
    while(!this->isEmpty()) {
        temp = this->head;
        this->head = this->head->getNextNode();
        delete temp;
    }
}

// MARK: - Find Arrival Times
string LinkedList :: findArrivalTime(Queue *queue, int burstTime, string processId,
                                     int remainingBurstTime) {
    LinkedListNode *temp = this->head, *nextTemp = NULL;
    LinkedListDataNode data;
    data.setProcessID(processId);
    int reached = 0;
    
    while(temp != NULL) {
        if(temp->getData().getProcessId() == processId) {
            reached = 1;
        }
        else if((reached == 1) && (temp->getData().getArrivalTime() <= burstTime)) {
            data = temp->getData();
            queue->enqueue(data);
        }
        temp = temp->getNextNode();
    }
    
    if(data.getProcessId() == processId && remainingBurstTime == 0) {
        if(queue->isEmpty()) {
            if(!this->isEmpty()) {
                nextTemp = this->head->getNextNode();

                if(nextTemp != NULL) {
                    queue->enqueue(nextTemp->getData());
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
    data.setProcessID("");
    
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
    data.setProcessID("");
    
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
void LinkedList :: FCFS(TempLinkedList *newTempLinkedList, WaitingAndTurnAroundTime *waitingAndTurnAroundTime,
                        int burstTime, int ran) throw(runtime_error) {
    LinkedListNode *temp;
    TempLinkedListNodeData data;
    WaitingAndTurnAroundTimeDataNode waitingAndTurnAroundData;
    bool shouldSkip = false;
    
    if(!this->isEmpty()) {
        temp = this->head;
        
        if(ran == 0) {
            burstTime = temp->getData().getArrivalTime();
        }
        
        if(temp->getData().getArrivalTime() > burstTime) {
            shouldSkip = true;
        }
        
        if (shouldSkip) {
            data.setArrivalTime(burstTime);
            
            burstTime += 1;
            data.setBurstTime(burstTime);
            data.setProcessID("-");
            
            newTempLinkedList->insertAtBack(data);
        }
        else {
            data.setProcessID(temp->getData().getProcessId());
            data.setArrivalTime(burstTime);
            burstTime += temp->getData().getBurstTime();
            data.setBurstTime(burstTime);
            
            newTempLinkedList->insertAtBack(data);
            
            waitingAndTurnAroundData.setProcessID(temp->getData().getProcessId());
            waitingAndTurnAroundData.setArrivalTime(temp->getData().getArrivalTime());
            waitingAndTurnAroundData.setBurstTime(temp->getData().getBurstTime());
            waitingAndTurnAroundData.calculateWaitingAndTurnAroundTime(burstTime);
            waitingAndTurnAroundTime->insertAtBack(waitingAndTurnAroundData);
            
            this->deleteNode(data.getProcessId());
        }
        
        this->FCFS(newTempLinkedList, waitingAndTurnAroundTime, burstTime, 1);
    }
}

// MARK: - Shortest Job First Scheduling
void LinkedList :: SJF(TempLinkedList *newTempLinkedList, WaitingAndTurnAroundTime *waitingAndTurnAroundTime,
                       int burstTime, int ran) throw(runtime_error) {
    LinkedListNode *temp;
    LinkedListDataNode data;
    TempLinkedListNodeData tempData;
    WaitingAndTurnAroundTimeDataNode waitingAndTurnAroundData;
    bool shouldSkip = false;
    
    if(!this->isEmpty()) {
        temp = this->head;
        
        if(ran == 0) {
            burstTime = temp->getData().getArrivalTime();
        }
        
        data = findSmallestBurstTime(burstTime);
        
        if(data.getProcessId() == "") {
            shouldSkip = true;
        }
        
        if (shouldSkip) {
            data.setArrivalTime(burstTime);
            
            burstTime += 1;
            data.setBurstTime(burstTime);
            data.setProcessID("-");
            
            tempData.setProcessID(data.getProcessId());
            tempData.setArrivalTime(data.getArrivalTime());
            tempData.setBurstTime(data.getBurstTime());
            
            newTempLinkedList->insertAtBack(tempData);
        }
        else {
            tempData.setProcessID(data.getProcessId());
            tempData.setArrivalTime(burstTime);
            burstTime += data.getBurstTime();
            tempData.setBurstTime(burstTime);
            
            newTempLinkedList->insertAtBack(tempData);
            
            waitingAndTurnAroundData.setProcessID(data.getProcessId());
            waitingAndTurnAroundData.setArrivalTime(data.getArrivalTime());
            waitingAndTurnAroundData.setBurstTime(data.getBurstTime());
            waitingAndTurnAroundData.calculateWaitingAndTurnAroundTime(burstTime);
            waitingAndTurnAroundTime->insertAtBack(waitingAndTurnAroundData);
            
            this->deleteNode(data.getProcessId());
        }
        
        this->SJF(newTempLinkedList, waitingAndTurnAroundTime, burstTime, 1);
    }
}

// MARK: - Shortest Remaining Time First Scheduling
void LinkedList :: SRTF(TempLinkedList *newTempLinkedList, int burstTime,
                        int arrivalTime, int ran) throw(runtime_error) {
    int tempBurstTime = 0;
    LinkedListNode *temp;
    LinkedListDataNode data, data2;
    TempLinkedListNodeData tempData;
    
    bool shouldSkip = false;
    
    if(!this->isEmpty()) {
        temp = this->head;
        
        if(ran == 0) {
            data = temp->getData();
            arrivalTime = burstTime = data.getArrivalTime();
        }
        else {
            data2 = findSmallestBurstTime(burstTime);
            
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
        }
        
        if (shouldSkip) {
            data.setArrivalTime(burstTime);
            
            burstTime += 1;
            data.setBurstTime(burstTime);
            data.setProcessID("-");
            
            tempData.setProcessID(data.getProcessId());
            tempData.setArrivalTime(data.getArrivalTime());
            tempData.setBurstTime(data.getBurstTime());
            
            newTempLinkedList->insertAtBack(tempData);
        }
        else {
            tempBurstTime = data.getBurstTime();
            
            for(int i = 0; i < tempBurstTime; i++) {
                burstTime++;
                data.setBurstTime(data.getBurstTime()-1);
                temp->setData(data);
                data2 = findSmallestBurstTime(burstTime);
                
                if(data.getProcessId() == data2.getProcessId()) {
                    /*Do Nothing*/
                }
                else {
                    break;
                }
            }
            
            tempData.setProcessID(data.getProcessId());
            tempData.setArrivalTime(arrivalTime);
            tempData.setBurstTime(burstTime);
            newTempLinkedList->insertAtBack(tempData);
            arrivalTime = burstTime;
            
            if(temp->getData().getBurstTime() == 0) {
                this->deleteNode(temp->getData().getProcessId());
            }
        }
        
        this->SRTF(newTempLinkedList, burstTime, arrivalTime, 1);
    }
}

// MARK: - Non-Preemptive Priority Scheduling
void LinkedList :: nonPreEmptivePriority(int priorityLevel, TempLinkedList *newTempLinkedList,
                                         WaitingAndTurnAroundTime *waitingAndTurnAroundTime, int burstTime) throw(runtime_error) {
    LinkedListNode *temp;
    LinkedListDataNode data;
    TempLinkedListNodeData tempData;
    WaitingAndTurnAroundTimeDataNode waitingAndTurnAroundData;
    bool shouldSkip = false;
    
    if(!this->isEmpty()) {
        temp = this->head;
        
        data = this->findHighestPriority(burstTime, priorityLevel);
        
        if(data.getProcessId() == "") {
            shouldSkip = true;
        }
        
        if (shouldSkip) {
            data.setArrivalTime(burstTime);
            
            burstTime += 1;
            data.setBurstTime(burstTime);
            data.setProcessID("-");
            
            tempData.setProcessID(data.getProcessId());
            tempData.setArrivalTime(data.getArrivalTime());
            tempData.setBurstTime(data.getBurstTime());
            
            newTempLinkedList->insertAtBack(tempData);
        }
        else {
            tempData.setProcessID(data.getProcessId());
            tempData.setArrivalTime(burstTime);
            burstTime += data.getBurstTime();
            tempData.setBurstTime(burstTime);
            
            newTempLinkedList->insertAtBack(tempData);
            
            waitingAndTurnAroundData.setProcessID(data.getProcessId());
            waitingAndTurnAroundData.setArrivalTime(data.getArrivalTime());
            waitingAndTurnAroundData.setBurstTime(data.getBurstTime());
            waitingAndTurnAroundData.calculateWaitingAndTurnAroundTime(burstTime);
            waitingAndTurnAroundTime->insertAtBack(waitingAndTurnAroundData);
            
            this->deleteNode(data.getProcessId());
        }
        this->nonPreEmptivePriority(priorityLevel, newTempLinkedList, waitingAndTurnAroundTime, burstTime);
    }
}

// MARK: - Preemptive Priority Scheduling
void LinkedList :: preEmptivePriority(int priorityLevel, TempLinkedList *newTempLinkedList,
                                      int burstTime, int arrivalTime) throw(runtime_error) {
    LinkedListNode *temp;
    LinkedListDataNode data, data2;
    TempLinkedListNodeData tempData;
    int tempBurstTime = 0;
    
    if(!this->isEmpty()) {
        temp = this->head;
        
        data = this->findHighestPriority(burstTime, priorityLevel);
        
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
        
        tempBurstTime = data.getBurstTime();
        
        for(int i = 0; i < tempBurstTime; i++) {
            burstTime++;
            data.setBurstTime(data.getBurstTime()-1);
            temp->setData(data);
            
            data2 = this->findHighestPriority(burstTime, priorityLevel);
            
            if(data2.getProcessId() == data.getProcessId()) {
                /*Do Nothing*/
            }
            else {
                break;
            }
        }
        
        tempData.setProcessID(temp->getData().getProcessId());
        tempData.setArrivalTime(arrivalTime);
        tempData.setBurstTime(burstTime);
        newTempLinkedList->insertAtBack(tempData);
        arrivalTime = burstTime;
        
        if(temp->getData().getBurstTime() == 0) {
            this->deleteNode(temp->getData().getProcessId());
        }
        this->preEmptivePriority(priorityLevel, newTempLinkedList, burstTime, arrivalTime);
    }
}

// MARK: - Round Robin Scheduling
void LinkedList :: roundRobin(Queue *queue, TempLinkedList *newTempLinkedList,
                              int timeQuantum, int burstTime, int arrivalTime,
                              int ran, string processId) throw(runtime_error) {
    LinkedListNode *temp;
    LinkedListDataNode data;
    TempLinkedListNodeData tempData;
    int subtractedValue = 0;
    
    if(!this->isEmpty()) {
        temp = this->head;
        
        if(ran == 0) {
            data = temp->getData();
            burstTime = arrivalTime = data.getArrivalTime();
        }
        else {
            data = queue->dequeue();
            
            if(data.getArrivalTime() > burstTime) {
                LinkedListDataNode tempNode;
                TempLinkedListNodeData tempData2;
                
                tempNode.setArrivalTime(burstTime);
                
                burstTime += 1;
                tempNode.setBurstTime(burstTime);
                tempNode.setProcessID("-");
                
                tempData2.setProcessID(tempNode.getProcessId());
                tempData2.setArrivalTime(tempNode.getArrivalTime());
                tempData2.setBurstTime(tempNode.getBurstTime());
                
                newTempLinkedList->insertAtBack(tempData2);
            }
            
            while(temp != NULL) {
                if(temp->getData().getProcessId() == data.getProcessId()) {
                    data = temp->getData();
                    break;
                }
                temp = temp->getNextNode();
            }
        }
        
        subtractedValue = data.getBurstTime() - timeQuantum;
        
        if(subtractedValue <= 0) {
            burstTime += data.getBurstTime();
            data.setBurstTime(0);
        }
        else {
            data.setBurstTime(subtractedValue);
            burstTime += timeQuantum;
        }
        
        tempData.setProcessID(data.getProcessId());
        tempData.setArrivalTime(arrivalTime);
        tempData.setBurstTime(burstTime);
        
        newTempLinkedList->insertAtBack(tempData);
        
        arrivalTime = burstTime;
        
        temp->setData(data);
        
        processId = findArrivalTime(queue, burstTime, processId, temp->getData().getBurstTime());
            
        if(temp->getData().getBurstTime() > 0) {
            queue->enqueue(temp->getData());
        }
        else if(temp->getData().getBurstTime() == 0) {
            this->deleteNode(temp->getData().getProcessId());
        }
        
        this->roundRobin(queue, newTempLinkedList, timeQuantum, burstTime, arrivalTime, 1, processId);
    }
}
