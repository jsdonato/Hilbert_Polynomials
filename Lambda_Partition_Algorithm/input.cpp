#include "input.hpp"
using namespace std;

Input::Input(int argc, char **argv) {
    get_options(argc, argv);
    read();
    if (input_polynomial_partition) {
        p_helper();
    }
    else if (input_partition_count) {
        cs_read();
        c_helper();
    }
    else if (input_partition_smooth) {
        cs_read();
        s_helper();
    }

}

void Input::get_options(int argc, char **argv) {
    int option_index = 0, option = 0;
    struct option longOpts[] = {{"polynomial", required_argument, nullptr, 'p'},
                                {"count", required_argument, nullptr, 'c'},
                                {"smooth", required_argument, nullptr, 's'},
                                { nullptr, 0, nullptr, '\0'}};
    while ((option = getopt_long(argc, argv, "p:c:s:", longOpts, &option_index)) != -1){
        switch (option){ 
            case 'p': {
                input_polynomial_partition = true;   
                std::string str_p(optarg);
                input_file_name = str_p; 
		break;
            }
	    case 'c': {
		input_partition_count = true;    
       	        std::string str_c(optarg);
                input_file_name = str_c;
		break;
	    }
            case 's': {
		input_partition_smooth = true;
	        std::string str_s(optarg);
                input_file_name = str_s;
		break;
	    }
	    default:
                exit(1);
        }
	if (int(input_polynomial_partition) + int(input_partition_count) + int(input_partition_smooth) > 1) {
	    cout << "ERROR: strictly one of the options -p , -c , -s is allowed\n";
	    exit(0);
	}
	else if (int(input_polynomial_partition) + int(input_partition_count) + int(input_partition_smooth) == 0) {
            cout << "ERROR: must choose strictly one of the following options: -p , -c , -s\n";
	    exit(0);
	}
    } 
}

optional<string> validList(const string& str, const char& delim) {
    string temp_str;
    for (const auto& c : str) {
        if (c == delim || c == ',') temp_str += string(1, c);
    }
    
    if (temp_str[0] != delim || temp_str[temp_str.size() - 1] != delim) return nullopt;
    
    string check = string(1, delim) + string(",");
    int check_index = 0;
    for (size_t i = 0; i < temp_str.size(); i++) {
         if (temp_str[i] != check[check_index]) return nullopt;
	 check_index = (check_index + 1) % 2;
    }
    return str;
}

void Input::read() {
    ifstream in;
    in.open(input_file_name);
 
    string entry;
    size_t i = 0;
    while (getline(in, entry)) {
        if (entry[0] != '#' && entry[0] != '\0') {
	    entry.erase(remove_if(entry.begin(), entry.end(), ::isspace), entry.end());
            size_t colon_pos = entry.find(':');
            string var = entry.substr(0, entry.find(':')+1);

	    if (count(entry.begin(), entry.end(), ':') != 1 || (var != "POLYNOMIAL:" && var != "N:" && var != "UPPER_BOUND:" && var != "PARTITION:")) {
	        cout << "ERROR: syntax error on line " << i << " of " << input_file_name << "\n";
                exit(0);
	    }
	    else if (var == "POLYNOMIAL:") POLYNOMIAL = validList(entry.substr(colon_pos+1), 'd'); 
	    else if (var == "N:") N = stoi(entry.substr(colon_pos+1));
	    else if (var == "UPPER_BOUND:") UPPER_BOUND = stoi(entry.substr(colon_pos+1));
            else if (var == "PARTITION:") PARTITION = validList(entry.substr(colon_pos+1), '^');
	}
        i++;
    }
    
}


void Input::p_helper() {
    if (!POLYNOMIAL) {
        cout << "ERROR: \"POLYNOMIAL\" variable was not entered correctly\n";
	exit(0);
    }
    else if (!N) {
        cout << "ERROR: \"N\" variable was not entered correctly\n";
	exit(0);
    }
    else if (!UPPER_BOUND) {
        cout << "ERROR: \"UPPER_BOUND\" variable was not entered correctly\n";
	exit(0);
    }
    
    std::regex re("[ d,]");
    std::sregex_token_iterator first{POLYNOMIAL.value().begin(), POLYNOMIAL.value().end(), re, -1}, last;
    std::vector<std::string> tokens{first, last};
    tokens.erase(std::remove(tokens.begin(), tokens.end(), "\0"), tokens.end());

    for (size_t i = 0; i < tokens.size(); i+=2) {
        polynomial.emplace_back(stod(tokens[i]), stoi(tokens[i + 1]));
    }
    cout << "UPPER_BOUND ENTERED BY USER: " << UPPER_BOUND.value() << "\n";
    cout << "N ENTERED BY USER: " << N.value() << "\n";
    Polynomial p(polynomial);
    cout << "POLYNOMIAL ENTERED BY USER: " << p << "\n";
    lambda_algo Algo(p, UPPER_BOUND.value());
    vector<uint64_t> result = Algo.Result();
    if (result.empty()) {
        cout << "FAILURE: Unable to find corresponding lambda partition.\n";
        cout << "         Corresponding lambda partition doesn't exist\n";
        cout << "         or you cant try entering a larger upper bound.\n";
	return;
    }
    
    if (N < result[0]) {
        cout << "WARNING: N is less than the largest element in resulting lambda partition.\n";
	cout << "         Count and smoothness detection will not be computed.\n";
	return;
    }
    else if (N <= 0) {
        cout << "WARNING: N is not a strictly positive integer.\n";
	cout << "         Count and smoothness detection will not be computed.\n";
	return;
    }
    else {
        if (N <= 2 && result[0] <= 2) {
	    sat_ideals(count(result.begin(), result.end(), 2), count(result.begin(), result.end(), 1), N.value());  
	}
	else {
	    cout << "N is strictly greater than 2 or the largest element in the resulting lambda partition\n";
	    cout << "is greater than 2.  Count will not be computed.\n";
	}
    }

    auto condition = check_good_lambda(result, N.value());
    if (!condition) cout << "The resulting lambda partition is not smooth.\n";
    else cout << "The resulting lambda partition is smooth and satisfies condition " << condition.value() << ".\n";
    
    

}

void Input::cs_read() {
    if (!PARTITION) {
        cout << "ERROR: \"PARTITION\" variable was not entered correctly\n";
	exit(0);
    }
    else if (!N) {
        cout << "ERROR: \"N\" variable was not entered correctly\n";
	exit(0);
    }

    
    std::regex re("[ ^,]");
    std::sregex_token_iterator first{PARTITION.value().begin(), PARTITION.value().end(), re, -1}, last;
    std::vector<std::string> tokens{first, last};
    tokens.erase(std::remove(tokens.begin(), tokens.end(), "\0"), tokens.end());
    
    for (size_t i = 0; i < tokens.size(); i += 2) {
        for (size_t j = 0; j < stoi(tokens[i + 1]); j++) {
    	partition.push_back(stoi(tokens[i]));
        }
    }
    cout << "N ENTERED BY USER: " << N.value() << "\n";
    sort(partition.begin(), partition.end(), greater<int>());
    cout << "PARTITION ENTERED BY USER: {";
    for (int i = 0; i < partition.size() - 1; i++) { cout << partition[i] << ", "; }
    cout << partition[partition.size() - 1] <<"}.\n";
}

void Input::c_helper() {
    if (N < partition[0]) {
        cout << "WARNING: N is less than the largest element in lambda partition.\n";
	cout << "         Count and smoothness detection will not be computed.\n";
	return;
    }
    else if (N <= 0) {
        cout << "WARNING: N is not a strictly positive integer.";
	cout << "         Count and smoothness detection will not be computed.\n";
	return;
    }
    else {
        if (N <= 2 && partition[0] <= 2) {
	    sat_ideals(count(partition.begin(), partition.end(), 2), count(partition.begin(), partition.end(), 1), N.value());
	}
	else {
	    cout << "N is strictly greater than 2 or the largest element in the lambda partition\n";
	    cout << "is greater than 2.  Count will not be computed.\n";
	}
    }
    auto condition = check_good_lambda(partition, N.value());
    if (!condition) cout << "The lambda partition is not smooth.\n";
    else cout << "The lambda partition is smooth and satisfies condition " << condition.value() << ".\n";
}

void Input::s_helper() {
    if (N < partition[0]) {
        cout << "WARNING: N is less than the largest element in lambda partition.\n";
	cout << "         smoothness detection will not be computed.\n";
	return;
    }
    else if (N <= 0) {
        cout << "WARNING: N is not a strictly positive integer.";
	cout << "         smoothness detection will not be computed.\n";
	return;
    }
    auto condition = check_good_lambda(partition, N.value());
    if (!condition) cout << "The lambda partition is not smooth.\n";
    else cout << "The lambda partition is smooth and satisfies condition " << condition.value() << ".\n";   
}
