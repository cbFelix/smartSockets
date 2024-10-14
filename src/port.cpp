#include "port.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<unsigned short int> Port::UsedPorts = {};

Port::Port(unsigned short int port) {
    if (!isValidPort(port)) {
        throw invalid_argument("Invalid port: port cannot be less than 0 and greater than 65535");
    }
    if (find(UsedPorts.begin(), UsedPorts.end(), port) != UsedPorts.end()) {
        throw invalid_argument("Error creating port " + to_string(port) + ": port already in use");
    }
    _port = port;
    UsedPorts.push_back(_port);
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
    if (find(UsedPorts.begin(), UsedPorts.end(), newPort) != UsedPorts.end()) {
        throw invalid_argument("Error creating port " + to_string(newPort) + ": port already in use");
    }
    UsedPorts.erase(remove(UsedPorts.begin(), UsedPorts.end(), _port), UsedPorts.end());
    _port = newPort;
    UsedPorts.push_back(_port);
}

void Port::setPort(const Port& other) {
    if (other._port == _port) {
        throw invalid_argument("The new port must not be equal to the old port.");
    }
    if (!isValidPort(other._port)) {
        throw invalid_argument("Invalid port: port must be between 1 and 65535.");
    }
    if (find(UsedPorts.begin(), UsedPorts.end(), other._port) != UsedPorts.end()) {
        throw invalid_argument("Error creating port " + to_string(other._port) + ": port already in use");
    }
    UsedPorts.erase(remove(UsedPorts.begin(), UsedPorts.end(), _port), UsedPorts.end());
    _port = other._port;
    UsedPorts.push_back(_port);
}

void Port::setRandPort() {
    const int maxPorts = 65535;
    const int minPort = 1;
    int attempts = 0;
    unsigned short int newPort;

    if (UsedPorts.size() >= maxPorts) {
        throw runtime_error("Unable to create new port: all ports are in use.");
    }

    do {
        newPort = rand() % (maxPorts - minPort + 1) + minPort;
        attempts++;

        if (attempts > maxPorts) {
            throw runtime_error("Unable to find a unique port after maximum attempts.");
        }

    } while (find(UsedPorts.begin(), UsedPorts.end(), newPort) != UsedPorts.end());

    UsedPorts.erase(remove(UsedPorts.begin(), UsedPorts.end(), _port), UsedPorts.end());
    _port = newPort;
    UsedPorts.push_back(_port);
}

void Port::setRandPort(unsigned short int min, unsigned short int max) {
    unsigned short int newPort = rand() % (max - min + 1) + min;
    if (!isValidPort(newPort)) {
        throw invalid_argument("Invalid port: port cannot be less than 0 and greater than 65535");
    }
    if (find(UsedPorts.begin(), UsedPorts.end(), newPort) != UsedPorts.end()) {
        throw invalid_argument("Error creating port " + to_string(newPort) + ": port already in use");
    }
    UsedPorts.erase(remove(UsedPorts.begin(), UsedPorts.end(), _port), UsedPorts.end());
    _port = newPort;
    UsedPorts.push_back(_port);
}

bool Port::operator==(const Port& other) const {
    return (_port  == other._port);
}

bool Port::operator>(const Port& other) const {
    return (_port > other._port);
}

bool Port::operator<(const Port& other) const {
    return (_port < other._port);
}

bool Port::operator!=(const Port& other) const {
    return !(_port == other._port);
}

bool Port::isValidPort(int port) const {
    return !(port < 0 || port > 65535);
}