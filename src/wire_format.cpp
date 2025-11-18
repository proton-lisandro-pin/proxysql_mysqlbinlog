#include <string>

#include "Slave.h"

#include "gtid.h"
#include "wire_format.h"

/*
 * The wire format for the binlogreader is defined server side in...
 *
 *     https://github.com/sysown/proxysql/blob/3db9c0df5d891852ce21e6688112376d137381c7/lib/GTID_Server_Data.cpp#L270
 * 
 * ...and it's basically three distinct messages in plaintext:
 * 
 * ST=<uuid>:<gtid>[-<gtid>], ... : Bootstrap message, providing individual GTID or GTID ranges for all seen UUID servers.
 * I1=<uuid>:<gtid>               : Latest seen GTID for a given UUID.
 * I2=<gtid>                      : Latest seen GTID.
 * 
 */

std::string wiremsg_st(slave::Position const &curpos) {
	return("ST=" + gtid_to_string(curpos) + "\n");
}

std::string wiremsg_i1(std::string const uuid, uint64_t const trx_id) {
	return("I1=" + uuid + ":" + std::to_string(trx_id) + "\n");
}

std::string wiremsg_i2(uint64_t const trx_id) {
	return("I2=" + std::to_string(trx_id) + "\n");
}
