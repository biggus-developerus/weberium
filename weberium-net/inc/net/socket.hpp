#pragma once

namespace net
{
    static const int INVALID_SOCKET = -1;

    class Socket
    {
        public:
            Socket(int af, int type, int proto);
            virtual ~Socket();
        private:
            int _sfd = INVALID_SOCKET;
    };
}