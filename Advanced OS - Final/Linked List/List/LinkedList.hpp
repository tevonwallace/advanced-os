//
//  LinkedList.hpp
//  Advanced OS - Final
//
//  Created by Dr. Tevon Wallace  on 12/24/23.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include "LinkedListNode.hpp"
#include "TempLinkedList.hpp"
#include "WaitingAndTurnAroundTime.hpp"
#include "Queue.hpp"

class LinkedList {
private:
    // MARK: - Declaring Variables
    LinkedListNode *head, *tail;
    int count;
    
    // MARK: - Insertions
    void insertAtFront(LinkedListDataNode data);
    
    void insertAtBack(LinkedListDataNode data);
    
    void insertAtMiddle(LinkedListDataNode data);
    
    // MARK: - Deleting a Node
    void deleteNode(string processId);
    
    // MARK: - Check if Empty
    bool isEmpty();
    
    LinkedListDataNode getTail() const;
    
    // MARK: - Find Arrival Times
    string findArrivalTime(Queue *Queue, int burstTime, string processId,
                           int remainingBurstTime);
    
    // MARK: - Find Smallest Burst Time
    LinkedListDataNode findSmallestBurstTime(int burstTime);
    
    // MARK: - Find Highest Priority
    LinkedListDataNode findHighestPriority(int burstTime, int priorityLevel);
    
public:
    // MARK: - Constructor
    LinkedList();
    
    // MARK: - Head and Tail Accessors
    LinkedListDataNode getHead() const;
    
    // MARK: - Destroying LinkedList
    void destroy(string schedulingAlgorithm);
    
    // MARK: - Displaying the contents of the list
    void display(int headerCount = 3);
    
    // MARK: - Organizing LinkedList
    void organize(LinkedListDataNode data);
    
    // MARK: - First Come First Serve Scheduling
    void FCFS(TempLinkedList *newTempLinkedList, WaitingAndTurnAroundTime *waitingAndTurnAroundTime,
              int burstTime, int ran) throw(runtime_error);
    
    // MARK: - Shortest Job First Scheduling
    void SJF(TempLinkedList *newTempLinkedList, WaitingAndTurnAroundTime *waitingAndTurnAroundTime,
             int burstTime, int ran) throw(runtime_error);
    
    // MARK: - Shortest Remaining Time First Scheduling
    void SRTF(TempLinkedList *newTempLinkedList, int burstTime,
              int arrivalTime, int ran) throw(runtime_error);
    
    // MARK: - Non-Preemptive Priority Scheduling
    void nonPreEmptivePriority(int priorityLevel, TempLinkedList *newTempLinkedList,
                               WaitingAndTurnAroundTime *waitingAndTurnAroundTime,
                               int burstTime) throw(runtime_error);
    
    // MARK: - Preemptive Priority Scheduling
    void preEmptivePriority(int priorityLevel, TempLinkedList *newTempLinkedList,
                            int burstTime, int arrivalTime) throw(runtime_error);
    
    // MARK: - Round Robin Scheduling
    void roundRobin(Queue *Queue, TempLinkedList *newTempLinkedList,
                    int timeQuantum, int burstTime, int arrivalTime,
                    int ran, string processId) throw(runtime_error);
};
#endif /* LinkedList_hpp */
