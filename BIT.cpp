class BIT {
public:
    BIT(int n)
        : n_(n), rangeSum_(vector<int>(n + 1, 0)) {}

    void update(int x, int delta) {
        while (x <= n_) {
            rangeSum_[x] += delta;
            x += lowbit(x);
        }
    }

    int query(int x) {
        int res = 0;

        while (0 < x) {
            res += rangeSum_[x];
            x -= lowbit(x);
        }

        return res;
    }

private:
    int n_;
    vector<int> rangeSum_;
    static inline int lowbit(int x) {
        return x & (-x);
    };
};