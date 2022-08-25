#include<iostream>
#include<deque>
using namespace std;

int main() {
	int n, find, num, idx;
	int count = 0;
	deque<int>d;

	cin >> n;
	cin >> find;

	for (int i = 1; i <= n; ++i) {
		d.push_back(i);
	}

	while (find--){
		cin >> num;

		for (int i = 0; i < d.size(); ++i) {
			if (d[i] == num) {
				idx = i;
				break;
			}
		}
		if (idx < d.size() - idx) {
			while (1) {
				if (d.front() == num) {
					d.pop_front();
					break;
				}
				++count;
				d.push_back(d.front());
				d.pop_front();
			}
		}
		else
		{
			while (1)
			{
				if (d.front() == num) {
					d.pop_front();
					break;
				}
				++count;
				d.push_front(d.back());
				d.pop_back();
			}
		}
	}
	cout << count << endl;
}
