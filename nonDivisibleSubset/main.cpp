#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binaryFind(int a, vector <int> v) {
	int b = 0;
	int e = v.size() - 1;

	while (b <= e) {
		int m = (e + b) / 2;
		if (a < v[m]) {
			e = m - 1;
		}
		else if (a > v[m]) {
			b = m + 1;
		}
		else if (a == v[m]) {
			return true;
		}
	}

	return false;
}
/*
int longest_subset_rec(int k, vector <int> remainders) {
	vector <int> max_lens;
	int n = remainders.size();
	
	for (int i = 0; i < n; i++) {
		int num = remainders[i];
		vector <int> reduced_remainders = remainders;
		reduced_remainders.erase(reduced_remainders.begin() + i);

		if (num == 0 && binaryFind(0, reduced_remainders)) {
			max_lens.push_back(longest_subset_rec(k, reduced_remainders));
		}
		else if (binaryFind(k - num, reduced_remainders)) {
			max_lens.push_back(longest_subset_rec(k, reduced_remainders));
		}
	}

	if (max_lens.size() == 0) return n;
	else {
		int maximum = 0;
		for (auto& el : remainders) {
			if (el > maximum) el = maximum;
		}
		return maximum;
	}
}*/

int nonDivisibleSubset(int k, vector<int> s) {
	for (auto& el : s) {
		el %= k;
	}
	int n = s.size();
	sort(s.begin(), s.end());
	vector <int> histogram(k);

	for (int i = 0; i < n; i++) {
		histogram[s[i]]++;
	}

	if (k % 2 == 0) {
		for (int i = 1; i < k / 2; i++) {
			n -= min(histogram[i], histogram[k - i]);
		}

		if (histogram[k / 2] >= 2) {
			n -= (histogram[k / 2] - 1);
		}
	}

	else {
		for (int i = 1; i <= k / 2; i++) {
			n -= min(histogram[i], histogram[k - i]);
		}
	}

	if (histogram[0] >= 2) {
		n -= (histogram[0] - 1);
	}

	return n;
}

int main() {
	vector <int> v1 = {
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10
	};

	cout << nonDivisibleSubset(4, v1) << endl;

	return 0;
}