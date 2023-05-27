#include "Computer.h"
#include <iostream>//cout cin endl
using std::cin;
using std::cout;
using std::endl;


//ALU*******************************
const int ALU::add(const int& a, const int& b) const{// take two and sum

    return a + b;
}
const int ALU::subtract(const int& a, const int& b) const{// take two and subtract
    return a - b;
};
const int ALU::multiply(const int& a, const int& b) const{// take two and multpily
    return a * b;
};

ALU::ALU(const int& a) : numPerCores{a} { //initilize numPerCores with member initilizer
    cout << "ALU is ready" << endl;
};

////it is not necessary to use this because it does not affect results
// const int& ALU::getNumPerCores() const{
//     return numPerCores;
// }





//CUDA*****************************
CUDA::CUDA(const int& a) : numCores{a} {//initilize numCores with member initilizer
    cout << "CUDA is ready" << endl;
};

const string CUDA::render() const{//just returns a string

    return "Video is rendered";

}


const string CUDA::trainModel() const{//just returns a string

    return "AI Model is trained";

}

////it is not necessary to use this because it does not affect results
// const int& CUDA::getNumCores() const{
//     return numCores;
// }




//CPU****************************
CPU::CPU(const int& a) : alu{a} {//takes parameter to inilize alu with member initilizer

    cout << "CPU is ready" << endl;
};

const int CPU::execute(const string &op) const {//take 2 inputs and send to ALU's regarding method
    int a, b;
    cout<<"Enter two integers"<<endl;
    cin >> a >> b; //2 inputs

    //send to ALU's regarding method:
    if (op == "add")
        return alu.add(a, b);
    else if (op == "subtract")
        return alu.subtract(a, b);

    else if (op == "multiply")
        return alu.multiply(a, b);
    return -1;
};





//GPU*************************
GPU::GPU(const int& a) : cuda{a} {//takes parameter to inilize cuda with member initilizer

    cout << "GPU is ready" << endl;
};

const string GPU::execute(const string& op)const {//select the operation

    if(op=="render")
            return cuda.render();
    else if (op == "trainModel")
            return cuda.trainModel();
    return "";
};






//Computer**************************
Computer::Computer(){
    cout << "Computer is ready" << endl;
}


void Computer::operator+(const CPU& a) {//Computer+CPU
    if (attachedCPU==nullptr) {
        attachedCPU=&a;
        cout << "CPU is attached" << endl;
    }
    else
        cout << "There is already a CPU" << endl;
}
void Computer::operator+(const GPU& a) {//Computer+GPU
    if (attachedGPU==nullptr) {
        attachedGPU=&a;
        cout << "GPU is attached" << endl;
    }
    else
        cout << "There is already a GPU" << endl;
}
void Computer::execute(const string &a) const{//execute given operation, catogorize regarding to the table
    
    if (a=="subtract" || a=="add" || a=="multiply")
        cout << attachedCPU->execute(a)<<endl;
    else if(a=="render" || a=="trainModel")
        cout << attachedGPU->execute(a)<<endl;
};



