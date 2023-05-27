#pragma once //header file is only included once in a translation unit
#include <string>
using std::string; // namespace std avoided :-)

class ALU{
public:
    ALU(const int& a);//initilize numPerCores
    const int add(const int& a, const int& b) const;// take two and sum
    const int subtract(const int& a, const int& b) const;// take two and subtract
    const int multiply(const int& a, const int& b) const;// take two and multpily

    //const int& getNumPerCores() const; //it is not necessary to use this because it doesn not affect results
    //cannot use set beacuse attribute is const
    //  ~ALU() = default;  //not necceasy for this example to define another destructor

private:
    const int numPerCores{}; //can be initilized to 0
};



class CPU{
public:
    CPU(const int& a); //takes parameter to inilize alu

    const int execute(const string& op)const; //take 2 inputs and send to ALU's regarding method

    // ~CPU() = default;  //not neccesary for this example to define another destructor
private:
    const ALU alu;//alu doesn't contain default constructor, so cannot be initilized in here
};





class CUDA{
public:
    CUDA(const int& a); //initilize numCores
    const string render() const; //just returns a string
    const string trainModel() const; //just returns a string
    // ~CUDA() = default;  //not necceasy for this example to define another destructor
    //cannot use set beacuse attribute is const

    //const int& getNumCores() const; //it is not necessary to use this because it doesn not affect results
private:
    const int numCores{};//can be initilized to 0

};




class GPU{
public:
    GPU(const int& a); //takes parameter to inilize cuda
    const string execute(const string& op)const; //select the operation
    // ~GPU() = default;  //not necceasy for this example to define another destructor

private:
    const CUDA cuda;//cuda doesn't contain default constructor, so cannot be initilized in here
};







class Computer{
public:
    Computer();
    void operator+(const CPU &);//Computer+CPU
    void operator+(const GPU &);//Computer+GPU
    void execute(const string &) const; //execute given operation, catogorize regarding to the table
    // ~Computer() = default;  //not necceasy for this example to define another destructor

private:
    const CPU* attachedCPU{nullptr};//initial non assgined value is nullptr
    const GPU* attachedGPU{nullptr};//initial non assgined value is nullptr

};