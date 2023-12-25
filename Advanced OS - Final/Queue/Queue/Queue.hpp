//
//  Queue.hpp
//  Advanced Operating Systems - Final Project
//
//  Created by Dr. Tevon Wallace  on 12/24/23.
//

#ifndef Queues_hpp
#define Queues_hpp

#include "QueueNode.hpp"

class Queue {
private:
    // MARK: - Declaring Variables
    QueueNode *front;
    QueueNode *rear;
    
public:
    // MARK: - Constructor
    Queue();
    
    // MARK: - Enqueue
    void enqueue(LinkedListDataNode data);
    
    // MARK: - Dequeue
    LinkedListDataNode dequeue();
    
    // MARK: - Check if Empty
    bool isEmpty();
    
    // MARK: - Destroying Queue
    void destroy();
};
#endif /* Queues_hpp */
