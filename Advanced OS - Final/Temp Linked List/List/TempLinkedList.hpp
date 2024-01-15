//
//  TempLinkedList.hpp
//  Advanced OS - Final
//
//  Created by Tevon Wallace  on 12/24/23.
//

#ifndef TempLinkedList_hpp
#define TempLinkedList_hpp

#include "TempLinkedListNode.hpp"
#include "ArrivalTimeLinkedList.hpp"

class TempLinkedList {
private:
    // MARK: - Declaring Variables
    TempLinkedListNode *head, *tail;
    
    TempLinkedListNodeData get(int index);
    
public:
    // MARK: - Constructor
    TempLinkedList();
    
    // MARK: - Insert At Back
    void insertAtBack(TempLinkedListNodeData data);
    
    // MARK: - Check if Empty
    bool isEmpty() const;
    
    // MARK: - Deleting a Node
    void deleteNode(TempLinkedListNode *newNode);
    
    // MARK: - Calculating Waiting & Turn Around Time
    void calculateWaitingAndTurnAroundTime(ArrivalTimeLinkedList *ArrivalTimeList,
                                           bool activateWaitingAndTurnAroundTimeForAllProcesses);
    
    // MARK: - Displaying List
    void display();
    
    // MARK: - Destroying List
    void destroy();
};
#endif /* TempLinkedList_hpp */
