#include "smartSockets.h"

#include <iostream>

//  Work with sockets

#include <arpa/inet.h>
#include <sys/socket.h>

string BaseSocket::getIpAddress() {
        return _ipAddress.toString();
    }

unsigned short int BaseSocket::getPort() const {
    return _socketPort.getPort();
}

BaseSocket::SocketType BaseSocket::getSocketType() const {
    return _socketType;
}

string BaseSocket::getSocketTypeString() const {
    if(_socketType == SocketType::UDP) {
        return "UDP";
    }
    else if(_socketType == SocketType::TCP) {
        return "TCP";
    }
    else if(_socketType == SocketType::Raw) {
        return "Raw";
    }
    else {
        throw(runtime_error("Error determining socket type: unknown socket type."));
    }
}

unsigned int BaseSocket::getTimeout() const {
    return _socketTimeout;
}

unsigned int BaseSocket::getBufferSize() const {
    return _buffer_size;
}

bool BaseSocket::isConnected() const {
    return _isConnected;
}

string BaseSocket::getHostName() const {
    return _hostName;
}