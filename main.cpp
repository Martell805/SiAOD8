#include "iostream"
#include "vector"

using namespace std;

void print(const vector<vector<int>>& l) {
    for(const auto& row: l) {
        for(auto el: row)
            cout << el << " ";
        cout << endl;
    }
}

int longestPalindrome(const string& s) {
    if(s.empty()) {
        return 0;
    }

    vector<vector<int>> l(s.size(), vector<int>(s.size(), 0));

    for(int diagonal = 0; diagonal < s.size(); diagonal++) {
        for(int i = diagonal; i < s.size(); i++) {
            int j = i - diagonal;

            if(diagonal == 0) {
                l[i][j] = 1;
                continue;
            }

            if(diagonal == 1) {
                if(s[i] == s[j]) {
                    l[i][j] = 2;
                } else {
                    l[i][j] = 1;
                }

                continue;
            }

            if(s[i] == s[j]) {
                l[i][j] = l[i - 1][j + 1] + 2;
            } else {
                l[i][j] = max(l[i][j + 1], l[i - 1][j]);
            }
        }
    }

    print(l);

    return l[s.size() - 1][0];
}

int main() {
    string s;
    cout << "Enter string to find length of longest palindrome:" << endl;
    cin >> s;

    cout << "Length of longest palindrome: " << longestPalindrome(s) << endl;

    return 0;
}
