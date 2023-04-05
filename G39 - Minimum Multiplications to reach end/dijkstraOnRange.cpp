#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr,
                               int start, int end)
    {
        // Create a queue for storing the numbers as a result of multiplication
        // of the numbers in the array and the start number.
        queue<pair<int, int>> q;
        q.push({start, 0});

        // Create a dist array to store the no. of multiplications to reach
        // a particular number from the start number.
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        int mod = 100000;

        // Multiply the start no. with each of numbers in the arr
        // until we get the end no.
        while (!q.empty())
        {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            for (auto it : arr)
            {
                int num = (it * node) % mod;

                // If the no. of multiplications are less than before
                // in order to reach a number, we update the dist array.
                if (steps + 1 < dist[num])
                {
                    dist[num] = steps + 1;

                    // Whenever we reach the end number
                    // return the calculated steps
                    if (num == end)
                        return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        // If the end no. is unattainable.
        return -1;
    }
};

int main()
{
    // Driver Code.
    int start = 3, end = 30;

    vector<int> arr = {2, 5, 7};

    Solution obj;

    int ans = obj.minimumMultiplications(arr, start, end);

    cout << ans;
    cout << endl;

    return 0;
}