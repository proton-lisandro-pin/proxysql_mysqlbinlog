#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdlib.h>
#include <stdint.h>


// Global CLI arguments

char         *arg_errorlog = NULL;
bool         arg_foreground = false;
unsigned int arg_listen_port = 0;
size_t       arg_max_netbuflen = 0;
uint64_t     arg_update_freq_ms = 0;


#endif // GLOBALS_H
