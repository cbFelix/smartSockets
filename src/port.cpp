#include "port.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<Port> Port::UsedPorts = {};

Port::Port(unsigned short int port) {
    if (!isValidPort(port)) {
        throw(invalid_argument("Invalid port: Invalid port: port cannot be less than 0 and greater than 65535"));
        return;
    }
    if (find(UsedPorts.begin(), UsedPorts.end(), *this) != UsedPorts.end()) {
        throw(invalid_argument("Port is already in use"));
    }

    _port = port;

    UsedPorts.push_back(*this);
}

unsigned short int Port::getPort() const {
    return _port;
}

void Port::setPort(unsigned short int newPort) {
    if (newPort == _port) {
        throw invalid_argument("The new port must not be equal to the old port.");
    }

    if (!isValidPort(newPort)) {
        throw invalid_argument("Invalid port: port must be between 1 and 65535.");
    }

    if (find(UsedPorts.begin(), UsedPorts.end(), Port(newPort)) != UsedPorts.end()) {
        throw invalid_argument("The new port is already in use.");
    }

    UsedPorts.erase(remove(UsedPorts.begin(), UsedPorts.end(), *this), UsedPorts.end());

    _port = newPort;
    UsedPorts.push_back(*this);
}


void Port::setRandPort() {
    unsigned short int newPort = rand() % (65535 - 1 + 1) + 1;
    if(!isValidPort(newPort)) {
        throw(invalid_argument("Invalid port: Invalid port: port cannot be less than 0 and greater than 65535"));
        return;
    }
    _port = newPort;
}

void Port::setRandPort(unsigned short int min, unsigned short int max) {
    unsigned short int newPort = rand() % (max - min + 1) + min;
    if(!isValidPort(newPort)) {
        throw(invalid_argument("Invalid port: Invalid port: port cannot be less than 0 and greater than 65535"));
        return;
    }
    _port = newPort;
}

bool Port::operator==(const Port& other) const {
    return (this->_port  == other._port);
}

bool Port::operator>(const Port& other) const {
    return (this->_port > other._port);
}

bool Port::operator<(const Port& other) const {
    return (this->_port < other._port);
}

bool Port::operator!=(const Port& other) const {
    return !(this->_port == other._port);
}

bool Port::isValidPort(int port) const {
    return !(port < 0 || port > 65535);
}