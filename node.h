#ifndef NODE_H
#define NODE_H
template <class T>
class Node
{
    friend class Linklist;
private:
    T account;
    Node * nextAccount;
    Node * previousAccount;
public:
    Node(){
        nextAccount = nullptr;
        previousAccount = nullptr;
    }
};

#endif // NODE_H
