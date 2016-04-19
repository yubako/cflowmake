#ifndef CYTYPES_CYFLOW_QUEUE_IMPL_H
#define CYTYPES_CYFLOW_QUEUE_IMPL_H

// --------------------------------------------------------------
template <typename T>
CyFlowQueue<T>::CyFlowQueue(size_t size)
{
    this->_data = new T&[size];
    this->_size = size;
    this->_tail = 0;
}

template <typename T>
CyFlowQueue<T>::~CyFlowQueue()
{
    unsigned int i;
    //for ( i = 0; i < this->_tail; i++ )
    //{
    //    delete this->_data[i];
    //}

    delete[] this->_data;
}

template <typename T> 
void CyFlowQueue<T>::push(T& t)
{
    if ( this->_tail < this->_size )
    {
        this->_data[this->_tail++] = t;
        return;
    }
    throw CyFlowQueueOverException();
}

template <typename T> 
T&  CyFlowQueue<T>::get(size_t pos)
{
    return this->_data[pos];
}

template <typename T> 
size_t CyFlowQueue<T>::size() 
{
    return this->_tail;
}

template <typename T>
CyFlowQueue* CyFLowQueue<T>::copy()
{
    unsigned int i;
    CyFlowQueue* nque = new CyFlowQueue(this->_size);
    for ( i = 0; i < this->_size; i++ )
    {
        nque->_data[i] = this->_data[i];
    }

    return nque;
}


#endif
