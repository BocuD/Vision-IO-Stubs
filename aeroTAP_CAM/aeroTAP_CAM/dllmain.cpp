#include <windows.h>
#include <chrono>
#include <format>

extern "C" int __stdcall AERO_GetLastError()
{
	return 0;
}

extern "C" bool __stdcall AERO_EnableLog(bool mode)
{
	return true;
}

extern "C" bool __stdcall InitAeroCam(void* hParentWnd, uint32_t nMSG, int nDeviceNo, int nFPS, void* pColor, void* pColorOrg, void* pDepth, int nMode)
{
	return true;
}

extern "C" bool __stdcall InitAeroStereoCam(void* hParentWnd, uint32_t nMSG, int nDeviceNo, uint32_t nFPS, void* pColor, int nWidth, int nHeight, bool bMJPG)
{
	return true;
}

extern "C" void __stdcall ExitAeroCam()
{
}

extern "C" bool __stdcall AERO_SetResolution(int nDevice, int nWidth, int nHeight)
{
	return true;
}

extern "C" int __stdcall AERO_SetZoom(int z)
{
	return 0;
}

extern "C" void __stdcall AERO_SetDepthRange(int min, int max)
{
	
}

extern "C" bool __stdcall AERO_StartCam(int nDevice)
{
	return true;
}

extern "C" void __stdcall AERO_StopCam(int nDevice)
{
	
}

extern "C" void __stdcall AERO_SwitchDevice(int nDevice)
{
	
}

enum IMAGETYPE
{
	IMAGE_ORIGINAL = 0,
	IMAGE_GRAY = 1,
	IMAGE_HISTGRAM = 2,
	IMAGE_RESIZED = 3,
	IMAGE_LASTDIFF = 4,
	IMAGE_WIDE = 5,
	IMAGE_DEPTH = 6,
	IMAGE_RAW = 7,
	IMAGE_DEPTH_RAW = 8,
	IMAGE_DEPTH_DISTANCE = 9
};

extern "C" bool __stdcall AERO_GetImage(void* pBuffer, IMAGETYPE nType, void* nMax, void* nTotal, void* nCount, void* nFrame, void* nP, void* nBlackout)
{
	return true;
}

extern "C" void __stdcall AERO_DoMaskDepth(void* pDepth, int nWidthOut, int nHeightOut, int nMode)
{
	
}

extern "C" void __stdcall AERO_DoMaskDepthByShadow(void* pDepth, int nWidthOut, int nHeightOut)
{
	
}

extern "C" void* __stdcall AERO_GetColorImage(void* _pColor, bool mode, void* pCrop)
{
	return nullptr;
}

extern "C" void* __stdcall AERO_GetGrayImage(void* pGray, bool mode, void* pCrop, void* _pDepth, int nThreshold)
{
	return nullptr;
}

extern "C" bool __stdcall AERO_IsNewFrame(int nDevice)
{
	return true;
}

extern "C" void __stdcall AERO_UpdateFrame(int nDevice)
{

}

extern "C" int __stdcall AERO_GetFPS()
{
	return 30;
}

extern "C" int __stdcall AERO_IsCameraConnected()
{
	return 1;
}

extern "C" void __stdcall AERO_GetSDKVersion(void* szVer)
{

}

extern "C" void __stdcall AERO_GetFWVersion(void* szVer)
{

}

extern "C" void __stdcall AERO_GetSN(void* szSN)
{

}

extern "C" void __stdcall AERO_GetPID(void* szPID)
{

}

extern "C" int __stdcall AERO_GetPType(int nDevice)
{
	return 0;
}

extern "C" void __stdcall AERO_LoadZDTable(void* pZDTable, int mode)
{

}

extern "C" int __stdcall AERO_EnableDepthLog(bool bMode)
{
	return false;
}

extern "C" void __stdcall AERO_LowTexture(bool mode)
{

}

extern "C" void __stdcall AERO_SetDOEPower(int nDeviceNo, int nMode)
{

}

extern "C" void __stdcall AERO_SetEnableNear(int mode)
{

}

extern "C" void __stdcall AERO_SetSavingMode(int nMode)
{

}

extern "C" void __stdcall AERO_SetSkeletonParams(int nRangeToHeads, int nAngle, int nCamHeight, int nAngleAttri)
{

}

extern "C" void __stdcall AERO_EnableSkeletonDetect(bool bMode)
{

}

extern "C" bool __stdcall AERO_isSkeletonValid()
{
	return false;
}

extern "C" bool __stdcall AERO_GetSkeletonPos(int type, void* xyz)
{
	return false;
}

extern "C" bool __stdcall AERO_GetSkeletonPart(int type, void* el)
{
	return false;
}

extern "C" int __stdcall AERO_GetSkeletonPartPoints(int type, void* el, int max)
{
	return 0;
}

extern "C" void __stdcall AERO_DoMaskBySkeleton(void* pBuffer, int nWidthOut, int nHeightOut, int nMode, void* pDdepthW)
{

}

extern "C" bool __stdcall AERO_InitDepthMask(int nDeviceNo)
{
	return false;
}

extern "C" void __stdcall AERO_doMaskDepth(bool bAdd)
{

}

extern "C" void __stdcall AERO_SetEnableDepthMask(bool enable)
{

}

extern "C" void __stdcall AERO_SetDepthMaskRange(int nRange)
{

}

extern "C" void __stdcall AERO_SetMaxDepth(int nMaxDepth)
{

}

extern "C" void __stdcall AERO_doImportMask(const char* szFileName)
{

}

extern "C" void __stdcall AERO_doExportMask(const char* szFileName)
{

}

extern "C" bool __stdcall AERO_doImportMaskPoints(int nWidth, int nHeight, void* pPoints)
{
	return false;
}

extern "C" bool __stdcall AERO_doImportMaskImage(int nWidth, int nHeight, uint16_t* pDepthW)
{
	return false;
}

extern "C" void __stdcall AERO_EnableSkeletonFPSabe(bool bMode)
{

}

extern "C" int __stdcall AERO_IsUSB30(int nCamNo)
{
	return 2;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	return TRUE;
}

