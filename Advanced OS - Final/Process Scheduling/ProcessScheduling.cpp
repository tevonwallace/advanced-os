//
//  ProcessScheduling.cpp
//  Advanced OS - Final
//
//  Created by Dr. Tevon Wallace  on 12/25/23.
//  Copyright © 2023 Tevon Wallace. All rights reserved.
//

#include "ProcessScheduling.hpp"

// MARK: - Constructors
ProcessScheduling :: ProcessScheduling() {
    this->priority = 0;
    this->activateWaitingAndTurnAroundTimeForAllProcesses = false;
}

// MARK: - Parsing the Options from String
void ProcessScheduling :: parsingString(string typeOfScheduling) { //This method is used to find the options that the user selected
    string str = "";
    long length = typeOfScheduling.length()-1;
    
    for(int index = 0; index <= length; index++) {
        if(isdigit(typeOfScheduling.at(index))) {
            str = str + typeOfScheduling.at(index);
            
            if(atoi(str.c_str())-1 < 6) {
                this->tempArray[atoi(str.c_str())-1] = atoi(str.c_str());
                str = "";
            }
        }
    }
}

// MARK: - Checking if Array is Empty
bool ProcessScheduling :: isArrayEmpty() {
    int count = 0;
    
    for(int index = 0; index < 6; index++) {
        if(this->tempArray[index] == 0) {
            count++;
        }
    }
    return (count == ProcessScheduling::NUMBER_OF_SUPPORTED_ALGORITHMS ? true : false);
}

// MARK: - Checking if string only contains white spaces
bool ProcessScheduling :: isBlankSpace(string data) {//This method is used to check if the string from the line has only white spaces
    long length = data.length()-1;
    int ans = 0;
    
    for(int index = 0; index <= length; index++) {
        if(data.at(index) == ' ') {
            ans++;
        }
    }
    return (ans==length ? true : false);
}

// MARK: - Destroying all Lists
void ProcessScheduling :: destroyLinkedLists() {
    if(this->tempArray[0] == ProcessScheduling::FCFS_INDEX) {
        this->fcfsList->destroy("FCFS");
    }
    if(this->tempArray[1] == ProcessScheduling::SJF_INDEX) {
        this->sjfList->destroy("SJF");
    }
    if(this->tempArray[2] == ProcessScheduling::SRTF_INDEX) {
        this->srtfList->destroy("SRTF");
        this->srtfArrivalList->destroy("SRTF Arrival Time LinkedList");
    }
    if(this->tempArray[3] == ProcessScheduling::NON_PRE_EMPTIVE_INDEX) {
        this->nonPreEmptivePriorityList->destroy("Non-PreEmptive Priority");
    }
    if(this->tempArray[4] == ProcessScheduling::PRE_EMPTIVE_INDEX) {
        this->preEmptivePriorityList->destroy("PreEmptive Priority");
        this->preEmptiveArrivalList->destroy("PreEmptive Arrival Time LinkedList");
    }
    if(this->tempArray[5] == ProcessScheduling::ROUND_ROBIN_INDEX) {
        this->roundRobinList->destroy("Round Robin");
        this->roundRobinArrivalList->destroy("Round Robin Arrival Time LinkedList");
    }
    
    for(int index = 0; index < 6; index++) {
        this->tempArray[index] = 0;
    }
}

string* ProcessScheduling :: splitStringByComma(string data) {
    long length = data.length()-1;
    
    int currentArrayIndex = 0;
    
    string* array = new string[4]{"", "", "", ""};
    
    for(int index = 0; index <= length; index++) {
        if(data.at(index) == ',') {
            currentArrayIndex += 1;
            array[currentArrayIndex] = "";
        }
        else {
            array[currentArrayIndex] += data.at(index);
        }
    }
    
    return array;
}

void ProcessScheduling :: validatePriority() {
    if (this->priority < 0) {
        throw runtime_error("\nPriority cannot be a negative number");
    }
}

// MARK: - Reading data from File
void ProcessScheduling :: readFromFile(string fileName)  throw(runtime_error) {
    LinkedListDataNode newDataNode;
    ArrivalTimeLinkedListDataNode arrivalTimeDataNode;
    
    // The working directory is set in Scheme
    ifstream fileObject(fileName, ios::in); //Opens the file for reading
    string dataFromLine;
    int numberOfProcesses = 0;
    
    if(fileObject) {
        while(!fileObject.eof()) {
            getline(fileObject, dataFromLine); //reads the entire line from the file
            
            if((dataFromLine == "") || (this->isBlankSpace(dataFromLine)))
            { }
            else {
                string* commaSeparatedData = this->splitStringByComma(dataFromLine);
                
                string processId = commaSeparatedData[0], arrivalTime = commaSeparatedData[1];
                string burstTime = commaSeparatedData[2], priority = commaSeparatedData[3];
                
                if(arrivalTime.empty()) {
                    throw runtime_error("\nNo Arrival Time was found for Process ID: "+processId);
                }
                if(burstTime.empty()) {
                    throw runtime_error("\nNo Burst Time was found for Process ID: "+processId);
                }
                else if(atoi(burstTime.c_str()) < 1) {
                    throw runtime_error("\nBurst Time cannot be less than 1");
                }
                else if(atoi(burstTime.c_str()) > 999) {
                    throw runtime_error("\nBurst Time cannot be greater than 999\nBecause of alignment problems");
                }
                
                numberOfProcesses++;
                newDataNode.setProcessID(processId);
                newDataNode.setArrivalTime(atoi(arrivalTime.c_str()));
                newDataNode.setBurstTime(atoi(burstTime.c_str()));
                
                if(this->tempArray[3] == ProcessScheduling::NON_PRE_EMPTIVE_INDEX) {
                    this->priority = atoi(priority.c_str());
                    this->validatePriority();
                    
                    if (!priority.empty() && (atoi(priority.c_str()) < 1)) {
                        this->tempArray[3] = 0;
                    }
                }
                if(this->tempArray[4] == ProcessScheduling::PRE_EMPTIVE_INDEX) {
                    this->priority = atoi(priority.c_str());
                    this->validatePriority();
                        
                    if (!priority.empty() && (atoi(priority.c_str()) < 1)) {
                        this->tempArray[4] = 0;
                    }
                }
                
                if(this->tempArray[0] == ProcessScheduling::FCFS_INDEX) {
                    this->fcfsList->organizeDataInLinkedList(newDataNode);
                }
                
                if(this->tempArray[1] == ProcessScheduling::SJF_INDEX) {
                    this->sjfList->organizeDataInLinkedList(newDataNode);
                }
                
                if(this->tempArray[2] == ProcessScheduling::SRTF_INDEX) {
                    arrivalTimeDataNode.setProcessId(processId);
                    arrivalTimeDataNode.setArrivalTime(atoi(arrivalTime.c_str()));
                    arrivalTimeDataNode.setBurstTime(atoi(burstTime.c_str()));
                    
                    this->srtfList->organizeDataInLinkedList(newDataNode);
                    this->srtfArrivalList->organizeDataInLinkedList(arrivalTimeDataNode);
                }
                
                if(this->tempArray[3] == ProcessScheduling::NON_PRE_EMPTIVE_INDEX) {
                    if (atoi(priority.c_str()) < 0) {
                        throw runtime_error("\nPriority cannot be a negative number");
                    }
                
                    newDataNode.setPriority(atoi(priority.c_str()));
                    this->nonPreEmptivePriorityList->organizeDataInLinkedList(newDataNode);
                }
                
                if(this->tempArray[4] == ProcessScheduling::PRE_EMPTIVE_INDEX) {
                    if (atoi(priority.c_str()) < 0) {
                        throw runtime_error("\nPriority cannot be a negative number");
                    }
                
                    arrivalTimeDataNode.setProcessId(processId);
                    arrivalTimeDataNode.setArrivalTime(atoi(arrivalTime.c_str()));
                    arrivalTimeDataNode.setBurstTime(atoi(burstTime.c_str()));
                    
                    newDataNode.setPriority(atoi(priority.c_str()));
                    this->preEmptivePriorityList->organizeDataInLinkedList(newDataNode);
                    this->preEmptiveArrivalList->organizeDataInLinkedList(arrivalTimeDataNode);
                }
                
                if(this->tempArray[5] == ProcessScheduling::ROUND_ROBIN_INDEX) {
                    arrivalTimeDataNode.setProcessId(processId);
                    arrivalTimeDataNode.setArrivalTime(atoi(arrivalTime.c_str()));
                    arrivalTimeDataNode.setBurstTime(atoi(burstTime.c_str()));
                    
                    this->roundRobinList->organizeDataInLinkedList(newDataNode);
                    this->roundRobinArrivalList->organizeDataInLinkedList(arrivalTimeDataNode);
                }
            }
        }
        fileObject.close();
        
        if(numberOfProcesses == 0) {
            throw runtime_error("\nNo process was found in the file");
        }
        else if(numberOfProcesses == 1) {
            throw runtime_error("\nCannot process 1 process. Please add more processes to the file");
        }
    }
    else {
        throw runtime_error("\nError opening file for reading");
    }
}

// MARK: - Swap Character with Integer
int ProcessScheduling :: swapCharacterWithInteger(char character) {
    int array[] = {1, 2, 3, 4, 5, 6};
    
    if(character == '1') {
        return array[0];
    }
    else if(character == '2') {
        return array[1];
    }
    else if(character == '3') {
        return array[2];
    }
    else if(character == '4') {
        return array[3];
    }
    else if(character == '5') {
        return array[4];
    }
    else if(character == '6') {
        return array[5];
    }
    else {
        return array[5];
    }
}

// MARK: - Checking for Dash (Shortcut for selecting options *1-6*)
bool ProcessScheduling :: checkStringForDashOperator(string data, int digit[]) {
    long length = data.length()-1;
    bool dashFound = false;
    
    for(int index = 0; index <= length; index++) {
        if(isdigit(data.at(index))) {
            
            digit[(index-1<=0?0:1)] = this->swapCharacterWithInteger(data.at(index));
        }
        else if(data.at(index) == '-') {
            if(isdigit(data.at(0)) && (data.at(1) == '-') && (isdigit(data.at(2)))) {
                dashFound = true;
            }
        }
    }
    return dashFound;
}

// MARK: - Checking for '-a' to Activate Times for All Processes
void ProcessScheduling :: checkCharacterForAllProcesses(string data) {
    string str = "";
    bool activateWaitingAndTurnAroundTimeForAllProcesses = false;
    long length = data.length()-1;
    
    for (int index = 0; index <= length; index++) {
        if (data.at(index) == '-') {
            str += data.at(index);
        }
        else if (isalpha(data.at(index))) {
            str += data.at(index);
            
            if (str == "-a") {
                activateWaitingAndTurnAroundTimeForAllProcesses = true;
                str = "";
                break;
            }
            else {
                str = "";
            }
        }
        else {
            str = "";
        }
    }
    
    this->activateWaitingAndTurnAroundTimeForAllProcesses = activateWaitingAndTurnAroundTimeForAllProcesses;
}

bool ProcessScheduling :: isPriorityScheduling() {
    return (this->tempArray[3] == ProcessScheduling::NON_PRE_EMPTIVE_INDEX)
    || (this->tempArray[4] == ProcessScheduling::PRE_EMPTIVE_INDEX);
}

void ProcessScheduling :: start() {
    try {
        while(true) {
            this->acceptDataToBeProcessed();
            this->processAlgorithms();
        }
    }
    catch(runtime_error &error) {
        this->destroyLinkedLists();
        cout << error.what() <<endl;
    }
}

void ProcessScheduling :: acceptDataToBeProcessed() {
    string typeOfScheduling, fileName;
    int numberOfProcesses, arrivalTime, burstTime;
    bool dashFound = false;
    
    LinkedListDataNode newDataNode;
    ArrivalTimeLinkedListDataNode arrivalTimeDataNode;
    
    for(int index = 0; index < ProcessScheduling::NUMBER_OF_SUPPORTED_ALGORITHMS; index++) {
        this->tempArray[index] = 0;
    }
    
    cout << "|*****************************************************************|" << endl;
    cout << "|          PRIORITY BASED PROCESS SCHEDULING ALGORITHMS           |"<<endl;
    cout << "|*****************************************************************|" << endl;
    cout << "\n1 -> FCFS (First Come First Serve) Scheduling\n2 -> SJF (Shortest Job First) Scheduling";
    cout << "\n3 -> SRTF (Shortest Remaining Time First) Scheduling\n4 -> Non-Preemptive Priority Scheduling";
    cout << "\n5 -> Preemptive Priority Scheduling\n6 -> Round Robin Scheduling\n7 -> Exit"<<endl;
    fflush(stdin);
    getline(cin, typeOfScheduling);
    
    int digit[2] = {0, 0};
    
    dashFound = this->checkStringForDashOperator(typeOfScheduling, digit);
    
    this->checkCharacterForAllProcesses(typeOfScheduling);
    
    if(typeOfScheduling == "7") {
        this->destroyLinkedLists();
        exit(0);
    }
    else if(dashFound) {
        for(int index = digit[0]; index <= digit[1]; index++) {
            switch (index) {
                case ProcessScheduling::FCFS_INDEX:
                    this->tempArray[0] = ProcessScheduling::FCFS_INDEX;
                    this->fcfsList = new LinkedList();
                    break;
                case ProcessScheduling::SJF_INDEX:
                    this->tempArray[1] = ProcessScheduling::SJF_INDEX;
                    this->sjfList = new LinkedList();
                    break;
                case ProcessScheduling::SRTF_INDEX:
                    this->tempArray[2] = ProcessScheduling::SRTF_INDEX;
                    this->srtfList = new LinkedList();
                    this->srtfArrivalList = new ArrivalTimeLinkedList();
                    break;
                case ProcessScheduling::NON_PRE_EMPTIVE_INDEX:
                    this->tempArray[3] = ProcessScheduling::NON_PRE_EMPTIVE_INDEX;
                    this->nonPreEmptivePriorityList = new LinkedList();
                    break;
                case ProcessScheduling::PRE_EMPTIVE_INDEX:
                    this->tempArray[4] = ProcessScheduling::PRE_EMPTIVE_INDEX;
                    this->preEmptivePriorityList = new LinkedList();
                    this->preEmptiveArrivalList = new ArrivalTimeLinkedList();
                    break;
                case ProcessScheduling::ROUND_ROBIN_INDEX:
                    this->tempArray[5] = ProcessScheduling::ROUND_ROBIN_INDEX;
                    this->roundRobinList = new LinkedList();
                    this->roundRobinArrivalList = new ArrivalTimeLinkedList();
                    break;
            }
        }
    }
    else if(!dashFound) {
        this->parsingString(typeOfScheduling);
        
        for(int index = 0; index < 2; index++) {
            digit[index] = 0;
        }
        
        for(int index = 0; index < ProcessScheduling::NUMBER_OF_SUPPORTED_ALGORITHMS; index++) {
            switch (this->tempArray[index]) {
                case ProcessScheduling::FCFS_INDEX:
                    this->fcfsList = new LinkedList();
                    break;
                case ProcessScheduling::SJF_INDEX:
                    this->sjfList = new LinkedList();
                    break;
                case ProcessScheduling::SRTF_INDEX:
                    this->srtfList = new LinkedList();
                    this->srtfArrivalList = new ArrivalTimeLinkedList();
                    break;
                case ProcessScheduling::NON_PRE_EMPTIVE_INDEX:
                    this->nonPreEmptivePriorityList = new LinkedList();
                    break;
                case ProcessScheduling::PRE_EMPTIVE_INDEX:
                    this->preEmptivePriorityList = new LinkedList();
                    this->preEmptiveArrivalList = new ArrivalTimeLinkedList();
                    break;
                case ProcessScheduling::ROUND_ROBIN_INDEX:
                    this->roundRobinList = new LinkedList();
                    this->roundRobinArrivalList = new ArrivalTimeLinkedList();
                    break;
            }
        }
    }
    else if(this->isArrayEmpty()) {
        throw runtime_error("Invalid Option");
    }
    
    cout << "\nHow many processes would you like to enter?\n[-1 = Exit, -2 = Read From File]"<<endl;
    cin >> numberOfProcesses;
    
    if(!cin) {
        throw runtime_error("\nIncorrect DataType Entered for Number of Processes");
    }
    else if(numberOfProcesses == -2) {
        cout << "\nEnter filename: ";
        cin >> fileName;
        
        this->readFromFile(fileName);
    }
    else if((numberOfProcesses == -1) || (numberOfProcesses < 2)) {
        if(numberOfProcesses == -1) {
            this->destroyLinkedLists();
            exit(0);
        }
        else {
            throw runtime_error("\nNumber of Processes cannot be less than 2");
        }
    }
    else {
        for(int index = 0; index < numberOfProcesses; index++) {
            string processData;
            cout << "Enter details [Process ID, Arrival Time, Burst Time" << ((this->isPriorityScheduling() == true) ? ", Priority]": "]:\t") << " ";
            cin >> processData;
            
            string* commaSeparatedData = this->splitStringByComma(processData);
            
            string processId = commaSeparatedData[0];
            
            arrivalTime = atoi(commaSeparatedData[1].c_str());
            burstTime = atoi(commaSeparatedData[2].c_str());
            this->priority = atoi(commaSeparatedData[3].c_str());
            
            if(arrivalTime < 0) {
                throw runtime_error("\nArrival Time cannot be less than 0");
            }
            
            if(burstTime <= 0) {
                throw runtime_error("\nBurst Time cannot be less than 1");
            }
            
            if(this->isPriorityScheduling()) {
                this->validatePriority();
            }
            
            newDataNode.setProcessID(processId);
            newDataNode.setArrivalTime(arrivalTime);
            newDataNode.setBurstTime(burstTime);
            
            for(int index = 0; index < ProcessScheduling::NUMBER_OF_SUPPORTED_ALGORITHMS; index++) {
                switch (this->tempArray[index]) {
                    case ProcessScheduling::FCFS_INDEX:
                        this->fcfsList->organizeDataInLinkedList(newDataNode);
                        break;
                    case ProcessScheduling::SJF_INDEX:
                        this->sjfList->organizeDataInLinkedList(newDataNode);
                        break;
                    case ProcessScheduling::SRTF_INDEX:
                        this->srtfList->organizeDataInLinkedList(newDataNode);
                        
                        arrivalTimeDataNode.setProcessId(processId);
                        arrivalTimeDataNode.setArrivalTime(arrivalTime);
                        arrivalTimeDataNode.setBurstTime(burstTime);
                        
                        this->srtfArrivalList->organizeDataInLinkedList(arrivalTimeDataNode);
                        break;
                    case ProcessScheduling::NON_PRE_EMPTIVE_INDEX:
                        newDataNode.setPriority(this->priority);
                        this->nonPreEmptivePriorityList->organizeDataInLinkedList(newDataNode);
                        break;
                    case ProcessScheduling::PRE_EMPTIVE_INDEX:
                        newDataNode.setPriority(this->priority);
                        this->preEmptivePriorityList->organizeDataInLinkedList(newDataNode);
                        
                        arrivalTimeDataNode.setProcessId(processId);
                        arrivalTimeDataNode.setArrivalTime(arrivalTime);
                        arrivalTimeDataNode.setBurstTime(burstTime);
                        
                        this->preEmptiveArrivalList->organizeDataInLinkedList(arrivalTimeDataNode);
                        break;
                    case ProcessScheduling::ROUND_ROBIN_INDEX:
                        this->roundRobinList->organizeDataInLinkedList(newDataNode);
                        
                        arrivalTimeDataNode.setProcessId(processId);
                        arrivalTimeDataNode.setArrivalTime(arrivalTime);
                        arrivalTimeDataNode.setBurstTime(burstTime);
                        
                        this->roundRobinArrivalList->organizeDataInLinkedList(arrivalTimeDataNode);
                        break;
                }
            }
        }
    }
}

void ProcessScheduling :: processAlgorithms() {
    this->priority = 0;
    
    int timeQuantum = 0, priorityLevel[2] = {0, 0};;
    
    TempLinkedList *newTempLinkedList;
    WaitingAndTurnAroundTime *waitingAndTurnAroundTime;
    
    for(int index = 3; index < 5; index++) {
        if(this->tempArray[index] == index+1) {
            cout << "\nPriority Type for "<< (this->tempArray[index]==4?"Non-Preemptive":"Preemptive") << " Priority"<<endl;
            cout << "1 -> Lowest Number - Highest Priority\n2 -> Highest Number - Highest Priority"<<endl;
            cin >> this->priority;
            
            if(!cin) {
                throw runtime_error("\nIncorrect DataType for Priority Level");
            }
            else if((this->priority < 1) ||(this->priority > 2)) {
                throw runtime_error("\nPriority cannot be less than 1 or greater than 2");
            }
            
            priorityLevel[index-3] = this->priority;
        }
    }
    
    if(this->tempArray[5] == ProcessScheduling::ROUND_ROBIN_INDEX) {
        cout << "\nEnter Time Quantum:\t";
        cin >> timeQuantum;
        
        if(!cin) {
            throw runtime_error("\nIncorrect DataType for Quantum Time");
        }
        else if(timeQuantum <= 1) {
            throw runtime_error("\nTime Quantum cannot be less than or equal to 1");
        }
    }
    
    newTempLinkedList = new TempLinkedList();
    waitingAndTurnAroundTime = new WaitingAndTurnAroundTime();
    
    for(int index = 0; index < ProcessScheduling::NUMBER_OF_SUPPORTED_ALGORITHMS; index++) {
        switch (this->tempArray[index]) {
            case ProcessScheduling::FCFS_INDEX:
                cout << "\nFCFS (First Come First Serve) Scheduling"<<endl;
                this->fcfsList->display();
                this->fcfsList->FCFS(newTempLinkedList, waitingAndTurnAroundTime, 0, 0);
                this->fcfsList->destroy("FCFS");
                newTempLinkedList->display("FCFS");
                newTempLinkedList->destroy("FCFS");
                waitingAndTurnAroundTime->display(this->activateWaitingAndTurnAroundTimeForAllProcesses, "FCFS");
                break;
            case ProcessScheduling::SJF_INDEX:
                cout << "\nSJF (Shortest Job First) Scheduling"<<endl;
                this->sjfList->display();
                this->sjfList->SJF(newTempLinkedList, waitingAndTurnAroundTime, 0, 0);
                this->sjfList->destroy("SJF");
                newTempLinkedList->display("SJF");
                newTempLinkedList->destroy("SJF");
                waitingAndTurnAroundTime->display(this->activateWaitingAndTurnAroundTimeForAllProcesses, "SJF");
                break;
            case ProcessScheduling::SRTF_INDEX:
                cout << "\nSRTF (Shortest Remaining Time First) Scheduling"<<endl;
                this->srtfList->display();
                this->srtfList->SRTF(newTempLinkedList, 0, 0, 0);
                this->srtfList->destroy("SRTF");
                newTempLinkedList->display("SRTF");
                newTempLinkedList->calculateWaitingAndTurnAroundTime(this->srtfArrivalList, "SRTF", this->activateWaitingAndTurnAroundTimeForAllProcesses);
                break;
            case ProcessScheduling::NON_PRE_EMPTIVE_INDEX:
                cout << "\nNon-Preemptive Priority Scheduling"<<endl;
                this->nonPreEmptivePriorityList->display(4);
                this->nonPreEmptivePriorityList->nonPreEmptivePriority(priorityLevel[0], newTempLinkedList, waitingAndTurnAroundTime, this->nonPreEmptivePriorityList->getHead().getArrivalTime());
                this->nonPreEmptivePriorityList->destroy("Non-PreEmptive Priority");
                newTempLinkedList->display("Non-PreEmptive Priority");
                newTempLinkedList->destroy("Non-PreEmptive Priority");
                waitingAndTurnAroundTime->display(this->activateWaitingAndTurnAroundTimeForAllProcesses, "Non-PreEmptive Priority");
                break;
            case ProcessScheduling::PRE_EMPTIVE_INDEX:
                cout << "\nPreemptive Priority Scheduling"<<endl;
                this->preEmptivePriorityList->display(4);
                this-> preEmptivePriorityList->preEmptivePriority(priorityLevel[1], newTempLinkedList, this->preEmptivePriorityList->getHead().getArrivalTime(), preEmptivePriorityList->getHead().getArrivalTime());
                this->preEmptivePriorityList->destroy("PreEmptive Priority");
                newTempLinkedList->display("PreEmptive Priority");
                newTempLinkedList->calculateWaitingAndTurnAroundTime(this->preEmptiveArrivalList, "PreEmptive Priority", this->activateWaitingAndTurnAroundTimeForAllProcesses);
                break;
            case ProcessScheduling::ROUND_ROBIN_INDEX:
                Queue *queue = new Queue();
                cout << "\nRound Robin Scheduling (Time Quantum: "<< timeQuantum<< ")"<<endl;
                this->roundRobinList->display();
                this->roundRobinList->roundRobin(queue, newTempLinkedList, timeQuantum, 0, 0, 0, this->roundRobinList->getHead().getProcessId());
                this->roundRobinList->destroy("Round Robin");
                newTempLinkedList->display("Round Robin");
                newTempLinkedList->calculateWaitingAndTurnAroundTime(this->roundRobinArrivalList, "Round Robin", this->activateWaitingAndTurnAroundTimeForAllProcesses);
                queue->destroy();
                break;
        }
    }
    
    cout << "\nTwo Process ids 'might' arrive at the same time and is adjacent in opposite\nplaces ([P6,P4] == [P4,P6]). Depending on your inserting at middle"<<endl;
    
    cin.sync();
    cin.get();
}
