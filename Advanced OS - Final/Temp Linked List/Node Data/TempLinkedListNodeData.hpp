//
//  TempLinkedListNodeData.hpp
//  Advanced OS - Final
//
//  Created by Dr. Tevon Wallace  on 12/24/23.
//

#ifndef TempLinkedListNodeData_hpp
#define TempLinkedListNodeData_hpp

#include <iostream>
#include <string>
using namespace std;

class TempLinkedListNodeData {
private:
    // MARK: - Declaring Variables
    string processId;
    int arrivalTime, burstTime;
    
public:
    // MARK: - Constructor
    TempLinkedListNodeData();
    
    TempLinkedListNodeData(string processId, int arrivalTime, int burstTime);
    
    // MARK: - Mutators
    void setProcessId(string processId);
    
    void setArrivalTime(int arrivalTime);
    
    void setBurstTime(int burstTime);
    
    // MARK: - Accessors
    string getProcessId() const;
    
    int getArrivalTime() const;
    
    int getBurstTime() const;
};
#endif /* TempLinkedListNodeData_hpp */
