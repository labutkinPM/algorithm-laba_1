#include "Generator.h"


//5. Разбиения числа m на n слагаемых 1..m (неубывающая последовательность)

int Factorial(int n)
{
	int f = 1;
	for (int b = 2; b <= n; b++)
	{
		f *= b;
	}
	return f;

}


void Generator::GenerateAll() {
	sampleResult.resize(3);
	sampleResult = std::vector<int>{ 1,2,3 };
	sequence.push_back({ 1,2,3 });
	sequence.push_back({ 1,2,4 });
	sequence.push_back({ 1,3,4 });
}

std::vector<int>& Generator::GetResult(int idx) {

	return sequence.at(idx);
}
