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

// Add two numbers together where their digits are stored individually in reverse order
// in a singly linked list and return the sum in a similarly defined linked
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void increment(ListNode* list) {
    if (list != nullptr) {
        if (list->next != nullptr) {
            if (list->next->val == 9) {
                list->next->val = 0;
                return increment(list->next);
            }else {
                list->next->val += 1;
            }
        }else { list->next = new ListNode(1); }
    }
}

ListNode* add_two_numbers(ListNode* l1, ListNode* l2) {
    ListNode* result = new ListNode(0);
    if (l1 == nullptr) {
        if (l2 == nullptr) return nullptr;

        result->val = l2->val;
        result->next = add_two_numbers(l2->next, nullptr);
        return result;
    }

    if (l2 == nullptr) {
        result->val = l1->val;
        result->next = add_two_numbers(l1->next, nullptr);
        return l1 ;
    }

    int value = l1->val + l2->val;
    bool inc = false;

    if (value > 9) {
        value %= 10;
        inc = true;
    }

    result->val = value;
    result->next = add_two_numbers(l1->next, l2->next);

    if (inc == true) increment(result);

    return result;
}

int main() {
    return 0;
}
