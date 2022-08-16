class Solution
{
public:
    /*
      It is similar to that of the House Robber or Maximum sum of non adjacent elements.
      The only difference is here first and last house are adjacent.i.e houses are in circular

      Approach :
      First house and Last house cannot be robbed in any case.So without considering them found the answer.
      1.Remove the last element and apply house robber technqiue and find answer
      2.Now Remove the first element and apply house robber technqiue and find answer.
      The final answer is the maximum among both the answers.
    */

    // direct space optimization
    int maximumAmount(int n, vector<int> &nums)
    {
        int prev2, prev = nums[0], curr;
        for (int i = 1; i < n; i++)
        {
            int rob = nums[i] + (i > 1 ? prev2 : 0);
            int noRob = 0 + prev;
            curr = max(rob, noRob);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int> &nums)
    {
        vector<int> temp1, temp2;
        // temp1 stores all the elements except the first element.
        // temp2 stroes all the elements except the last element
        int n = nums.size();
        if (n == 1)
            return nums[0];
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }
        return max(maximumAmount(n - 1, temp1), maximumAmount(n - 1, temp2));
    }
};