#include <algorithm>
#include <iostream>
#include <vector>

void rotate(std::vector<std::vector<int>> &matrix);
void print_matrix(const std::vector<std::vector<int>> &matrix);

int main() {

    std::vector<std::vector<int>> matrix{{1, 2}, {3, 4}};

    std::cout << "Input Matrix:" << std::endl;
    print_matrix(matrix);
    rotate(matrix);
    std::cout << "Rotated Matrix:" << std::endl;
    print_matrix(matrix);

    return 0;
}

// Transpose & reverse approach
void rotate(std::vector<std::vector<int>> &matrix) {
    const int n(matrix.size());
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i; ++j) {
            std::swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
        }
    }
    std::reverse(matrix.begin(), matrix.end());
}

void print_matrix(const std::vector<std::vector<int>> &matrix) {
    for (auto i : matrix) {
        for (auto j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}