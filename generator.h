#pragma once
#include <vector>

class Generator {

    std::vector<int> sampleResult;
    std::vector<std::vector<int>> sequence;

    // завести набор построенных объектов - vector<vector>

    // конструктор с n,k

public:
    void GenerateAll();
    std::vector<int>& GetResult(int index);
};

int Factorial(int n);
