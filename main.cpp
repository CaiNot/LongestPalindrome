#include <iostream>
#include <string>

using namespace std;


string longestPalindrome(string s) {
    int length = s.size();
    int dp[length][length] = {0};

    int end = length - 1;
    string target = "";
    for (int i = 0; i < length; i++) {
        dp[i][i] = 1;
    }
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            
        }
    }

    return target;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    cout << longestPalindrome("babad");
    return 0;
}