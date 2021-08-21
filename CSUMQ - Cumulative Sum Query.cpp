/*
CSUMQ - Cumulative Sum Query
William Macfarlane wants to look at an array.

You are given a list of N numbers and Q queries. Each query is specified by two numbers i and j; the answer to each query is the sum of every number between the range [i, j] (inclusive).

Note: the query ranges are specified using 0-based indexing.

Input
The first line contains N, the number of integers in our list (N <= 100,000). The next line holds N numbers that are guaranteed to fit inside an integer. Following the list is a number Q (Q <= 10,000). The next Q lines each contain two numbers i and j which specify a query you must answer (0 <= i, j <= N-1).

Output
For each query, output the answer to that query on its own line in the order the queries were made.

Example
Input:
3
1 4 1
3
1 1
1 2
0 2
Output:
4
5
6
*/

#include <bits/stdc++.h>
using namespace std;

int prefix(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i <= n; i++)
        sum += arr[i];
    return sum;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int q;
    cin >> q;
    while (q--)
    {
        int i, j;
        cin >> i >> j;
        int sum;
        if (i - 1 >= 0)
            sum = prefix(arr, j) - prefix(arr, i - 1);
        else
            sum = prefix(arr, j);
        cout << sum << endl;
    }
    return 0;
}
