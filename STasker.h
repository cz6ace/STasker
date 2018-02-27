// ensure this library description is only included once
#ifndef Tasker_h
#define Tasker_h

#include <stddef.h>

/** millis() */
#include <Arduino.h>

struct scheduler_t {
  unsigned long last;
  unsigned long period;
  void (*task)() ;
  scheduler_t* next;
};

class Tasker
{
  // user-accessible "public" interface
  public:
  
  Tasker();
  
  void addTask(void (*task)(), unsigned long period);

  void addTask(void (*task)(), unsigned long period, unsigned long last);

  void runTasks();
    
  // library-accessible "private" interface
  private:
  
  scheduler_t *tFirst = NULL;
  scheduler_t *tLast = NULL;
  scheduler_t *tCurrent = NULL;

  void addTask(scheduler_t* taskPtr);
    
};

#endif
