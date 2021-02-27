#pragma once
#include<iostream>
#include<memory>

template<typename T>
class Stack {
private:
	class Node {
	private:
		std::shared_ptr<Node> next, previous;
		T value;

	public:
		Node() : value(), next(nullptr), previous(nullptr){}
		Node(T val): value(val), next(nullptr), previous(nullptr) {}
		~Node(){}
		friend class Stack;
	};

	std::shared_ptr<Node> head, tail;
	long long size;

public:
	Stack(): head(nullptr), tail(nullptr), size(0) {}
	~Stack() {}
	long long Size() {
		return size;
	}
	class Forward_iterator {
	public:
		using value_type = T;
		using reference = T&;
		using pointer = T*;
		using difference_type = ptrdiff_t;
		using iterator_category = std::forward_iterator_tag;
		Forward_iterator(std::shared_ptr<Node> elem=nullptr) :node(elem) {}
		~Forward_iterator() {}
		friend Stack;
		bool operator==(const Forward_iterator& other) const{
			return node == other.node;
		}

		bool operator!=(const Forward_iterator& other) const{
			return node != other.node;
		}

		Forward_iterator operator++() {
			node = node->next;
			return *this;
		}

		Forward_iterator operator++(int index) {
			Forward_iterator tmp(node);
			node = node->next;
			return tmp;
		}

		std::shared_ptr<Node> operator->() {
			return this->node;
		}

		T& operator*() {
			return this->node->value;
		}

	private:
		std::shared_ptr<Node> node;
	};
	
	void Push(T& elem) {
		if (size == 0) {
			tail = std::make_shared<Node>(elem);
			head = tail;
		}
		else {
			std::shared_ptr<Node> node = std::make_shared<Node>(elem);
			node->previous = head;
			head->next = node;
			head = node;
		}
		size++;
	}

	void Insert(Forward_iterator iter, T& obj) {
		if (iter == Begin()) {
			if (tail == nullptr) {
				Push(obj);
				return;
			}
			else {
				std::shared_ptr<Node> tmp = std::make_shared<Node>(obj);
				tail->previous = tmp;
				tmp->next = tail;
				tail = tmp;
			}
		}else if(iter == End()){
			std::shared_ptr<Node> tmp = std::make_shared<Node>(obj);
			tmp->next = head;
			tmp->previous = head->previous;
			head->previous = tmp;
		}
		else {
			std::shared_ptr<Node> tmp = std::make_shared<Node>(obj);
			tmp->next = iter.node;
			iter->previous->next = tmp;
			tmp->previous = iter->previous;
			iter->previous = tmp;
		}
		size++;
	}
	
	void Erase(Forward_iterator iter) {
		if (iter == tail) {
			try{
				if (size == 0) {
					throw "List is empty\n";
				}
			}catch (const char a[14]) {
				std::cout << a;
				return;
			}
		}else if (iter == head) {
			std::shared_ptr<Node> tmp = head->previous;
			head->previous->next = nullptr;
			head = tmp;
			size--;
			return;
		}
		else {
			iter->next->previous = iter->previous;
			iter->previous->next = iter->next;
			size--;
			return;
		}
	}

	bool Empty() {
		return size==0;
	}

	void Pop() {
		Erase(head);
	}

	Forward_iterator Top() {
		return head;
	}

	Forward_iterator Begin() {
		return tail;
	}

	Forward_iterator End() {
		return Forward_iterator{};
	}
};
