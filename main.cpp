#include <cassert>
#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* Advance(ListNode* item, int step) {
  while (0 < step-- && item) {
    item = item->next;
  }
  return item;
}

class Solution {
 public:
  ListNode *middleNode(ListNode *head) {
    ListNode *slow = head, *fast = head->next;
    int length = 0;
    while (fast) {
      slow = Advance(slow, 1);
      fast = Advance(fast, 2);
    }

    return slow;
  }
};

ListNode* MakeList(const std::vector<int>& numbers) {
  ListNode* head = nullptr;
  for (auto iter = numbers.rbegin(); iter != numbers.rend(); ++iter) {
    head = new ListNode{*iter, head};
  }

  return head;
}

void TestMiddleNode() {
  Solution s;
  {
    auto head = MakeList({1,2,3,4,5});
    auto mid = s.middleNode(head);
    assert(mid);
    assert(3 == mid->val);
  }
  {
    auto head = MakeList({1,2,3,4,5,6});
    auto mid = s.middleNode(head);
    assert(mid);
    assert(4 == mid->val);
  }
}

int main() {
  TestMiddleNode();
  std::cout << "Ok!" << std::endl;
  return 0;
}
