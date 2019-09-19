#include <iostream>
#include <omp.h>
#include <time.h>
using namespace std;

int main(int argc,char* argv[])
{
	int NUM_THREADS;
	cout << "选择并行线程数（1，2，3，4，5）：" << endl;
	cin >> NUM_THREADS;

	int NUM_MILLION;
	cout << "选择累加至几百万（1，2，4，8，10）：" << endl;
	cin >> NUM_MILLION;

	omp_set_num_threads(NUM_THREADS);
	long long sum = 0;
	clock_t t1 = clock();

#pragma omp parallel for reduction(+:sum)
	for (long i = 1; i <= (NUM_MILLION*1000000); i++)
	{
		sum = sum + i;
	}

	clock_t t2 = clock();
	
	cout << "sum = " << sum << endl;
	cout << "parallel time = " << (t2 - t1) << endl;


	/*sum = 0;
	t1 = clock();
	for (long i = 1; i <= 1000000000; i += 1)
		sum = sum + i;
	t2 = clock();
	printf("sum=%lld\n", sum);
	printf("serial time=%d\n", (t2 - t1));*/
	system("pause");
	return 0;
}