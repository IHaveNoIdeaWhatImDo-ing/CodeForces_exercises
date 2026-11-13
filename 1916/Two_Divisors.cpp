#include <iostream>
#include <fstream>
#include <cstdlib>

inline long long gcd(long long a, long long b)
{
    unsigned long long trailing {__builtin_ctzll(a | b)};
    a >>= __builtin_ctz(a);

    while (b)
    {
        a >>= __builtin_ctz(a);
        if (b > a)
        {
            a ^= b;
            b ^= a;
            a ^= b;
        }
        a -= b;
    }

    return a << trailing;
}

namespace
{
    class Init
    {
    public:
        Init()
        {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(nullptr);
            std::cout.tie(nullptr);
        }
    };
}

static Init init;

int main()
{
    int count;
    long long a, b;
    long long res;

    std::cin >> count;

    for (; count > 0; --count)
    {
        std::cin >> a >> b;
        res = gcd(a, b);
        std::cout << (res == a ? b * b : a * b) / res << '\n';
        // idk, this does not work for 'a' and 'b' where 'b' is a power of 'a' larger than 2 or 'b' is a multiple of 'a' and some other number
    }
}
