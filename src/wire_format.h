#ifndef WIRE_FORMAT_H
#define WIRE_FORMAT_H

#include <string>

#include "Slave.h"

std::string wiremsg_st(slave::Position const &curpos);
std::string wiremsg_i1(std::string const uuid, uint64_t const trx_id);
std::string wiremsg_i2(uint64_t const trx_id);

#endif // WIRE_FORMAT_H