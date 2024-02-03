#include "CRingBuffer.h"

template <typename T>
CRingBuffer<T>::CRingBuffer(size_t capacity) : m_nCapacity(capacity), m_arrBuffer(capacity), m_nHead(0), m_nTail(0), m_nSize(0) {}

template <typename T>
void CRingBuffer<T>::Push(const T& value) {
    if (m_nSize == m_nCapacity) {
        // Buffer is full, overwrite the oldest element
        Pop();
    }

    m_arrBuffer[m_nHead] = value;
    m_nHead = (m_nHead + 1) % m_nCapacity;
    m_nSize++;
}

template <typename T>
T CRingBuffer<T>::Pop() {
    if (m_nSize == 0) {
        // Buffer is empty
        throw std::out_of_range("Buffer is empty");
    }

    T value = m_arrBuffer[m_nTail];
    m_nTail = (m_nTail + 1) % m_nCapacity;
    m_nSize--;

    return value;
}

template <typename T>
size_t CRingBuffer<T>::GetSize() const {
    return m_nSize;
}

template <typename T>
T CRingBuffer<T>::GetCurrentElement() const {
    if (m_nSize == 0) {
        throw std::out_of_range("Buffer is empty");
    }

    return m_arrBuffer[m_nTail];
}

template <typename T>
T CRingBuffer<T>::GetNextElement() const {
    if (m_nSize == 0) {
        throw std::out_of_range("Buffer is empty");
    }

    size_t nextIndex = (m_nTail + 1) % m_nCapacity;
    return m_arrBuffer[nextIndex];
}

template <typename T>
T CRingBuffer<T>::GetPreviousElement() const {
    if (m_nSize == 0) {
        throw std::out_of_range("Buffer is empty");
    }

    size_t previousIndex = (m_nTail == 0) ? m_nCapacity - 1 : m_nTail - 1;
    return m_arrBuffer[previousIndex];
}
