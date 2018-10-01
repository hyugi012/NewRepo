#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M, card[100001];
	cin >> N >> M;


	for (int i = 1; i <= N; i++)
		card[i] = i;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		card[x]++;
		card[y]--;
	}

	for (int i = 1; i <= N-1; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (card[i] == card[j]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

	for (int i = 1; i <= N; i++)
		cout << card[i] << " ";
	cout << endl;
}