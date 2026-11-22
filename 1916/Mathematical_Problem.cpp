#include <iostream>
#include <cstdint>
//#include <fstream>
#include <cstring>

static constexpr uint32_t size {169150u}; // sum of squares till and including 99 + new line for each and every number
static uint32_t count {};
static uint32_t idx_count {};

static char nums[size];

static uint32_t indices[51];

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

            uint32_t linesLeft;

            std::memset(nums, '0', size * sizeof(char));
            nums[size - 1] = '\n';
            indices[50] = size;

            indices[idx_count++] = count;

            nums[count++] = '1';
            nums[count++] = '\n';

            indices[idx_count++] = count;

            strncpy(nums + count, "169\n", 4);
            count += 4;
            strncpy(nums + count, "196\n", 4);
            count += 4;
            strncpy(nums + count, "961\n", 4);
            count += 4;

            for (uint32_t i {5u}; i <= 99u; i += 2u)
            {
                indices[idx_count++] = count;

                nums[count] = '1';
                nums[count + 1] = '6';
                nums[count + 2] = '9';
                nums[count + i] = '\n';
                count += i + 1;

                nums[count] = '1';
                nums[count + 1] = '9';
                nums[count + 2] = '6';
                nums[count + i] = '\n';
                count += i + 1;

                nums[count] = '9';
                nums[count + 1] = '6';
                nums[count + 2] = '1';
                nums[count + i] = '\n';
                count += i + 1;

                linesLeft = (i - 3) >> 1;
                for (uint32_t j {}; j < linesLeft; ++j)
                {
                    nums[count] = '1';
                    nums[count + 1 * (j + 2)] = '6';
                    nums[count + 2 * (j + 2)] = '9';
                    count += i;
                    nums[count++] = '\n';

                    nums[count] = '9';
                    nums[count + 1 * (j + 2)] = '6';
                    nums[count + 2 * (j + 2)] = '1';
                    count += i;
                    nums[count++] = '\n';
                }
            }
        }
    };
}

static Init _init;

int main()
{
    //std::ifstream ifs("input.txt", std::ios::in);

    uint16_t t;
    uint16_t n;
    uint16_t i;
    uint32_t idx;

    //ifs >> t;
    std::cin >> t;

    for (; t > 0; --t)
    {
        //ifs >> n;
        std::cin >> n;

        idx = static_cast<uint32_t>(n) / 2u;
        std::cout.write(nums + indices[idx], indices[idx + 1] - indices[idx]);
    }
}
