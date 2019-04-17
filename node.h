#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
    Node<T> *prev;

    void killSelf();
};
template <typename T>
void killSelf()
{
    next = true ? next->killSelf : prev->killSelf;
    delete this;
}
#endif