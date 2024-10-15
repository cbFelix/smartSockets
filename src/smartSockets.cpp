#include "smartSockets.h"

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <errno.h>

//  Work with sockets

#include <arpa/inet.h>
#include <sys/socket.h>

// get

BaseSocket::BaseSocket(const string& ip, 
            unsigned short int port, 
            SocketType socketType, 
            IPAddress::AddressFamily protocol,
            unsigned int socketTimeout, // default value for timeout
            int bufferSize)
    : _ipAddress(ip, protocol),      // init IPAddress
        _socketPort(port),             // init Port
        _socketType(socketType),       // init SocketType
        _protocol(protocol),           // init protocol
        _socketTimeout(socketTimeout), // init timeout
        _buffer_size(bufferSize),      // init buffer size
        _isConnected(false),       // Connection init state, why false? But connection can't be connected immediately after init
        _isPortBinded(false) {}


BaseSocket::BaseSocket(IPAddress ip, 
            Port port, 
            SocketType socketType, 
            unsigned int socketTimeout, // default value for timeout
            int bufferSize)    // default value for buffer)
    : _ipAddress(ip),                // init IPAddress
        _socketPort(port),             // init Port
        _socketType(socketType),       // init SocketType
        _protocol(ip.getFamily()),           // init protocol
        _socketTimeout(socketTimeout), // init timeout
        _buffer_size(bufferSize),      // init buffer size
        _isConnected(false),            // init state of connection
        _isPortBinded(false)
{
    _hostName = ip.toString();
}

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

IPAddress::AddressFamily BaseSocket::getProtocol() const {
    return _protocol;
}

// set

void BaseSocket::setIPAddress(IPAddress& newAddress) {
    _ipAddress.setIP(newAddress);
}
void BaseSocket::setIPAddress(const string& newIp, IPAddress::AddressFamily addressFamily) {
    _ipAddress.setIP(newIp, addressFamily);
}

void BaseSocket::setPort(Port newPort) {
    _socketPort.setPort(newPort);
}
void BaseSocket::setPort(unsigned short int newPort) {

}

void BaseSocket::setHostName(string newHostName) {
    _hostName = newHostName;
}

BaseConnection BaseSocket::initConnection() {
    return BaseConnection(*this);
}

//  BaseConnectionClass

int BaseConnection::connect() {

}
int BaseConnection::disconnect() {
    
}

int BaseConnection::bind(unsigned short int port) {

}
int BaseConnection::unbind() {
    
}

int BaseConnection::accept() {
    
}
int BaseConnection::close() {
    
}

int BaseConnection::sendData() {
    
}
int BaseConnection::reciveData() {
    
}

int BaseConnection::listen() {

}