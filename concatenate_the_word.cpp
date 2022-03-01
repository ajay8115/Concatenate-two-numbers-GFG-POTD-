// CODE BY :- AJAY PAL IIT (BHU) VARANASI
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

// Please upvote if you like my solution
class Solution
{
public:
    long long countPairs(int N, int X, vector<int> a)
    {
        unordered_map<string, int> m;

        for (int i = 0; i < N; i++)
        {
            m[to_string(a[i])]++; // Insert all array int after convert string in map
        }

        // Suffix -> suf   , Prefix -> pre  , count ->  cnt
        long long cnt = 0;
        string x = to_string(X);    // convert int X to string x;
        for (int i = 0; i < N; i++) // traverese vec array;
        {
            string pre = to_string(a[i]); // we consider each array string as pref
            int n = pre.size();
            if (x.substr(0, n) == pre) // and check first n char of string x is equal to pre string
            {
                string suf = x.substr(n);   // then string suf is substring of string x after remove first n char
                if (m.find(suf) != m.end()) // if that suf string preset in map
                {
                    cnt += m[suf]; // then count their frequency
                }
                if (pre == suf) // if suff is equal to pre
                {
                    cnt--; // then dec cnt by one
                }
            }
        }

        return cnt; //   return count
    }
};
