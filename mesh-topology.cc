#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/netanim-module.h"

using namespace ns3;

int main () {
    NodeContainer nodes;
    nodes.Create(15);

    InternetStackHelper internet;
    internet.Install(nodes);

    PointToPointHelper p2p;
    p2p.SetDeviceAttribute("DataRate", StringValue("10Mbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));

    for (int i = 0; i < 15; i++) {
        for (int j = i + 1; j < 15; j++) {
            p2p.Install(NodeContainer(nodes.Get(i), nodes.Get(j)));
        }
    }

    AnimationInterface anim("mesh.xml");
    Simulator::Run();
    Simulator::Destroy();
    return 0;
}
