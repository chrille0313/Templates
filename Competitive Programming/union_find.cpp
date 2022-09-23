class DSU {
public:
	vector<int> parent;
	vector<int> size;


	DSU(int n) {
		parent = vector<int>(n, -1);
		size = vector<int>(n, 1);

		rep(i, n) {
			parent[i] = i;
		}
	}

	int find(int i) {
		return (i == parent[i]) ? i : parent[i] = find(parent[i]);
	}

	// Union by size;
  /*
	void unite(int a, int b) {
		a = find(a);
		b = find(b);

		if (a != b) {
			if (size[a] < size[b])
				swap(a, b);
			parent[b] = a;
			size[a] += size[b];
		}
	}
  */

	// Union by rank
	void union_sets(int a, int b) {
		a = find(a);
		b = find(b);
		if (a != b) {
			if (size[a] < size[b])
				swap(a, b);
			parent[b] = a;
			if (size[a] == size[b])
				size[a]++;
		}
	}
};
