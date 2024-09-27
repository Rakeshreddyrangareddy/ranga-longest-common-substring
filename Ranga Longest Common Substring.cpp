#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

pair<int, string> longestCommonSubstring(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();

    // Creating a 2D vector for storing the lengths of longest common suffixes
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int maxLength = 0;
    int endIndex = 0; // Will store the ending index of the longest common substring in str1

    // Build the table in a bottom-up manner
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i;
                }
            }
        }
    }

    // The longest common substring is str1 ending at endIndex with length maxLength
    string longestSubstring = str1.substr(endIndex - maxLength, maxLength);

    // Output the 2D table 
    cout << "The dynamic programming table is:\n";
    cout << "    ";
    for (char c : str2) {
        cout << c << " ";
    }
    cout << endl;

    for (int i = 0; i <= n; ++i) {
        if (i > 0)
            cout << str1[i - 1] << " ";
        else
            cout << "  ";

        for (int j = 0; j <= m; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return {maxLength, longestSubstring};
}

int main() {
    string str1, str2;

    // Input the strings
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    // Find the longest common substring
    pair<int, string> result = longestCommonSubstring(str1, str2);

    // Output the result
    cout << "\nThe longest common substring is: \"" << result.second << "\" with length " << result.first << endl;

    return 0;
}
