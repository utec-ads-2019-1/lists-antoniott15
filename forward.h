#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T>
{
public:
    ForwardList() : List<T>() {}

    T front()
    {
        return head->data;
    }

    T back()
    {
        return tail->data;
    }

    void push_front(T value)
    {
        Node<T> *NewData = new Node<T>;
        if (!empty())
        {
            NewData->next = head;
            NewData->data = value;
            head = NewData;
        }
        else
        {
            NewData->data = value;
            NewData->next = nullptr;
            head = NewData;
            tail = NewData;
        }
    }

    void push_back(T value)
    {
        Node<T> *NewData = new Node<T>;
        if (!empty())
        {
            NewData->next = tail;
            NewData->data = value;
            tail->next = NewData;
            tail = NewData;
        }
        else
        {
            NewData->data = value;
            NewData->next = nullptr;
            tail = NewData;
            head = NewData;
        }
    }

    void pop_front()
    {
    }

    void pop_back()
    {
        // TODO
    }

    T operator[](int index)
    {
        // TODO
    }

    bool empty()
    {
        // TODO
    }

    int size()
    {
        // TODO
    }

    void clear()
    {
        // TODO
    }

    void sort()
    {
        // TODO
    }

    void reverse()
    {
        // TODO
    }

    string name()
    {
        return "Forward List";
    }

    ForwardIterator<T> begin()
    {
        // TODO
    }

    ForwardIterator<T> end()
    {
        // TODO
    }

    void merge(ForwardList<T> list)
    {
        // TODO
    }
};

#endif