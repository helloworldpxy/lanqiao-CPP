// p801 优秀的拆分
#include <iostream>
#include <math.h> 
using namespace std;
int main() {
    
    int n;
    cin >> n;
    int r[1000]; // 定义一个大数组,存储所有n的余数 
    int *p = r; 
    for (int i = 0;i < 100;i++) { // 给数组的所有元素赋值为 -1,方便后面的条件判断 
        *p = -1;
        p++; 
    }
    
    int i =0; // 存储在数组中余数的真实个数 
    int x; 
    
    if (n % 2 == 0) { // 按题目要求只有偶数才能满足优秀的拆分,因为奇数拆分成二进制之后总会有一个 2的0次方 
        
        while (n) {
             
            r[i] = n % 2; // 将二进制余数存入数组 
            n=n/2;
            i++; 
        } 
        
    } else {
        cout << -1; 
    } 
    
    int s = i; 
    x = --i; 
    for (int j = s - 1;j >= 0;j--) { 
        
        if (r[j] != 0) {
            s = r[j] * pow(2,x); // 从大到小计算出十进制整数拆分成的二进制数的幂项 
            cout << s << " " ;
        }
            
        x--; 
    } 
    
  return 0;
} 
