#ifndef __COMMANDER_HPP__
#define __COMMANDER_HPP__

namespace game {
  template <typename T> class Command {
    public:
      ~Command() {}
      virtual void execute(T&) = 0;
  };
}

#endif // __COMMANDER_HPP__
