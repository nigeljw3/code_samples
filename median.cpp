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
#include <set>

// Using here only for convenience
using namespace std;

// Find the median of two sorted arrays
double median(vector<int>& nums1, vector<int>& nums2) {
    multiset<int> array(nums1.begin(), nums1.end());
    array.insert(nums2.begin(), nums2.end());
    auto iter = array.cbegin();
    unsigned int size = array.size();
    advance(iter, size/2);
    if (size%2 == 0) {
        return (*iter + *(--iter))/2.0;
    } else return *iter;
}

int main() {
    return 0;
}
