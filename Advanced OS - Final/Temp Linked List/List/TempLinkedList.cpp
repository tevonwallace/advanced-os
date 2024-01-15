//
//  TempLinkedList.cpp
//  Advanced OS - Final
//
//  Created by Tevon Wallace  on 12/25/23.
//  Copyright © 2023 Tevon Wallace. All rights reserved.
//

#include "TempLinkedList.hpp"

// MARK: - Constructor
TempLinkedList :: TempLinkedList() {
    this->head = this->tail = NULL;
}

// MARK: - Insert At Back
void TempLinkedList :: insertAtBack(TempLinkedListNodeData data) {
    TempLinkedListNode *temp = new TempLinkedListNode(data, NULL);
    
    if (temp != NULL) {
        if (this->isEmpty()) {
            this->head = temp;
            this->tail = temp;
        }
        else {
            this->tail->setNextNode(temp);
            this->tail = temp;
        }
    }
    else {
        cout << "Error inserting node at back" << endl;
    }
}

// MARK: - Check if Empty
bool TempLinkedList :: isEmpty() const {
    return this->head == NULL;
}

// MARK: - Deleting a Node
void TempLinkedList :: deleteNode(TempLinkedListNode *newNode) {
    TempLinkedListNode *current, *prevNode, *temp;
    int counter = 0;
    
    current = this->head;
    prevNode = this->head;
    
    if(!this->isEmpty()) {
        if (this->head == newNode) {
            temp = this->head;
            
            if(this->head->getNextNode() == NULL) {
                this->head = NULL;
                this->tail = NULL;
            }
            else {
                this->head = this->head->getNextNode();
            }
            delete temp;
        }
        else if(this->tail == newNode) {
            temp = this->head;
            
            while(temp != this->tail) {
                prevNode = temp;
                temp = temp->getNextNode();
            }
            
            prevNode->setNextNode(NULL);
            this->tail = prevNode;
            delete temp;
        }
        else {
            while(current->getNextNode() != NULL) {
                counter++;
                temp = current;
                current = current->getNextNode();
                
                if(temp == newNode) {
                    prevNode->setNextNode(current);
                    delete temp;
                    break;
                }
                
                if (counter > 1) {
                    prevNode = prevNode->getNextNode();
                }
            }
        }
    }
    else {
        cout << "\nList is empty" << endl;
    }
}

TempLinkedListNodeData TempLinkedList :: get(int index) {
    TempLinkedListNode *temp = this->head;
    int count = 0;
    
    while (temp != NULL) {
        if (index == count) {
            return temp->getData();
        }
        
        temp = temp->getNextNode();
        count++;
    }
    
    return TempLinkedListNodeData();
}

// MARK: - Calculating Waiting & Turn Around Time
void TempLinkedList :: calculateWaitingAndTurnAroundTime(ArrivalTimeLinkedList *arrivalTimeLinkedList,
                                                         bool activateWaitingAndTurnAroundTimeForAllProcesses) {
    TempLinkedListNode *temp = this->head;
    TempLinkedList *processIdList = new TempLinkedList();
    int count = 0, burstTime = 0;
    
    if (activateWaitingAndTurnAroundTimeForAllProcesses) {
        cout << "\nWaiting and Turn Around Time for Individual Processes" << endl;
        cout << "\nProcessID\tWaiting Time\tTurn Around Time" << endl;
    }
    
    while(temp != NULL) {
        processIdList->insertAtBack(TempLinkedListNodeData(temp->getData().getProcessId(), 0, 0));
        burstTime = temp->getData().getBurstTime();
        
        TempLinkedListNode *temp2 = temp->getNextNode();
        
        while (temp2 != NULL) {
            if (temp2->getData().getProcessId() == processIdList->get(count).getProcessId()) {
                burstTime = temp2->getData().getBurstTime();
                this->deleteNode(temp2);
                temp2 = temp;
            }
            temp2 = temp2->getNextNode();
        }
        
        arrivalTimeLinkedList->calculateWaitingAndTurnAroundTime(processIdList->get(count).getProcessId(),
                                                                 burstTime,
                                                                 activateWaitingAndTurnAroundTimeForAllProcesses);
        
        count++;
        temp = temp->getNextNode();
    }
    
    cout << "Average Waiting Time: " << arrivalTimeLinkedList->calculateWaitingTime() << endl;
    cout << "Average Turn Around Time: " << arrivalTimeLinkedList->calculateTurnAroundTime() << "\n" << endl;
    
    arrivalTimeLinkedList->destroy();
    this->destroy();
    processIdList->destroy();
}

// MARK: - Displaying List
void TempLinkedList :: display() {
    TempLinkedListNode *temp = this->head;
    int ranCount = 0, oneDigit = 0;
    long oneID = 0;
    
    while(temp != NULL) {
        oneID = temp->getData().getProcessId().length();
        
        cout << (ranCount==0?"|":"");
        if(oneID==1)
        { cout << "---|"; }
        else if(oneID==2)
        { cout << "----|"; }
        else if(oneID==3)
        { cout << "-----|"; }
        
        ranCount = 1;
        
        temp = temp->getNextNode();
    }
    
    temp = this->head;
    ranCount = 0; cout << endl;
    
    while(temp != NULL) {
        cout << (ranCount==0?"|":"") <<" "<<temp->getData().getProcessId()<< " |";
        
        ranCount = 1;
        
        temp = temp->getNextNode();
    }
    
    temp = this->head;
    ranCount = 0; cout << endl;
    
    while(temp != NULL) {
        cout << (ranCount==0?"|":"");
        if(oneID==1)
        { cout << "---|"; }
        else if(oneID==2)
        { cout << "----|"; }
        else if(oneID==3)
        { cout << "-----|"; }
        
        ranCount = 1;
        
        temp = temp->getNextNode();
    }
    
    temp = this->head;
    ranCount = 0; cout << endl;
    
    while(temp != NULL) {
        if(ranCount == 0) {
            if(temp->getData().getArrivalTime() <= 9) {
                oneDigit = 1;
            }
            else if(temp->getData().getArrivalTime() >= 100) {
                oneDigit = 3;
            }
            else {
                oneDigit = 2;
            }
        }
        else {
            if(temp->getData().getArrivalTime() <= 9) {
                oneDigit = 1;
            }
            else if(temp->getData().getArrivalTime() >= 100) {
                oneDigit = 3;
            }
            else {
                oneDigit = 2;
            }
        }
        
        if(ranCount == 0) {
            cout << temp->getData().getArrivalTime();
        }
        if((oneID == 1 && oneDigit == 1) || (oneID == 2 && oneDigit == 2)) {
            cout << "   "<< temp->getData().getBurstTime();
        }
        else if(oneID == 1 && oneDigit == 2) {
            cout << "  "<< temp->getData().getBurstTime();
        }
        else if((oneID == 2 && oneDigit == 1) || (oneID == 3 && oneDigit == 2)) {
            cout << "    "<< temp->getData().getBurstTime();
        }
        else if(oneID == 1 && oneDigit == 3) {
            cout << " "<< temp->getData().getBurstTime();
        }
        else if(oneID == 3 && oneDigit == 1) {
            cout << "     "<< temp->getData().getBurstTime();
        }
        else if(oneID == 3 && oneDigit == 3) {
            cout << "   "<< temp->getData().getBurstTime();
        }
        
        ranCount = 1;
        
        temp = temp->getNextNode();
    }
    cout << endl;
}

// MARK: - Destroying List
void TempLinkedList :: destroy() {
    TempLinkedListNode *temp;
    
    while(!this->isEmpty()) {
        temp = this->head;
        this->head = this->head->getNextNode();
        delete temp;
    }
}
