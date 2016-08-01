/* Copyright (c) 2016, David Hauweele <david@hauweele.net>
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
   ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
   ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <assert.h>

#include "common.h"

const char * basename(const char *s)
{
  const char *base = (const char *)strrchr(s, '/');
  base = base ? (base + 1) : s;
  return base;
}

/* TODO: move to sockaddr.c */
unsigned int sockaddr_addrlen(const struct sockaddr *saddr)
{
  switch(saddr->sa_family) {
  case AF_INET:
    return sizeof(((struct sockaddr_in *)saddr)->sin_addr);
  case AF_INET6:
    return sizeof(((struct sockaddr_in6 *)saddr)->sin6_addr);
  }

  assert(0); /* unsupported address family */
  return 0;
}

const void * sockaddr_addr(const struct sockaddr *saddr)
{
  switch(saddr->sa_family) {
  case AF_INET:
    return &((struct sockaddr_in *)saddr)->sin_addr;
  case AF_INET6:
    return &((struct sockaddr_in6 *)saddr)->sin6_addr;
  }

  assert(0); /* unsupported address family */
  return 0;
}
