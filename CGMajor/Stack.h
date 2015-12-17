#pragma once

#ifndef STACK_H
#define STACK_H

const int STACK_SIZE = 10;

template<typename T>
class Stack
{
public:
	Stack();

	bool push(T data);
	bool pop(T& out);
	bool is_empty();

private:
    T stack[STACK_SIZE];
    int head;
};

template<typename T>
inline Stack<T>::Stack()
{
    //Initialization
    head = 0;
}

template<typename T>
inline bool Stack<T>::push(T data)
{
    if(head == STACK_SIZE)
	{
		return false;
	}

    stack[head] = data;
    head++;

	return true;
}

template<typename T>
inline bool Stack<T>::pop(T& out)
{
    if(head == 0)
	{
		return false;
	}

    out = stack[head - 1];

    head--;

	return true;
}

template<typename T>
inline bool Stack<T>::is_empty()
{
    return (head == 0);
}

#endif
