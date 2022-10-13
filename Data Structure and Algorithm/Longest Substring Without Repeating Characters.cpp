#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define all(c) c.begin(), c.end()
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int lengthOfLongestSubstring(string s)
{
    map<char, int> m;
    int ans = 0;
    int i = 0, j = 0;
    while (i < s.length())
    {
        if (m[s[i]] <= 0)
        {
            m[s[i]]++;
            i++;
            ans = max(ans, i - j);
        }
        else
        {
            m.erase(s[j]);
            j++;
        }
    }
    return ans;
}

void Result()
{
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
}

int main()
{
    FAST int test = 1;
    // cin>>test;
    while (test--)
    {
        Result();
    }
    return 0;
}

/*

Input: s = "xcode"
Output: 5
Explanation: The answer is "xcode", with the length of 5.

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

*/
