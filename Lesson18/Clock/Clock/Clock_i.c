

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Wed Feb 14 14:27:09 2018
 */
/* Compiler settings for Clock.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_ClockLib,0xB0AD96A5,0x2EE1,0x415A,0x88,0xC4,0x50,0x35,0x95,0xE8,0x76,0xDF);


MIDL_DEFINE_GUID(IID, DIID__DClock,0x446C6DAC,0x46DD,0x4226,0x9C,0x26,0x3D,0x9E,0xED,0xBA,0x02,0xA9);


MIDL_DEFINE_GUID(IID, DIID__DClockEvents,0xE8B85249,0x5ACB,0x45B0,0xBD,0xA4,0xBB,0xC1,0x28,0xC9,0xAE,0x14);


MIDL_DEFINE_GUID(CLSID, CLSID_Clock,0xD4DE08FA,0x2261,0x4D9A,0x84,0xE6,0x8D,0xF6,0xCB,0x60,0x94,0x9A);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



