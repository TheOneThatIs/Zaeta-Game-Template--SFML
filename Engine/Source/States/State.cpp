#include"States\State.h"

State::State(){

}


State::~State(){

}

void State::setManager (StateManager *manager_pointer) {
	manager = manager_pointer;
}