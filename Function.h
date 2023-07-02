#pragma once
#include <Windows.h>
#include <winternl.h>


extern "C" PPEB GetPEB();

#define CUT_LIST(item) \
	item.Blink->Flink = item.Flink; \
	item.Flink->Blink = item.Blink

#define RTL_MAX_DRIVE_LETTERS 32

typedef struct _CURDIR {
	UNICODE_STRING DosPath;
	HANDLE Handle;
} CURDIR, * PCURDIR;

typedef struct _RTL_DRIVE_LETTER_CURDIR {
	USHORT Flags;
	USHORT Length;
	ULONG TimeStamp;
	UNICODE_STRING DosPath;
} RTL_DRIVE_LETTER_CURDIR, * PRTL_DRIVE_LETTER_CURDIR;

typedef struct _MEM_RTL_USER_PROCESS_PARAMETERS {
	ULONG MaximumLength;
	ULONG Length;
	ULONG Flags;
	ULONG DebugFlags;
	PVOID ConsoleHandle;
	ULONG ConsoleFlags;
	HANDLE StdInputHandle;
	HANDLE StdOutputHandle;
	HANDLE StdErrorHandle;
	UNICODE_STRING CurrentDirectoryPath;
	HANDLE CurrentDirectoryHandle;
	UNICODE_STRING DllPath;
	UNICODE_STRING ImagePathName;
	UNICODE_STRING CommandLine;
	PVOID Environment;
	ULONG StartingX;
	ULONG StartingY;
	ULONG CountX;
	ULONG CountY;
	ULONG CountCharsX;
	ULONG CountCharsY;
	ULONG FillAttribute;
	ULONG WindowFlags;
	ULONG ShowWindowFlags;
	UNICODE_STRING WindowTitle;
	UNICODE_STRING DesktopInfo;
	UNICODE_STRING ShellInfo;
	UNICODE_STRING RuntimeData;
	RTL_DRIVE_LETTER_CURDIR CurrentDirectories[RTL_MAX_DRIVE_LETTERS];
	ULONG_PTR EnvironmentSize;
	ULONG_PTR EnvironmentVersion;
	PVOID PackageDependencyData;
	ULONG ProcessGroupId;
	ULONG LoaderThreads;
} MEM_RTL_USER_PROCESS_PARAMETERS, * PMEM_RTL_USER_PROCESS_PARAMETERS;

typedef struct _MEM_PEB_LDR_DATA {
	ULONG Length;
	BOOLEAN Initialized;
	PVOID SsHandle;
	LIST_ENTRY InLoadOrderModuleList;
	LIST_ENTRY InMemoryOrderModuleList;
	LIST_ENTRY InInitializationOrderModuleList;
	PVOID EntryInProgress;
} PMEM_EB_LDR_DATA, * PMEM_PEB_LDR_DATA;

typedef struct _MEM_PEB {
	BOOLEAN InheritedAddressSpace;
	BOOLEAN ReadImageFileExecOptions;
	BOOLEAN BeingDebugged;
	union
	{
		BOOLEAN BitField;
		struct
		{
			BOOLEAN ImageUsesLargePages : 1;
			BOOLEAN IsProtectedProcess : 1;
			BOOLEAN IsLegacyProcess : 1;
			BOOLEAN IsImageDynamicallyRelocated : 1;
			BOOLEAN SkipPatchingUser32Forwarders : 1;
			BOOLEAN SpareBits : 3;
		};
	};
	HANDLE Mutant;
	PVOID ImageBaseAddress;
	PMEM_PEB_LDR_DATA Ldr;
	PMEM_RTL_USER_PROCESS_PARAMETERS ProcessParameters;
	PVOID SubSystemData;
	PVOID ProcessHeap;
	PVOID FastPebLock;
	PVOID AtlThunkSListPtr;
	PVOID IFEOKey;
	union
	{
		ULONG CrossProcessFlags;
		struct
		{
			ULONG ProcessInJob : 1;
			ULONG ProcessInitializing : 1;
			ULONG ProcessUsingVEH : 1;
			ULONG ProcessUsingVCH : 1;
			ULONG ProcessUsingFTH : 1;
			ULONG ReservedBits0 : 27;
		};
		ULONG EnvironmentUpdateCount;
	};
	union
	{
		PVOID KernelCallbackTable;
		PVOID UserSharedInfoPtr;
	};
	ULONG SystemReserved[1];
	ULONG AtlThunkSListPtr32;
	PVOID ApiSetMap;
} MEM_PEB, * PMEM_PEB;

namespace Function
{
	typedef LPVOID(WINAPI* tVirtualAlloc)(
		LPVOID lpAddress,
		SIZE_T dwSize,
		DWORD  flAllocationType,
		DWORD  flProtect
	);
	typedef BOOL(WINAPI* tVirtualProtect)(
		LPVOID lpAddress,
		SIZE_T dwSize,
		DWORD  flNewProtect,
		PDWORD lpflOldProtect
	);
	typedef HANDLE(WINAPI* tCreateFileA)(
		LPCSTR lpFileName,
		DWORD  dwDesiredAccess,
		DWORD  dwShareMode,
		LPSECURITY_ATTRIBUTES lpSecurityAttributes,
		DWORD  dwCreationDisposition,
		DWORD  dwFlagsAndAttributes,
		HANDLE hTemplateFile
	);
	typedef BOOL(WINAPI* tReadFile)(
		HANDLE       hFile,
		LPVOID       lpBuffer,
		DWORD        nNumberOfBytesToRead,
		LPDWORD      lpNumberOfBytesRead,
		LPOVERLAPPED lpOverlapped
	);
	typedef BOOL(WINAPI* tCloseHandle)(
		HANDLE hObject
	);
	typedef DWORD(WINAPI* tGetFileSize)(
		HANDLE  hFile,
		LPDWORD lpFileSizeHigh
	);
	typedef DWORD(WINAPI* tGetFileAttributesA)(
		LPCSTR lpFileName
	);
	typedef DWORD(WINAPI* tSearchPathA)(
		LPCSTR lpPath,
		LPCSTR lpFileName,
		LPCSTR lpExtension,
		DWORD  nBufferLength,
		LPSTR  lpBuffer,
		LPSTR* lpFilePart
	);
	typedef BOOL (WINAPI* tFreeLibrary)(
		HMODULE hLibModule
	);
	typedef HMODULE(WINAPI* tLoadLibraryA)(
		LPCSTR lpLibFileName
	);
	typedef DWORD(WINAPI* tSearchPathW)(
		LPCWSTR lpPath,
		LPCWSTR lpFileName,
		LPCWSTR lpExtension,
		DWORD   nBufferLength,
		LPWSTR  lpBuffer,
		LPWSTR* lpFilePart
	);
	typedef DWORD(WINAPI* tGetModuleFileNameW)(
		HMODULE hModule,
		LPWSTR lpFilename,
		DWORD nSize
	);
	typedef BOOL(WINAPI* tSetConsoleTitleW)(
		LPWSTR lpConsoleTitle
	);
	typedef BOOL(WINAPI* tVirtualFree)(
		LPVOID lpAddress,
		SIZE_T dwSize,
		DWORD  dwFreeType
	);
	typedef DWORD(WINAPI* tGetEnvironmentVariableW)(
		_In_opt_ LPCWSTR lpName,
		_Out_writes_to_opt_(nSize, return +1) LPWSTR lpBuffer,
		_In_ DWORD nSize
	);
	typedef HANDLE(WINAPI* tCreateFileW)(
			_In_ LPCWSTR lpFileName,
			_In_ DWORD dwDesiredAccess,
			_In_ DWORD dwShareMode,
			_In_opt_ LPSECURITY_ATTRIBUTES lpSecurityAttributes,
			_In_ DWORD dwCreationDisposition,
			_In_ DWORD dwFlagsAndAttributes,
			_In_opt_ HANDLE hTemplateFile
	);
	typedef HANDLE(WINAPI* tCreateFileMappingW)(
		_In_     HANDLE hFile,
		_In_opt_ LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
		_In_     DWORD flProtect,
		_In_     DWORD dwMaximumSizeHigh,
		_In_     DWORD dwMaximumSizeLow,
		_In_opt_ LPCWSTR lpName
	);
	typedef LPVOID(WINAPI* tMapViewOfFile)(
		_In_ HANDLE hFileMappingObject,
		_In_ DWORD dwDesiredAccess,
		_In_ DWORD dwFileOffsetHigh,
		_In_ DWORD dwFileOffsetLow,
		_In_ SIZE_T dwNumberOfBytesToMap
	);
	typedef HMODULE(WINAPI* tGetModuleHandleW)(
		_In_opt_ LPCWSTR lpModuleName
	);
	typedef VOID(WINAPI* tSleep)(
		_In_ DWORD dwMilliseconds
	);
	typedef BOOL(WINAPI* tCopyFileW)(
		_In_ LPCWSTR lpExistingFileName,
		_In_ LPCWSTR lpNewFileName,
		_In_ BOOL bFailIfExists
	);
	typedef BOOL(WINAPI* tCreateDirectoryW)(
		_In_ LPCWSTR lpPathName,
		_In_opt_ LPSECURITY_ATTRIBUTES lpSecurityAttributes
	);
	typedef  HANDLE(WINAPI* tGetCurrentProcess)(
		VOID
	);
	typedef FARPROC(WINAPI* tGetProcAddress)(
		_In_ HMODULE hModule,
		_In_ LPCSTR lpProcName
	);
	typedef DWORD(WINAPI* tGetFileAttributesW)(
		_In_ LPCWSTR lpFileName
	);

	namespace call {
		extern Function::tVirtualFree virtualFree;
		extern Function::tCloseHandle closehandle;
		extern Function::tCreateFileA createFileA;
		extern Function::tVirtualAlloc virtualAlloc;
		extern Function::tGetFileSize getFileSize;
		extern Function::tReadFile readFile;
		extern Function::tVirtualProtect virtualProtect;
		extern Function::tGetFileAttributesA getFileAttributesA;
		extern Function::tSearchPathA searchPathA;
		extern Function::tFreeLibrary freeLibrary;
		extern Function::tLoadLibraryA loadLibraryA;
		extern Function::tSearchPathW searchPathW;
		extern Function::tGetModuleFileNameW getModuleFileNameW;
		extern Function::tSetConsoleTitleW setConsoleTitleW;
		extern Function::tGetEnvironmentVariableW getEnvironmentVariableW;
		extern Function::tCreateFileW createFileW;
		extern Function::tCreateFileMappingW createFileMappingW;
		extern Function::tMapViewOfFile mapViewOfFile;
		extern Function::tGetModuleHandleW getModuleHandleW;
		extern Function::tSleep sleep;
		extern Function::tCopyFileW copyFileW;
		extern Function::tCreateDirectoryW createDirectoryW;
		extern Function::tGetCurrentProcess getCurrentProcess;
		extern Function::tGetProcAddress getProcAddress;
		extern Function::tGetFileAttributesW getFileAttributesW;
	}

	bool Init_Setup();
	void* Memcpy(void* dst, const void* src, unsigned int cnt);
	int _strcmp(const char* str1, const char* str2);
	int wstrcmp(const wchar_t* str1, const wchar_t* str2);
	int _strlen(const wchar_t* str1);
	void GetLowerLetters(WCHAR* input);
	void* pGetProcAddress(void* moduleHandle, const char* functionName);
	void* pGetModuleHandle(const wchar_t* moduleName);
};

