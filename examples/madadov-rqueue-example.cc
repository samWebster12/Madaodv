#include "madaodv-rqueue.h"
#include <iostream>

int main() 
{
    //Need to comment on out first section of code in Enqueue for the following to work so a 0 pointer is not dereferenced.


    ns3::Time routeToQTime;

    ns3::madaodv::RequestQueue queue (100, routeToQTime);
    ns3::madaodv::QueueEntry entry;
    queue.Enqueue(entry);

    std::cout << "Size: " << queue.GetSize() << std::endl;
    std::cout << "ipv6 addr found: " << queue.Find(ns3::Ipv6Address("1::")) << std::endl;




    for (int i = 0; i < 6; i++)
    {
        ns3::madaodv::QueueEntry newentry1;
        ns3::Ipv6Header header1;
        header1.SetDestinationAddress(ns3::Ipv6Address("100::ffff:ffff:ffff"));
        newentry1.SetIpv6Header(header1);
        queue.Enqueue(newentry1);
    }

    ns3::madaodv::QueueEntry newentry1;
    ns3::Ipv6Header header1;
    header1.SetDestinationAddress(ns3::Ipv6Address("100::ffff:ffef:ffff"));
    newentry1.SetIpv6Header(header1);
    queue.Enqueue(newentry1);

    for (int i = 0; i < 12; i++)
    {
        ns3::madaodv::QueueEntry newentry1;
        ns3::Ipv6Header header1;
        header1.SetDestinationAddress(ns3::Ipv6Address("100::ffff:ffff:ffff"));
        newentry1.SetIpv6Header(header1);
        queue.Enqueue(newentry1);
    }

    std::vector<ns3::madaodv::QueueEntry> apqueries;
    std::cout << "ap query found: " << queue.DequeueApQueries(apqueries) << std::endl;
    std::cout << "number of ap queries: " << apqueries.size() << std::endl;
}