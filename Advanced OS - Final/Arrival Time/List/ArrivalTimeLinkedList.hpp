//
//  ArrivalTimeLinkedList.hpp
//  Advanced Operating Systems - Final Project
//
//  Created by Dr. Tevon Wallace  on 12/24/23.
//

#ifndef ArrivalTimeLinkedList_hpp
#define ArrivalTimeLinkedList_hpp

//This LinkedList calculates the Waiting Time and Turn Around Time for the SRTF, PreEmptivePriority and Round Robin

#include "ArrivalTimeLinkedListNode.hpp"

class ArrivalTimeLinkedList
{
private:
    // MARK: - Declaring Variables
    ArrivalTimeLinkedListNode *head, *tail;
    double waitingTime, turnAroundTime;
    int count;
    
public:
    // MARK: - Constructor
    ArrivalTimeLinkedList();
    
    //MARK: - Insertions
    void insertAtFront(ArrivalTimeLinkedListDataNode data);
    
    void insertAtBack(ArrivalTimeLinkedListDataNode data);
    
    void insertAtMiddle(ArrivalTimeLinkedListDataNode data);
    
    // MARK: - Head and Tail Accessors
    ArrivalTimeLinkedListDataNode getHead() const;
    
    ArrivalTimeLinkedListDataNode getTail() const;
    
    // MARK: - Organizing List
    void organizeDataInLinkedList(ArrivalTimeLinkedListDataNode data);
    
    // MARK: - Check If Empty
    bool isEmpty();
    
    // MARK: - Mutators
    void setWaitingTime(double waitingTime);
    
    void setTurnAroundTime(double turnAroundTime);
    
    // MARK:-  Accessors
    double getWaitingTime() const;
    
    double getTurnAroundTime() const;
    
    int getCount() const;
    
    double calculateWaitingTime() const;
    
    double calculateTurnAroundTime() const;
    
    // MARK: - Destroy Arrival Time LinkedList
    void destroy(string schedulingAlgorithm);
    
    // MARK: - Calculate Waiting & Turn Around Time
    void calculateWaitingAndTurnAroundTime(string processID, int completedTime,
                                           bool activateWaitingAndTurnAroundTimeForAllProcesses);
};
#endif /* ArrivalTimeLinkedList_hpp */
