
#ifndef X_GINA_H_
#define X_GINA_H_

#include <windows.h>
#include <Winwlx.h>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dllmain.h"

//Location of the real MSGINA.
BOOL OrgInitialize(HINSTANCE hDll, DWORD dwWlxVersion);

//Function prototypes for the GINA interface.
typedef BOOL (WINAPI * PFWLXNEGOTIATE)(DWORD, DWORD *);
typedef BOOL (WINAPI * PFWLXINITIALIZE)(LPWSTR, HANDLE, PVOID, PVOID, PVOID *);
typedef VOID (WINAPI * PFWLXDISPLAYSASNOTICE)(PVOID);
typedef int  (WINAPI * PFWLXLOGGEDOUTSAS)(PVOID, DWORD, PLUID, PSID, PDWORD,
										   PHANDLE, PWLX_MPR_NOTIFY_INFO, 
										   PVOID *);
typedef BOOL (WINAPI * PFWLXACTIVATEUSERSHELL)(PVOID, PWSTR, PWSTR, PVOID);
typedef int  (WINAPI * PFWLXLOGGEDONSAS)(PVOID, DWORD, PVOID);
typedef VOID (WINAPI * PFWLXDISPLAYLOCKEDNOTICE)(PVOID);
typedef int  (WINAPI * PFWLXWKSTALOCKEDSAS)(PVOID, DWORD);
typedef BOOL (WINAPI * PFWLXISLOCKOK)(PVOID);
typedef BOOL (WINAPI * PFWLXISLOGOFFOK)(PVOID);
typedef VOID (WINAPI * PFWLXLOGOFF)(PVOID);
typedef VOID (WINAPI * PFWLXSHUTDOWN)(PVOID, DWORD);

typedef int (WINAPI * PWLXCHANGEPASSWORDNOTIFY)(HANDLE , PWLX_MPR_NOTIFY_INFO ,  DWORD );

//New for version 1.1
typedef BOOL (WINAPI * PFWLXSCREENSAVERNOTIFY)(PVOID, BOOL *);
typedef BOOL (WINAPI * PFWLXSTARTAPPLICATION)(PVOID, PWSTR, PVOID, PWSTR);

//New for version 1.3
typedef BOOL (WINAPI * PFWLXNETWORKPROVIDERLOAD)(PVOID, PWLX_MPR_NOTIFY_INFO);
typedef BOOL (WINAPI * PFWLXDISPLAYSTATUSMESSAGE)(PVOID, HDESK, DWORD, PWSTR, PWSTR);
typedef BOOL (WINAPI * PFWLXGETSTATUSMESSAGE)(PVOID, DWORD *, PWSTR, DWORD);
typedef BOOL (WINAPI * PFWLXREMOVESTATUSMESSAGE)(PVOID);

typedef DWORD (WINAPI *FUNShellShutdownDialog)(HWND hParent, WCHAR *Username, BOOL bHideLogoff);

//Remote desktop
typedef BOOL (WINAPI * FUNWLXGetConsoleSwitchCredentials)(PVOID,PVOID);
typedef VOID (WINAPI * FUNWLXReconnectNotify)(PVOID);
typedef VOID (WINAPI * FUNWLXDisconnectNotify)(PVOID);

#define GINASTUB_VERSION   (WLX_VERSION_1_3) // Highest version supported at

#endif