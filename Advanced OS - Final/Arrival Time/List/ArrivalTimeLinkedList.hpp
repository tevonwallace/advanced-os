//
//  ArrivalTimeLinkedList.hpp
//  Advanced OS - Final
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
    
    //MARK: - Insertions
    void insertAtFront(ArrivalTimeLinkedListDataNode data);
    
    void insertAtBack(ArrivalTimeLinkedListDataNode data);
    
    void insertAtMiddle(ArrivalTimeLinkedListDataNode data);
    
    ArrivalTimeLinkedListDataNode getTail() const;
    
    // MARK: - Check If Empty
    bool isEmpty() const;
    
    // MARK: - Mutators
    void setWaitingTime(double waitingTime);
    
    void setTurnAroundTime(double turnAroundTime);
    
    // MARK:-  Accessors
    double getWaitingTime() const;
    
    double getTurnAroundTime() const;
    
    int getCount() const;
    
public:
    // MARK: - Constructor
    ArrivalTimeLinkedList();
    
    // MARK: - Head and Tail Accessors
    ArrivalTimeLinkedListDataNode getHead() const;
    
    // MARK: - Organizing List
    void organize(ArrivalTimeLinkedListDataNode data);
    
    double calculateWaitingTime() const;
    
    double calculateTurnAroundTime() const;
    
    // MARK: - Destroy Arrival Time LinkedList
    void destroy();
    
    // MARK: - Calculate Waiting & Turn Around Time
    void calculateWaitingAndTurnAroundTime(string processId, int completedTime,
                                           bool activateWaitingAndTurnAroundTimeForAllProcesses);
};
#endif /* ArrivalTimeLinkedList_hpp */
