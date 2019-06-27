#define NODE_SIZE 100
int parent[NODE_SIZE];
int ranking[NODE_SIZE] = { 0, };

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return;
	if (ranking[x] < ranking[y]) parent[x] = y;
	else parent[y] = x;
	if (ranking[x] == ranking[y]) ranking[x]++;
}

int main() {
	for (int i = 0; i < NODE_SIZE; i++)
		parent[i] = i;
}