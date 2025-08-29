#include <cstddef>
template<typename T>
class queue{
	T *arr;
	int cs,ms,front,rear;
public:
	//  constructor to initialize the queue object.
	queue(const int defaultSize=7){
		this->ms = defaultSize;
		this->cs = 0;
		this->front = 0;
		this->rear = defaultSize-1;
		this->arr = new T[this->ms]();
	}
	//  bool isEmpty checks if the queue is empty or not.
	bool isEmpty(){
		return this->cs==0;
	}
	//  bool isFull to check if the queue is full or not.
	bool isFull(){
		return this->cs == this->ms;
	} 
	// enqueue insert the data into the queue.
	void enqueue(const T data){
		if(!this->isFull()){
			this->rear = (this->rear+1)%this->ms;
			this->arr[this->rear] = data;
			this->cs+=1;
		}
	} 
	void dequeue(){
		if(!this->isFull()){
			this->front = (this->front+1)%this->ms;
			this->cs-=1;
		}	
	}
	T* getFront(){
		if(!isEmpty()){
			return &this->arr[this->front];
		}
		return NULL;
	}
	int getSize(){
		return this->cs;
	}
};