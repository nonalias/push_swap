#include <iostream>
#include <random>
#include <fstream>
#include <unordered_map>

using namespace std;
int main(void)
{
	int N;
	std::random_device rnd;
	unordered_map<int, int> m;
	std::ofstream fouts;
	cout << "몇 까지의 난수를 생성할까요?(음수생성불가) : ";
	cin >> N;
	fouts.open(to_string(N) + ".txt");

	unsigned int rand_int = rnd();
	// -> 랜덤한 난수 생성
	// 여기서, random_device 객체는 음수값도 반환하기 때문에 unsigned 로 선언해 주어야
	// 양수 값의 범위를 구할 수 있다.

	//범위지정 하고 싶을 때 예를 들어, 200 ~ 1000 사이의 수만 출력하고 싶다.
	for (int i = 0; i < N; i++)
	{
		rand_int = rnd();
		int ran = rand_int % N;
		if (!m[ran])
		{
			m[ran]++;
			fouts << ran << " ";
		}
		else
			i--;
	}
	//cout << ran;
}
