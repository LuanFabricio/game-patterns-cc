#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <cstdint>
#include <cstdio>
#include <cstdlib>
namespace game{
  template <typename T> struct Buffer{
    public:
      T* buffer;

      Buffer(uint32_t capacity):
        buffer((T*)malloc(sizeof(T) * capacity)),
        _capacity(capacity),
        _size(0) { }

      uint32_t getSize()
      {
        return this->_size;
      }

      uint32_t getCapacity()
      {
        return this->_capacity;
      }

      void append(T item)
      {
        const uint32_t newSize = this->_size + 1;
        if (this->_capacity > newSize) {
          this->buffer[this->_size] = item;
          this->_size = newSize;
        }
      }

      void clear()
      {
        this->_size = 0;
      }

    private:
      uint32_t _capacity;
      uint32_t _size;
  };
}

#endif // __BUFFER_H__
