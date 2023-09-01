#include <iostream>
#include <vector>
#include<string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size())
        {
            return vector<int>();
        }
        unordered_map<char, int> map_p;
        unordered_map<char, int> map_s;
        vector<int> ans;
        for (int i = 0; i < p.size(); i++)
        {
            map_p[p[i]]++;
            map_s[s[i]]++;
        }
        if (map_s == map_p)
            ans.emplace_back(0);
        int n = s.size() - p.size();
        for (int i = 0; i < n; i++)
        {
            map_s[s[i]]--;
            if (map_s[s[i]] == 0)
                map_s.erase(s[i]);
            map_s[s[i + p.size()]]++;
            cout << s.substr(i, p.size()) << endl;
            if (map_s == map_p)
                ans.emplace_back(i + 1);
        }
        return ans;
    }
};

int main()
{
    string s = "cbaebabacd", p ="abc";
    Solution solve;
    vector<int> res = solve.findAnagrams(s, p);
    for (auto it : res)
    {
        cout << it << endl;
    }
}