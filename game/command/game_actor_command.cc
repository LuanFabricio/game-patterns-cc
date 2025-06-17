#include "./game_actor_command.hpp"

namespace game {
  void GameActorMoveCommand::execute(game::GameActor& game_actor, float deltaTime)
  {
    game_actor.move(deltaTime);
    game_actor.direction.x = 0;
    game_actor.direction.y = 0;
    game_actor.direction.z = 0;
    game_actor.hb.position = game_actor.position;
  }

  void GameActorRotateCommand::execute(game::GameActor& game_actor, float deltaTime)
  {
    game_actor.rotate(this->angle);
  }

  void GameActorSetDirectionCommand::execute(game::GameActor& game_actor, float deltaTime)
  {
    printf("Axis: %i\n", _axis);
    switch (_axis) {
      case axis_e::AXIS_X:
        game_actor.direction.x = _value;
        break;
      case axis_e::AXIS_Y:
        game_actor.direction.y = _value;
        break;
      case axis_e::AXIS_Z:
        game_actor.direction.z = _value;
        break;
      default:
        return;
    }

    game_actor.direction.normalize();
  }
};
