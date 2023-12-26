//
//  LinkedListDataNode.hpp
//  Advanced OS - Final
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
    string processId;
    int arrivalTime, burstTime, priority;
    
public:
    // MARK: - Contructor
    LinkedListDataNode();
    LinkedListDataNode(string processId, int arrivalTime, int burstTime);
    
    // MARK: - Mutators
    void setProcessId(string processId);
    
    void setArrivalTime(int arrivalTime);
    
    void setBurstTime(int burstTime);
    
    void setPriority(int priority);
    
    // MARK: - Accessors
    string getProcessId() const;
    
    int getArrivalTime() const;
    
    int getBurstTime() const;
    
    int getPriority() const;
};
#endif /* LinkedListDataNode_hpp */
