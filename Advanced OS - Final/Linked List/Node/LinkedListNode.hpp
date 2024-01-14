//
//  LinkedListNode.hpp
//  Advanced OS - Final
//
//  Created by Tevon Wallace  on 12/24/23.
//

#ifndef LinkedListNode_hpp
#define LinkedListNode_hpp

#include "LinkedListDataNode.hpp"

class LinkedListNode {
private:
    // MARK: - Declaring Variables
    LinkedListDataNode data;
    LinkedListNode *nextNode;
    
public:
    // MARK: - Constructors
    LinkedListNode();
    
    LinkedListNode(LinkedListDataNode data, LinkedListNode *nextNode);
    
    // MARK: - Mutators
    void setData(LinkedListDataNode data);
    
    void setNextNode(LinkedListNode *nextNode);
    
    // MARK: - Accessors
    LinkedListDataNode getData() const;
    
    LinkedListNode *getNextNode() const;
};
#endif /* LinkedListNode_hpp */
