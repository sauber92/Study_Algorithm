#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;
    
int wearItem(unordered_map<string, int> map) {
    int result = 1;

    for (auto itr = map.begin(); itr != map.end(); itr++) {
        result *= (itr->second) + 1;
    }

    return (result - 1);
}

int main() {
    int num_case, num_item;
    string item_name, item_kind;

    cin >> num_case;

    for (int i = 0; i < num_case; i++) {
        unordered_map<string, int> map_kind;

        cin >> num_item;

        for (int j = 0; j < num_item; j++) {
            cin >> item_name >> item_kind;

            if (map_kind.find(item_kind) == map_kind.end()) {
                map_kind.insert({item_kind, 1});
            }
            else {
                map_kind[item_kind]++;
            }
        }
        cout << wearItem(map_kind) << "\n";
    }

    return 0;
}
