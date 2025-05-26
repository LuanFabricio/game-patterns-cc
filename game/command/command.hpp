#ifndef __COMMANDER_HPP__
#define __COMMANDER_HPP__

namespace game {
  template <typename T, typename R=void> class Command {
    public:
      ~Command() {}
      virtual R execute(T&, float deltaTime) = 0;
  };
}

#endif // __COMMANDER_HPP__
