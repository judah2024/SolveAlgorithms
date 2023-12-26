#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using Point = pair<double, double>;

// 삼각형의 공식 : 두변의 외적 / 2

// 세 점을 통해 외적을 구하는 함수
// 끼인각의 점은 a로 설정
double CrossProduct(const Point& a, const Point& b, const Point& c)
{
	// u X v	= (a - b) X (a - c)
	//		= a X a - a X c - b X a + b X c
	//		= a X b + b X c - a X c
	//		= (a0 * b1 - b0 * a1) + (b0 * c1 - c0 * b1) - (a0 * c1 - c0 * a1)
	//		= a0 * b1 + b0 * c1 + c0 * a1 - (a0 * c1 + b0 * a1 + c0 * b1)		
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
		// 0번째 요소가 항삭 끼인각이 된다.
		S += 0.5 * CrossProduct(points[0], points[i - 1], points[i]);
	}

	cout << fixed;
	cout.precision(1);
	// 넓이이므로 절대값을 사용한다.
	cout << abs(S);

	return 0;
}
