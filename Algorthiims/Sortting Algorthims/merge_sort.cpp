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
void merge(int *Arr, int start, int mid, int end)
{
	// create a temp array
	int temp[end - start + 1];

	// crawlers for both intervals and for temp
	int i = start, j = mid + 1, k = 0;

	// traverse both arrays and in each iteration add smaller of both elements in temp
	while (i <= mid && j <= end)
	{
		if (Arr[i] <= Arr[j])
		{
			temp[k] = Arr[i];
			k += 1;
			i += 1;
		}
		else
		{
			temp[k] = Arr[j];
			k += 1;
			j += 1;
		}
	}

	// add elements left in the first interval
	while (i <= mid)
	{
		temp[k] = Arr[i];
		k += 1;
		i += 1;
	}

	// add elements left in the second interval
	while (j <= end)
	{
		temp[k] = Arr[j];
		k += 1;
		j += 1;
	}

	// copy temp to original interval
	for (i = start; i <= end; i += 1)
	{
		Arr[i] = temp[i - start];
	}
}

// Arr is an array of integer type
// start and end are the starting and ending index of current interval of Arr

void mergeSort(int *Arr, int start, int end)
{

	if (start == end)
		return;
	int mid = (start + end) / 2;
	mergeSort(Arr, start, mid);
	mergeSort(Arr, mid + 1, end);
	merge(Arr, start, mid, end);
}
int32_t main()
{

	int n;
	cin >> n;
	int arr[n];
	fo(i, n)
			cin >>
		arr[i];
	mergeSort(arr, 0, n - 1);
	fo(i, n)
			cout
		<< arr[i] << endl;
	return 0;
} 