#ifndef _SERVER_H
#define _SERVER_H

#include "decls.h"
#include "files.h"
#include "kv.h"
#include "map.h"
#include "ops.h"

void serverLoop(int connfd);
void startServer();

#endif