#include "makeSequence.h"

//5. Разбиения числа m на n слагаемых 1..m (неубывающая последовательность)

makeSequence::makeSequence(int number, int numberOfTerms) {
	this->number = number;
	this->numberOfTerms = numberOfTerms;
	this->printFlag = true;
	count = 0;
}

makeSequence::makeSequence(int number, int numberOfTerms,
	float printFlag)
{
	this->number = number;
	this->numberOfTerms = numberOfTerms;
	this->printFlag = printFlag;
	count = 0;
}

int makeSequence::account_previous(std::vector<int>& sequence, int pos) {
	int accountPrevious = 0;
	for (int j = 0; j < pos; ++j) {
		accountPrevious += sequence[j];
	}
	return accountPrevious;
}


void  makeSequence::make_end_number(std::vector<int>& sequence, int& numForEnd) {
	sequence[numberOfTerms - 1] = number - numForEnd;
}



bool makeSequence::check_raise(std::vector<int>& sequence, int pos) {
	if ((sequence[pos] + 1) > (number - account_previous(sequence, pos)) /
		(numberOfTerms - pos)) {
		return false;
	}
	return true;
}


void  makeSequence::make_tail(std::vector<int>& sequence, int pos, int& sumForEnd) {
	for (int t = pos; t < numberOfTerms - 1; ++t) {
		sumForEnd -= sequence[t];
		sumForEnd += sequence[pos - 1];

		sequence[t] = sequence[pos - 1];
	}
}

std::vector<std::vector<int>> makeSequence::sequencing_no_recursion()
{
	sequences = std::vector<std::vector<int>>{};
	std::vector<int> tempAns(numberOfTerms);
	tempAns.assign(numberOfTerms, 1);

	int sumForEnd = 1 * (numberOfTerms - 1);
	make_end_number(tempAns, sumForEnd);
	
	sequences.push_back(tempAns);

	while (true) {

		int penultimatePosition = numberOfTerms - 2;
		while (penultimatePosition >= 0) {
			if (check_raise(tempAns, penultimatePosition)) {
				tempAns[penultimatePosition]++;
				sumForEnd++;
				if (penultimatePosition != numberOfTerms - 2) {
					make_tail(tempAns, penultimatePosition + 1, sumForEnd);
				}
				make_end_number(tempAns, sumForEnd);
				sequences.push_back(tempAns);
				break;
			}
			else {
				penultimatePosition--;
				if (penultimatePosition >= 0) {
				}
			}
		}
		if (penultimatePosition < 0) {
			break;
		}

	}
	if (printFlag) {
		print_sequences();
	}

	count = sequences.size();
	return sequences;
}




std::vector<std::vector<int>> makeSequence::sequencing_recursion()
{
	sequences = std::vector<std::vector<int>>{};
	if (number < numberOfTerms) {
		std::cout << "impossible";
	}
	else {
		sequence_generation_recursion(0, std::vector<int>{});
	}

	if (printFlag) {
		print_sequences();
	}
	count = sequences.size();
	return sequences;
}

void makeSequence::sequence_generation_recursion(int sumBefore,
	std::vector<int>& sequence)
{

	int numberOfTermsUsed = sequence.size();
	if (numberOfTermsUsed == numberOfTerms - 1) {

		sequence.push_back(number - sumBefore);
		sequences.push_back(sequence);
		sequence.pop_back();
		return;
	}
	
	int end = (number - sumBefore) / (numberOfTerms - numberOfTermsUsed);
	int start = numberOfTermsUsed > 0 ? sequence[sequence.size() - 1] : 1;
	for (int i = start; i <= end; ++i) {

		sequence.push_back(i);
		sequence_generation_recursion(sumBefore + i, sequence);
		sequence.pop_back();
	}
	
}


void makeSequence::print_sequences() {
	for (int i = 0; i < sequences.size(); ++i) {
		for (int j = 0; j < sequences[i].size(); ++j) {
			std::cout << sequences[i][j] << " ";
		}
		std::cout << '\n';
	}
}

