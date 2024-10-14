#include "ip.h"
#include "smartSockets.h"
#include "port.h"

#include <iostream>

using namespace std;

#define IPv4 IPAddress::AddressFamily::IPv4
#define IPv6 IPAddress::AddressFamily::IPv6

int main() {
    try {
        Port port1(8080);
        Port port2(9090);

        cout << "port1\t" << port1.getPort() << endl;
        cout << "port2\t" << port2.getPort() << endl;

        port1.setPort(443);
        port2.setPort(80);

        cout << "port1\t" << port1.getPort() << endl;
        cout << "port2\t" << port2.getPort() << endl;

        IPAddress ip("1.2.3.4", IPv4);
        IPAddress ipv6("2001:0db8:85a3:0000:0000:8a2e:0370:7334", IPv6);

        cout << endl;
        cout << "IP " << ip.toString() << " is IPv4: " << ip.isIPv4() << endl;
        cout << "IP " << ip.toString() << " is IPv6: " << ip.isIPv6() << endl;
        cout << endl;
        cout << "IP " << ipv6.toString() << " is IPv4: " << ipv6.isIPv4() << endl;
        cout << "IP " << ipv6.toString() << " is IPv6: " << ipv6.isIPv6() << endl;

        return 0;
    }
    catch(const exception& e) {
        cout << e.what() << endl;
    }
}