/***********************
 * Program Name: Circular Linked List
 * Author: Michael Ton
 * Date: 11/10/18
 * Description: Main file for Circular Linked List lab.  Creates and displays menu to user, allowing them to add and delete from the queue as well as see the current state of the queue.  This main file contains similar code to my own main.cpp from Lab 6 - Doubly Linked List, as they accomplish nearly the same thing in terms of menu function and input validation.
 ***********************/

#include "utility.hpp"
#include "menu.hpp"
#include "queue.hpp"
#include <iostream>

int main()
{
	Menu menu;
	Queue queue;
	int choice;
	bool quit = false;
	
	std::cout << "Welcome to my queue!" << std::endl;

	menu.addString("\nChoose from the following options:\n");
	menu.addString("1. Enter a value to be added to the back of queue;");
	menu.addString("2. Display first node (front) value");
	menu.addString("3. Remove first node (front) value");
	menu.addString("4. Display the queue contents");
	menu.addString("5. Exit.\n");

	do //show menu to user and receive input, calling functions based on input
	{	
		menu.display();
		choice = getInteger(1, 5);
	
		std::cout << std::endl;

		switch(choice)
		{
			case 1:
				std::cout << "Please enter a positive integer:\n" << std::endl;
				queue.addBack(getInteger());
				break;
			case 2:
				if(queue.getFront() == -1) //if there are no nodes, tell user there are no nodes to print
				{
					std::cout << "There is no node to print the value of." << std::endl;
				}
				else
				{
					std::cout << "The first node value is: " << queue.getFront() << std::endl;
				}
				break;
			case 3:
				queue.removeFront();
				break;
			case 4:
				queue.printQueue();
				break;
			case 5:
				std::cout << "Good-bye!" << std::endl;
				quit = true;
				break;
		}
	} while(!quit);

	return 0;
}
