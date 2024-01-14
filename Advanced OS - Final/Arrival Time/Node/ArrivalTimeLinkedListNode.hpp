//
//  ArrivalTimeLinkedListNode.hpp
//  Advanced OS - Final
//
//  Created by Tevon Wallace  on 12/24/23.
//

#ifndef ArrivalTimeLinkedListNode_hpp
#define ArrivalTimeLinkedListNode_hpp

#include "ArrivalTimeLinkedListDataNode.hpp"

class ArrivalTimeLinkedListNode {
private:
    // MARK: - Declaring Variables
    ArrivalTimeLinkedListDataNode data;
    ArrivalTimeLinkedListNode *nextNode;
    
public:
    // MARK: - Constructors
    ArrivalTimeLinkedListNode();
    ArrivalTimeLinkedListNode(ArrivalTimeLinkedListDataNode data, ArrivalTimeLinkedListNode *nextNode);
    
    // MARK: - Mutators
    void setWaitingAndTurnAroundTime(int completedTime);
    void setData(ArrivalTimeLinkedListDataNode data);
    
    void setNextNode(ArrivalTimeLinkedListNode *nextNode);
    
    // MARK: - Accessors
    ArrivalTimeLinkedListDataNode getData();
    
    ArrivalTimeLinkedListNode *getNextNode();
};
#endif /* ArrivalTimeLinkedListNode_hpp */
