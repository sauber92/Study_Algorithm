#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

void optimalVector(vector<int>& v) {
	int min = *min_element(v.begin(), v.end());

	for (auto itr = v.begin(); itr != v.end(); itr++) {
		*itr -= min;
	}
}

int main() {
	int pNum, rWidth, pHeight, arrNum;
	int minSize = 0;
	deque<int> plank;

	cin >> pNum;
	cin >> rWidth;

	if (pNum % rWidth != 0) {
		arrNum = (pNum / rWidth) + 1;
	}
	else {
		arrNum = (pNum / rWidth);
	}

	for (int i = 0; i < pNum; i++) {
		cin >> pHeight;
		plank.push_back(pHeight);
	}

	vector<vector<int> > arr(arrNum, vector<int>(rWidth, 0));
	for (int i = 0; i < arrNum; i++) {
		for (int j = 0; j < rWidth; j++) {
			if (i != 0 && j == 0) {
				arr[i][j] = arr[i-1][rWidth-1];
			}
			else {
				arr[i][j] = plank.front();
				plank.pop_front();
			}
		}
	}

	for (int i = 0; i < arrNum; i++) {
		optimalVector(arr[i]);
	}

	for (int i = 0; i < arrNum ; i++) {
		if (i+1 < arrNum && arr[i].back() < arr[i+1].front()) {
			arr[i+1].front() = arr[i].back();
		}
		else if (i+1 < arrNum && arr[i].back() > arr[i+1].front()) {
			arr[i].back() = arr[i+1].front();
		}
	}

	for (int i = 0; i < arrNum; i++) {
		for (auto itr = arr[i].begin(); itr != arr[i].end(); itr++) {
			minSize += *itr;
		}
	}

	cout << minSize << "\n" << arrNum << "\n";

	return 0;
}
