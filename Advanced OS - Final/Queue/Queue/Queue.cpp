//
//  Queue.cpp
//  Advanced Operating Systems - Final Project
//
//  Created by Dr. Tevon Wallace  on 12/25/23.
//  Copyright © 2023 Tevon Wallace. All rights reserved.
//

#include "Queue.hpp"

// MARK: - Constructor
Queue :: Queue() {
    this->front = NULL;
    this->rear = NULL;
}

// MARK: - Enqueue
void Queue :: enqueue(LinkedListDataNode data) {
    QueueNode *temp = new QueueNode(data, NULL, NULL);
    
    if(temp != NULL) {
        if(this->front == NULL) {
            this->front = temp;
            this->rear = temp;
        }
        else {
            this->rear->setNextNode(temp);
            temp->setPrevNode(this->rear);
            this->rear = temp;
        }
    }
    else {
        cout << "Unable to enqueue new data in the queue, Out of Memory"<<endl;
    }
}

// MARK: - Dequeue
LinkedListDataNode Queue :: dequeue() {
    QueueNode *temp;
    LinkedListDataNode data;
    
    if(this->front != NULL) {
        if(this->rear == this->front) {
            this->rear = NULL;
        }
        
        temp = this->front;
        this->front = this->front->getNextNode();
        
        if(this->front != NULL) {
            this->front->setPrevNode(NULL);
        }
        
        data = temp->getData();
        delete temp;
    }
    else {
        cout << "Error, cannot dequeue from an empty queue"<<endl;
    }
    return data;
}

// MARK: - Check if Empty
bool Queue :: isEmpty() {
    if(this->front == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// MARK: - Destroying Queue
void Queue :: destroy() {
    while(!this->isEmpty()) {
        this->dequeue();
    }
    //cout << "\nRound Robin Queue was Destroyed"<<endl;
}
