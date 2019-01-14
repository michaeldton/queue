/***********************
 * Program Name: Circular Linked List
 * Author: Michael Ton
 * Date: 11/10/18
 * Description: Header file for Queue class. Contains struct called QueueNode which represents each node, containing pointers to the next and previous nodes, and the value contained by the node
 ***********************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue
{	
	private:
		struct Node  //struct
		{
			Node* next;
			Node* prev;
			int val;

			Node(int val)
			{
				next = nullptr;
				prev = nullptr;
				this->val = val;
			}
		};

		Node* head; //pointer to head of queue
		
	public:
		Queue();
		~Queue();
	
		bool isEmpty() const; //checks if queue is empty
		void addBack(int); //takes input integer, creates QueueNode and adds to back of list
		int getFront(); //returns value of node at front
		void removeFront(); //removes front and frees memory
		void printQueue(); //traverse queue starting at head, using next pointers and print value of each QueueNode in queue
};
#endif
