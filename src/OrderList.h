#ifndef ORDER_LIST_H
#define ORDER_LIST_H

#include "Defines.h"

namespace AlgoSE
{

class OrderListImpl;

class OrderList
{
public:
    OrderList();
    OrderList(const OrderList& other);
    ~OrderList();
    OrderList &operator=(const OrderList& other);
    void push_back(const Order& order);
    void clear();
    int size() const;
    const Order& operator[](int idx) const;

    OrderListImpl& getImplementor() const;

private:
    OrderListImpl* m_implementor;
};

} // namespace AlgoSE

#endif // ORDER_LIST_H