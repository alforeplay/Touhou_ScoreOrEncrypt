#include "MainThread.h"

#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <string>

using namespace System;
using namespace System::Windows::Forms;
using namespace Touhou_ScoreOrEncrypt;


const wchar_t *nameOfProcess = L"th06e.exe";
//Process Name

LPCVOID MemoryAddress = (LPCVOID)0x0069BCA0;
//Memory Address of Score

//BitConverter.toInt32
template <typename IntegerType>
IntegerType bitsToInt(IntegerType& result, const unsigned char* bits, bool little_endian = true)
{
	result = 0;
	if (little_endian)
		for (int n = sizeof(result); n >= 0; n--)
			result = (result << 8) + bits[n];
	else
		for (unsigned n = 0; n < sizeof(result); n++)
			result = (result << 8) + bits[n];
	return result;
}
//End of BitConverter Sample

//ProcessId Finder
DWORD FindProcessId(const std::wstring& processName)
{
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);

	HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (processesSnapshot == INVALID_HANDLE_VALUE) {
		return 0;
	}

	Process32First(processesSnapshot, &processInfo);
	if (!processName.compare(processInfo.szExeFile))
	{
		CloseHandle(processesSnapshot);
		return processInfo.th32ProcessID;

	}

	while (Process32Next(processesSnapshot, &processInfo))
	{
		if (!processName.compare(processInfo.szExeFile))
		{
			CloseHandle(processesSnapshot);
			return processInfo.th32ProcessID;
		}

	}

	CloseHandle(processesSnapshot);
	return 0;

} //this function
  //ProcessId Finder End

  //Check Process is online
bool IsProcessRunning(const wchar_t *processName)
{
	bool exists = false;
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry))
		while (Process32Next(snapshot, &entry))
			if (!(_wcsicmp(entry.szExeFile, processName)))
				exists = true;

	CloseHandle(snapshot);
	return exists;
}
//Check Done

/*
int labeloutput(System::Windows::Forms::Label^ somelabel, String^ output)
{
	somelabel->Text = output;
	
	return 0;
}
*/

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Touhou_ScoreOrEncrypt::MainThread form;
	Application::Run(%form);

	while (true)
	{
		if (IsProcessRunning)
		{

		}
		else {

		}
	}
	
}


/*
const wchar_t *nameOfProcess = L"th06e.exe";
//Process Name

LPCVOID MemoryAddress = (LPCVOID)0x0069BCA0;
//Memory Address of Score

//LOAD FUNCTIONS
DWORD FindProcessId(const std::wstring& processName);
bool IsProcessRunning(const wchar_t *processName);

//BitConverter.toInt32
template <typename IntegerType>
IntegerType bitsToInt(IntegerType& result, const unsigned char* bits, bool little_endian = true)
{
	result = 0;
	if (little_endian)
		for (int n = sizeof(result); n >= 0; n--)
			result = (result << 8) + bits[n];
	else
		for (unsigned n = 0; n < sizeof(result); n++)
			result = (result << 8) + bits[n];
	return result;
}
//End of BitConverter Sample

//Process online checker group code
bool checkonline()
{
	bool running = IsProcessRunning(nameOfProcess);
	//bool running = IsProcessRunning(L"th06e.exe");

	while (!running)
	{
		running = IsProcessRunning(nameOfProcess);
		//0running = IsProcessRunning(L"th06e.exe");
		if (running == true)
		{
			break;
		}
		printf("%S is NOT online! \n", nameOfProcess);
		Sleep(100);
	}

	return running;
}
//Process online checker group code

int main( int args, char* argv[] )
{

	unsigned char *buffer = new unsigned char[4];
	//Storage For Readed Memory

	//Online Check
	checkonline();

	//Get Process ID
	DWORD ProcessID = FindProcessId(nameOfProcess);

	//Open Process
	HANDLE hProcess = OpenProcess(PROCESS_VM_READ, false, ProcessID);
	//PROCESS_ALL_ACCESS

	while (true)
	{
		//Read the Process
		ReadProcessMemory(hProcess, MemoryAddress, buffer, 4, 0);

		//output factorization
		int output = 0;

		//BitConverter.Int16 or 32 Alternative
		bitsToInt(output, buffer);

		// Touhou score support (TH06)
		int score = output;

		// Touhou score support (TH12)
		//int score = output * 10;

		//Touhou Score As Output
		printf("Touhou Score : ");
		printf("%d\n\n", score);
		printf("==========================\n");
		printf("*** DEBUG ***\n");
		printf("Process(%S) data : ", nameOfProcess);
		printf("%d\n\n", output);
		printf("**************************\n");

		if (!IsProcessRunning(nameOfProcess))
		{
			main();
		}


		Sleep(100);

	}

	system("pause");

}







//==================================================================
//====================== CORE FUNCTIONS ============================
//==================================================================

//ProcessId Finder
DWORD FindProcessId(const std::wstring& processName)
{
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);

	HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (processesSnapshot == INVALID_HANDLE_VALUE) {
		return 0;
	}

	Process32First(processesSnapshot, &processInfo);
	if (!processName.compare(processInfo.szExeFile))
	{
		CloseHandle(processesSnapshot);
		return processInfo.th32ProcessID;

	}

	while (Process32Next(processesSnapshot, &processInfo))
	{
		if (!processName.compare(processInfo.szExeFile))
		{
			CloseHandle(processesSnapshot);
			return processInfo.th32ProcessID;
		}

	}

	CloseHandle(processesSnapshot);
	return 0;

} //this function
  //ProcessId Finder End

  //Check Process is online
bool IsProcessRunning(const wchar_t *processName)
{
	bool exists = false;
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry))
		while (Process32Next(snapshot, &entry))
			if (!(_wcsicmp(entry.szExeFile, processName)))
				exists = true;

	CloseHandle(snapshot);
	return exists;
}
//Check Done
*/

