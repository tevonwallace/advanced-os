//
//  WaitingAndTurnAroundTimeDataNode.hpp
//  Advanced Operating Systems - Final Project
//
//  Created by Dr. Tevon Wallace  on 12/24/23.
//

#ifndef WaitingAndTurnAroundTimeDataNode_hpp
#define WaitingAndTurnAroundTimeDataNode_hpp

#include <iostream>
#include <string>

using namespace std;

//Turn Around Time = Time Finished/Completed - Arrival Time
//Waiting Time =  Turn Around Time - Burst Time

class WaitingAndTurnAroundTimeDataNode {
private:
    // MARK: - Declaring Variables
    string processID;
    int arrivalTime, burstTime, waitingTime, turnAroundTime, timeCompleted;
    
public:
    // MARK: - Constructor
    WaitingAndTurnAroundTimeDataNode();
    
    // MARK: - Calculating Waiting & Turn Around Time
    void calculateWaitingAndTurnAroundTime(int timeCompleted);
    
    // MARK: - Mutators
    void setProcessID(string processID);
    
    void setArrivalTime(int arrivalTime);
    
    void setBurstTime(int burstTime);
    
    void setTimeCompleted(int timeCompleted);
    
    // MARK: - Accessors
    string getProcessID() const;
    
    int getArrivalTime() const;
    
    int getBurstTime() const;
    
    int getTurnAroundTime() const;
    
    int getWaitingTime() const;
    
    int getTimeCompleted() const;
};
#endif /* WaitingAndTurnAroundTimeDataNode_hpp */
