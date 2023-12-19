#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    bool compare(vector<int> &a, vector<int> &b)
    {
        return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1];
    }

    void quickSort(vector<vector<int>> &a, int l, int r)
    {
        vector<int> p = a[(l + r) / 2];
        int i = l, j = r;
        while (i < j)
        {
            while (compare(p, a[i]))
            {
                i++;
            }
            while (compare(a[j], p))
            {
                j--;
            }
            if (i <= j)
            {
                vector<int> temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;
                j--;
            }
        }
        if (i < r)
        {
            quickSort(a, i, r);
        }
        if (l < j)
        {
            quickSort(a, l, j);
        }
    }
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        quickSort(points, 0, points.size() - 1);
        vector<vector<int>> firstNElements(points.begin(), points.begin() + k);
        return firstNElements;
    }

    vector<vector<int>> kClosest(vector<vector<int>> &p, int k)
    {

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < p.size(); i++)
        {
            int dist = p[i][0] * p[i][0] + p[i][1] * p[i][1];
            pq.push({-1 * dist, i});
        }
        vector<vector<int>> ans;
        while (k--)
        {
            auto x = pq.top();
            pq.pop();
            ans.push_back(p[x.second]);
        }
        return ans;
    }
};