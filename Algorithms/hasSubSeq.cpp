#include <vector>
#include <iostream>

bool hasSubSeq (std::vector<int> s1, std::vector<int> s2) {
    int len1 = s1.size(), len2 = s2.size();
    int i = 0;
    while (i < len1) {
        if (len1 - i < len2) return false;
        if (s1[i++] != s2[0]) continue;
        int k = 1;
        while (k < len2 && s1[i] == s2[k]) { ++k; ++i; }
        if (k == len2) break;
    }
    return true;
}

int main() {
    std::vector<int> s1 {1,2,3,4,5,6,7,8};
    std::vector<int> s2 {4,5};
    std::cout << hasSubSeq(s1, s2) << std::endl;
}