#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int dist[222222];
int n, k;

void solve()
{
  cin >> n >> k;
  deque<int> dq;
  dq.push_back(n);
  fill(dist, dist + 222222, 1e9);
  dist[n] = 0;

  while (dq.size())
  {
    int cur = dq.front();
    dq.pop_front();

    if (cur == k)
    {
      cout << dist[k];
      return;
    }

    int warp = cur * 2;

    if (warp <= 200000 && dist[warp] > dist[cur])
    {
      dist[warp] = dist[cur];
      dq.push_front(warp);
    }

    int l = cur - 1, r = cur + 1;

    if (l >= 0 && dist[l] > dist[cur] + 1)
    {
      dq.push_back(l);
      dist[l] = dist[cur] + 1;
    }
    
    if (r <= 200000 && dist[r] > dist[cur] + 1)
    {
      dq.push_back(r);
      dist[r] = dist[cur] + 1;
    }
  }
}

int main()
{
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  solve();
}