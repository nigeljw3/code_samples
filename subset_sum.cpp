/**
 * Copyright (C) 2016 Nigel Williams
 *
 * This program is free software:
 * you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <vector>
#include <cstdint>
#include <string>

// Using here only for convenience
using namespace std;
// dynamic programming subset sum solution (psuedo polynomial time)
string subset_sum(const uint64_t value, vector<uint16_t> factors) {
    uint32_t size = static_cast<uint32_t>(factors.size()) + 1;
    bool* sum = nullptr;

    try {
        sum = new bool[(value + 1)*size];
    }catch (const bad_alloc&) {
        sum = nullptr;
    }

    if (sum == nullptr) return string("");

    for (uint32_t i = 0; i < size; ++i) {
        sum[i] = true;
    }

    for (uint64_t i = 1; i <= value; ++i) {
        sum[i*size] = false;
    }

    for (uint64_t i = 1; i <= value; ++i) {
        uint64_t row = i*size;
        for (size_t j = 1; j < size; ++j) {
            if (i >= factors[j - 1]) {
                uint64_t index = i - factors[j - 1];
                index = index*size + j - 1;
                sum[row + j] = sum[row + j - 1] || sum[index];
            } else {
                sum[row + j] = sum[row + j - 1];
            }
        }
    }

    string str("");

    if(sum[(value + 1)*size - 1]) {
        uint32_t temp = size;
        bool first = true;

        for (uint64_t i = value; i > 1; --i) {
            for (uint32_t j = temp; j > 1; --j) {
                if (!sum[i*size + j - 1]) {
                    uint16_t factor = factors[j - 1];
                    if (!first) str += " + ";
                    else first = false;
                    str += to_string(factor);
                    i -= factor;
                    temp -= temp - j;
                    break;
                }
            }
            ++i;
        }
    }

    delete[] sum;

    return str;
}

int main() {
    return 0;
}
