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
        if (empty())
        {
            if (head->next == nullptr)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                Node *temp = head->next;
                delete head;
                head = nullptr;
                head = temp;
            }
        }
    }

    void pop_back()
    {
        if (empty())
        {
            if (head->next = nullptr)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                Node *temp = head;
                while (temp->next = !tail)
                {
                    temp = temp->next;
                }

                delete tail;
                tail = temp;
                tail->next = nullptr;
            }
        }
    }

    T operator[](int index)
    {
        Node *temp;
        temp = head;
        for (int i = 0; i <= index; i++)
        {
            if (temp->next == nullptr)
            {
                throw;
            }
            temp->next = temp;
        }
        cout << temp << "\n";
    }

    bool empty()
    {
        return head == NULL ? true : false;
    }

    int size()
    {
        if (!empty())
        {
            int count = 0;
            while (temp->next != nullptr)
            {
                count++;
            }
        }
        return count;
    }

    void clear()
    {
        Node *temp;
        temp = tail;
        for (int i = 0; i <= size(); i++)
        {
            temp->next = temp;
            delete temp;
        }
    }

    void sort()
    {
        Node *temp;
        temp = tail;
        for (int i = 0; i <= size(); i++)
        {
            
        }
    }

    void reverse()
    {
        for (int i = size(); i > 0; --i)
        {
            coutt << operator[i - 1] << "\n";
        }
    }

    string name()
    {
        return "Forward List";
    }

    ForwardIterator<T> begin();

    ForwardIterator<T> end();

    void merge(ForwardList<T> list)
    {
        if (empty())
        {
            head = list->head;
            tail = list->tail;
        }
        else if (!list.empty())
        {
            tail->next = list->head;
            tail = list->tail;
        }
    }
};

#endif