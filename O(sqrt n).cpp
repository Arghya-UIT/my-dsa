// One example of an algorithm that takes square root of n time complexity is the square root decomposition algorithm. This algorithm is commonly used in problems that require performing range queries on an array or a data structure. The idea behind this algorithm is to divide the input array into blocks of size sqrt(n) and precompute some information for each block. Then, when a query is made, we can quickly compute the answer by processing only the relevant blocks. The time complexity of this algorithm is O(sqrt(n)) for both preprocessing and query processing.




// Here's an example implementation of the square root decomposition algorithm in C++ that can be used to find the sum of elements in a given range of an array:



#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> blocks; // stores the precomputed information for each block
vector<int> arr;    // stores the original array

// preprocess the array and compute information for each block
void preprocess(int n) {
    int block_size = sqrt(n);
    int num_blocks = (n + block_size - 1) / block_size;
    blocks.resize(num_blocks);

    for (int i = 0; i < n; i++) {
        blocks[i / block_size] += arr[i];
    }
}

// query the sum of elements in the range [l, r]
int query(int l, int r) {
    int block_size = sqrt(arr.size());
    int sum = 0;

    // process the blocks fully contained in the range
    for (int i = l / block_size + 1; i < r / block_size; i++) {
        sum += blocks[i];
    }

    // process the elements in the partial blocks
    for (int i = l; i < min((l / block_size + 1) * block_size, (int)arr.size()); i++) {
        sum += arr[i];
    }

    for (int i = r; i >= max((r / block_size) * block_size, 0); i--) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    int n, q;
    cin >> n >> q;

    arr.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    preprocess(n);

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }

    return 0;
}


// In this implementation, the preprocess function computes the sum of elements for each block, and the query function processes the blocks fully contained in the range and the elements in the partial blocks to compute the sum of elements in the range [l, r]. The main function reads in the input array and queries, and outputs the result of each query.