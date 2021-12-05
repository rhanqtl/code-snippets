#ifndef _LINKED_LIST_OWNERSHIP_H_
#define _LINKED_LIST_OWNERSHIP_H_

#include <memory>
#include <iostream>

namespace hq {

template <typename T>
struct ListNode {
	std::weak_ptr<ListNode<T>> prev_;
	std::shared_ptr<ListNode<T>> next_;

	T data_;

  ListNode(std::shared_ptr<ListNode<T>> prev, 
			     std::shared_ptr<ListNode<T>> next,
					 const T &data)
		  : prev_(prev), next_(next), data_(data) {}
	ListNode(const T &data): ListNode(nullptr, nullptr, data) {}
	~ListNode() = default;
};

template <typename T>
class LinkedList {
 public:
	LinkedList()
	    : head_(std::make_shared<ListNode<T>>(T())), 
			  tail_(std::make_shared<ListNode<T>>(T())) {
		head_->next_ = tail_;
		tail_->prev_ = head_;
	}
	~LinkedList() = default;

	void add_first(const T &data);
	void add_last(const T &data);
	/**
	 * @param[out] data of first node
	 *
	 * @retval true if linked list is not empty
	 * @retval false otherwise
	 */
	bool remove_first(T &data);
	/**
	 * @see LinkedList::remove_first
	 */
	bool remove_last(T &data);
	bool empty() const;
	std::size_t size() const;

 private:
	std::shared_ptr<ListNode<T>> head_;
	std::shared_ptr<ListNode<T>> tail_;
	std::size_t n_elements_;
};

template <typename T>
void LinkedList<T>::add_first(const T &data) {
	auto old_first = head_->next_;
	auto new_node = std::make_shared<ListNode<T>>(head_, old_first, data);
	head_->next_ = new_node;
	old_first->prev_ = new_node;

	n_elements_++;
}

template <typename T>
void LinkedList<T>::add_last(const T &data) {
}

template <typename T>
bool LinkedList<T>::remove_first(T &data) {
	if (empty()) {
		return false;
	}

	auto to_remove = head_->next_;

	// NOTE: order is important in case of copy ctor exception

	data = to_remove->data_;

	head_->next_ = to_remove->next_;
	to_remove->next_->prev_ = head_;
	to_remove->next_ = nullptr;
	to_remove->prev_.reset();

	n_elements_--;

	return true;
}

template <typename T>
bool LinkedList<T>::remove_last(T &data) {
	return false;
}

template <typename T>
bool LinkedList<T>::empty() const {
	return size() == 0;
}

template <typename T>
std::size_t LinkedList<T>::size() const {
	return n_elements_;
}

}

#endif  // _LINKED_LIST_OWNERSHIP_H_
