// An example of an algorithm that takes 2^n time complexity is the exhaustive search algorithm, also known as brute force search. The exhaustive search algorithm works by systematically enumerating all possible solutions to a problem and checking each solution to see if it satisfies the problem's requirements.

// In general, the time complexity of the exhaustive search algorithm is O(2^n), where n is the size of the input. This is because for each element in the input, the algorithm must consider two possibilities: either the element is included in the solution or it is not. Therefore, the total number of possible solutions is 2^n, and the algorithm must check each one to find the optimal solution.

// While the exhaustive search algorithm is guaranteed to find the optimal solution (if one exists), it is often impractical for large input sizes due to its exponential time complexity. In such cases, heuristic algorithms that trade off optimality for efficiency, such as greedy algorithms or dynamic programming algorithms, may be more appropriate.




// Here's an example implementation of the exhaustive search algorithm in C++ that generates all possible subsets of a given set and prints them:



#include <iostream>
#include <vector>

using namespace std;

// generate all possible subsets of the set s
void exhaustive_search(vector<int>& s, int n) {
    for (int i = 0; i < (1 << n); i++) {
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset.push_back(s[j]);
            }
        }
        // print the subset
        cout << "{";
        for (int j = 0; j < subset.size(); j++) {
            cout << subset[j];
            if (j < subset.size() - 1) {
                cout << ", ";
            }
        }
        cout << "}" << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    exhaustive_search(s, n);

    return 0;
}

// In this implementation, the exhaustive_search function generates all possible subsets of the input set s using bit manipulation. The outer loop iterates over all possible binary numbers with n bits (i.e., 2^n), and the inner loop checks whether each bit is set to 1 or 0. If the bit is set to 1, then the corresponding element of s is included in the subset. The main function reads in the input set and calls the exhaustive_search function to generate and print all possible subsets.