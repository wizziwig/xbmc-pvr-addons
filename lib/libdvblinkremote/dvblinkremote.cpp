/***************************************************************************
 * Copyright (C) 2012 Marcus Efraimsson.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included 
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
 * DEALINGS IN THE SOFTWARE.
 *
 ***************************************************************************/

#include "dvblinkremote.h"
#include "dvblinkremoteconnection.h"

using namespace dvblinkremote;

IDVBLinkRemoteConnection::~IDVBLinkRemoteConnection()
{
}

IDVBLinkRemoteConnection* DVBLinkRemote::Connect(dvblinkremotehttp::HttpClient& httpClient, const std::string& hostAddress, const long port) 
{
  return new DVBLinkRemoteCommunication(httpClient, hostAddress, port);
}

IDVBLinkRemoteConnection* DVBLinkRemote::Connect(dvblinkremotehttp::HttpClient& httpClient, const std::string& hostAddress, const long port, const std::string& username, const std::string& password) 
{
  return new DVBLinkRemoteCommunication(httpClient, hostAddress, port, username, password);
}

void DVBLinkRemote::GetCopyrightNotice(std::string& copyright) 
{
  copyright.assign(LIBDVBLINKREMOTE_COPYRIGHT);
}

void DVBLinkRemote::GetVersion(std::string& version)
{
  version.assign(LIBDVBLINKREMOTE_VERSION);
}

void DVBLinkRemote::GetVersion(int& major, int& minor, int& patch)
{
  major = LIBDVBLINKREMOTE_VERSION_MAJOR;
  minor = LIBDVBLINKREMOTE_VERSION_MINOR;
  patch = LIBDVBLINKREMOTE_VERSION_PATCH;
}
