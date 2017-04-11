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

// Using here only for convenience
using namespace std;

// Determine the maximum area for an array of positive integers which represent
// the sides of a container where the shortest of the two sides represent the height
int max_area(vector<int>& height) {
    int result = 0;
    int value = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
        value = (right - left)*std::min(height[right], height[left]);
        if (value > result) result = value;
        if (height[left] < height[right]) ++left;
        else --right;
    }

    return result;
}

int main() {
    return 0;
}
