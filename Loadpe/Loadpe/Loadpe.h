// LoadPe.h
#pragma once

// ���ڴ��м���PE�ļ�����Ҫ֧��EXE��DLL�Լ���֮������OCX��AX�ȣ�
// ��ԭʼ�Ĵ���μ�Bo2000��dll_load.cpp��
// Ҫ��
//               �Ƽ����ض�λ��Ϣ��������ڶ���Pe�ļ����޷��ɹ����صġ�
// ע�⣺
//               ���ڱ��˻����ϲ��ԣ�������CPU: Celeron 1.7G Memory: 256M OS:WinXp sp2 Complier: VC++6.0 Editor: VS2005
//               ֧��Win2000,WinXp,Win2003,WinVista; 
//               ��֧��WinMe,Win98,Win95�Լ������Windows��Ʒ
// ���ƣ�
//               Commandline Ӧ����"ModuleFileName Param1 param2 ...", ���ModuleFileNameΪ�գ�GetModuleFileName�����ؿգ�����ڶ����������޷����ܵġ�
//               ��֧��ͨ�����;����ͨ��������ŵ���GetModuleHandle,GetModuleFileName,GetCommandLine��������Щ�����䷵��ֵ��Pe�ļ���
//               ����MFC����,ModuleFileName�������"."(�ο�MFCԴ����AppInit.cpp��CWinApp::SetCurrentHandles()������Ҫ���ļ����б�����"."�Ĵ��ڣ�����"my.dll", "my.", ".my"���Ϸ�)��
//               ��֧�ֶ�̬���ӵ�MFC����(ԭ�����ڶ�̬����MFC��ĳ�����GetModuleHandle,GetModuleFileName,GetCommandLine����MFC*.dll�е���,Υ����������)��
// �����ȷ��ʹ�ã�
//               fSuicid��һ��������ϸ���ǵ�һ����־��
//                        �趨��fSuicid,��Pe�ļ��Ƕ��̵߳ģ���Ӧ�ñ�֤ExeEntry��DllEntry�����һ�����ص��̣߳������ж�����л�̵߳��ڴ����򣬵����̷߳�����ж�ص��ڴ�ռ������
//                        ��apiHookĿ�ĵ�Pe��Ӧ��ָ��fSuicid=TRUE;


#ifdef __cplusplus
extern "C" {
#endif
	typedef int(__stdcall *PROCUNLOAD)(int uExitCode);
	HINSTANCE __stdcall _LoadLibraryA(LPVOID lpRawRelocPe, LPCSTR lpLibFileName);
	HINSTANCE __stdcall _LoadLibraryW(LPVOID lpRawRelocPe, LPCWSTR lpLibFileName);
	HINSTANCE __stdcall _LoadLibraryExA(LPVOID lpRawRelocPe, LPCSTR lpLibFileName, HANDLE hFile, DWORD dwFlags);
	HINSTANCE __stdcall _LoadLibraryExW(LPVOID lpRawRelocPe, LPCWSTR lpLibFileName, HANDLE hFile, DWORD dwFlags);
	BOOL      __stdcall _FreeLibrary(HMODULE hLibModule);



	HANDLE __stdcall LoadPeA(LPVOID lpRawRelocPe, LPCSTR lpCommandLine, HINSTANCE *phInst = NULL, BOOL fSuicid = FALSE, PROCUNLOAD *pfUnload = NULL); // if fSuicid is FASLE, the pfUnload should NOT be NULL;
	HANDLE __stdcall LoadPeW(LPVOID lpRawRelocPe, LPCWSTR lpwCommandLine, HINSTANCE *phInst = NULL, BOOL fSuicid = FALSE, PROCUNLOAD *pfUnload = NULL);
	HANDLE __stdcall LoadPeExA(DWORD dwProcessID, LPVOID lpRawRelocPe, LPCSTR lpCommandLine, HINSTANCE *phRemotInst = NULL, BOOL fSuicid = FALSE, PROCUNLOAD *pfUnload = NULL);
	HANDLE __stdcall LoadPeExW(DWORD dwProcessID, LPVOID lpRawRelocPe, LPCWSTR lpwCommandLine, HINSTANCE *phRemotInst = NULL, BOOL fSuicid = FALSE, PROCUNLOAD *pfUnload = NULL);

	int __stdcall UnloadPe(PROCUNLOAD pFouncUnload);
	int __stdcall UnloadPeEx(DWORD dwProcessID, PROCUNLOAD pFouncUnload);

	FARPROC __stdcall _GetProcAddress(HMODULE hModule, LPCSTR FuncName);

#ifdef __cplusplus
}

#endif



#ifdef UNICODE

#define LoadPe LoadPeW

#define LoadPeEx LoadPeExW

#else

#define LoadPe LoadPeA

#define LoadPeEx LoadPeExA

#endif