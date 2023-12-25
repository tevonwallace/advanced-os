//
//  ProcessScheduling.hpp
//  Advanced OS - Final
//
//  Created by Dr. Tevon Wallace  on 12/25/23.
//  Copyright © 2023 Tevon Wallace. All rights reserved.
//

#ifndef ProcessScheduling_hpp
#define ProcessScheduling_hpp

#include "LinkedList.hpp"
#include <fstream>

class ProcessScheduling {
private:
    LinkedList *fcfsList = NULL;
    LinkedList *sjfList = NULL;
    LinkedList *srtfList = NULL;
    LinkedList *nonPreEmptivePriorityList = NULL;
    LinkedList *preEmptivePriorityList = NULL;
    LinkedList *roundRobinList = NULL;
    
    int tempArray[6];
    
    ArrivalTimeLinkedList *srtfArrivalList = NULL;
    ArrivalTimeLinkedList *preEmptiveArrivalList  = NULL;
    ArrivalTimeLinkedList *roundRobinArrivalList = NULL;
    
    int priority;
    bool activateWaitingAndTurnAroundTimeForAllProcesses;
    
    const int FCFS_INDEX = 1,
        SJF_INDEX = 2,
        SRTF_INDEX = 3,
        NON_PRE_EMPTIVE_INDEX = 4,
        PRE_EMPTIVE_INDEX = 5,
        ROUND_ROBIN_INDEX = 6;
    
    const int NUMBER_OF_SUPPORTED_ALGORITHMS = 6;
    
    // MARK: - Used to split string by comma
    string* splitStringByComma(string data);
        
    // MARK: - Parsing the Options from String
    void parsingString(int tempArray[], string typeOfScheduling);
    
    // MARK: - Checking if Array is Empty
    bool isArrayEmpty();
    
    // MARK: - Checking if string only contains white spaces
    bool isBlankSpace(string data);
    
    // MARK: - Destroying all Lists
    void destroyLinkedLists();
    
    // MARK: - Reading data from File
    void readFromFile(string path)  throw(runtime_error);
    
    // MARK: - Swap Character with Integer
    int swapCharacterWithInteger(char character);
    
    // MARK: - Checking for Dash (Shortcut for selecting options *1-6*)
    bool checkStringForDashOperator(string data, int digit[]);
    
    // MARK: - Checking for '-a' to Activate Times for All Processes
    void checkCharacterForAllProcesses(string data);
    
    void acceptDataToBeProcessed();
    
    void processAlgorithms();
    
    void validatePriority(string priority);
public:
    // MARK: - Constructors
    ProcessScheduling();
    
    void start();
};
#endif /* ProcessScheduling_hpp */
