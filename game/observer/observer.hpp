#ifndef __OBSERVER_HPP__
#define __OBSERVER_HPP__

namespace game {
  template<typename T>  struct Observer {
    Observer* next;

    Observer() {
      this->next = nullptr;
    }
    virtual void update(T data) = 0;

    protected:
      void notifyNext(T data)
      {
        if (this->next) {
          this->next->update(data);
        }
      }
  };
}

#endif // __OBSERVER_HPP__
