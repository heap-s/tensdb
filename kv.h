#ifndef _KV_H
#define _KV_H

#include "files.h"
#include "map.h"
#include "ops.h"

bool checkDirExists(const char* dirname);
bool checkFileExists(const char* file);
void createDb(char* name);
void writeKV(char* file, HashMap* map);

#endif
