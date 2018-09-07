/*

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

贪心

*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int sum = 0;
		int lower = prices[0], upper = prices[0];
		for (vector<int>::iterator it = prices.begin(); it != prices.end()-1; ++it){
			if ((*it) <= *(it + 1)){
				upper= *(it + 1);
			}
			else{//下降
				sum += upper - lower;
				upper = *(it + 1);
				lower=*(it + 1);
			}
		}
        sum += upper - lower;
		return sum;
	}
};
