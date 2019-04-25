#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T>
{
private:
    Node<T> *head;
    Node<T> *tail;
    int node;

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
        if (empty())
        {
            NewData->data = value;
            NewData->next = nullptr;
            head = NewData;
            tail = NewData;
        }
        else
        {
            NewData->data = value;
            NewData->next = head;
            head = NewData;
        }
    }

    void push_back(T value)
    {
        Node<T> *NewData = new Node<T>;
        NewData->data = value;
        NewData->next = nullptr;
        NewData->prev = nullptr;

        if (head == nullptr)
        {
            head = NewData;
            if (tail == nullptr)
            {
                tail = head;
            }
        }
        else
            tail->prev = NewData;
    }

    void pop_front()
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
    }

    void pop_back()
    {
        if (empty())
        {
            cout << "empty list" << endl;
        }
        else
        {
            Node<T> *nodeToDelete = tail;
            tail = tail->prev;

            if (tail)
            {
                tail->next = nullptr;
            }
            else
            {
                head = nullptr;
            }

            delete nodeToDelete;
        }
    }

    T operator[](int index)
    {
        Node<T> *temp;
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
        Node<T> *temp;
        temp = head;
        int count;
        if (empty())
        {
            count = 0;
            while (temp->next != nullptr)
            {
                count++;
            }
        }
        return count;
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
        return "Forward List";
    }

    ForwardIterator<T> begin()
    {
        if (empty())
        {
            cout << "list empyty";
        }
        return head;
    };

    ForwardIterator<T> end()
    {
        if (empty())
        {
            cout << "list empyty";
        }
        return tail;
    };

    void merge(ForwardList<T> list)
    {
        if (empty())
        {
            head = list.head;
            tail = list.tail;
        }
        else if (!list.empty())
        {
            tail->next = list.head;
            tail = list.tail;
        }
    }
};

#endif