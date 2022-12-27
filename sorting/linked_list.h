/*
 * =====================================================================================
 *
 *       Filename:  linked_list.h
 *
 *    Description:  Linked list.
 *
 *        Version:  1.0
 *        Created:  12/24/2022 22:41:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hanfezh<xianfeng.zhu@gmail.com>
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef SORTING_LINKED_LIST_H__
#define SORTING_LINKED_LIST_H__

#include <initializer_list>
#include <string>
#include <vector>

template <typename T>
class LinkedList {
  struct Node {
    T val;
    Node* next;
    Node() : val{}, next(nullptr) {}
    Node(const T& v) : val(v), next(nullptr) {}
    Node(const T& v, Node* n) : val(v), next(n) {}
  };

 public:
  LinkedList(std::initializer_list<T> l) {
    Node dummy;
    Node* p = &dummy;
    for (const T& v : l) {
      p->next = new Node(v);
      p = p->next;
    }
    head_ = dummy.next;
  }

  LinkedList(const std::vector<T>& l) {
    Node dummy;
    Node* p = &dummy;
    for (const T& v : l) {
      p->next = new Node(v);
      p = p->next;
    }
    head_ = dummy.next;
  }

  virtual ~LinkedList() {
    Node* p = nullptr;
    while (head_ != nullptr) {
      p = head_;
      head_ = p->next;
      delete p;
    }
  }

  void MergeSort() { head_ = MergeSort(head_); }

  std::string String() const {
    std::string s;
    Node* p = head_;
    while (p != nullptr) {
      if (!s.empty()) {
        s += " -> ";
      }
      s += std::to_string(p->val);
      p = p->next;
    }
    return s;
  }

 private:
  Node* MergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    Node* slow = head;
    Node* fast = head->next->next;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    Node* a = head;
    Node* b = slow->next;
    slow->next = nullptr;
    a = MergeSort(a);
    b = MergeSort(b);
    return MergeList(a, b);
  }

  Node* MergeList(Node* a, Node* b) {
    Node dummy;
    Node* p = &dummy;
    while (a != nullptr && b != nullptr) {
      if (a->val < b->val) {
        p->next = a;
        a = a->next;
      } else {
        p->next = b;
        b = b->next;
      }
      p = p->next;
    }
    if (b != nullptr) {
      a = b;
    }
    p->next = a;
    return dummy.next;
  }

 private:
  Node* head_ = nullptr;
};

#endif  // SORTING_LINKED_LIST_H__
