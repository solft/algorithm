#define NODE_SIZE 100
int parant[NODE_SIZE];
int rank[NODE_SIZE] = { 0, };

int Find(int x) {
	if (parant[x] == x) return x;
	return parant[x] = Find(parant[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return;
	if (rank[x] < rank[y]) parant[x] = y;
	else parant[y] = x;
	if (rank[x] == rank[y]) rank[x]++;
}

int main() {
	for (int i = 0; i < NODE_SIZE; i++)
		parant[i] = i;
}