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
    vector<int> maxProfit(vector<int> &prices) { //pair<int, int>
        if (prices.size() <= 1) {
            //return 0;
        }
        int len = prices.size();
        int minP = prices[0]; //记录当前搜素到的最小股价
        vector<int> profits(len, numeric_limits<int>::min());
       
        int index = 0;
        //计算 [0，i-1]天的最大收益
        for (int i = 1; i < len; i++) {
            profits[i] = max(prices[i] - minP, profits[i - 1]);
            minP = min(minP, prices[i]);
        }

        int maxP = prices[len-1]; //记录当前最大股价
        vector<int> profits2(len, numeric_limits<int>::min()); //numeric_limits<int>::min()
        
        //计算 [i,n-1]天的最大收益
        for (int i = len-2 ; i >0; i--) {
            profits2[i] = max(maxP -prices[i], profits[i + 1]);
            maxP = max(maxP, prices[i]);
        }

        return profits2;
    }
    

};

int main()
{
    int st[] = { 4,6,7,8,3,1,10,21,3,5 };
    int size = end(st) - begin(st);
    int size2 = sizeof(st) / sizeof(st[0]);
    cout << size << size2 << endl;
    vector<int> stock_price(st,st+10);
    //pair<int, int> result;
    Solution2 a;
    vector<int> result = a.maxProfit(stock_price);
    //cout << result.first << "," << result.second << endl;

    //vector<int> profits{ numeric_limits<int>::min() };
    //profits.resize(10);
    for (int i = 0; i < 10; i++) {
        cout << result[i] << ",";
    }
    cin.get();
    return 0;
}
