#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    void shortest_distance(vector<vector<int>>& mat){
        int n = mat.size();
        
        // Initialize unreachable distances with infinity
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == -1){
                    mat[i][j] = numeric_limits<int>::max();
                }
            }
        }
        
        // Apply Floyd Warshall algorithm
        for(int vi = 0; vi < n; vi++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    mat[i][j] = min(mat[i][j], mat[i][vi] + mat[vi][j]);
                }
            }
        }
        
        // Replace infinity with -1 for unreachable distances
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == numeric_limits<int>::max()){
                    mat[i][j] = -1;
                }
            }
        }
    }
};

int main() {
    vector<vector<int>> mat = {
        {0, 5, -1, 10},
        {-1, 0, 3, -1},
        {-1, -1, 0, 1},
        {-1, -1, -1, 0}
    };

    Solution obj;
    obj.shortest_distance(mat);

    cout << "Shortest distances between every pair of vertices:\n";
    for (const auto& row : mat) {
        for (int distance : row) {
            cout << distance << " ";
        }
        cout << endl;
    }

    return 0;
}
