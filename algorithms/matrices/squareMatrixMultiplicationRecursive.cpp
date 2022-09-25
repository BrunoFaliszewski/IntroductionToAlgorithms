#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> addSquareMatrix(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            C[i][j] = A[i][j]+B[i][j];
        }
    }
    return C;
}

vector<vector<int>> mergeSquareMatrix(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C, vector<vector<int>>& D) {
    int n = A.size()*2;
    int q = n/2;
    vector<vector<int>> E(n, vector<int>(n, 0));
    for (int i=0; i<q; i++) {
        for (int j=0; j<q; j++) {
            E[i][j] = A[i][j];
            E[i][q+j] = B[i][j];
            E[q+i][j] = C[i][j];
            E[q+i][q+j] = D[i][j];
        }
    }
    return E;
}

auto demergeSquareMatrix(vector<vector<int>>& E) {
    struct returnVals {
        vector<vector<int>> A, B, C, D;
    };
    int n = E.size()/2;
    vector<vector<int>> A(n, vector<int>(n, 0));
    vector<vector<int>> B(n, vector<int>(n, 0));
    vector<vector<int>> C(n, vector<int>(n, 0));
    vector<vector<int>> D(n, vector<int>(n, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            A[i][j] = E[i][j];
            B[i][j] = E[i][n+j];
            C[i][j] = E[n+i][j];
            D[i][j] = E[n+i][n+j];
        }
    }
    return returnVals{A, B, C, D};
}

vector<vector<int>> squareMatrixMultiplicationRecursive(vector<vector<int>>& A, vector<vector<int>>& B) {
    const int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    if (n==1) {
        C[0][0] = A[0][0]*B[0][0];
    } else {
        auto [A11, A12, A21, A22] = demergeSquareMatrix(A);
        auto [B11, B12, B21, B22] = demergeSquareMatrix(B);
        vector<vector<int>> C1 = addSquareMatrix(squareMatrixMultiplicationRecursive(A11, B11), squareMatrixMultiplicationRecursive(A12, B21));
        vector<vector<int>> C2 = addSquareMatrix(squareMatrixMultiplicationRecursive(A11, B12), squareMatrixMultiplicationRecursive(A12, B22));
        vector<vector<int>> C3 = addSquareMatrix(squareMatrixMultiplicationRecursive(A21, B11), squareMatrixMultiplicationRecursive(A22, B21));
        vector<vector<int>> C4 = addSquareMatrix(squareMatrixMultiplicationRecursive(A21, B12), squareMatrixMultiplicationRecursive(A22, B22));
        C = mergeSquareMatrix(C1, C2, C3, C4);
    }
    return C;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    vector<vector<int>> A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> B = {{16, 15, 14, 13}, {12, 11, 10, 9}, {8, 7, 6, 5}, {4, 3, 2, 1}};

    vector<vector<int>> C = squareMatrixMultiplicationRecursive(A, B);

    for (int i = 0; i<C.size(); i++) {
        for (int j = 0; j<C[0].size(); j++) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }

}