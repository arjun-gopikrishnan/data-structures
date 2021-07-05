#ifndef QNODE_H
#define QNODE_H
template <typename DataType>
class QNode{
    public:
        DataType data;
        QNode *next;
};

#endif