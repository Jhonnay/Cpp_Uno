#ifndef CRINGBUFFER_H
#define CRINGBUFFER_H

#include <iostream>
#include <vector>

template <typename T>
class CRingBuffer {
public:
    CRingBuffer(size_t capacity);
    void Push(const T& value);
    T Pop();
    size_t GetSize() const;
    T GetCurrentElement() const;
    T GetNextElement() const;
    T GetPreviousElement() const;

private:
    size_t m_nCapacity;
    std::vector<T> m_arrBuffer;
    size_t m_nHead;
    size_t m_nTail;
    size_t m_nSize;
};

#endif // CRINGBUFFER_H
