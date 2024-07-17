/*
每个人依此选择项目，每个人选项目时都（选择当下花费增加最多的项目），若项目i的门票价格为kx+b，
那么增加的花费为：increase = k(x+1)^2 + b(x+1) - kx^2 - bx = k(2x+1) + b，
可以用优先队列存项目的k、b、x(选择这个项目的人数)、increase（当前项目人数增加为x+1所增加的花费），
使increase最大的项目排在队首，每加一个人出队一个并使总花费增加increase，
即总花费money = money + increase，更新x和increase，若increase > 0重新入队，
若increase <= 0不重新入队(人数到了开口向下的二次函数的对称轴，花费开始下降，不能再增加人数了)
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
struct Para{
  int k, b, x, increase;
  Para(int k, int b, int x, int increase) : k(k), b(b), x(x), increase(increase) {}
  bool operator < (const Para& other) const {
    return increase < other.increase;
  }
};

int main()
{
  int N, M, x_max;
  cin >> N >> M;
  priority_queue<Para> pq;
  Para cost(0, 0, 0, 0);
  for(int i = 0; i < M; i++) {
    scanf("%d %d", &cost.k, &cost.b);
    cost.increase = cost.b + cost.k;
    if(cost.increase <= 0) {
      continue;
    }
    cost.x = 1;
    pq.push(cost);
  }
  ll money = 0, person;
  for(person = 0; !pq.empty() && person < N; person++) {
    cost = pq.top();
    pq.pop();
    // k(x+1)^2 + b(x + 1) - kx^2 - bx = k(2x+1) + b
    money += cost.increase;
    cost.increase = cost.k * (2*cost.x + 1) + cost.b;
    if(cost.increase > 0) {
      cost.x += 1;
      pq.push(cost);
    }
  }
  cout << money;
  return 0;
}
