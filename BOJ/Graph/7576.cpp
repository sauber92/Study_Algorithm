#include <iostream>
#include <queue>
using namespace std;

int m, n;
int map[1000][1000];
int tomato[1000][1000];
queue<pair<int, int> > q;

const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, 1, -1 };

int main() {
    scanf("%d %d", &m, &n);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            scanf("%d", &map[y][x]);
            tomato[y][x] = -1;
            if (map[y][x] == 1) {
                q.push(make_pair(y, x));
                tomato[y][x] = 0;
            }
        }
    }

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                continue;
            }
            else {
                if (map[ny][nx] == 0 && tomato[ny][nx] == -1) {
                    q.push(make_pair(ny, nx));
                    tomato[ny][nx] = tomato[y][x] + 1;
                }
            }
        }
    }

    int result = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (result < tomato[y][x]) {
                result = tomato[y][x];
            }
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (map[y][x] == 0 && tomato[y][x] == -1) {
                result = -1;
            }
        }
    }
    printf("%d\n", result);

    return 0;
}
