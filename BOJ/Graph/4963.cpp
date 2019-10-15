#include <iostream>
using namespace std;

int w, h;
int map[50][50];
bool check[50][50];

const int dy[8] = { 1, -1,  0,  0,  1,  1, -1, -1};
const int dx[8] = { 0,  0,  1, -1,  1, -1, -1,  1};

void dfs(int x, int y) {
    check[x][y] = true;

    for (int dir = 0; dir < 8; dir++) {
        if (map[x][y] == 1) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
                continue;
            }
            else {
                if (check[nx][ny] == false) {
                    dfs(nx, ny);
                }
            }
        }
    }
}

int main() {
    while (1) {
        scanf("%d %d", &w, &h);
        if (w == 0 && h == 0) {
            break;
        }

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                map[x][y] = 0;
                check[x][y] = false;
            }
        }

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                scanf("%d", &map[x][y]);
            }
        }

        int component = 0;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (map[x][y] == 1 && check[x][y] == false) {
                    component++;
                    dfs(x, y);
                }
            }
        }

        printf("%d\n", component);
    }

    return 0;
}
