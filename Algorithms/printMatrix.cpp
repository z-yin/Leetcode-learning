#include <vector>

class Solution {
public:
    std::vector<int> printMatrix(std::vector<std::vector<int> > matrix) {
        std::vector<int> res;
        if (matrix.size() == 0) return res;
        if (matrix.size() == 1) return matrix[0];
        
        int N1 = matrix.size(), N2 = matrix[0].size();
        
        // left, right, top, bottom
        int boundary[4] = {-1, N2, -1, N1};
        while (boundary[0] != boundary[1] - 1 && boundary[2] != boundary[3] - 1) {
            for (int k = boundary[0] + 1; k < boundary[1]; ++k) 
                res.emplace_back(matrix[boundary[2] + 1][k]);
            ++boundary[2];
            if (boundary[2] == boundary[3] - 1) break;

            for (int k = boundary[2] + 1; k < boundary[3]; ++k)
                res.emplace_back(matrix[k][boundary[1] - 1]);
            --boundary[1];
            if (boundary[0] == boundary[1] - 1) break;

            for (int k = boundary[1] - 1; k > boundary[0]; --k)
                res.emplace_back(matrix[boundary[3] - 1][k]);
            --boundary[3];
            if (boundary[2] == boundary[3] - 1) break;

            for (int k = boundary[3] - 1; k > boundary[2]; --k)
                res.emplace_back(matrix[k][boundary[0] + 1]);
            ++boundary[0];
            if (boundary[0] == boundary[1] - 1) break;
        }
        return res;
    }
};