// problem statement
// given the n jobs, and the profit associated with
// supppose
// job           1        2       3       4
// profit        30       32      40      45
// duration       3       2        1      1
// All the works/job can be done in 1 unit of time /1 hour, 1st person can wait for 3 hrs to finish the work,second person can wait for 2 hrs to finish the work,3 person can wait for 1 hr,similarly 4th person
// All the jobs require 1 hr time ,so now we should find the maximum profit,we can get by doing these jobs

// Approach
// sort the profit in decreasing order,and find the maximum value among the duration
// maximum duration is 3hrs,so there will be 3 slots,let say _ _ _
// first the job which has highest profit try to fill as far as possible

// profit 45 40 32 30
// job     1 1  2  3

// _ _ _ so maximum profit is 45 and he can wait for 1 hr only ,here 3 slots are vacant,let do job with profit 45 in 1st slot,now 2 slots are left, now go for second job,he would wait for 1 hr only,as 1hr already completed the person two will leave,so we cannot do it,now go for job 3,he can wait for 2 hrs,we used already 1hr,so we have another 1hr,so do job in reaming 1hr,now go for 4th job, 4th person can waits for 3 hrs,as we have 1hr left in 3hrs ,the 4ht job can be done
// so maximum profit we get is 45 + 32 + 30

#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define mod 1000000007
#define ps(x, y) fixed << setprecision(y) << x
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define vii vector<pair<int, int>>
#define si stack<int>
#define li list<int>
#define endl "\n"
#define pi pair<int, int>
#define scan(h) scanf("%lld", &h)
#define st(g, h) scanf("%lld %lld", &g, &h)
#define print(g) printf("%lld", g)
#define deb(x) cout << #x << " = " << x << endl;
#define fo(i, n) for (int i = 0; i < n; i++)
#define fok(i, k, n) for (int i = k; i >= n; i--)

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}
int power(int a, int b)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
            result = result * a;
        a = a * a;
        b = b >> 1;
    }
    return result;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
bool cmp1(pi &p1, pi &p2)
{
    return p1.first > p2.first;
}
int maximumprofit(vector<pi> &v)
{

    sort(v.begin(), v.end(), cmp1);
    int duration = INT_MIN;
    for (auto pair : v)
        duration = max(duration, pair.second);
    vector<int> temp(duration+1, 0);
    int count = 0, ans = 0;
    for (auto pair : v)
    {
        if (temp[pair.second] == 0 and count < temp.size() - 1)
        {
            temp[pair.second] = pair.first;
            ans += pair.first;
            count++;
        }
        else if (temp[pair.second] != 0 and count < temp.size() - 1) 
        {
            for (int i = pair.second - 1; i >= 1; i--)
            {
                if (temp[i] == 0)
                {
                    temp[i] = pair.first;
                    ans += pair.first;
                    count++;
                    break;
                }
            }
        } 
        else if (count >= temp.size()-1)
            break;
    }
    return ans;
} 
int32_t main()
{

    ios_base::sync_with_stdio(false);
    //  cin.tie(NULL);
    //  cout.tie(NULL);
    //  srand(time(NULL));
    int n;
    cout << "enter the no of jobs " << endl;
    cin >> n;
    vector<pi> v(n);
    for (int i = 0; i < n; i++)
    {
        cout << "enter the profit of the job " << i+1<<endl;
        cin >> v[i].first;
        cout << "Enter the duration of the job : " << endl;
        cin >> v[i].second;
    }
    cout << "maximum profit is : " <<maximumprofit(v);
        return 0;
} 