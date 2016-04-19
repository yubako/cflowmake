#ifndef CYTYPES_CYFLOW_QUEUE_H
#define CYTYPES_CYFLOW_QUEUE_H

#include <sys/types.h>
#include <exception>

template <typename T>
class CyFlowQueue 
{
    private:
        T&             _data;
        size_t         _size;
        size_t         _tail;

    public:
        CyFlowQueue(size_t size);
        ~CyFlowQueue();

        void            push(T& t);
        T&              get(size_t pos);
        size_t          size();
        CyFlowQueue*    copy();
};

class CyFlowQueueOverException : public std::exception { };


#include "CyFlowQueue_impl.h"
#endif

