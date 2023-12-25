//
//  TempLinkedListNode.hpp
//  Advanced Operating Systems - Final Project
//
//  Created by Dr. Tevon Wallace  on 12/24/23.
//

#ifndef TempLinkedListNode_hpp
#define TempLinkedListNode_hpp

#include "TempLinkedListNodeData.hpp"

class TempLinkedListNode {
private:
    // MARK: - Delcaring Variables
    TempLinkedListNodeData data;
    TempLinkedListNode *nextNode;
    
public:
    // MARK: - Constructors
    TempLinkedListNode();
    
    TempLinkedListNode(TempLinkedListNodeData data, TempLinkedListNode *nextNode);
    
    // MARK: - Mutators
    void setData(TempLinkedListNodeData data);
    
    void setNextNode(TempLinkedListNode *nextNode);
    
    // MARK: - Accessors
    TempLinkedListNodeData getData() const;
    
    TempLinkedListNode *getNextNode() const;
};
#endif /* TempLinkedListNode_hpp */
