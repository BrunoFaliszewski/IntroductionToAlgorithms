#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> squareMatrixMultiplication(vector<vector<int>>& A, vector<vector<int>>& B) {
    const int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int c = 0;
            for (int k=0; k<n; k++) {
                c += A[i][k]*B[k][j];
            }
            C[i][j] = c;
        }
    }
    return C;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> B = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    vector<vector<int>> C = squareMatrixMultiplication(A, B);

    for (int i = 0; i<C.size(); i++) {
        for (int j = 0; j<C[0].size(); j++) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }

}