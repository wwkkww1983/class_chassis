#ifndef SCHEDULE_H
#define SCHEDULE_H
#include "init.h"
#include "parameter.h"
void updateDeviceStatusThread(void);
bool ping(const char*);
void checkConnectionHealthThread(void);
#endif // SCHEDULE_H
