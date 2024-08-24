#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string nearestPalindromic(std::string n) {
        int s = n.size();
        int l = s / 2;
        bool even = false;
        if (s % 2 == 0) {
            even = true;
            l--;
        }
        long num = 0;
        for (int i = 0; i <= l; i++) {
            num = num * 10 + (n[i] - '0'); // Convert character to digit
        }
        std::vector<long> v;
        v.push_back(fun(num, even));
        v.push_back(fun(num + 1, even));
        v.push_back(fun(num - 1, even));
        v.push_back(static_cast<long>(pow(10, s - 1) - 1));
        v.push_back(static_cast<long>(pow(10, s ) + 1));

        long mini = 0;
        long diff = LONG_MAX; // Use LONG_MAX instead of INT_MAX for long
        long given = stol(n);
        for (int i = 0; i < 5; i++) {
            if (v[i] == given) continue;
            if (abs(given - v[i]) < diff) {
                mini = v[i];
                diff = abs(given - v[i]);
            }
            else if (abs(given - v[i]) == diff) {
                mini = std::min(mini, v[i]);
            }
        }
        return std::to_string(mini);
    }

private:
    long fun(long num, bool even) {
        long result = num;
        if (!even) {
            num = num / 10;
        }
        while (num) {
            result = result * 10 + (num % 10);
            num = num / 10;
        }
        return result;
    }
};
