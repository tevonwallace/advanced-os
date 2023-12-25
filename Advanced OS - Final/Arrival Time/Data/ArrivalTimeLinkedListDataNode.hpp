//
//  ArrivalTimeLinkedListDataNode.hpp
//  Advanced Operating Systems - Final Project
//
//  Created by Dr. Tevon Wallace  on 12/24/23.
//

#ifndef ArrivalTimeLinkedListDataNode_hpp
#define ArrivalTimeLinkedListDataNode_hpp

#include <iostream>
#include <string>

using namespace std;

class ArrivalTimeLinkedListDataNode {
private:
    // MARK: - Declaring Variables
    string processID;
    int arrivalTime, burstTime, timeCompleted;
    double waitingTime, turnAroundTime;
    
public:
    // MARK: - Constructors
    ArrivalTimeLinkedListDataNode();
    
    // MARK: - Calculating Waiting and Turn Around Time
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
    
    double getWaitingTime() const;
    
    double getTurnAroundTime() const;
    
    int getTimeCompleted() const;
};
#endif /* ArrivalTimeLinkedListDataNode_hpp */
