//
//  TempLinkedList.hpp
//  Advanced Operating Systems - Final Project
//
//  Created by Dr. Tevon Wallace  on 12/24/23.
//

#ifndef TempLinkedList_hpp
#define TempLinkedList_hpp

#include "TempLinkedListNode.hpp"
#include "ArrivalTimeLinkedList.hpp"

class TempLinkedList {
private:
    // MARK: - Declaring Variables
    TempLinkedListNode *head, *tail;
    
public:
    // MARK: - Constructor
    TempLinkedList();
    
    // MARK: - Insert At Back
    void insertAtBack(TempLinkedListNodeData data);
    
    // MARK: - Check if Empty
    bool isEmpty();
    
    // MARK: - Deleting a Node
    void deleteNode(TempLinkedListNode *newNode);
    
    // MARK: - Calculating Waiting & Turn Around Time
    void calculateWaitingAndTurnAroundTime(ArrivalTimeLinkedList *ArrivalTimeList, string schedulingAlgorithm,
                                           bool activateWaitingAndTurnAroundTimeForAllProcesses);
    
    // MARK: - Displaying List
    void display(string schedulingAlgorithm);
    
    // MARK: - Destroying List
    void destroy(string schedulingAlgorithm);
};
#endif /* TempLinkedList_hpp */
