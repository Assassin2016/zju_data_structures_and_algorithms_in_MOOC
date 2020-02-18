#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[110], w[10010];
bool choice[10010][110];
int cmp(int a, int b) { return a > b; }
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
	sort(w + 1, w + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= w[i]; j--)
			if (dp[j] <= dp[j-w[i]] + w[i]) {
				choice[i][j] = true;
				dp[j] = dp[j-w[i]] + w[i];
			}
	if (dp[m] != m) printf("No Solution");
	else {
		vector<int> ans;
		for (int v = m, index = n; v > 0; index--)
			if (choice[index][v] == true) {
				ans.push_back(w[index]);
				v -= w[index];
			}
		for (int i = 0; i < ans.size(); i++) {
			if (i != 0) printf(" ");
			printf("%d", ans[i]);
		}
	}
	return 0;
}
