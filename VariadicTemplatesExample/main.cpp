//
//  main.cpp
//  VariadicTemplatesExample
//
//  Created by Diana UMA on 11/2/22.
//

// printSize.cpp

#include <iostream>

template<typename ... Args> // Variadic template
class Process : public Args... // Class inherits from all template parameters. 
{
public:
    
    void run()
    {
        (Args::process(), ...); // Fold expression, requires C++17.
    }
};

struct Stage1 {
    void process() {
        std::cout << "STAGE 1" << std::endl;
    }
};
struct Stage2 {
    void process() {
        std::cout << "STAGE 2" << std::endl;
    }
};
struct Stage3 {
    
    std::string parameter;
    
    void Filter3_Setup(const std::string& _parameter)
    {
        parameter = _parameter;
    }
    
    void process() {
        std::cout << "STAGE 3 (" << parameter << ")" << std::endl;
    }
};

Process<Stage1,Stage2> process1;
Process<Stage1,Stage2,Stage3> process2;

int main() {

    std::cout << "** PROCESS 1: " << std::endl;
    process1.run();
    
    std::cout << '\n';
    std::cout << "** PROCESS 2: " << std::endl;
    process2.Filter3_Setup("this works!");
    process2.run();

}
 
