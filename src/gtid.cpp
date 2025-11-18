#include "Slave.h"

#include "gtid.h"


std::string gtid_to_string(slave::Position const &curpos) {
	std::string gtid_set { "" };
	for (auto it=curpos.gtid_executed.begin(); it!=curpos.gtid_executed.end(); ++it) {
		std::string s = it->first;
		s.insert(8,"-");
		s.insert(13,"-");
		s.insert(18,"-");
		s.insert(23,"-");
		s = s + ":";
		for (auto itr = it->second.begin(); itr != it->second.end(); ++itr) {
			std::string s2 = s;
			s2 = s2 + std::to_string(itr->first);
			s2 = s2 + "-";
			s2 = s2 + std::to_string(itr->second);
			s2 = s2 + ",";
			gtid_set = gtid_set + s2;
		}
	}
	if (gtid_set.empty() == false) {
		gtid_set.pop_back();
	}
	return gtid_set;
}
