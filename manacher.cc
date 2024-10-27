#include <bits/stdc++.h>

/**
 * Function to find the radiuses of palindromic substrings centered at each character using Manacher's algorithm.
 * 
 * @param s The original input string.
 * @return A vector containing the radius of the longest palindromic substring centered at each character of the transformed string.
 */

std::vector<int> manacher(std::string &s) {
    // Transform the original string `s` by inserting '#' between each character and at the start and end, to handle even-length palindromes uniformly.
    std::string str = "#";
    for (char &c : s) {
        str += std::string({c, '#'});
    }

    int m = str.size();

    // Array to store the radius of the longest palindromic substring for each position.
    std::vector<int> radiuses(m, 0);

    // Variables to keep track of the rightmost palindrome's center and its right edge.
    int center = 0, right = 0;

    for (int current = 1; current < m; ++current) {
        // If `current` is within the range of the rightmost palindrome, use the previously calculated values to initialize `radiuses[current]`.
        if (current < right) {
            radiuses[current] = std::min(right - current, radiuses[center - (current - center)]);
        }

        // Expand around the current center to find the maximum palindrome radius.
        for (int l = current - (radiuses[current] + 1), r = current + (radiuses[current] + 1); 0 <= l && r < m; --l, ++r, ++radiuses[current]) {
            if (str[l] != str[r]) {
                break;
            }
        }

        // Update the `center` and `right` if the new palindrome expands beyond `right`.
        if (right < current + radiuses[current]) {
            center = current;
            right = current + radiuses[current];
        }
    }

    return radiuses;
}

int main () {
    std::string s = "abaaba";
    std::vector<int> radiuses = manacher(s);
    return 0;
}