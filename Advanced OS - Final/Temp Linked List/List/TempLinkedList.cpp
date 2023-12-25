//
//  TempLinkedList.cpp
//  Advanced OS - Final
//
//  Created by Dr. Tevon Wallace  on 12/25/23.
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
bool TempLinkedList :: isEmpty() {
    if(this->head == NULL) {
        return true;
    }
    return false;
}

// MARK: - Deleting a Node
void TempLinkedList :: deleteNode(TempLinkedListNode *newNode) {
    TempLinkedListNode *current, *prevNode, *temp;
    int counter = 0;
    
    current = this->head;
    prevNode = this->head;
    
    if(this->head != NULL) {
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
            temp = head;
            
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
                if (counter <= 1){
                    /* Do Nothing */
                }
                else {
                    prevNode = prevNode->getNextNode();
                }
            }
        }
    }
    else {
        cout << "\nList is empty" << endl;
    }
}

// MARK: - Calculating Waiting & Turn Around Time
void TempLinkedList :: calculateWaitingAndTurnAroundTime(ArrivalTimeLinkedList *arrivalTimeLinkedList,
                                                         string schedulingAlgorithm, bool activateWaitingAndTurnAroundTimeForAllProcesses) {
    TempLinkedListNode *temp = this->head, *temp2;
    string processIDArray[30];
    int count = 0, burstTime = 0;
    
    if (activateWaitingAndTurnAroundTimeForAllProcesses) {
        cout << "\nWaiting and Turn Around Time for Individual Processes" << endl;
        cout << "\nProcessID\tWaiting Time\tTurn Around Time" << endl;
    }
    
    while(temp != NULL) {
        processIDArray[count] = temp->getData().getProcessID();
        burstTime = temp->getData().getBurstTime();
        
        temp2 = temp->getNextNode();
        
        while (temp2 != NULL) {
            if (temp2->getData().getProcessID() == processIDArray[count]) {
                burstTime = temp2->getData().getBurstTime();
                this->deleteNode(temp2);
                temp2 = temp;
            }
            temp2 = temp2->getNextNode();
        }
        
        arrivalTimeLinkedList->calculateWaitingAndTurnAroundTime(processIDArray[count], burstTime, activateWaitingAndTurnAroundTimeForAllProcesses);
        
        count++;
        temp = temp->getNextNode();
    }
    
    cout << "Average Waiting Time: " << arrivalTimeLinkedList->calculateWaitingTime() << endl;
    cout << "Average Turn Around Time: " << arrivalTimeLinkedList->calculateTurnAroundTime() << "\n" << endl;
    
    arrivalTimeLinkedList->destroy(schedulingAlgorithm);
    this->destroy(schedulingAlgorithm);
}

// MARK: - Displaying List
void TempLinkedList :: display(string schedulingAlgorithm) {
    TempLinkedListNode *temp = this->head;
    int ranCount = 0, oneDigit = 0;
    long oneID = 0;
    
    while(temp != NULL) {
        oneID = temp->getData().getProcessID().length();
        
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
        cout << (ranCount==0?"|":"") <<" "<<temp->getData().getProcessID()<< " |";
        
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
void TempLinkedList :: destroy(string schedulingAlgorithm) {
    TempLinkedListNode *temp;
    
    while(!this->isEmpty()) {
        temp = this->head;
        this->head = this->head->getNextNode();
        delete temp;
    }
}
