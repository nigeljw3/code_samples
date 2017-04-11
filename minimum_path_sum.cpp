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

// Dynamic programming solution for the shortest path through a two dimensional array of values
int minimum_path_sum(vector<vector<int>>& grid) {
    unsigned int m = grid.size();
    unsigned int n = grid[0].size();
    int cache[m*n] = {0};
    cache[0] = grid[0][0];

    for(unsigned int i = 1; i < n; ++i) {
        cache[i] = grid[0][i] + cache[i - 1];

    }

    for(unsigned int i = 1; i < m; ++i) {
        cache[i*n] = grid[i][0] + cache[(i - 1)*n];
    }

    for(unsigned int i = 1; i < m; ++i) {
        for(unsigned int j = 1; j < n; ++j) {
            if (cache[(i - 1)*n + j] < cache[i*n + j - 1]) { 
                cache[i*n + j] = grid[i][j] + cache[(i - 1)*n + j];
            } else cache[i*n + j] = grid[i][j] + cache[i*n + j - 1];
        }
    }

    return cache[m*n - 1];
}

int main() {
    return 0;
}
