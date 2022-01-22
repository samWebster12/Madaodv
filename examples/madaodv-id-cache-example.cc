#include "madaodv-id-cache.h"
#include <iostream>

int main() 
{
    ns3::Time t;
    ns3::madaodv::IdCache cache(t);

    ns3::Ipv6Address addr("5:5:5:5:5:5:5:5");

    std::cout << cache.IsDuplicate(addr, 1) << std::endl;
    std::cout << cache.IsDuplicate(addr, 1) << std::endl;
}