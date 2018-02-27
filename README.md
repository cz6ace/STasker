# Usage example

```cpp
/** tasker */
#include <STasker.h>
Tasker tasker;

/**
 * some task
 */
void task1() {
  digitalWrite(BUILTIN_LED, LOW);
  //...
  digitalWrite(BUILTIN_LED, HIGH);
}

/**
 * Main setup
 */
void setup() {
  tasker.addTask(&task1, 60000L, 100UL);
}

/**
 * Main loop
 */
void loop() {
  // put your main code here, to run repeatedly:
  tasker.runTasks();
}
```