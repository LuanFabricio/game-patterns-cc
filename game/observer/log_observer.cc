#include "log_obsever.hpp"
#include <cstdio>

void game::LogObserver::update(char* data) {
  FILE* out;
  std::string prefix;
  switch(this->_logLevel) {
    case game::LogLevel::INFO: {
      prefix = "INFO";
      out = stdout;
    } break;

    case game::LogLevel::WARNING: {
      prefix = "WARNING";
      out = stderr;
    } break;

    case game::LogLevel::ERROR: {
      prefix = "ERROR";
      out = stderr;
    } break;
  }

  fprintf(out, "%s: %s\n", prefix.data(), data);

  this->notifyNext(data);
}
