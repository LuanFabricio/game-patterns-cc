#ifndef __COMMANDER_GAME_ACTOR_HPP__
#define __COMMANDER_GAME_ACTOR_HPP__

#include "command.hpp"
#include "../game_actor.hpp"
#include "../utils.hpp"

#define GameActorCommand Command<GameActor>

namespace game {

  struct GameActorMoveCommand : public Command<GameActor> {
    public:
      virtual void execute(game::GameActor& game_actor, float deltaTime);
  };

  struct GameActorRotateCommand : public Command<GameActor> {
    GameActorRotateCommand(float _angle = 16.f) : angle(_angle) {}
    virtual void execute(game::GameActor& game_actor, float deltaTime);
    private:
      float angle;
  };

  struct GameActorSetDirectionCommand : public GameActorCommand
  {
    GameActorSetDirectionCommand(float value, axis_e axis) :
      _value(value), _axis(axis) {}
    virtual void execute(game::GameActor& game_actor, float deltaTime);

    private:
    float _value;
    axis_e _axis;
  };
}

#endif // __COMMANDER_GAME_ACTOR_HPP__
