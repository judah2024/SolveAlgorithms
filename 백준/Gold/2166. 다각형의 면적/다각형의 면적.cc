#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using Point = pair<double, double>;

double CrossProduct(const Point& a, const Point& b, const Point& c)
{
	return (a.first * b.second + b.first * c.second + c.first * a.second)
		 - (a.first * c.second + b.first * a.second + c.first * b.second);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n;
	cin >> n;

	vector<Point> points(n);
	for (auto& point : points)
	{
		cin >> point.first >> point.second;
	}

	double S = 0;
	for (int i = 2; i < n; i++)
	{
		S += 0.5 * CrossProduct(points[0], points[i - 1], points[i]);
	}

	cout << fixed;
	cout.precision(1);
	cout << abs(S);

	return 0;
}