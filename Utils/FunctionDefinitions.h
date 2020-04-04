#ifndef SPACEINVADERS_FUNCTIONDEFINITIONS_H
#define SPACEINVADERS_FUNCTIONDEFINITIONS_H

    typedef void (*CallbackFunction) (void*);

    typedef struct{
        CallbackFunction func;
        unsigned long tick;
        void* listener;
        unsigned long id;
    } TimerCallbackObject;

    typedef struct {
        CallbackFunction func;
        void* listener;
    } CallbackObject;


#endif
