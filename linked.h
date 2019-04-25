#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T>
{
private:
    Node<T> *head;
    Node<T> *tail;
    int node;

public:
    LinkedList() : List<T>() {}

    T front()
    {
        return head->data;
    }

    T back()
    {
        return head->prev->data;
    }

    void push_front(T value)
    {
        Node<T> *NewData = new Node<T>;
        NewData->data = value;
        if (empty())
        {
            NewData->next = nullptr;
            NewData->prev = nullptr;
            head = NewData;
            tail = NewData;
        }
        else
        {
            head->prev = NewData;
            NewData->next = head;
            head = NewData;
        }
    }

    void push_back(T value)
    {
        Node<T> *NewData = new Node<T>;
        NewData->data = value;

        if (empty())
        {
            NewData->next = nullptr;
            NewData->prev = nullptr;
            head = NewData;
            tail = NewData;
        }
        else
        {
            if (tail != nullptr)
                tail->next = NewData;
            NewData->next = nullptr;
            NewData->prev = tail;
            tail = NewData;
        }
    }

    void pop_front()
    {
        if (!empty())
        {
            Node<T> *nodeToDelete = head;
            head = head->next;

            if (head)
            {
                head->next = nullptr;
            }
            else
            {
                head = nullptr;
            }

            delete nodeToDelete;
        }
        else
        {
            cout << "empty list" << endl;
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
        }
    }

    T operator[](int index)
    {
        Node<T> *temp = head;
        for (int i = 0; i <= index; i++)
        {
            if (temp->next == nullptr)
            {
                cout << "not more values";
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
        int count;
        if (empty())
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