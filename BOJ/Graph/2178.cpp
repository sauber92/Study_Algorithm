#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[100][100];
int dist[100][100];
queue<pair<int, int> > q;

const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, 1, -1 };

int main() {
    scanf("%d %d", &n, &m);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            scanf("%1d", &map[y][x]);
        }
    }

    dist[0][0] = 1;
    q.push(make_pair(0, 0));
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
                if (map[ny][nx] == 1 && dist[ny][nx] == 0) {
                    dist[ny][nx] = (dist[y][x] + 1);
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }

    printf("%d\n", dist[n - 1][m - 1]);

    return 0;
}
