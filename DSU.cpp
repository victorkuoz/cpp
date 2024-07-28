#include <vector>

class DSU {
public:
    DSU (int size) : size(size), rank(std::vector<int>(size, 0)), root(std::vector<int>(size)) {
        for (int i = 0; i < size; ++i) {
            root[i] = i;
        }
    }

    int getRoot(int x) {
        return x == root[x] ? x : root[x] = getRoot(root[x]);
    }

    void join(int x, int y) {
        if ((x = getRoot(x)) == (y = getRoot(y))) {
            return;
        }

        // make sure rank[x] >= rank[y] 
        if (rank[x] < rank[y]) {
            std::swap(x, y);
        }

        root[y] = x;
        if (rank[x] == rank[y]) {
            ++rank[x];
        }
    }

private:
    int size;
    std::vector<int> rank, root;
};