#include <bits/stdc++.h>

/**
 * s:
 *  index: 0 1 2 3 4 5
 *  value: a b a a b a
 * 
 * str:
 *  index: 0123456789ABC
 *  value: #a#b#a#a#b#a#
 */

std::vector<int> manacher(std::string &s) {
    std::string str = "#";
    for (char &c : s) {
        str += std::string({c, '#'});
    }

    int m = str.size();
    std::vector<int> radiuses(m, 0);
    for (int current = 1, center = 0, right = 0; current < m; ++current) {
        if (current < right) {
            radiuses[current] = std::min(right - current, radiuses[center - (current - center)]);
        }

        for (int l = current - (radiuses[current] + 1), r = current + (radiuses[current] + 1); 0 <= l && r < m; --l, ++r, ++radiuses[current]) {
            if (str[l] != str[r]) {
                break;
            }
        }

        if (right < current + radiuses[current]) {
            center = current, right = current + radiuses[current];
        }
    }

    return radiuses;
}

int main () {
    std::string s = "abaaba";
    std::vector<int> radiuses = manacher(s);
    return 0;
}