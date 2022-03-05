#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
using vl = vector<ll>;

vl memo;
ll solve(int y) {
	if (memo[y] < 0) {
		auto ans1 = ll{ -1 };
		if (0 <= y - 1) {
			ans1 = static_cast<ll>(solve(y - 1) * 1.05);
		}

		auto ans2 = ll{ -1 };
		if (0 <= y - 3) {
			ans2 = static_cast<ll>(solve(y - 3) * 1.2);
		}

		auto ans3 = ll{ -1 };
		if (0 <= y - 5) {
			ans3 = static_cast<ll>(solve(y - 5) * 1.35);
		}

		memo[y] = max({ ans1, ans2, ans3 });
	}

	return memo[y];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int h, y;
	cin >> h >> y;

	memo = vl(y + 1, -1);
	memo[0] = h;

	cout << solve(y);

	return 0;
}