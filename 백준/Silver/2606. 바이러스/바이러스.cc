#include <iostream>
using namespace std;

int com[200][200];
int visited[10000];
int stack[101];
int top;

int main() {
	int n;
	cin >> n;

	int edge;
	cin >> edge;


	for (int i = 0; i < edge; i++) {
		int a, b;
		cin >> a >> b;
		com[a - 1][b - 1] = 1;
		com[b - 1][a - 1] = 1;
	}

	top = 0;
	stack[top] = 0;
	visited[0] = 1;
	while (top != -1) {
		int vertex = stack[top];
		top--;
		for (int i = 0; i < n; i++) {
			if (com[vertex][i] == 1 && visited[i] != 1) {
				stack[++top] = i;
				visited[i] = 1;
			}
		}
	}
	

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i] == 1 && i != 0) {
			count++;
		}
	}
	cout << count;
}