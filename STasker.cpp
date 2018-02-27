#include "STasker.h"

Tasker::Tasker(void) {
}

/**
 * Executes planned tasks
 */
void Tasker::runTasks() {
  unsigned long m = millis();
  if (tCurrent == NULL) {
    tCurrent = tFirst;
	}
  if (tCurrent) {
    if ((unsigned long)(m - tCurrent->last) >= tCurrent->period) {
      tCurrent->last = m;
      tCurrent->task();
    }
    tCurrent = tCurrent->next; 
	}
}

void Tasker::addTask(scheduler_t* taskPtr) {
  if (!tFirst) {
	  tFirst = taskPtr;
	}
  if (tLast) {
	  tLast->next = taskPtr;
  }
	tLast = taskPtr; 
}

void Tasker::addTask(void (*task)(), unsigned long period) {
  addTask(task, period, 0L);
}

void Tasker::addTask(void (*task)(), unsigned long period, unsigned long last) {
  scheduler_t* taskPtr = new scheduler_t;
	taskPtr->last = last;
	taskPtr->task = task; 
	taskPtr->period = period;
  taskPtr->next = NULL;
  addTask(taskPtr);
}


/* eof */
