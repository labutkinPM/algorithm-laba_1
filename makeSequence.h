#pragma once
#include <vector>
#include <iostream>

class makeSequence {
public:
	makeSequence(int number, int numberOfTerms);
	makeSequence(int number, int numberOfTerms, float printFlag);
	std::vector<std::vector<int>> sequencing_recursion();
	std::vector<std::vector<int>> sequencing_no_recursion();

private:
	int numberOfTerms;
	int number;
	float printFlag;
	int count;
	std::vector<std::vector<int>> sequences;

	int account_previous(std::vector<int>& temp, int pos);
	void sequence_generation_recursion(int sumBefore, std::vector<int>& sequence);
	void print_sequences();
	void make_end_number(std::vector<int>& sequence, int& numForEnd);
	bool check_raise(std::vector<int>& temp, int pos);
	void make_tail(std::vector<int>& temp, int pos, int& sumForEnd);

};
