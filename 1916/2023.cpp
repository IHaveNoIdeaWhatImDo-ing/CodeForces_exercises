#include <iostream>
#include <fstream>
#include <cstdint>

static constexpr uint64_t mults2023[] = {1, 7, 17, 119, 289, 2023}; 
static constexpr int size {6};

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

static Init _init;

int binSearch(uint64_t num)
{
    int res {-1};

    int left {};
    int right {size - 1};
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (num < mults2023[mid])
        {
            right = mid - 1;
        }
        else if (num > mults2023[mid])
        {
            left = mid + 1;
        }
        else
        {
            res = mid;
            break;
        }
    }

    return res;
}

int main()
{
    uint16_t i;

    uint16_t count;
    uint16_t n, k;
    uint64_t num;

    uint64_t mult;

    int res;

    //std::ifstream input("input.txt", std::ios::in);

    //input >> count;
    std::cin >> count;

    for (; count > 0; --count)
    {
        mult = static_cast<uint32_t>(1);

        //input >> n >> k;
        std::cin >> n >> k;

        for (i = static_cast<uint16_t>(0); i < n; ++i)
        {
            //input >> num;
            std::cin >> num;
            mult *= num;
        }

        if (!(mult & 1) || (res = binSearch(mult)) < 0)
        {
            std::cout << "NO\n";
            continue;
        }

        std::cout << "YES\n";
        std::cout << mults2023[size - res - 1] << ' ';

        for (i = static_cast<uint16_t>(0); i < k - 1; ++i)
        {
            std::cout << "1 ";
        }
        std::cout << '\n';
    }

    return 0;
}
