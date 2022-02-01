#include <iostream>
#include <list>

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

template<typename T>
class stack {
private:
	singlyLinkedList<T> l;
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

template<typename T>
class queue {
private:
	singlyLinkedList<T> l;
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

//////////////////////////////////////////////////////////DONE BEFORE THIS LINE/////////////////////////////////////////////////////////////

//this is priority queue too!!!

/*
need to add to hashtable :
* 1.void swap(V elem1, V elem2, K elem1_key, k elem2_key)
* 2.bool contains(V elem)
* 3.K peek(V elem)
*/
template<typename T>
class heap {
private:
	//variables
	int heap_size;
	int heap_capacity;
	singlyLinkedList<T> heap;
	bool min_heap;
	hashTable<int, T> map;

	//Functions
	void swap(int i, int j) {
		T elem_i = heap.peek(i);
		T elem_j = heap.peek(j);

		heap.set(i, elem_j);
		heap.set(j, elem_i);

		map.swap(elem_i, elem_j, i, j);
	}

	void swim(int k) {
		int parent = (k - 1) / 2;
		while (k > 0 && heap.peek(k) < heap.peek(parent)) {
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

			if (right < heap_size && heap.peek(right) < heap.peek(left))
				smallest = right;

			if (left >= heap_size || heap.peek(k) < heap.peek(smallest))
				break;

			std::swap(smallest, k);
			k = smallest;
		}
	}

	T remove_at(int i) {
		if (empty())
			return NULL;

		heap_size--;
		T removed_data = heap.peek(i);
		swap(i, heap_size);

		heap.set(heap_size, NULL);
		map.remove_key(heap_size);

		if (i == heap_size)
			return removed_data;
		T elem = heap.peek(i);

		sink(i);

		if (heap.peek(i) == elem)
			swim(i);
		return removed_data;
	}

	T neg(T elem);
public:
	heap() {
		heap_capacity = 0;
		heap_size = 0;
		heap.clear();
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
		heap.clear();
		heap_size = 0;
		map.clear();
	}

	T peek() {
		T tmp = heap.peek();
		if (!min_heap)
			tmp = tmp.neg();
		return tmp;
	}

	T remove_root() {
		return remove_at(0);
	}

	bool contains(T elem) {
		if (elem == NULL) return false;
		return map.contains(elem);
	}

	void insert(T elem) {
		if (elem == NULL)
			return;
		if (!min_heap)
			elem = elem.neg();
		if (heap_size < heap_capacity)
			heap.set(heap_size, elem);
		else {
			heap.insert_tail(elem);
			heap_capacity++;
		}
		map.insert(heap_size, elem);
		swim(heap_size);
		heap_size++;
	}

	bool remove(T element) {
		if (element == NULL)
			return false;
		int index = map.peek(elem);
		if (index != NULL)
			remove_at(index);
		return index != null;
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

template<typename K, typename V>
class hashTable {
private:
	//Constants
	const K tomb_stone = new K;
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
		used_buckets = 0;
		key_count = 0;
		contains_flag = false;
		modificaton_count = 0;
	}

	hashTable(int cap) {
		capacity = cap;
		used_buckets = 0;
		key_count = 0;
		contains_flag = false;
		modificaton_count = 0;
	}

	hashTable(int cap, double load) {
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

		for (int i = 0; i < capacity; i++) {
			key_table[i] = NULL;
			value_table[i] = NULL;
		}
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
						value_table = val;
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

	std::list<K> keys() {
		std::list<K> keys = new std::list<K>(size());
		for (int i = 0; i < capacity; i++)
			if (key_table[i] != NULL && key_table[i] != tomb_stone)
				keys.push_back(key_table[i]);
		return keys;
	}

	std::list<V> values() {
		std::list<V> values = new std::list<K>(size());
		for (int i = 0; i < capacity; i++)
			if (key_table[i] != NULL && key_table[i] != tomb_stone)
				values.push_back(value_table[i]);
		return values;
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
		for (int i = 0; i < old_key_table.length; i++) {
			if (old_key_table[i] != NULL && old_key_table[i] != tomb_stone)
				insert(old_key_table[i], old_value_table[i]);
			old_value_table[i] = NULL;
			old_key_table[i] = NULL;
		}
		delete[] old_key_table;
		delete[] old_value_table;
	}
};

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

/*
int main() {
	doublyLinkedList<int> a;
	a.insert_head(29);
	a.insert_tail(83);
	a.insert_at(1, 94);
	std::cout << a.peek(2);
	a.print();
}
*/