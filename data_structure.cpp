#include <iostream>
#include <climits>
#include <list>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <queue>

/*
dinamic array :
* insert/remove O(n)
* peek O(1)
* contains O(1)
*/

template<typename T>
class dinamicArray {
private:
	//Variables
	T* arr;
	int length;
	int capacity;
public:
	dinamicArray() { 
		this->length = 0;
		this->capacity = 0;
	}
	dinamicArray(int c) {
		this->capacity = c;
		this->length = 0;
		arr = new T[capacity];
	}

	int size() { 
		return this->length; 
	}

	bool empty() { 
		return this->size() == 0; 
	}

	T operator[](int index) { 
		return this->arr[index]; 
	}

	void set(int index, T element) { 
		this->arr[index] = element; 
	}

	void clear() {
		delete []arr;
		this->length = 0;
		this->capacity = 0;
	}

	void resize(int size) {
		this->capacity = size;
		T* new_arr = new T[this->capacity];
		for (int i = 0; i < this->length; i++)
			new_arr[i] = this->arr[i];
		delete[] arr;
		this->arr = new_arr;
	}

	void insert(T element) {
		if (this->length + 1 >= this->capacity)
			resize(this->capacity * 2);
		this->arr[this->length++] = element;
	}

	T remove_at(int remove_index) {
		T data = this->arr[remove_index];
		T* new_arr = new T[this->length];
		for (int i = 0, j = 0; i < this->length; i++, j++)
			if (i == remove_index) j--;
			else new_arr[j] = this->arr[i];
		delete[] arr;
		this->arr = new_arr;
		this->capacity = --this->length;
		return data;
	}

	bool remove(T obj) {
		for (int i = 0; i < this->length; i++)
			if (this->arr[i] == obj) {
				remove_at(i);
				return true;
			}
		return false;
	}

	int index_of(T obj) {
		for (int i = 0; i < this->length; i++)
			if (this->arr[i] == obj)
				return i;
		return -1;
	}

	bool contains(T obj) { 
		return index_of(obj) != -1; 
	}

	//print the array
	void print() {
		for (int i = 0; i < size(); i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}
};

/*
linked list :
* insert/remove :
* * head O(1)
* * tail O(1)
* * mid O(n)
* peek O(n)
*/

template<typename T>
class singlyLinkedList {
private:
	struct node {
		int data;
		node* next;
		node() {
			data = NULL;
			next = nullptr;
		}
	};
	int s;
	node* head;
	node* tail;
public:
	singlyLinkedList() {
		s = 0;
		head = nullptr;
		tail = nullptr;
	}

	void clear() {
		node* current = head;
		node* previous;
		s = 0;
		while (current->next != nullptr) {
			previous = current;
			current = current->next;
			delete previous;
		}
	}

	int size() {
		return this->s;
	}

	bool empty() {
		return s == 0;
	}

	void insert_tail(T value) {
		node* temp = new node;
		temp->data = value;

		if (this->empty()) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
		s++;
	}

	void insert_head(T value) {
		node* temp = new node;
		temp->data = value;
		temp->next = head;
		head = temp;
		if (this->empty())
			this->tail = temp;
		s++;
	}

	void insert_at(int position, T value) {
		node* previousNode = nullptr;
		node* currentNode;
		node* temp = new node;

		currentNode = head;
		for (int i = 0; i < position; i++) {
			previousNode = currentNode;
			currentNode = currentNode->next;
		}

		temp->data = value;
		previousNode->next = temp;
		temp->next = currentNode;
		s++;
	}

	T remove_head() {
		node* temp;
		temp = head;

		head = head->next;
		T tmp = temp->data;
		delete temp;
		s--;
		return tmp;
	}

	T remove_tail() {
		node* current;
		node* previous = nullptr;

		current = head;

		while (current->next != nullptr) {
			previous = current;
			current = current->next;
		}

		tail = previous;
		previous->next = nullptr;
		T tmp = current->data;
		delete current;
		s--;
		return tmp;
	}

	T remove_at(int position) {
		node* current;
		node* previous = nullptr;

		current = head;
		for (int i = 0; i < position; i++) {
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		T tmp = current->data;
		delete current;
		s--;
		return tmp;
	}

	T peek(int pos) {
		node* current;

		current = head;
		for (int i = 0; i < pos; i++)
			current = current->next;
		return current->data;
	}

	void set(int pos, T val) {
		node* current;

		current = head;
		for (int i = 0; i < pos; i++)
			current = current->next;
		current->data = val;
	}

	//print the list
	void print() {
		node* trav = head;
		for (int i = 0; i < s; i++)
			std::cout << trav->data << " ", trav = trav->next;
		std::cout << std::endl;
	}
};

template<typename T>
class doublyLinkedList {
private:
	struct node {
		T data;
		node* next;
		node* last;
		node() {
			data = NULL;
			next = nullptr;
			last = nullptr;
		}
	};
	int s;
	node* head;
	node* tail;
public:
	doublyLinkedList() {
		s = 0;
		head = NULL;
		tail = NULL;
	}

	void clear() {
		node* current = head;
		while (current->next != nullptr) {
			current = current->next;
			delete current->last;
		}
	}

	int size() {
		return this->size;
	}

	bool empty() {
		return s == 0;
	}

	void insert_tail(T value) {
		node* temp = new node;
		temp->data = value;
		if (this->empty()) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			temp->last = tail;
			tail = temp;
		}
		s++;
	}

	void insert_head(T value) {
		node* temp = new node;
		temp->data = value;
		temp->next = head;
		head = temp;
		if (this->empty())
			this->tail = temp;
		else head->last = temp;
		s++;
	}

	void insert_at(int position, T value) {
		node* currentNode;
		node* temp = new node;

		currentNode = head;
		for (int i = 0; i < position - 1; i++) {
			currentNode = currentNode->next;
		}

		temp->data = value;
		temp->last = currentNode;
		temp->next = currentNode->next;
		currentNode->next = temp;
		temp->next->last = temp;
		s++;
	}

	T remove_head() {
		node* temp;
		temp = head;
		T tmp = head->data;
		head->next->next->last = head;
		head = head->next;
		delete temp;
		s--;
		return tmp;
	}

	T remove_tail() {
		node* current;

		current = head;

		while (current->next != nullptr) {
			current = current->next;
		}

		T tmp = current->data;
		tail = current->last;
		current->last->next = nullptr;
		delete current;
		s--;
		return tmp;
	}

	T remove_at(int position) {
		node* current;

		current = head;
		for (int i = 0; i < position; i++) {
			current = current->next;
		}
		T tmp = current->data;
		current->last->next = current->next;
		current->next->last = current->last;
		delete current;
		s--;
		return tmp;
	}

	T peek(int pos) {
		node* current;
		current = head;
		for (int i = 0; i < pos - 1; i++)
			current = current->next;
		return current->data;
	}

	void set(int pos, T val) {
		node* current;

		current = head;
		for (int i = 0; i < pos; i++)
			current = current->next;
		current->data = val;
	}

	//print the list
	void print() {
		node* trav = head;
		for (int i = 0; i < s; i++)
			std::cout << trav->data << " ", trav = trav->next;
		std::cout << std::endl;
	}
};

/*
stack :
* insert_tail/remove_tail O(1)
* peek_tail O(1)
*/

template<typename T>
class stack {
private:
	doublyLinkedList<T> l;
public:
	stack() { l.clear(); }
	void push(T val) { l.insert_tail(val); }
	T pop() { return l.remove_tail(); }
	void size() { return l.size(); }
	void empty() { return l.size() == 0; }
	T peek() {
		T tmp = l.remove_tail();
		l.insert_tail(T);
		return tmp;
	}
};

/*
stack :
* insert_head/remove_tail O(1)
* peek_tail O(1)
*/

template<typename T>
class queue {
private:
	doublyLinkedList<T> l;
public:
	queue() { l.clear(); }
	void push(T val) { l.insert_tail(val); }
	T pop() { return l.remove_head(); }
	void size() { return l.size(); }
	void empty() { return l.size() != 0; }
	T peek_head() {
		T tmp = l.remove_head;
		l.insert_head(tmp);
		return tmp;
	}
};

class unionFind {
private:
	int s;
	int* sz;
	int* id;
	int number_components;
public:
	unionFind(int sze) {
		s = sze;
		number_components = sze;
		sz = new int[s];
		id = new int[s];

		for (int i = 0; i < s; i++)
			id[i] = i, sz[i] = 1;
	}

	int find(int p) {
		if (p == id[p])
			return p;
		return id[p] = find(id[p]);
	}

	bool connected(int p, int q) {
		return find(p) == find(q);
	}

	int component_size(int p) {
		return sz[find(p)];
	}

	int size() {
		return s;
	}

	int components() {
		return number_components;
	}

	void unify(int p, int q) {
		int root1 = find(p);
		int root2 = find(q);

		if (root1 == root2)
			return;

		if (sz[root1] < sz[root2]) {
			sz[root2] += sz[root1];
			id[root1] = root2;
		}
		else {
			sz[root1] += sz[root2];
			id[root2] = root1;
		}
		number_components--;
	}
 };

/*
binary search tree
* insert/remove O(log n)
* contains O(log n)
*/

template<typename T>
class binarySearchTree {
private:
	struct node {
		T data;
		node* left, right;
		node() {
			data = NULL;
			left = nullptr;
			right = nullptr;
		}
		node(node* l, node* r, T elem) {
			data = elem;
			left = l;
			right = r;
		}
	};

	int node_count;
	node* root = nullptr;

	//Functions
	node* insert(node* n, T elem) {
		if (n == NULL)
			n = new node(nullptr, nullptr, elem);
		else
			if (elem < n.data)
				n.left = insert(n.left, elem);
			else
				n.right = insert(n.right, elem);
		return node;
	}

	node* remove(node* n, T elem) {
		if (n == NULL)
			return NULL;
		int cmp = elem - n.data;

		if (cmp < 0)
			n.left = remove(n.left, elem);
		else if (cmp > 0)
			n.right = remove(n.right, elem);
		else {
			if (n.left == NULL) {
				node right_child = n.right;
				return right_child;
			}
			else if (n.right == NULL) {
				node left_child = n.left;
				return left_child;
			}
			else {
				node tmp = find_min(n.right);
				n.data = tmp.data;
				n.right = remove(n.right, tmp.data);
			}
		}
		return n;
	}

	node find_min(node n) {
		while (n.left != NULL) n = n.left;
		return n;
	}

	node find_max(node n) {
		while (n.right != NULL) n = n.right;
		return n;
	}

	bool contains(node* n, T elem) {
		if (n == nullptr)
			return false;
		int cmp = elem - n.data;
		if (cmp < 0)
			return contains(n.left, elem);
		else if (cmp > 0)
			return contains(n.right, elem);
		else return true;
	}

	int height(node n) {
		if (n == NULL)
			return 0;
		return std::max(height(n.left), height(n.right)) + 1;
	}
public:
	int size() {
		return node_count;
	}

	bool empty() {
		return size() == 0;
	}

	bool insert(T elem) {
		if (contains(elem))
			return false;
		root = insert(root, elem);
		node_count++;
		return true;
	}

	bool remove(T elem) {
		if (contains(elem)) {
			root = remove(root, elem);
			node_count--;
			return true;
		}
		return false;
	}

	bool contains(T elem) {
		return contains(root, elem);
	}

	int height() {
		return height(root);
	}
};

//////////////////////////////////////////////////////////DONE BEFORE THIS LINE/////////////////////////////////////////////////////////////

/*
hash table :
* insert/remove O(log n)
* peek/contains O(log n)
*/

//Compile Error
template<typename K, typename V>
class hashTable {
private:
	//Constants
	const K tomb_stone = K(rand());
	const int default_capacity = 8;
	double default_load_factor = 0.45;

	//Variables
	double load_factor;
	int capacity, threshold, modificaton_count;
	int used_buckets, key_count;
	K* key_table;
	V* value_table;
	bool contains_flag;

	//Functions
	int next_2_power(int n) {
		int cnt = 0;
		while (n) n /= 2, cnt++;
		return cnt << 2;
	}

	int P(int x) {
		return (x * x + x) >> 1;
	}

	int normalize_index(int key_hash) {
		return (key_hash & 0x7FFFFFFF) % capacity;
	}

	K hash_code(V val);
public:
	hashTable() {
		srand(time(NULL));
		used_buckets = 0;
		key_count = 0;
		contains_flag = false;
		modificaton_count = 0;
	}

	hashTable(int cap) {
		srand(time(NULL));
		capacity = cap;
		used_buckets = 0;
		key_count = 0;
		contains_flag = false;
		modificaton_count = 0;
	}

	hashTable(int cap, double load) {
		srand(time(NULL));
		if (cap <= 0)
			return;
		if (load <= 0)
			return;
		load_factor = load;
		capacity = std::max(default_capacity, next_2_power(cap));
		threshold = (int)(capacity * load_factor);

		key_table = new K[capacity];
		value_table = new V[capacity];
	}

	void clear() {
		delete[] key_table;
		delete[] value_table;
		key_count = used_buckets = 0;
		modificaton_count++;
	}

	int size() {
		return key_count;
	}

	bool empty() {
		return key_count == 0;
	}

	V insert(K key, V val) {
		if (key == NULL)
			return NULL;
		if (used_buckets >= threshold)
			resize_table();
		int hash = normalize_index(hash_code(key));
		int i = hash, j = -1, x = 1;
		do {
			if (key_table[i] = tomb_stone)
				if (j == -1)
					j = i;
				else if (key_table[i] != NULL) {
					if (key_table[i] == key) {
						V old_value = value_table[i];
						if (j == -1)
							value_table[i] = val;
						else {
							key_table[i] = tomb_stone;
							value_table[i] = NULL;
							key_table[j] = key;
							value_table[j] = val;
						}
						modificaton_count++;
						return old_value;
					}
				}
				else {
					if (j == -1) {
						used_buckets++;
						key_count++;
						key_table[i] = key;
						value_table[i] = val;
					}
					else {
						key_count++;
						key_table[j] = key;
						value_table[j] = val;
					}
					modificaton_count++;
					return NULL;
				}
			i = normalize_index(hash + P(x++));
		} while (true);
	}

	bool contains_key(K key) {
		peek_key(key);
		return contains_flag;
	}

	V peek_key(K key) {
		if (key == NULL)
			return NULL;
		int hash = normalize_index(hash_code(key));
		int i = hash, j = -1, x = 1;
		do {
			if (key_table[i] == tomb_stone)
				if (j == -1)
					j = i;
				else if (key_table[i] != NULL) {
					if (key_table[i] == key)
						contains_flag = true;
					if (j != -1) {
						key_table[j] = key_table[i];
						value_table[j] = value_table[i];
						key_table[i] = tomb_stone;
						value_table[i] = NULL;
						return value_table[j];
					}
					else return value_table[j];
				}
				else {
					contains_flag = false;
					return value_table[i];
				}
			i = normalize_index(hash + P(x++));
		} while (true);
	}

	K peek(V key) {
		return peek_key(hash_code(key));
	}

	bool contains(V val) {
		return contains_key(hash_code(val));
	}

	V remove_key(K key) {
		if (key == NULL)
			return NULL;
		int hash = normalize_index(hash_code(key));
		int i = hash, x = 1;
		for (;; i = normalize_index(hash + P(x++))) {
			if (key_table[i] == tomb_stone)
				continue;
			if (key_table[i] = NULL)
				return NULL;
			if (key_table[i] == key) {
				key_count--;
				modificaton_count++;
				V old_value = value_table[i];
				key_table[i] = tomb_stone;
				value_table[i] = NULL;
				return old_value;
			}
		}
	}

	void resize_table() {
		capacity *= 2;
		threshold = (int)(capacity * load_factor);
		K* old_key_table = new K[capacity];
		V* old_value_table = new V[capacity];

		K* key_table_tmp = key_table;
		key_table = old_key_table;
		old_key_table = key_table;

		V* value_table_tmp = value_table;
		value_table = old_value_table;
		old_value_table = value_table_tmp;

		key_count = used_buckets = 0;
		//complied error, can't find thing's to replace ".length"
		for (int i = 0; i < old_key_table.length; i++) {
			if (old_key_table[i] != NULL && old_key_table[i] != tomb_stone)
				insert(old_key_table[i], old_value_table[i]);
			old_value_table[i] = NULL;
			old_key_table[i] = NULL;
		}
		delete[] old_key_table;
		delete[] old_value_table;
	}

	void swap(V val1, V val2, K val1_index, K val2_index) {
		remove_key(val1_index);
		remove_key(val2_index);
		insert(val1_index, val2);
		insert(val2_index, val1);
	}
};

/*
heap :
* insert O(n log n)
* remove O(log n)
* peek O(n)
*/

//this is priority queue too!!!
template<typename T>
class heap {
private:
	//variables
	int heap_size;
	int heap_capacity;
	singlyLinkedList<T>* hp;
	bool min_heap;
	hashTable<int, T>* map;

	//Functions
	void swap(int i, int j) {
		T elem_i = hp->peek(i);
		T elem_j = hp->peek(j);

		hp->set(i, elem_j);
		hp->set(j, elem_i);

		map->swap(elem_i, elem_j, i, j);
	}

	void swim(int k) {
		int parent = (k - 1) / 2;
		while (k > 0 && hp->peek(k) < hp->peek(parent)) {
			swap(parent, k);
			k = parent;
			parent = (k - 1) / 2;
		}
	}

	void sink(int k) {
		while (true) {
			int left = 2 * k + 1;
			int right = 2 * k + 2;

			int smallest = left;

			if (right < heap_size && hp->peek(right) < hp->peek(left))
				smallest = right;

			if (left >= heap_size || hp->peek(k) < hp->peek(smallest))
				break;

			std::swap(smallest, k);
			k = smallest;
		}
	}

	T remove_at(int i) {
		if (empty())
			return NULL;

		heap_size--;
		T removed_data = hp->peek(i);
		swap(i, heap_size);

		hp.set(heap_size, NULL);
		map->remove_key(heap_size);

		if (i == heap_size)
			return removed_data;
		T elem = hp.peek(i);

		sink(i);

		if (hp->peek(i) == elem)
			swim(i);
		return removed_data;
	}

	T neg(T elem);
public:
	heap() {
		heap_capacity = 0;
		heap_size = 0;
		hp = new singlyLinkedList<T>;
		min_heap = true;
		map = new hashTable<int, T>;
	}

	void set_heap(bool isMinHeap) {
		min_heap = isMinHeap;
	}

	int size() {
		return this->heap_size;
	}

	bool empty() {
		return this->size() != 0;
	}

	void clear() {
		hp->clear();
		heap_size = 0;
		map->clear();
	}

	T peek() {
		T tmp = hp->peek();
		if (!min_heap)
			tmp = tmp->neg();
		return tmp;
	}

	T remove_root() {
		return remove_at(0);
	}

	bool contains(T elem) {
		if (elem == NULL) return false;
		return map->contains(elem);
	}

	void insert(T elem) {
		if (elem == NULL)
			return;
		if (!min_heap)
			elem = elem.neg();
		if (heap_size < heap_capacity)
			hp->set(heap_size, elem);
		else {
			hp->insert_tail(elem);
			heap_capacity++;
		}
		map->insert(heap_size, elem);
		swim(heap_size);
		heap_size++;
	}

	bool remove(T element) {
		if (element == NULL)
			return false;
		int index = map->peek(element);
		if (index != NULL)
			remove_at(index);
		return index != NULL;
	}
};

template<typename T>
class indexedHeap {
private:
	//Variables
	int sz;
	int number_elements;
	int degree_node;
	int* child, parent;
	int* position_map;
	int* inverse_map;
	bool min_heap;

	//Functions
	void sink(int i) {
		for (int j = min_child(i); j != -1; ) {
			swap(i, parent[i]);
			i = parent[i];
			j = min_child(i);
		}
	}

	void swim(int i) {
		while (less(i, parent[i])) {
			swap(i, parent[i]);
			i = parent[i];
		}
	}

	int min_child(int i) {
		int index = -1, from = child[i], to = std::min(sz, from + degree_node);
		for (int j = from; j < to; j++)
			if (less(j, i))
				index = i = j;
		return index;
	}

	void swap(int i, int j) {
		position_map[inverse_map[j]] = i;
		position_map[inverse_map[i]] = j;
		int tmp = inverse_map[i];
		inverse_map[i] = inverse_map[j];
		inverse_map[j] = tmp;
	}

	bool less(T a, T b) {
		return a < b;
	}

	bool less(int i, int j) {
		return values[inverse_map[i]] < values[inverse_map[j]];
	}
public:
	T* values;

	indexedHeap(int degree, int max_size) {
		degree_node = std::max(2, degree);
		number_elements = std::max(degree_node + 1, max_size);
		inverse_map = new int[number_elements];
		position_map = new int[number_elements];
		child = new int[number_elements];
		parent = new int[number_elements];
		values = new T[number_elements];

		for (int i = 0; i < number_elements; i++) {
			parent[i] = (i - 1) / degree_node;
			child[i] = i * degree_node + 1;
			position_map[i] = -1;
			inverse_map[i] = -1;
		}
	}

	int size() {
		return sz;
	}

	bool empty() {
		return sz == 0;
	}

	bool contains(int key) {
		return position_map[key] != -1;
	}

	int peek_min_key_index() {
		return inverse_map[0];
	}

	int poll_min_key_index() {
		int min_key = peek_min_key_index();
		remove(min_key);
		return min_key;
	}

	T peek_min_value() {
		return values[inverse_map[0]];
	}

	T poll_min_value() {
		T min_val = peek_min_value();
		remove(peek_min_key_index());
		return min_val;
	}

	void insert(int key, T value) {
		if (contains(key))
			return;
		if (value == NULL)
			return;
		position_map[key] = sz;
		inverse_map[sz] = key;
		values[key] = value;
		swim(sz++);
	}

	T value_of(int key) {
		if (!contains(key))
			return NULL;
		return values[key];
	}

	T remove(int key) {
		if (!contains(key))
			return NULL;
		int i = position_map[key];
		swap(i, --sz);
		sink(i);
		swim(i);
		T value = values[key];
		values[key] = NULL;
		position_map[key] = -1;
		inverse_map[sz] = -1;
		return value;
	}

	T update(int key, T value) {
		if (!contains(key) || value == NULL)
			return NULL;
		int i = position_map[key];
		T old_value = values[key];
		values[key] = value;
		swim(i);
		sink(i);
		return old_value;
	}

	void decrease(int key, T value) {
		if (!contains(key) || value == NULL)
			return;
		if (less(value, values[key])) {
			values[key] = value;
			swim(position_map[key]);
		}
	}

	void increase(int key, T value) {
		if (!contains(key) || value == NULL)
			return;
		if (less(values[key], value)) {
			values[key] = value;
			sink(position_map[key]);
		}
	}
};

/*
FenwickTree
* sum O(log n)
*/

//Fenwick Trees are always one based
template<typename T>
class FenwickTree {
private:
	//Variables
	T* tree;
	int length;

	//Functions
	int lsb(int i) {
		return i & -i;
	}
public:
	FenwickTree(int sz) {
		tree = new T[sz];
		length = sz;
	}

	FenwickTree(long long val[], int sz) {
		if (val == NULL)
			return;
		tree = new T[sz];
		for (int i = 0; i < sz; i++)
			tree[i] = val[i];
		length = sz;
		for (int i = 1; i < length; i++) {
			int j = i + lsb(i);
			if (j < length)
				tree[j] += tree[i];
		}
	}

	T prefix_sum(int i) {
		T sum = 0;
		while (i != 0) {
			sum += tree[i];
			i &= ~lsb(i);
		}
		return sum;
	}

	T sum(int i, int j) {
		return prefix_sum(j) - prefix_sum(i);
	}

	void add(int i, T k) {
		while (i < length) {
			tree[i] += k;
			i += lsb;
		}
	}

	void set(int i, T k) {
		T val = sum(i, i);
		add(i, k - val);
	}
};

/*
* two balanced tree
* insert/remove O(log n)
*/

template<typename T>
class AVLTree {
private:
	//Classes
	class node {
	public:
		int balance_factor;
		T value;
		int height;
		node* right, left;
		node(T val) {
			balance_factor = 0;
			height = 0;
			value = val;
			right = nullptr;
			left = nullptr;
		}

		node() {
			balance_factor = 0;
			height = 0;
			value = NULL;
			right = nullptr;
			left = nullptr;
		}
	};

	//Variables
	node* root;

	int node_count;
	
	//Functions
	bool contains(node* n, T val) {
		if (*n == NULL)
			return false;
		int cmp = val - n->value;
		if (cmp < 0)
			return contains(n->left, val);
		if (cmp > 0)
			return contain(n->right, val);
		return true;
	}

	node insert(node* n, T val) {
		if (*n == NULL)
			return new node(val);

		int cmp = val - n.value;

		if (cmp < 0)
			n->left = insert(n->left, val);
		else
			n->right = insert(n->right, val);
		update(n);
		return balance(n);
	}

	void update(node* n) {
		int left_node_height = (n->left == nullptr) ? -1 : n->left->height;
		int right_node_height = (n->right == nullptr) ? -1 : n->right->height;
		n->height = 1 + max(left_node_height, right_node_height);
		n->balance_factor = right_node_height - left_node_height;
	}

	node balance(node* n) {
		if (n->balance_factor == -2)
			if (n->left->balance_factor <= 0)
				return left_left_case(n);
			else
				return left_right_case(n);
		else if (n->balance_factor == 2)
			if (n->right->balance_fatcor >= 0)
				return right_right_case(n);
			else
				return right_left_case(n);
		else
			return n;
	}

	node left_left_case(node* n) {
		return right_rotation(n);
	}
	node left_right_case(node* n) {
		n->left = left_rotation(n->left);
		return left_left_case(n);
	}
	node right_right_case(node* n) {
		return left_rotation(n);
	}
	node right_left_case(node* n) {
		n->right = right_rotation(n->right);
		return right_right_case(n);
	}

	node left_rotation(node* n) {
		node* new_parent = n->right;
		n->right = new_parent->left;
		new_parent->left = n;
		update(n);
		update(new_parent);
		return new_parent;
	}
	node right_rotation(node* n) {
		node new_parent = n->left;
		n->left = new_parent->right;
		new_parent->right = n;
		update(n);
		update(new_parent);
		return new_parent;
	}

	node remove(node* n, T elem) {
		if (*n == NULL)
			return NULL;
		int cmp = elem - n->value;
		if (cmp < 0)
			n->left = remove(n->left, elem);
		else if (cmp > 0)
			n->right = remove(n->right, elem);
		else {
			if (n->left == nullptr)
				return n->right;
			else if (n->right == nullptr)
				return n->left;
			else {
				if (n->left->height > n->right->height) {
					T successor_val = find_max(n->left);
					n->value = successor_val;
					n->left = remove(n->left, successor_val);
				}
				else {
					T successor_val = find_min(n->right);
					n->value = successor_val;
					n->right = remove(n->right, successor_val);
				}
			}
		}
		update(n);
		return balance(n);
	}

	//n* or n???
	T find_max(node* n) {
		while (n->left != nullptr)
			n = n->left;
		return n->value;
	}
	T find_min(node* n) {
		while (n->right != nullptr)
			n = n->right;
		return n->value;
	}
public:

	int height() {
		if (root == nullptr)
			return 0;
		return (*root).height;
	}

	int size() {
		return node_count;
	}

	bool empty() {
		return node_count == 0;
	}

	bool contains(T val) {
		return contains(root, val);
	}

	bool insert(T val) {
		if (val == NULL)
			return false;
		if (!contains(root, val)) {
			root = insert(root, val);
			node_count++;
			return true;
		}
		return false;
	}

	bool remove(T elem) {
		if (elem == NULL)
			return false;

		if (contains(root, elem)) {
			root = remove(root, elem);
			node_count--;
			return true;
		}
		return false;
	}
};

template<typename T>
class redBlackTree {
private:
	//Classes
	class node {
	public:
		bool color;
		T value;
		node* left, right, parent;
		node() {
			color = red;
			value = NULL;
			left = nullptr;
			right = nullptr;
			parent = nullptr;
		}
		node(T val, node* pa) {
			value = val;
			parent = pa;
		}
	};

	//Variables
	const bool red = true;
	const bool black = false;
	node* root;
	int node_count;

	//Functions
	void insertion_relabel(node* n) {
		node* pa = n->parent;
		if (pa == nullptr) {
			n->color = black;
			root = n;
			return;
		}
		node* grand_parent = pa->parent;
		if (grand_parent == nullptr)
			return;
		bool node_is_left_child = pa->left == n;
		bool parent_is_left_child = pa == grand_parent->left;
		node* uncle = parent_is_left_child ? grand_parent->right : grand_parent->left;
		bool uncle_is_red_node = uncle == nullptr ? black : uncle->color;
		if (uncle_is_red_node) {
			pa->color = black;
			grand_parent->color = red;
			uncle->color = black;
		}
		else
			if (parent_is_left_child)
				if (node_is_left_child)
					grand_parent = left_left_case(grand_parent);
				else
					grand_parent = left_right_case(grand_parent);
			else
				if (node_is_left_child)
					grand_parent = right_left_case(grand_parent);
				else
					grand_parent = right_right_case(grand_parent);
		insertion_relabel(grand_parent);
	}

	node swap_colors(node* a, node* b) {
		bool tmp_color = a->color;
		a->color = b->color;
		b->color = tmp_color;
	}

	node* left_left_case(node* n) {
		n->left = right_rotation(n->left);
		swap_colors(n, n->right);
		return n;
	}
	node* left_right_case(node* n) {
		n->left = left_rotation(n->left);
		return left_left_case(n);
	}
	node* right_right_case(node* n) {
		n = left_rotation(n->left);
		swap_colors(n, n->left);
		return n;
	}
	node* right_left_case(node* n) {
		n->right = right_rotation(n->right);
		return right_right_case(n);
	}

	node* right_rotation(node* parent) {
		node* grandparent = parent->parent;
		node* child = parent->left;
		parent->left = child->right;
		if (child->right != nullptr)
			child->right->parent = parent;
		child->right = parent;
		parent->parent = child;
		child->parent = grandparent;
		update_parent_child_link(grandparent, parent, child);
		return child;
	}
	node* left_rotation(node* parent) {
		node* grandparent = parent->parent;
		node* child = parent->right;
		parent->right = child->left;
		if (child->left != nullptr)
			child->left->parent = parent;
		child->left = parent;
		parent->parent = child;
		child->parent = grandparent;
		update_parent_child_link(grandparent, parent, child);
		return child;
	}

	void update_parent_child_link(node* parent, node* old_child, node* new_child) {
		if (parent != nullptr)
			if (parent->left == old_child)
				parent->left = new_child;
			else
				parent->right = new_child;
	}

	node find_min(node n) {
		while (n.left != nullptr)
			n = n.left;
		return n;
	}

	node find_max(node n) {
		while (n.right != nullptr)
			n = n.right;
		return n;
	}
public:
	redBlackTree() {
		root = nullptr;
		node_count = 0;
	}

	int size() {
		return node_count;
	}

	bool empty() {
		return node_count == 0;
	}

	bool contains(T val) {
		node* n = root;
		if (n == nullptr || val == NULL)
			return false;
		while (node != nullptr) {
			int cmp = val - n->vlaue;
			if (cmp < 0)
				n = n->left;
			else if (cmp > 0)
				n = n->right;
			else return true;
		}
		return false;
	}

	bool insert(T val) {
		if (val == NULL)
			return false;
		if (root == nullptr) {
			root = new node(val, nullptr);
			insertion_relabel(root);
			node_count++;
			return true;
		}
		for (node* n = root; ; ) {
			int cmp = val - n->value;
			if (cmp < 0) {
				if (n->left == nullptr) {
					n->left = new node(val, n);
					insertion_relabel(n->left);
					node_count++;
					return true;
				}
				n = n->left;
			}
			else if (cmp > 0) {
				if (n->right == nullptr) {
					n->right = new node(val, n);
					insertoon_relabel(n->left);
					node_count++;
					return true;
				}
				n = n->right;
			}
			else return false;
		}
	}
};

/*
bloom filters :
* check whether an element is in an list, can be wrong when there is, can't be wrong when there isn's, has a great advantage on time and space
* insert O(1)
* contains O(log n)
*/

class blooomFilters {
private:
	//Variables
	int n_sets;
	long long** bit_sets;
	int* set_size;
	long long mod_64 = 0x7F;
	long long div_64 = 6;
public:
	blooomFilters(int bit_set_size[], int size) {
		n_sets = size;
		set_size = bit_set_size;
		bit_sets = new long long*[n_sets];
		for (int i = 0; i < n_sets; i++)
			bit_sets[i] = new long long[set_size[i]];
	}

	void insert(int set_index, long hash) {
		hash = hash % set_size[set_index];
		int block = (int)(hash >> div_64);
		bit_sets[set_index][block] |= (1L << (hash & mod_64));
	}

	void insert(long long hashes[]) {
		for (int i = 0; i < n_sets; i++)
			insert(i, hashes[i]);
	}

	bool contains(long long hashes[], int size) {
		for (int i = 0; i < size; i++) {
			int block = (int)(hashes[i] >> div_64);
			long mask = 1L << (hashes[i] & mod_64);
			if ((bit_sets[i][block] & mask) != mask)
				return false;
		}
		return true;
	}
};

class quadTree {
private:
	//Constants
	static const int NORTH_EAST = 1;
	static const int NORTH_WEST = 2;
	static const int SOUTH_EAST = 3;
	static const int SOUTH_WEST = 4;
	
	//Functions
	static bool north(int dir) {
		return dir == NORTH_EAST || dir == NORTH_WEST;
	}
public:
	//Classes
	class rectangle {
	public:
		long long x1, y1, x2, y2;
		rectangle(long long x11, long long y11, long long x22, long long y22) {
			this->x1 = x11;
			this->y1 = y11;
			this->x2 = x22;
			this->y2 = y22;
		}

		bool intersects(rectangle* r) {
			return r != nullptr && !(r->x2 < x1 || r->x1 > x2 || r->y1 > y2 || r->y2 < y1);
		}

		bool contains(long long x, long long y) {
			return (x1 <= x && x <= x2) && (y1 <= y && y <= y2);
		}

		bool contains(rectangle* r) {
			return r != nullptr && contains(r->x1, r->y1) && contains(r->x1, r->y2);
		}
	};
private:
	//Classes
	class point {
	public:
		long long x, y;
		point() {

		}
		point(long long xx, long long yy) {
			x = xx;
			y = yy;
		}
	};
	class sortedPoint {
	public:
		point pt;
		double distance;
		sortedPoint(double dis, point po) {
			distance = dis;
			pt = po;
		}

		int compare_to(sortedPoint other) {
			return distance - other.distance;
		}
	};
	class node {
	public:
		//Variables
		int point_count;
		long long* X;
		long long* Y;
		node* nor_wes;
		node* nor_eas;
		node* sou_wes;
		node* sou_eas;
		rectangle* region;

		//Functions
		bool add(long long x, long long y) {
			if (!region->contains(x, y))
				return false;
			if (point_count < num_point) {
				X[point_count] = x;
				Y[point_count] = y;
				point_count++;
				return true;
			}
			else {
				long long cx = (region->x1 + region->x2) / 2;
				long long cy = (region->y1 + region->y2) / 2;

				if (sou_wes == nullptr)
					sou_wes = new node(new rectangle(region->x1, region->y1, cx, cy));
				if (sou_wes->add(x, y))
					return true;

				if (nor_wes == nullptr)
					nor_wes = new node(new rectangle(region->x1, cy, cx, region->y2));
				if (nor_wes->add(x, y))
					return true;

				if (nor_eas == nullptr)
					nor_eas = new node(new rectangle(cx, cy, region->x2, region->y2));
				if (nor_eas->add(x, y))
					return true;

				if (sou_eas == nullptr)
					sou_eas = new node(new rectangle(cx, region->y1, region->x2, cy));
				return sou_eas->add(x, y);
			}
		}

		void k_nearest_neighbors(int k, long long x, long long y, std::priority_queue<sortedPoint>* heap) {
			for (int i = 0; i < point_count; i++) {
				long long xx = X[i], yy = Y[i];
				double radius = heap->empty() ? INT_MAX : heap->top().distance;

				double distance = std::sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y));

				if ((int)heap->size() < k)
					heap->push(*new sortedPoint(distance, *new point(xx, yy)));
				else if (distance < radius) {
					heap->pop();
					heap->push(*new sortedPoint(distance, *new point(xx, yy)));
				}
			}

			int point_quadrant = 0;

			if (nor_wes != nullptr && region->contains(x, y)) {
				nor_wes->k_nearest_neighbors(k, x, y, heap);
				point_quadrant = NORTH_WEST;
			}
			else if (nor_eas != nullptr && region->contains(x, y)) {
				nor_eas->k_nearest_neighbors(k, x, y, heap);
				point_quadrant = NORTH_EAST;
			}
			else if (sou_wes != nullptr && region->contains(x, y)) {
				sou_wes->k_nearest_neighbors(k, x, y, heap);
				point_quadrant = SOUTH_WEST;
			}
			else if (sou_eas != nullptr && region->contains(x, y)) {
				sou_eas->k_nearest_neighbors(k, x, y, heap);
				point_quadrant = SOUTH_EAST;
			}

			if (point_quadrant)
				return;

			double radius = heap->empty() ? INT_MAX : heap->top().distance;

			long long cx = (region->x1 + region->x2) / 2;
			long long cy = (region->y1 + region->y2) / 2;

			long long dx = std::abs(x - cx);
			long long dy = std::abs(y - cy);

			bool chech_horizontal_cell = radius >= dx;
			bool check_vertical_cell = radius >= dy;
			bool check_diagonal_cell = chech_horizontal_cell && check_vertical_cell;

			if (heap->size() == k)
				if (north(point_quadrant))
					if (point_quadrant == NORTH_WEST) {
						if (nor_eas != nullptr)
							nor_eas->k_nearest_neighbors(k, x, y, heap);
						if (sou_wes != nullptr)
							sou_wes->k_nearest_neighbors(k, x, y, heap);
						if (sou_eas != nullptr)
							sou_eas->k_nearest_neighbors(k, x, y, heap);
					}
					else {
						if (nor_wes != nullptr)
							nor_wes->k_nearest_neighbors(k, x, y, heap);
						if (sou_eas != nullptr)
							sou_eas->k_nearest_neighbors(k, x, y, heap);
						if (nor_wes != nullptr)
							nor_wes->k_nearest_neighbors(k, x, y, heap);
					}
				else
					if (point_quadrant == SOUTH_WEST) {
						if (sou_eas != nullptr)
							sou_eas->k_nearest_neighbors(k, x, y, heap);
						if (nor_wes != nullptr)
							nor_wes->k_nearest_neighbors(k, x, y, heap);
						if (nor_eas != nullptr)
							nor_eas->k_nearest_neighbors(k, x, y, heap);
					}
					else {
						if (sou_wes != nullptr)
							sou_wes->k_nearest_neighbors(k, x, y, heap);
						if (nor_wes != nullptr)
							nor_wes->k_nearest_neighbors(k, x, y, heap);
						if (nor_wes != nullptr)
							nor_wes->k_nearest_neighbors(k, x, y, heap);
					}
			else
				if (north(point_quadrant))
					if (point_quadrant == NORTH_WEST) {
						if (chech_horizontal_cell)
							if (nor_eas != nullptr)
								nor_eas->k_nearest_neighbors(k, x, y, heap);
						if (check_vertical_cell)
							if (sou_wes != nullptr)
								sou_wes->k_nearest_neighbors(k, x, y, heap);
						if (check_diagonal_cell)
							if (sou_eas != nullptr)
								sou_eas->k_nearest_neighbors(k, x, y, heap);
					}
					else {
						if (chech_horizontal_cell)
							if (nor_wes != nullptr)
								nor_wes->k_nearest_neighbors(k, x, y, heap);
						if (check_vertical_cell)
							if (sou_eas != nullptr)
								sou_eas->k_nearest_neighbors(k, x, y, heap);
						if (check_diagonal_cell)
							if (nor_wes != nullptr)
								nor_wes->k_nearest_neighbors(k, x, y, heap);
					}
				else
					if (point_quadrant == SOUTH_WEST) {
						if (chech_horizontal_cell)
							if (sou_eas != nullptr)
								sou_eas->k_nearest_neighbors(k, x, y, heap);
						if (check_vertical_cell)
							if (nor_wes != nullptr)
								nor_wes->k_nearest_neighbors(k, x, y, heap);
						if (check_diagonal_cell)
							if (nor_eas != nullptr)
								nor_eas->k_nearest_neighbors(k, x, y, heap);
					}
					else {
						if (chech_horizontal_cell)
							if (sou_wes != nullptr)
								sou_wes->k_nearest_neighbors(k, x, y, heap);
						if (check_vertical_cell)
							if (nor_wes != nullptr)
								nor_wes->k_nearest_neighbors(k, x, y, heap);
						if (check_diagonal_cell)
							if (nor_wes != nullptr)
								nor_wes->k_nearest_neighbors(k, x, y, heap);
					}
		}
		
		node(rectangle* region) {
			this->region = region;
			X = new long long[num_point];
			Y = new long long[num_point];
		}

		int count(rectangle* area) {
			if (area == nullptr || !region->intersects(area))
				return 0;
			int count = 0;
			if (area->contains(region))
				count = point_count;
			else
				for (int i = 0; i < point_count; i++)
					if (area->contains(X[i], Y[i]))
						count++;
			if (nor_wes != nullptr)
				count += nor_wes->count(area);
			if (nor_eas != nullptr)
				count += nor_eas->count(area);
			if (sou_wes != nullptr)
				count += sou_wes->count(area);
			if (sou_eas != nullptr)
				count += sou_eas->count(area);

			return count;
		}

		std::list<point>* k_nearest_neighbors(int k, long long x, long long y) {
			std::priority_queue<sortedPoint>* h = new std::priority_queue<sortedPoint>;

			k_nearest_neighbors(k, x, y, h);

			std::list<point>* neighbors = new std::list<point>;

			while (h->size()) {
				neighbors->push_back(h->top().pt);
				h->pop();
			}

			return neighbors;
		}
	};

	//Functions
	void getPoints(node* node, std::list<point>* points) {
		if (node == NULL)
			return;
		for (int i = 0; i < node->point_count; i++)
			points->push_back(*(new point(node->X[i], node->Y[i])));
		getPoints(node->nor_wes, points);
		getPoints(node->nor_eas, points);
		getPoints(node->sou_wes, points);
		getPoints(node->sou_eas, points);
	}
public:
	//Variables
	static int num_point;

	const int defualt_num_points = 16;

	node* root;

	//Functions
	quadTree(rectangle* region) {
		num_point = defualt_num_points;
		root = new node(region);
	}

	quadTree(rectangle* region, int points_per_node) {
		num_point = points_per_node;
		root = new node(region);
	}

	bool add(long long x, long long y) {
		return root->add(x, y);
	}

	int count(rectangle* region) {
		return root->count(region);
	}

	std::list<point>* k_nearest_neighbors(int k, long long x, long long y) {
		return root->k_nearest_neighbors(k, x, y);
	}

	std::list<point>* getPoints() {
		std::list<point>* points = new std::list<point>;
		getPoints(root, points);
		return points;
	}
};

int main() {

}