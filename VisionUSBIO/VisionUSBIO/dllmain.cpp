#include <windows.h>
#include <chrono>
#include <format>
#include <iostream>

static bool insertingCard = false;

enum RFID_STATUS
{
    IDLE = 0,
    READING = 1
};

enum RFID_RESULT
{
    OK = 0,
    DISCONNECT = 1,
    ERR = 2,
    CANCEL = 3
};

struct RFID_ID
{
	byte ID[16];
	byte NESiCA_UID[7];
    byte AMIC_AccCode[20];
    byte IsAMIC;
};

std::string nesicaId = "7020392002630000";

extern "C" unsigned int NESiCAReaderCancelRead()
{
    return 1;
}

extern "C" unsigned int NESiCAReaderGetID(RFID_ID* id)
{
    if (insertingCard) 
    {
        for (int i = 0; i < nesicaId.size(); i++)
        {
            id->ID[i] = nesicaId[i];
        }
        id->IsAMIC = false;
        return 1;
	}
    else 
    {
        return 0;
    }
}

extern "C" RFID_RESULT NESiCAReaderGetResult()
{
    return OK;
}

extern "C" RFID_STATUS NESiCAReaderGetStatus()
{
	if (insertingCard)
	{
		return IDLE;
	}
    else 
    {
        return READING;
    }
}

extern "C" unsigned int NESiCAReaderIsError()
{
    return 0;
}

extern "C" unsigned int NESiCAReaderRead()
{
    return 1;
}

struct IOBUFFER
{
    uint32_t InPort;

    uint16_t InAnalog[8];
    uint16_t InEncoder[4];

    uint32_t OutPort;

    uint8_t OutPWM[24];

    int32_t NESiCALEDControl;

    uint16_t Coin[2];
    int16_t CoinDec[2];

    uint8_t IsCoinDecreasing[2];
    uint8_t Padding[2];
};


extern "C" unsigned int VisionUSBGetDeviceVersion()
{
    return 0;
}

extern "C" unsigned int VisionUSBIOClose()
{
    return true;
}

extern "C" unsigned int VisionUSBIOGetStatus()
{
    return 512;
}

extern "C" unsigned int VisionUSBIOOpen()
{
    return 1;
}

static bool btn_coin = false;
static bool btn_service = false;
static bool btn_test = false;
static bool btn_select = false;
static bool btn_enter = false;

static int coinCount = 0;
static bool inputEnabled = true;

extern "C" uint32_t VisionUSBIOUpdate(IOBUFFER* buf)
{
    buf->InPort = 0;

    if (inputEnabled)
    {
        //add all the button states to inport
        buf->InPort |= btn_coin ? 0x8000 : 0;
        buf->InPort |= btn_service ? 0x2000 : 0;
        buf->InPort |= btn_test ? 0x1000 : 0;
        buf->InPort |= btn_select ? 0x800 : 0;
        buf->InPort |= btn_enter ? 0x400 : 0;
    }
	else
    {
		buf->InPort = 0;
	}

	buf->OutPort = 0;

	buf->Coin[0] = coinCount;

    return 1;
}

static bool wasCoin = false;
static bool wasCaps = false;

static DWORD WINAPI InsertCardThread(LPVOID)
{
    static bool keyDown;
    while (true)
    {
        btn_coin = (GetAsyncKeyState('C') & 0x8000);
		btn_service = (GetAsyncKeyState('S') & 0x8000);
		btn_test = (GetAsyncKeyState('T') & 0x8000);
        btn_select = (GetAsyncKeyState(VK_SPACE) & 0x8000);
		btn_enter = (GetAsyncKeyState(VK_RETURN) & 0x8000);

		if (!wasCoin && btn_coin)
		{
			std::cout << "Coin pressed" << std::endl;
            wasCoin = true;
            coinCount++;
		}

		if (wasCoin && !btn_coin)
		{
			wasCoin = false;
		}

        //check if caps lock is enabled
        const bool capsEnabled = GetKeyState(VK_CAPITAL) & 1;

		if (!wasCaps && capsEnabled)
		{
			inputEnabled = !inputEnabled;
			wasCaps = true;

			std::cout << "Input " << (inputEnabled ? "enabled" : "disabled") << std::endl;
		}

		if (wasCaps && !capsEnabled)
		{
			wasCaps = false;
		}

        //insert card with P
		if (GetAsyncKeyState('P') & 0x8000)
		{
			insertingCard = true;
			std::cout << "Inserting card" << std::endl;
		}
        else
        {
            insertingCard = false;
        }

        Sleep(16);
    }
}

BOOL WINAPI MyHandlerRoutine(DWORD dwCtrlType) {
    TerminateProcess(GetCurrentProcess(), 2);
    return TRUE;
}

HANDLE hThread;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        AllocConsole();
        SetConsoleCtrlHandler(MyHandlerRoutine, TRUE);
		freopen("CONOUT$", "w", stdout);
        std::cout << "IO hook active" << std::endl;
        hThread = CreateThread(nullptr, 0, InsertCardThread, nullptr, 0, nullptr);
        break;

    case DLL_PROCESS_DETACH:
        FreeConsole();
		TerminateThread(hThread, 0);
        break;
    }

    return TRUE;
}

