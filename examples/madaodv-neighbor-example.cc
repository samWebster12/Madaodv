#include "madaodv-neighbor.h"
#include <iostream>

int main() 
{
    char const * ipAddrStr = "100:0:0:0:0:ffff:ffff:ffff";
    ns3::Ipv6Address ipAddr(ipAddrStr);
    ns3::Time t;
    ns3::madaodv::Neighbors neighbors(t);
    ns3::Mac48Address hdwrAddr = neighbors.LookupMacAddress(ipAddr);

    std::cout << hdwrAddr << std::endl;
}