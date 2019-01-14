/***********************
 * Program Name: Circular Linked List
 * Author: Michael Ton
 * Date: 11/18/18
 * Description: Source file for Queue class. Contains definitions for the functions that manage the queue.
 ***********************/

#include "queue.hpp"
#include "utility.hpp"
#include <iostream>

Queue::Queue() //constructor
{
	head = nullptr;
}

Queue::~Queue() //destructor; is different form removeFront() in that "tail" does not need to be accounted for since it will be deleted in destructor eventually
{
	while(!isEmpty()) //loop runs until queue is empty
	{
		if(head->prev == head) //if only one node remains
		{
			delete head; //clear final node
			head = nullptr; //set head to nullptr
		}
		else //if there is more than node
		{
			Node* temp = head; 
			head = head->next; //set next node from front as new head
			head->prev = temp->prev; //re-assign pointer to "tail"
			delete temp; //delete temp
		}
	}
}

bool Queue::isEmpty() const //check if queue is empty
{
	if(head == nullptr) //if head is nullptr, queue is empty; return true
	{
		return true;
	}
	else //otherwise, return false
	{
		return false;
	}
}

void Queue::addBack(int val) //adds node with user-input value to back of queue 
{
	if(isEmpty()) //if queue is empty, set new node as head
	{
		head = new Node(val); //set new node as head
		head->next = head;  //ensure queue is circular
		head->prev = head; //ensure queue is circular
	}
	else //if there are other nodes in queue
	{
		Node* tail = head->prev; //initialize a Node pointer to the end of queue
		Node* temp = new Node(val); //initailize new Node
		temp->prev = tail; //set temp as new "tail"
		temp->next = head; //set temp as new "tail:
		tail->next = temp; //set previous "tail" to be second from back
		tail = temp; //set temp as back of queue
		head->prev = tail; //set head and tail to be circular
	}
}

int Queue::getFront() //returns value of node in front; returns -1 if there are no nodes in the queue
{
	if(isEmpty()) //return -1 if queue is empty
	{
		return -1;
	}
	else //if not empty, return value contained by head
	{
		return head->val;
	}
}

void Queue::removeFront() //deletes node in front of queue
{
	if(isEmpty())
	{
		std::cout << "Nothing in the queue to delete." << std::endl;
	}
	else if(!isEmpty() && head->prev == head) //if queue is not empty and contains one node, delete it
	{
		delete head; 
		head = nullptr;
	}
	else //if there is more than one node, remove front of queue by establishing new head of queue
	{
		Node* temp = head; //set new Node pointer to current head
		Node* tail = head->prev; //set new Node pointer to current tail
		tail->next = head->next; //set current back of queue to be circular with second node from front (will be new head)
		head = head->next; //set second from front as new head
		head->prev = tail; //set new head's pointer to "tail" to ensure circular list
		delete temp; //delete temp
	}
}

void Queue::printQueue() //display current queue to user
{
	Node *readNode = head;

	if(isEmpty()) //notify user if there is nothing to print
	{
		std::cout << "Nothing in the queue to print." << std::endl;
	}
	else //if there are nodes in the queue, print starting at the head and traverse using next pointers to print next value
	{
		std::cout << "Your queue is: ";

		do	
		{
			std::cout << readNode->val << " ";
			readNode = readNode->next;

		} while(readNode != head); //stop printing once tail is reached, represented by final node's next pointer which points back to the head of queue

		std::cout << std::endl;
	}
}
