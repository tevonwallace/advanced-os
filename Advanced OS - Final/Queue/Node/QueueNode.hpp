//
//  QueueNode.hpp
//  Advanced Operating Systems - Final Project
//
//  Created by Dr. Tevon Wallace  on 12/24/23.
//

#ifndef QueueNode_hpp
#define QueueNode_hpp

#include "LinkedListDataNode.hpp"

class QueueNode {
private:
    // MARK: - Declaring Variables
    LinkedListDataNode data;
    QueueNode *prevNode;
    QueueNode *nextNode;
    
public:
    // MARK: - Constructors
    QueueNode();
    
    QueueNode(LinkedListDataNode data, QueueNode *prevNode, QueueNode *nextNode);
    
    // MARK: - Mutators
    void setData(LinkedListDataNode data);
    
    void setPrevNode(QueueNode *prevNode);
    
    void setNextNode(QueueNode *nextNode);
    
    // MARK: - Accessors
    LinkedListDataNode getData() const;
    
    QueueNode *getPrevNode() const;
    
    QueueNode *getNextNode() const;
};
#endif /* QueueNode_hpp */
