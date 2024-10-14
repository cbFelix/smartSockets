#ifndef PORT_H
#define PORT_H

#include <iostream>
#include <vector>

using namespace std;

class Port{
public:
    Port(unsigned short int port);

    unsigned short int getPort() const;

    bool operator==(const Port& other) const;
    bool operator<(const Port& other) const;
    bool operator>(const Port& other) const;
    bool operator!=(const Port& other) const;

    // set methods

    void setPort(unsigned short int newPort);
    void setRandPort(unsigned short int min, unsigned short int max);
    void setRandPort();

protected:
    bool isValidPort(int port) const;

private:
    unsigned short _port;

    static vector<Port> UsedPorts;
};

#endif  //  PORT_H