//
//  WaitingAndTurnAroundTime.h
//  Advanced OS - Final
//
//  Created by Dr. Tevon Wallace  on 12/24/23.
//

#ifndef WaitingAndTurnAroundTime_hpp
#define WaitingAndTurnAroundTime_hpp

#include "WaitingAndTurnAroundTimeNode.hpp"

// This LinkedList calculates the Waiting Time and Turn Around Time for FCFS, SJF and Non-PreEmptive Priority

// Turn Around Time = Time Finished/Completed - Arrival Time
// Waiting Time =  Turn Around Time - Burst Time

class WaitingAndTurnAroundTime{
private:
    // MARK: - Delcaring Variables
    WaitingAndTurnAroundTimeNode *head, *tail;
    int count;
    
public:
    // MARK: - Constructor
    WaitingAndTurnAroundTime();
    
    // MARK: - Insert At Back
    void insertAtBack(WaitingAndTurnAroundTimeDataNode data);
    
    // MARK: - Check if Empty
    bool isEmpty();
    
    // MARK: - Display Waiting & Turn Around Time
    void display(bool activateWaitingAndTurnAroundTimeForAllProcesses);
    
    void destroy();
};
#endif /* WaitingAndTurnAroundTime_hpp */

