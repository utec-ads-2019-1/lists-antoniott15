#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"
#include <iostream>
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
            throw out_of_range("List empty, no front exists.");
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
            throw out_of_range("List empty, no tail exists.");
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
            NewData->data = value;
            NewData->next = nullptr;
            head = NewData;
            tail = NewData;
        }
        else
        {
            NewData->next = NULL;
            NewData->data = value;
            tail->next = NewData;
            tail = NewData;
        }
        countingElements++;
    }

    void pop_front()
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
                Node<T> *temp = head->next;
                delete head;
                head = nullptr;
                head = temp;
            }
            countingElements--;
        }
        else
        {
            cout << "invalid";
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
            cout << "invalid";
        }
    }

    T operator[](int index)
    {
        Node<T> *temp = head;

        for (int i = 0; i < index; ++i)
        {
            if (temp->next == nullptr)
            {
                cout << "invalid";
            }
            temp->next = temp;
        }
        return temp->data;
    }

    bool empty()
    {
        return head == NULL ? true : false;
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
            cout << "list empty";
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
            cout << "list empyty";
        }
        return head;
    };
    BidirectionalIterator<T> end()
    {
        if (empty())
        {
            cout << "list empyty";
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