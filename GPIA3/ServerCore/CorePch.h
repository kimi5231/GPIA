#pragma once

using namespace std;

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <mswsock.h>
#include <assert.h>

#include "Types.h"
#include "CoreMacro.h"
#include "CoreTLS.h"
#include "CoreGlobal.h"
#include "SocketUtils.h"
#include "SendBuffer.h"
#include "Session.h"

#pragma comment(lib, "ws2_32.lib")