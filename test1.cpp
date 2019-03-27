#include <benchmark/benchmark.h>

#include <algorithm>
#include <string>


static void BM_lazy_palindrome(benchmark::State & state)
{
    for (auto _ : state)
    {
        std::string str = "hello";
        std::string tmp;
        for (auto c : str)
        {
            tmp = c + tmp;
        }
    }
}
BENCHMARK(BM_lazy_palindrome)->Range(8, 8<<10);

static void BM_better_palindrome(benchmark::State & state)
{
    for (auto _ : state)
    {
        std::string str = "hello";
        for (size_t i = 0, end = str.size() - 1, middle = (str.size() + 1) / 2 ; i < middle ; ++i)
        {
            std::swap(str[i], str[end - i]);
        }
    }
}
BENCHMARK(BM_better_palindrome)->Range(8, 8<<10);

BENCHMARK_MAIN();
