#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"
#include <iostream>
#include <stdexcept>

using namespace std;
template <typename T>
class LinkedList : public List<T>
{
private:
    Node<T> *head;
    Node<T> *tail;
    int node;
    int countingElements = 0;

public:
    LinkedList() : List<T>() {}

    T front()
    {
        if (head != nullptr)
        {
            return head->data;
        }
        else
        {
            throw out_of_range("Invalid");
        }
    }

    T back()
    {
        if (tail != nullptr)
        {
            return head->prev->data;
        }
        else
        {
            throw out_of_range("Invalid");
        }
    }

    void push_front(T value)
    {
        Node<T> *NewData = new Node<T>;
        if (empty())
        {
            NewData->data = value;
            NewData->next = nullptr;
            head = NewData;
            tail = NewData;
        }
        else
        {
            NewData->next = head;
            NewData->data = value;
            head = NewData;
        }
        countingElements++;
    }

    void push_back(T value)
    {
        Node<T> *NewData = new Node<T>;
        if (empty())
        {
            head = NewData;
            tail = NewData;
        }
        else
        {
            this->tail->next = NewData;
            NewData->prev = this->tail;
            this->tail = NewData;
        }
        countingElements++;
    }

    void pop_front()
    {
        if (!empty())
        {
            if (head->next == nullptr)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                Node<T> *temp = head->next;
                delete head;
                head = nullptr;
                head = temp;
            }
            countingElements--;
        }
    }

    void pop_back()
    {
        if (empty())
        {
            if (head->next == nullptr)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                Node<T> *temp = head;
                while (temp->next != tail)
                {
                    temp = temp->next;
                }

                delete tail;
                tail = temp;
                tail->next = nullptr;
            }
            countingElements--;
        }
        else
        {
            throw out_of_range("Invalid.");
        }
    }

    T operator[](int index)
    {
        Node<T> *temp;
        temp = head;
        for (int i = 0; i < index; ++i)
        {
            if (temp->next == nullptr)
            {
                throw out_of_range("Invalid");
            }
            temp->next = temp;
        }
        return temp->data;
    }

    bool empty()
    {
        return countingElements == 0 ? true : false;
    }

    int size()
    {
        return countingElements;
    }

    void clear()
    {
        while (head != nullptr)
        {
            pop_front();
        }
    }

    void sort()
    {
        if (empty())
        {
            throw out_of_range("Invalid");
        }
        else
        {
            Node<T> *i, *j;
            int temp;
            for (i = head; i->next != nullptr; i = i->next)
            {
                for (j = i->next; j != nullptr; j = j->next)
                {
                    if (i->data > j->data)
                    {
                        temp = i->data;
                        i->data = j->data;
                        j->data = temp;
                    }
                }
            }
        }
    }

    void reverse()
    {
        for (int i = size(); i > 0; --i)
        {
            cout << operator[](i - 1) << "\n";
        }
    }

    string name()
    {
        return "Linked List";
    }

    BidirectionalIterator<T> begin()
    {
        if (empty())
        {
            throw out_of_range("Invalid");
        }
        return head;
    };
    BidirectionalIterator<T> end()
    {
        if (empty())
        {
            throw out_of_range("Invalid");
        }
        return tail;
    };

    void merge(LinkedList<T> list)
    {
        if (empty())
        {
            head = list.head;
            tail = list.tail;
        }
        else if (!list.empty())
        {
            tail->next = list.head;
            list.head = head->prev;
            tail = list.tail;
        }
    }
};

#endif