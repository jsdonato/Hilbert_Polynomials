#include <iostream>
#include <vector>

using namespace std;

optional<string> check_good_lambda (vector<unsigned long long> lambda_partition, int N) {
    // Check the first criterion
    if (N >= 0 && N <= 2) return "1";
    // Check the criterion 3a
    else if (lambda_partition.size() <= 1) return "3a";
    
    // Check criterion 7a
    else if (lambda_partition.size() == 0) return "7a";

    //Check criterion 7b
    else if (lambda_partition.size() == N + 1) return "7b";

    // r is the number of lambdas
    size_t r = lambda_partition.size();
    
    // Here, the compact form means writing the lambda partion in another more compact
    // format, e.g. [9, 9, 9, 6, 6, 2, 1] => [(9, 3), (6, 6), (2, 1), (1, 1)]
    // Note that: The first element in each pair denotes the value of lambda_i, while
    //            the second element denotes the number of that lambda_i.
    vector<pair<size_t, size_t>> compact_form;
    compact_form.push_back(make_pair(lambda_partition[0], 1));
    
    for (size_t i = 1; i < lambda_partition.size(); i++) {
        if (lambda_partition[i] == lambda_partition[i - 1]) {
            compact_form[compact_form.size() - 1].second++;
        } // if
        else {
            compact_form.push_back(make_pair(lambda_partition[i], 1));
        } // else
    } // for
    
    
    size_t index_of_smallest_lambda = compact_form.size() - 1;
    // Check criterion 2
    if (compact_form[compact_form.size() - 1].first >= 2) return "2";
    // Check criterion 3b
    else if (compact_form[0].first == N
             && compact_form[0].second == r - 2
             && compact_form[index_of_smallest_lambda].first == 1
             && compact_form[index_of_smallest_lambda].second == 1) return "3b";
    else {
        // Check criterion 4
        if (r >= 3) {
            if (compact_form.size() == 2 && compact_form[0].first < N
                && compact_form[0].first > 2 && compact_form[1].first == 1
                && compact_form[1].second == 1) return true;
            else if (compact_form.size() == 3 && compact_form[0].first == N
                     && compact_form[0].second <= r - 3 && compact_form[1].first > 2
                     && compact_form[2].first == 1 && compact_form[2].second == 1)
                return "4";
            // Check criterion 6
            else if (compact_form.size() == 2 && compact_form[0].first == N
                     && compact_form[1].first == 1 && compact_form[1].second == 3)
                return "6";
        }
        // Check criterion 5
        if (r >= 5) {
            if (compact_form.size() == 2 && compact_form[0].first == 2
                && compact_form[1].first == 1 && compact_form[1].second == 1) return true;
            else if (compact_form.size() == 3 && compact_form[0].first == N
                     && compact_form[0].second <= r - 5 && compact_form[1].first == 2
                     && compact_form[2].first == 1 && compact_form[2].second == 1)
                return "5";
        }
    }
    
    return nullopt;
};




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
