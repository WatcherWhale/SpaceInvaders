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

void EventHandler::mouseMove(int x, int y)
{
    for(auto listener : listeners)
        listener->mouseMove(x, y);
}

void EventHandler::mouseDown(int x, int y)
{
    for(auto listener : listeners)
        listener->mouseDown(x, y);
}

void EventHandler::mouseUp(int x, int y)
{
    for(auto listener : listeners)
        listener->mouseUp(x, y);
}

void EventHandler::clearListeners()
{
    this->listeners.clear();
}