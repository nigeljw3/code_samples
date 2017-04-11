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
#include <cmath>

// Using here only for convenience
using namespace std;

// Reverse the digits of a 32 bit signed integer
// returns 0 if integer overfloow occurs
int reverse_integer(int x) {
    int result = 0;
    int value;
    int modulus = 10;
    int denom = 1;
    bool neg = false;
    bool overflow = false;
    
    if (x == INT_MIN) return 0;
    
    if (x < 0) {
        neg = true;
        x = abs(x);
    }

    while (true) {
        value = x % modulus;
        x -= value;
        value /= denom;
        result *= 10;
        result += value;
        
        if (x <= 0) break;
        
        if (INT_MAX/10 < modulus) {
            overflow = true;
            break;
        } else modulus *= 10;
        
        denom *= 10;
    }
    
    if (overflow == true) {
        value = x/modulus;
        
        if (INT_MAX/10 < result) {
            result = 0;
        } else {
            result *= 10;
            result += value;
        }
    }

    if (neg) {
        result *= -1;
    }

    return result;
}

int main() {
    return 0;
}
