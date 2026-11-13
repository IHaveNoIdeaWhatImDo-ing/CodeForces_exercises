#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstring>

static uint32_t losses[100000];

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

            uint32_t idx {1u};

            losses[0] = 0u;
            for (uint16_t i {}; idx < 99998; ++i)
            {
                losses[idx++] = i + 1;
                losses[idx++] = i;
                losses[idx++] = i + 1;
            }
        }
    };
}

static Init _init;

int main()
{
    //std::fstream ifs("input.txt", std::ios::in);
    uint32_t i;

    uint16_t t;
    uint32_t n;
    uint32_t a_i;
    uint64_t sum;
    uint32_t odds;

    //ifs >> t;
    std::cin >> t;

    for (; t > 0; --t)
    {
        sum = 0ull;
        odds = 0u;

        //ifs >> n;
        std::cin >> n;

        //ifs >> a_i;
        std::cin >> a_i;
        sum += a_i;

        std::cout << sum << ' ';

        if (a_i & 1)
        {
            ++odds;
        }

        for (i = 1u; i < n; ++i)
        {
            //ifs >> a_i;
            std::cin >> a_i;
            sum += a_i;
            if (a_i & 1)
            {
                ++odds;
            }
            std::cout << sum - losses[odds] << ' ';
        }

        std::cout << '\n';
    }
}
