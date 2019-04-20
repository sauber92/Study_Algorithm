#include <iostream>
using namespace std;

const int MAX = 500;
int arr[MAX][MAX];

const int block[19][3][2] = {
    { { 0, 1}, { 0, 2}, { 0, 3} },
    { { 1, 0}, { 2, 0}, { 3, 0} },
    { { 1, 0}, { 1, 1}, { 1, 2} },
    { { 0, 1}, { 1, 0}, { 2, 0} },
    { { 0, 1}, { 0, 2}, { 1, 2} },
    { { 1, 0}, { 2, 0}, { 2,-1} },
    { { 0, 1}, { 0, 2}, {-1, 2} },
    { { 1, 0}, { 2, 0}, { 2, 1} },
    { { 0, 1}, { 0, 2}, { 1, 0} },
    { { 0, 1}, { 1, 1}, { 2, 1} },
    { { 0, 1}, { 1, 0}, { 1, 1} },
    { { 0, 1}, {-1, 1}, {-1, 2} },
    { { 1, 0}, { 1, 1}, { 2, 1} },
    { { 0, 1}, { 1, 1}, { 1, 2} },
    { { 1, 0}, { 1,-1}, { 2,-1} },
    { { 0, 1}, { 0, 2}, {-1, 1} },
    { { 0, 1}, { 0, 2}, { 1, 1} },
    { { 1, 0}, { 2, 0}, { 1, 1} },
    { { 1, 0}, { 2, 0}, { 1,-1} }
};

int main() {
    int N, M;
    int sum = 0;

    cin >> N >> M;
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            cin >> arr[n][m];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 19; k++) {
                bool ok = true;
                int tmp = arr[i][j];
                for (int l = 0; l < 3; l++) {
                    int x = i + block[k][l][0];
                    int y = j + block[k][l][1];
                    if (x >= 0 && x < N && y >= 0 && y < M) {
                        tmp += arr[x][y];
                    }
                    else {
                        ok = false;
                        break;
                    }
                }
                if (ok && sum < tmp) {
                    sum = tmp;
                }
            }
        }
    }
    cout << sum << "\n";

    return 0;
}
