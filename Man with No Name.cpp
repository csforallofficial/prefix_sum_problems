/*
Blondie is a bounty hunter. Today, he is on a mission to shoot criminals in a particular city. A city is divided into N areas, numbered 1 through N. It is known that an area numbered i contains Ai criminals. But the problem here is that for some areas, the number of criminals is unknown. Blondie needs to know the number of criminals in each area in advance, as he is very good with the gun, so he only needs a single bullet for one criminal, that’s why he needs to know the count. He doesn’t like to carry more bullets with him.

The areas are arranged linearly in order. And the good part is that for each area with unknown criminals, the number of criminals can be calculated by following these simple steps:

Step 1: Count the criminals shot before
Step 2: Count the areas visited before
Step 3: Divide criminals found in Step 1 by areas found in Step 2
Step 4: Round it down to the nearest integer
Step 5: That’s it

Calculate the number of bullets Blondie needs for each area.

Input:
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,...,AN denoting the number of criminals in each area respectively. An area with unknown number of criminals is denoted by −1.
Output:
For each testcase, print a single line containing N space separated integers, denoting the number of bullets required by Blondie for each area in the city in order.

Constraints
1≤T≤10
1≤N≤105
1≤Ai≤109 or Ai=−1 (for each valid i)
A1>0
Subtasks
30 points: 1≤N≤100
70 points: original constraints
Sample Input:
2
5
23 2 4 1 -1
8
34 56 -1 4 67 2 -1 43
Sample Output:
23 2 4 1 7
34 56 45 4 67 2 34 43
EXPLANATION:
Example Case 1: For last area, ⌊(23+2+4+1)4⌋=7 bullets

Example Case 2: For 3rd area, ⌊(34+56)2⌋=45 bullets

Then, for 7th area, ⌊(34+56+45+4+67+2)6⌋=34 bullets
*/


#include <bits/stdc++.h>
#include<cmath>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x;
        long sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (x == -1)
            {
                x = sum/i;
            }
            sum += x;
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
