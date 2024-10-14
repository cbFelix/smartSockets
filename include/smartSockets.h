#ifndef SMARTSOCKETS_H
#define SMARTSOCKETS_H

#include "ip.h"
#include "port.h"

#include <iostream>

class BaseSocket {
public:
    enum class SocketType {Raw, UDP, TCP};

    BaseSocket(const string& ip, 
               unsigned short int port, 
               SocketType socketType = SocketType::TCP, 
               IPAddress::AddressFamily protocol = IPAddress::AddressFamily::IPv4,
               unsigned int socketTimeout = 3000, // default value for timeout
               int bufferSize = 1024);

    BaseSocket(IPAddress ip, 
               Port port, 
               SocketType socketType = SocketType::TCP, 
               IPAddress::AddressFamily protocol = IPAddress::AddressFamily::IPv4,
               unsigned int socketTimeout = 3000, // default value for timeout
               int bufferSize = 1024); 


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

    void setHostName(string newHostName);

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

class BaseConnection {
public:
    int connect();
    int disconnect();

    int bind();
    int unbind();
    
    int accept();
    int close();

    int sendData();
    int reciveData();

    int listen();

protected:
    

private: 

};


#endif