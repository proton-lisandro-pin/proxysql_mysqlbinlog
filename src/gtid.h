#ifndef GTID_H
#define GTID_H

#include "Slave.h"


std::string gtid_to_string(slave::Position const &curpos);

#endif // GTID_H