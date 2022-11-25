#include "pch.h"
#include <iostream>
#include <ctime>

using namespace std;

// 使用 unsigned long long (ull) 储存计算结果。
// 实际上，ull 也不能保证不会溢出。此程序主要目的是验证时间复杂度。
typedef unsigned long long ull;

/* 用递推计算 Fibonacci number */
ull fibIter(int n) {
	// 防止出现 n 小于 0 情况
	if (n < 0) {
		cout << "Error! n < 0" << endl;
		return 0;
	}
	// f(0) = 0, f(1) = 1
	if (n <= 1)		return n;

	// 递推关系：fib_2 表示当前正在计算的项目，fib_1 和 fib_0 分别是前面两项
	// 在每次计算时，上一次的 fib_2 和 fib_1 成为下一次的 fib_1 和 fib_0
	// fib_0 = f(0) = 0, fib_1 = f(1) = 1
	ull fib_0 = 0, fib_1 = 1, fib_2 = 1;
	for (int i = 3; i <= n; i++) {
		fib_0 = fib_1;
		fib_1 = fib_2;
		fib_2 = fib_0 + fib_1;
	}
	return fib_2;
}

/* 用递推计算 Fibonacci number，尝试优化（虽然实际上没有优化） */
ull fibIterOptm(int n) {
	if (n < 0) {
		cout << "Error! n < 0" << endl;
		return 0;
	}
	if (n <= 1)		return n;

	// 这里尝试通过循环使用三个变量的数组简化代码，但实际上由于取模运算较为复杂，
	// 常数上有了一定损失。
	ull fib[3] = { 0, 1, 1 };
	for (int i = 3; i <= n; i++) {
		fib[i % 3] = fib[(i + 1) % 3] + fib[(i + 2) % 3];
	}
	return fib[n % 3];
}

/* 用递归计算 Fibonacci number */
ull fibRecr(int n) {
	if (n < 0) {
		cout << "Error! n < 0" << endl;
		return 0;
	}
	if (n <= 1)		return n;
	// 递归关系式
	return fibRecr(n - 1) + fibRecr(n - 2);
}

int main()
{
	// 计时
	clock_t start, end;

	const int DATASIZE_NUM = 5, FUN_NUM = 3;
	// 测试数据，分别设置了两组各 5 个数据作为所求项数
	const int datasize[2][DATASIZE_NUM] =
	{ { 1000000, 10000000, 100000000, 200000000, 400000000 },
	  { 25, 30, 35, 40, 45 } };
	// 测试函数，将三个待测函数放到函数指针数组中
	ull(*fun[FUN_NUM])(int) = { fibIter , fibIterOptm, fibRecr };

	cout << " datasize funcID timeCost result" << endl;

	for (int j = 0; j < FUN_NUM; j++)	// 分别测试 3 种函数
		for (int i = 0; i < DATASIZE_NUM; i++)
		{
			start = clock();	// 开始计时
			// 对于前两种递推函数，采用第一组较大数据测试；
			// 对于第三种递归函数，采用第二组较小数据测试。
			ull result = fun[j](datasize[j < 2 ? 0 : 1][i]);
			end = clock();		// 结束计时
			// 输出数据规模、函数编号、用时和结果
			printf("%9d %6d %8d %lld\n", datasize[j < 2 ? 0 : 1][i], j, end - start, result);
		}

	return 0;
}
