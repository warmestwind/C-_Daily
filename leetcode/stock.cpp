#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

class Solution {
public:
    pair<int, int> maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) {
            //return 0;
        }
        int minP = prices[0];
        int profit = prices[1] - prices[0];
        int index = 0;
        for (int i = 2; i < prices.size(); i++) {
            minP = min(prices[i - 1], minP);
            //profit = max(profit, prices[i] - minP);
            if (prices[i] - minP > profit) {
                profit = prices[i] - minP;
                index = i;
            }
                
        }
        if (profit < 0) {
            //return 0;
        }
        pair<int, int> result;
        result = std::make_pair(profit, index);
        return result;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int> &prices) { //pair<int, int> //vector<int>
        if (prices.size() <= 1) {
            //return 0;
        }
        int len = prices.size();
        int minP = prices[0]; //记录当前搜素到的最小股价
        vector<int> profits(len, numeric_limits<int>::min());
        profits[0] = 0;
        int index = 0;
        //计算 [1，i-1]天的最大收益
        for (int i = 1; i < len; i++) {
            //最大收益 = max（当天股价-当前最小股价，之前计算的最大收益）
            profits[i] = max(prices[i] - minP, profits[i - 1]);
            minP = min(minP, prices[i]);
        }

        int maxP = prices[len-1]; //记录当前最大股价
        vector<int> profits2(len, numeric_limits<int>::min()); //numeric_limits<int>::min()
        profits2[len-1] = 0;
        //计算 [i,n-2]天的最大收益
        for (int i = len-2 ; i >= 0; i--) {
            //最大收益 = max（当前最大股价-当天股价，之前计算的的最大收益）
            profits2[i] = max(maxP - prices[i], profits2[i + 1]);
            maxP = max(maxP, prices[i]);
            profits[i] = profits[i] + profits2[i];
        }

        int maxProfit = 0;
        for (int i = 0; i < len; i++) {
            maxProfit = max(maxProfit, profits[i]);
        }
        return maxProfit;
    }
    

};

int main()
{
    //int st[] = { 4,6,7,8,3,1,10,21,3,5 };
    int st[] = { 3,1,10,21,3,5,13,3,7,5 };
    int size = end(st) - begin(st);
    int size2 = sizeof(st) / sizeof(st[0]);
    cout << size << size2 << endl;
    vector<int> stock_price(st,st+10);
    //pair<int, int> result;
    Solution2 a;
    int result = a.maxProfit(stock_price);
    cout << result;
    cin.get();
    return 0;
}
