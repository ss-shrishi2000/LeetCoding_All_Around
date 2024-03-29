PROBLEM STATEMENT :- It is a sweltering summer day, and a boy wants to buy some ice cream bars.
At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. 
The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 
Return the maximum number of ice cream bars the boy can buy with coins coins.
Note: The boy can buy the ice cream bars in any order.
  
Example 1:
Input: costs = [1,3,2,4,1], coins = 7
Output: 4
Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
  
Example 2:
Input: costs = [10,6,8,7,7,8], coins = 5
Output: 0
Explanation: The boy cannot afford any of the ice cream bars.
  
  SOLUTION :-
    
    class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < costs.size(); i++)
        {
            pq.push(costs[i]);
        }
        int ans = 0;
        long long s = 0;
        while(!pq.empty())
        {
            int t = pq.top();
            pq.pop();

            if(s+t <= coins)
            ans++, s = s+t;
            else
            break;
        }
        return ans;
    }
};
