//
//  WaitingAndTurnAroundTimeNode.h
//  Advanced OS - Final
//
//  Created by Dr. Tevon Wallace  on 12/24/23.
//

#ifndef WaitingAndTurnAroundTimeNode_hpp
#define WaitingAndTurnAroundTimeNode_hpp

#include "WaitingAndTurnAroundTimeDataNode.hpp"

class WaitingAndTurnAroundTimeNode {
private:
    // MARK: - Declaring Variables
    WaitingAndTurnAroundTimeDataNode data;
    WaitingAndTurnAroundTimeNode *nextNode;
    
public:
    // MARK: - Constructors
    WaitingAndTurnAroundTimeNode();
    
    WaitingAndTurnAroundTimeNode(WaitingAndTurnAroundTimeDataNode data, WaitingAndTurnAroundTimeNode *nextNode);
    
    // MARK: - Mutators
    void setData(WaitingAndTurnAroundTimeDataNode data);
    
    void setNextNode(WaitingAndTurnAroundTimeNode *nextNode);
    
    // MARK: - Accessors
    WaitingAndTurnAroundTimeDataNode getData() const;
    
    WaitingAndTurnAroundTimeNode *getNextNode() const;
};
#endif /* WaitingAndTurnAroundTimeNode_hpp */
