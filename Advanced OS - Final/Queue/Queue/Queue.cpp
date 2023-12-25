//
//  Queue.cpp
//  Advanced OS - Final
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
        if(this->isEmpty()) {
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
    
    if(!this->isEmpty()) {
        if(this->rear == this->front) {
            this->rear = NULL;
        }
        
        temp = this->front;
        this->front = this->front->getNextNode();
        
        if(!this->isEmpty()) {
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
    return this->front == NULL;
}

// MARK: - Destroying Queue
void Queue :: destroy() {
    while(!this->isEmpty()) {
        this->dequeue();
    }
}
