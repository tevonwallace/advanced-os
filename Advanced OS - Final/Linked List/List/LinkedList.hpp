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
#include "../../Enums/Enums.cpp";

class LinkedList {
private:
    // MARK: - Declaring Variables
    LinkedListNode *head, *tail;
    int count;
    Algorithm algorithm;
    
    TempLinkedList *newTempLinkedList;
    WaitingAndTurnAroundTime *waitingAndTurnAroundTime;
    
    Queue *queue;
    
    // MARK: - Insertions
    void insertAtFront(LinkedListDataNode data);
    
    void insertAtBack(LinkedListDataNode data);
    
    void insertAtMiddle(LinkedListDataNode data);
    
    // MARK: - Deleting a Node
    void deleteNode(string processId);
    
    // MARK: - Check if Empty
    bool isEmpty() const;
    
    LinkedListDataNode getTail() const;
    
    // MARK: - Find Arrival Times
    string findArrivalTime(int burstTime, string processId, int remainingBurstTime);
    
    // MARK: - Find Smallest Burst Time
    LinkedListDataNode findSmallestBurstTime(int burstTime);
    
    // MARK: - Find Highest Priority
    LinkedListDataNode findHighestPriority(int burstTime, int priorityLevel);
    
    string getAlgorithm() const;
    
public:
    // MARK: - Constructor
    LinkedList();
    
    // MARK: - Head and Tail Accessors
    LinkedListDataNode getHead() const;
    
    // MARK: - Destroying LinkedList
    void destroy();
    
    void initialize(Algorithm algorithm);
    
    // MARK: - Displaying the contents of the list
    void display(int headerCount = 3);
    
    void displayCharts(int activateWaitingAndTurnAroundTimeForAllProcesses,
                       ArrivalTimeLinkedList *arrivalList =  NULL);
    
    // MARK: - Organizing LinkedList
    void organize(LinkedListDataNode data);
    
    // MARK: - First Come First Serve Scheduling
    void FCFS(int burstTime = 0, int ran = 0) throw(runtime_error);
    
    // MARK: - Shortest Job First Scheduling
    void SJF(int burstTime = 0, int ran = 0) throw(runtime_error);
    
    // MARK: - Shortest Remaining Time First Scheduling
    void SRTF(int burstTime = 0, int arrivalTime = 0, int ran = 0) throw(runtime_error);
    
    // MARK: - Non-Preemptive Priority Scheduling
    void nonPreEmptivePriority(int priorityLevel, int burstTime = 0) throw(runtime_error);
    
    // MARK: - Preemptive Priority Scheduling
    void preEmptivePriority(int priorityLevel, int burstTime = 0, int arrivalTime = 0) throw(runtime_error);
    
    // MARK: - Round Robin Scheduling
    void roundRobin(string processId, int timeQuantum, int burstTime = 0,
                    int arrivalTime = 0, int ran = 0) throw(runtime_error);
};
#endif /* LinkedList_hpp */
