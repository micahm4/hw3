#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
  bool operator()(const Event* f, const Event* s) const {
    return f->time < s->time;
  }
} EventLess;
	
#endif
