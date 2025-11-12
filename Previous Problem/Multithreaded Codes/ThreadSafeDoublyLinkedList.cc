#include<bits/stdc++.h>
using namespace std;

void fastio(bool read = false) 
{
    if(read) 
    {
        #ifndef ONLINE_JUGDE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
        #endif  
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return;
}


template<typename T>
class LinkedList{
private:
	struct Node {
		T data;
		shared_ptr<Node> prev;
		shared_ptr<Node> next;
		mutex node_mtx;
		Node(const T &value)
		{
			data = value;
			prev = nullptr;
			next = nullptr;
		} 
	};
	shared_ptr<Node> head, tail;
public:

	LinkedList() 
	{
		this->head = nullptr;
		this->tail = nullptr;
	}

	void push_back(const T &value)
	{
		auto new_node = std::make_shared<Node>(value);
		if(this->head == nullptr)
		{
			this->head = this->tail = new_node;
			return;
		}
		// now it has aquired the lock at the tail node.
		std::lock_guard<std::mutex> lock(tail->node_mtx);
		this->tail->next = new_node;
		new_node->prev = this->tail;
		this->tail = new_node;
	}

	void push_front(const T &value)
	{	
		auto new_node = std::make_shared<Node>(value);
		if(this->head == nullptr)
		{
			this->head = this->tail = new_node;
			return;
		}
		// now it has aquired the lock at the tail node.
		std::lock_guard<std::mutex> lock(head->node_mtx);
		new_node->next = this->head;
		this->head->prev = new_node;
		this->head = new_node;
	}

	void pop_front() 
	{
		if (!this->head) return;
		// now we know that the list is not empty we can remove.
		std::lock_guard<std::mutex> lock(this->head->node_mtx);
		auto new_node = this->head->next;
		if(new_node)
		{
			std::lock_guard<std::mutex> new_lock(new_node->node_mtx);
			new_node->prev.reset();
		}
		this->head = new_node;
		if (!new_node)
			this->tail.reset();
	}

	void pop_back() 
	{
		if (!this->head) return;
		// now we know that the list is not empty we can remove.
		std::lock_guard<std::mutex> lock(this->tail->node_mtx);
		auto new_node = this->tail->prev;
		if(new_node)
		{
			std::lock_guard<std::mutex> new_lock(new_node->node_mtx);
			new_node->next.reset();
		}
		this->tail = new_node;
		if (!new_node)
			this->head.reset();
	}



	void print_forward() const {
        auto current = head;
        while (current) {
            std::lock_guard<std::mutex> lock(current->node_mtx);
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

};


/*
void pop_front() {
        if (!head) return;

        std::lock_guard<std::mutex> lock(head->node_mtx);
        auto next_node = head->next;
        if (next_node) {
            std::lock_guard<std::mutex> next_lock(next_node->node_mtx);
            next_node->prev.reset();
        }
        head = next_node;
        if (!head) tail.reset();
    }

    void pop_back() {
        if (!tail) return;

        std::lock_guard<std::mutex> lock(tail->node_mtx);
        auto prev_node = tail->prev;
        if (prev_node) {
            std::lock_guard<std::mutex> prev_lock(prev_node->node_mtx);
            prev_node->next.reset();
        }
        tail = prev_node;
        if (!tail) head.reset();
    }
*/

int main()
{
	fastio(true);
	LinkedList<int> *ll = new LinkedList<int>();
	auto inserter = [&ll](int start, bool isStart) {
		for (int i = 0; i < 20; ++i)
		{
			if (isStart) ll->push_front(i+start);
			else ll->push_back(i+start);
			isStart = !isStart;
		}
	};
	
	auto deleteer = [&ll](bool isStart) {
		for (int i = 0; i < 5; ++i)
		{
			if (isStart) ll->pop_front();
			else ll->pop_back();
			isStart = !isStart;
		}
	};

	cout << "Inserting into the list\n";
	ll->push_back(10);
	ll->push_back(30);
	ll->push_front(20);
	ll->push_front(40);
	ll->print_forward();
	int n = 10;
	vector<thread> threads;
	for(int i = 0; i < n; ++i)
	{
		if (i < n/2) threads.push_back(thread(inserter, i*100, true));
		else threads.push_back(thread(deleteer, true));
	}

	for(int i = 0; i < n; ++i)
	{
		threads[i].join();
		cout << "State After Joining the " << i << "th thread\n";
		ll->print_forward();
	}

	ll->print_forward();

	return 0;
}

/*

Sample Input:


Sample Output:


*/
