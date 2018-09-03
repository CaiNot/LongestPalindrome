#include <iostream>
#include <string>

using namespace std;


string longestPalindrome(string s) {
    int length = s.size();
    if (length==0)
        return "";
    int dp[length][length] = {0};
    int i_max = 0, j_max = 0;
    int j = 0;
    string target = "";
    for (int i = 0; i < length; i++) {
        dp[i][i] = 1;
        if (i < length - 1) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                i_max = i;
                j_max = i + 1;
            }
        }
    }
    int L = 0;
    for (L = 3; L <=length; L++) {
        for (int i = 0; i + L - 1 < length; i++) {
            j = i + L - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
                i_max = i;
                j_max = j;
            }
        }
    }

    return s.substr(i_max,j_max+1);

}
string betterWay(string s){
    /**
     * 重点就是：如果是回文串的话，回文串的中间必定是对称的，
     * 那么该函数就是找到对称轴，以此拓展找到目标回文串
     */

    int len = (int) s.length();
    int left = 0;
    int right = 0;
    int leftres = 0;
    int maxlen = 0;

    int i = 0;
    while (i < len) {
        left = i;
        right = i;
        while (right + 1 < len && s[right] == s[right + 1]) ++right;
        i=right+1;
        while (left >= 0 && right < len && s[left] == s[right]) {
            --left;
            ++right;
        }
        if (maxlen < right - left - 1) {
            leftres = left + 1;
            maxlen = right - left - 1;
        }
    }
    return s.substr(leftres, maxlen);
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    cout << betterWay("abcb");
    return 0;
}