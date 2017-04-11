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

#include <string>
#include <cstdint>

// Using here only for convenience
using namespace std;

// Find the longest palindrome substring
string longest_palindrome(string s) {
    string result, str;
    uint32_t strLength = s.size();

    if (strLength == 1) {
        result += s;
    } else if (strLength == 2) {
        if (s[0] == s[1]) {
            result += s;
        } else {
            result += s[0];
        }
    } else if (strLength != 0) {
        uint32_t start;
        uint32_t end;
        uint32_t start_result = 0;
        uint32_t end_result = 0;

        for (uint32_t middle = 1; middle < strLength; ++middle) {
            start = middle - 1;
            end = middle;

            while (true) {
                if (s[start] == s[end]) {
                    if (end - start > end_result - start_result) {
                        start_result = start;
                        end_result = end;
                    }
                } else break;

                if (start == 0 || end == strLength - 1) break;
                else {
                    --start;
                    ++end;
                }
            }
        }

        for (uint32_t middle = 1; middle < strLength - 1; ++middle) {
            start = middle - 1;
            end = middle + 1;

            while (true) {
                if (s[start] == s[end]) {
                    if (end - start > end_result - start_result) {
                        start_result = start;
                        end_result = end;
                    }
                } else break;

                if (start == 0 || end == strLength - 1) break;
                else {
                    --start;
                    ++end;
                }
            }
        }

        result = s.substr(start_result, end_result - start_result + 1);
    }

    return result;
}

int main() {
    return 0;
}
