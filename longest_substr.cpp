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

// Using here only for convenience
using namespace std;

// Find the longest substring without repeating charaters
string longest_substring(string str) {
    unsigned int length = 0;
    unsigned int longest_length = 0;
    unsigned int start = 0;
    string longest_str;
    string substring;

    for (unsigned int i = 0; i < str.length(); ++i) {
        char c = str[i];
        size_t pos = substring.find(c);
        
        if (pos != string::npos) {
            if (length > longest_length) {
                longest_length = length;
                longest_str = substring;
            }
            substring = substring.substr(pos + 1 , substring.size() - 1);
            length -= pos + 1;
            start += pos + 1;
        }

        substring.push_back(c);
        ++length;
    }

    if (length > longest_length) {
        longest_str = substring;
    }

    return longest_str;

}

int main() {
    return 0;
}
