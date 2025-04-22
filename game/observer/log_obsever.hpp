#ifndef __OBSERVER_LOG_LEVEL_HPP__
#define __OBSERVER_LOG_LEVEL_HPP__

#include <string>

#include "observer.hpp"

namespace game {
  enum LogLevel {
    INFO,
    WARNING,
    ERROR
  };

  struct LogObserver : public game::Observer<char*> {
    LogObserver(game::LogLevel logLevel)
      : game::Observer<char*>(),
        _logLevel(logLevel) {}

    virtual void update(char* data);

    private:
      game::LogLevel _logLevel;
  };

};

#endif // __OBSERVER_LOG_LEVEL_HPP__
