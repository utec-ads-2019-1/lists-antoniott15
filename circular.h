#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <iostream>
#include "list.h"

template <typename T>
class CircularLinkedList : public List<T>
{
private:
    Node<T> *start;

public:
    CircularLinkedList() : List<T>() {}

    T front()
    {
        if (!start)
        {
            throw out_of_range("Invalid");
        }
        else
        {
            return start->data;
        }
    }

    T back()
    {
        if (!start)
        {
            throw out_of_range("Invalid");
        }
        else
        {

            return start->prev->data;
        }
    }

    void push_front(T value)
    {
        Node<T> *temp = new Node<T>;
        temp->data = value;
        if (start)
        {
            temp->next = start;
            temp->prev = start->prev;
            temp->prev->next = temp;
            temp->next->prev = temp;
            start = temp;
        }
        else
        {
            start = temp;
            temp->next = start;
            temp->prev = start;
        }
    }

    void push_back(T value)
    {
        Node<T> *temp = new Node<T>;
        temp->data = value;
        if (start)
        {
            temp->next = start;
            temp->prev = start->prev;
            temp->prev->next = temp;
            temp->next->prev = temp;
        }
        else
        {
            start = temp;
            temp->next = start;
            temp->prev = start;
        }
    }

    void pop_front()
    {
        if (start)
        {
            Node<T> *temp_start;
            start->next->prev = start->prev;
            start->prev->next = start->next;
            temp_start = start->next;
            delete start;

            if (start == temp_start)
            {
                start = nullptr;
                temp_start = nullptr;
            }
            else
            {
                start = temp_start;
                temp_start = nullptr;
            }
        }
        else
        {
            throw out_of_range("Invalid");
        }
    }

    void pop_back()
    {
        if (start)
        {
            if (start == start->prev)
            {
                delete start;
                start = nullptr;
            }
            else
            {
                Node<T> *temp_prev;
                temp_prev = start->prev;

                start->prev->prev->next = start;
                start->prev = start->prev->prev;
                delete temp_prev;
                temp_prev = nullptr;
            }
        }
        else
        {
            cout << "empty list" << endl;
        }
    }

    T operator[](int index)
    {
        if (!start)
        {
            if (index < 1)
            {
                cout << start << endl;
            }
            else
            {
                Node<T> *curr;
                curr = start;
                for (int i = 0; i < index; ++i)
                {
                    curr = curr->next;
                }
                return curr->data;
            }
        }
        else
        {
            cout << "invalid";
        }
    }

    bool empty()
    {
        return (!start);
    }

    int size()
    {
        if (start)
        {
            Node<T> *curr;
            curr = start;
            int count = 0;
            while (curr->next != start->next)
            {
                curr = curr->next;
                count++;
            }
            return count;
        }
        else
        {
            return 0;
        }
    }

    void clear()
    {

        while (start != nullptr)
        {
            pop_front();
        }
    }

    void sort()
    {
        if (start)
        {
            Node<T> *i, *j;
            int temp;
            for (i = start; i->next != nullptr; i = i->next)
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
        else
            throw out_of_range("Invalid");
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
        return "Circular Linked List";
    }

    BidirectionalIterator<T> begin()
    {
        return BidirectionalIterator<T>(start);
    }

    BidirectionalIterator<T> end()
    {
        return BidirectionalIterator<T>(start->prev);
    }

    void merge(CircularLinkedList<T> list)
    {
        BidirectionalIterator<T> tmp = list.begin();
        do
        {
            this->push_back(*tmp);
            ++tmp;
        } while (tmp != list.begin());
    }
};

#endif