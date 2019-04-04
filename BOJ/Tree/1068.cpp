#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> vec_tree[50];
vector<int> vec_parents;
queue<int> q;

void calcLeaf(int& count) {
    while (!q.empty()) {
        int front = q.front();
        int size = vec_tree[front].size();
        q.pop();

        if (size == 0) {
            count++;
        }
        else {
            for (int i = 0; i < size; i++) {
                q.push(vec_tree[front][i]);
            }
        }
    }
}

int main() {
    int N, parent, del, count = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> parent;

        if (parent != -1) {
            vec_tree[parent].push_back(i);
        }
        else {
            vec_parents.push_back(i);
        }
    }

    cin >> del;

    for (auto itr = vec_parents.begin(); itr != vec_parents.end(); itr++) {
        if (*itr == del) {
            vec_parents.erase(itr);
            break;
        }
    }

    for (int i = 0; i < N; i++) {
        for (auto itr = vec_tree[i].begin(); itr != vec_tree[i].end(); itr++) {
            if (*itr == del) {
                vec_tree[i].erase(itr);
                break;
            }
        }
    }

    for (unsigned int i = 0; i < vec_parents.size(); i++) {
        q.push(vec_parents[i]);
        calcLeaf(count);
    }

    cout << count << "\n";

    return 0;
}
