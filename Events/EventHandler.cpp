#include "EventHandler.h"
using namespace SpaceInvaders::Events;

EventHandler::~EventHandler()
{
    this->listeners.clear();
}

void EventHandler::addListener(EventListener* listener)
{
    this->listeners.push_back(listener);
}

void EventHandler::onKeyDown(Key key)
{
    for(auto listener : listeners)
        listener->onKeyDown(key);
}

void EventHandler::onKeyUp(Key key)
{
    for(auto listener : listeners)
        listener->onKeyUp(key);
}