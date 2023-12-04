/* Rabin Karp algorithm */
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

long long calcHash(const std::string& str, int prime) {
    long long hash = 0;
    for (int i = 0; i < str.length(); i++) {
        hash += (str[i] * pow(prime, i));
    }
    return hash;
}

std::vector<int> stringMatch(const std::string& text, const std::string& pattern) {
    int p_size = pattern.size();
    int t = text.size();
    std::vector<int> res;
    int prime = 101;
    long long baseHash = calcHash(pattern, prime);
    long long currHash = 0;

    for (int i = 0; i <= t - p_size; i++) {
        if (i == 0)
            currHash = calcHash(text.substr(i, p_size), prime);
        else
            currHash = (currHash - text[i - 1]) / prime +
                        text[i + p_size - 1] * pow(prime, p_size - 1);

        if (currHash == baseHash) {
            bool isMatch = true;
            for (int j = 0; j < p_size; j++) {
                if (text[i + j] != pattern[j]) {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch)
                res.push_back(i + 1);
        }
    }
    return res;
}

int main() {
    std::string text = "ababacabab";
    std::string pattern = "aba";
    std::vector<int> result = stringMatch(text, pattern);

    std::cout << "Pattern found at positions:";
    for (int pos : result) {
        std::cout << " " << pos;
    }

    return 0;
}