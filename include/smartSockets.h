#ifndef SMARTSOCKETS_H
#define SMARTSOCKETS_H

#include "ip.h"
#include "port.h"

#include <iostream>

class BaseSocket {
public:
    enum class SocketType {Raw, UDP, TCP};

    BaseSocket(const string& ip, unsigned short int port, 
               SocketType socketType = SocketType::TCP, 
               IPAddress::AddressFamily protocol = IPAddress::AddressFamily::IPv4,
               unsigned int socketTimeout = 3000, // default value for timeout
               int bufferSize = 1024,    // default value for buffer
               bool isConnected = false)
        : _ipAddress(ip, protocol),      // init IPAddress
          _socketPort(port),             // init Port
          _socketType(socketType),       // init SocketType
          _socketTimeout(socketTimeout), // init timeout
          _buffer_size(bufferSize),      // init buffer size
          _isConnected(isConnected)      // init state of connection
    {}

    //  get methods

    string getIpAddress();

    unsigned short int getPort() const;

    SocketType getSocketType() const;

    string getSocketTypeString() const;

    unsigned int getTimeout() const;

    unsigned int getBufferSize() const;

    bool isConnected() const;

    string getHostName() const;

    //  set methods

    void setIPAddress(IPAddress& newAddress);
    void setIPAddress(const string& newIp, IPAddress::AddressFamily addressFamily);

    void setPort(Port newPort);
    void setPort(unsigned short int newPort);


protected:  
    string _hostName;

private:
    IPAddress _ipAddress;
    Port _socketPort;
    SocketType _socketType;
    unsigned int _socketTimeout;
    unsigned int _buffer_size;
    bool _isConnected;
};


#endif