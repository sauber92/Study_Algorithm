#include <iostream>
#include <queue>
using namespace std;

const int MAX = 200001;

int n, k;
int map[MAX];
int dist[MAX];
bool check[MAX];
queue<int> q;

int main() {
    scanf("%d %d", &n, &k);

    q.push(n);
    dist[n] = 0;
    check[n] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (check[k] == true) {
            printf("%d\n", dist[k]);
            break;
        }

        if (cur + 1 < MAX) {
            if (check[cur + 1] == false) {
                q.push(cur + 1);
                dist[cur + 1] = dist[cur] + 1;
                check[cur + 1] = true;
            }
        }
        if (cur - 1 >= 0) {
            if (check[cur - 1] == false) {
                q.push(cur - 1);
                dist[cur - 1] = dist[cur] + 1;
                check[cur - 1] = true;
            }
        }
        if (cur * 2 < MAX) {
            if (check[cur * 2] == false) {
                q.push(cur * 2);
                dist[cur * 2] = dist[cur] + 1;
                check[cur * 2] = true;
            }
        }
    }

    return 0;
}
