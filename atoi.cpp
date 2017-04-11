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

#include <climits>
#include <string>

// Using here only for convenience
using namespace std;

int atoi(string str) {
    int result = 0;
    int start = 0;
    int length = str.size();
    
    while (str[start] == ' ') ++start;
    
    bool negative = (str[start] == '-') ? true : false;
    
    if (str[start] == '+' || negative) ++start;
    
    while (str[start] == '0') ++start;

    for (unsigned int i = start; i < length; ++i) {
        int digit = (int)str[i] - (unsigned int)'0';
        if (digit < 0 || digit > 9) {
            break;
        }

        if (!negative) {
            if ((INT_MAX - digit)*0.1 > result) result = result*10 + digit;
            else {
                result = INT_MAX;
                break;
            }
        } else {
            if ((INT_MIN + digit)*0.1 <= result) result = result*10 - digit;
            else {
                result = INT_MIN;
                break;
            }
        }
    }

    return result;
}

int main() {
    return 0;
}
