#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename Predicate>
class PriorityQueue
{
public:
	void push(const T& data)
	{
		_heap.push_back(data);

		int now = static_cast<int>(_heap.size()) - 1;

		while (now > 0)
		{
			int next = (now - 1) / 2;
			/*if (_heap[now] < _heap[next])
				break;*/
			if (_predicate(_heap[now], _heap[next]))
				break;

			::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	void pop()
	{
		_heap[0] = _heap.back();
		_heap.pop_back();

		int now = 0;

		while (true)
		{
			int left = (now * 2) + 1;
			int right = (now * 2) + 2;

			int next = now;

			/*if (_heap[next] < _heap[left])
				next = left;*/
			if (_predicate(_heap[next], _heap[left]))
				break;
			
			/*if (right < _heap.size() && _heap[next] < _heap[right])
				next = right;*/
			if (right < _heap.size() && _predicate(_heap[next], _heap[right]))
				next = right;

			if (next == now)
				break;

			::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	T& top()
	{
		return _heap[0];
	}

	void empty()
	{
		return _heap.empty();
	}

private:
	vector<T> _heap;
	Predicate _predicate;
};

int main()
{
	vector<int> v;
	//PriorityQueue<int, less<int>> pq;
	PriorityQueue<int, greater<int>> pq;

	pq.push(10);
	pq.push(40);
	pq.push(30);
	pq.push(50);
	pq.push(20);

	int value = pq.top();
	pq.pop();
}