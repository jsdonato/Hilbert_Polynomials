#ifndef input_hpp
#define input_hpp

#include <getopt.h>
#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include <optional>
#include <algorithm>
using namespace std;

class Input {
public:
    Input(int argc, char **argv);	


private:
    string input_file_name;
    vector<Term> polynomial;
    vector<uint32_t> partition;
    optional<string> POLY = nullopt;
    optional<string> PARTITION = nullopt;
    optional<size_t> N = nullopt;
    optional<size_t> UPPER_BOUND = nullopt;
    bool input_polynomial_partition = false;
    bool input_partition_count = false;
    bool input_partition_smooth = false;
    
    void get_options(int argc, char **argv); 
    void p_helper();
    void cs_read();
    void c_helper();
    void s_helper();

};	




#endif
