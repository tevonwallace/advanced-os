//
//  LinkedListDataNode.hpp
//  Advanced Operating Systems - Final Project
//
//  Created by Dr. Tevon Wallace  on 12/24/23.
//

#ifndef LinkedListDataNode_hpp
#define LinkedListDataNode_hpp

#include <iostream>
#include <string>
using namespace std;

class LinkedListDataNode {
private:
    // MARK: - Declaring Variables
    string processID;
    int arrivalTime, burstTime, priority;
    
public:
    // MARK: - Contructor
    LinkedListDataNode();
    
    // MARK: - Mutators
    void setProcessID(string processID);
    
    void setArrivalTime(int arrivalTime);
    
    void setBurstTime(int burstTime);
    
    void setPriority(int priority);
    
    // MARK: - Accessors
    string getProcessID() const;
    
    int getArrivalTime() const;
    
    int getBurstTime() const;
    
    int getPriority() const;
};
#endif /* LinkedListDataNode_hpp */
