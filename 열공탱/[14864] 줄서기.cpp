#include <bits/stdc++.h>

using namespace std;

int N, M, card[100001], valid[100001];
int main()
{
	
	cin >> N >> M;


	for (int i = 1; i <= N; i++)
		card[i] = i;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		card[x]++;
		card[y]--;
	}

	for (int i = 1; i <= N; i++) {
		if (valid[card[i]]) {
			cout << -1 << endl;
			return 0;
		}
		valid[card[i]]++;
	}

	for (int i = 1; i <= N; i++)
		cout << card[i] << " ";
	cout << endl;
}