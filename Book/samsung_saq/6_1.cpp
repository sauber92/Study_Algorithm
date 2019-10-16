#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int test_case;
int n, m;
int wine[2][200000];

int main() {
    scanf("%d", &test_case);

    for (int t = 1; t <= test_case; t++) {
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n + m; i++) {
            wine[0][i] = 0;
            wine[1][i] = 0;
        }

        for (int day = 0; day < 2; day++) {
            for (int i = 0; i < n + m; i++) {
                scanf_s("%d", &wine[day][i]);
            }
        }

        vector<int> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back(0);
        }
        for (int i = 0; i < m; i++) {
            vec.push_back(1);
        }

        vector<int> ans;
        do {
            vector<int> today;
            vector<int> tommorow;
            for (int i = 0; i < n + m; i++) {
                if (vec[i] == 0) {
                    today.push_back(wine[0][i]);
                }
                else {
                    tommorow.push_back(wine[1][i]);
                }
            }
            int ans_today = 0;
            int ans_tommorow = 0;

            for (auto itr = today.begin(); itr != today.end(); itr++) {
                ans_today += *itr;
            }
            for (auto itr = tommorow.begin(); itr != tommorow.end(); itr++) {
                ans_tommorow += *itr;
            }
            ans.push_back(ans_today + ans_tommorow);
        } while (next_permutation(vec.begin(), vec.end()));

        sort(ans.begin(), ans.end());

        printf("#%d %d\n", t, ans.front());
    }

    return 0;
}
