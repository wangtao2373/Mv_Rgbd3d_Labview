#include "Mv3dRgbdApi.h"

#include <string.h>
#include <malloc.h>


#ifdef __cplusplus
extern "C" {
#endif
#ifdef  MV3D_RGBD_API_Ex
#else
#define MV3D_RGBD_API_Ex __declspec(dllexport)
#endif


typedef struct _MV3D_RGBD_GigEDEVICE_INFO_
{
	char                        chManufacturerName[32];             // 设备厂商
	char                        chModelName[32];                    // 设备型号
	char                        chDeviceVersion[32];                // 设备版本
	char                        chManufacturerSpecificInfo[48];     // 设备厂商特殊信息
	char                        chSerialNumber[16];                 // 设备序列号
	char                        chUserDefinedName[16];              // 设备用户自定义名称
	int32_t          enDeviceType;                       // 设备类型：网口、USB
	unsigned char               chMacAddress[8];                    // Mac地址
	int32_t           enIPCfgMode;                        // 当前IP类型
	char                        chCurrentIp[16];                    // 设备当前IP
	char                        chCurrentSubNetMask[16];            // 设备当前子网掩码
	char                        chDefultGateWay[16];                // 设备默认网关
	char                        chNetExport[16];                    // 网口IP地址
	uint8_t                     nReserved[16];                      // 保留字节
} MV3D_RGBD_GigEDEVICE_INFO;

typedef struct _MV3D_RGBD_U3DEVICE_INFO_
{
	char                        chManufacturerName[32];             // 设备厂商
	char                        chModelName[32];                    // 设备型号
	char                        chDeviceVersion[32];                // 设备版本
	char                        chManufacturerSpecificInfo[48];     // 设备厂商特殊信息
	char                        chSerialNumber[16];                 // 设备序列号
	char                        chUserDefinedName[16];              // 设备用户自定义名称
	int32_t          enDeviceType;                       // 设备类型：网口、USB
	uint32_t                    nVendorId;                          // 供应商ID号 
	uint32_t                    nProductId;                         // 产品ID号 
	int32_t         enUsbProtocol;                      // 支持的USB协议
	char                        chDeviceGUID[64];                   // 设备GUID号
	uint8_t                     nReserved[16];                      // 保留字节 
} MV3D_RGBD_U3DEVICE_INFO;



/************************************************************************
*  @fn     MV3D_RGBD_GetGigEDeviceList()
*  @brief  获取GigE设备列表
*  @param  nDeviceType                 [IN]            设备类型,见Mv3dRgbdDeviceType,可全部获取(DeviceType_Ethernet | DeviceType_USB)
*  @param  pstDeviceInfos              [IN OUT]        设备列表
*  @param  nMaxDeviceCount             [IN]            设备列表缓存最大个数
*  @param  pDeviceCount                [OUT]           填充列表中设备个数
*  @return 成功，返回MV3D_RGBD_OK；错误，返回错误码

*  @fn     MV3D_RGBD_GetGigEDeviceList()
*  @brief  Gets GigE 3D cameras list
*  @param  nDeviceType                 [IN]            device type，refer to Mv3dRgbdDeviceType，get all(DeviceType_Ethernet | DeviceType_USB)
*  @param  pstDeviceInfos              [IN OUT]        devices list
*  @param  nMaxDeviceCount             [IN]            Max Number of device list caches
*  @param  pDeviceCount                [OUT]           number of devices in the fill list
*  @return Success, return MV3D_RGBD_OK. Failure, return error code
************************************************************************/
MV3D_RGBD_API_Ex MV3D_RGBD_STATUS MV3D_RGBD_GetGigEDeviceList(MV3D_RGBD_GigEDEVICE_INFO* pstGigEDeviceInfos, uint32_t nMaxDeviceCount, uint32_t* pDeviceCount);

/************************************************************************
*  @fn     MV3D_RGBD_GetU3DeviceList()
*  @brief  获取USB设备列表
*  @param  nDeviceType                 [IN]            设备类型,见Mv3dRgbdDeviceType,可全部获取(DeviceType_Ethernet | DeviceType_USB)
*  @param  pstDeviceInfos              [IN OUT]        设备列表
*  @param  nMaxDeviceCount             [IN]            设备列表缓存最大个数
*  @param  pDeviceCount                [OUT]           填充列表中设备个数
*  @return 成功，返回MV3D_RGBD_OK；错误，返回错误码

*  @fn     MV3D_RGBD_GetU3DeviceList()
*  @brief  Gets USB 3D cameras list
*  @param  nDeviceType                 [IN]            device type，refer to Mv3dRgbdDeviceType，get all(DeviceType_Ethernet | DeviceType_USB)
*  @param  pstDeviceInfos              [IN OUT]        devices list
*  @param  nMaxDeviceCount             [IN]            Max Number of device list caches
*  @param  pDeviceCount                [OUT]           number of devices in the fill list
*  @return Success, return MV3D_RGBD_OK. Failure, return error code
************************************************************************/
MV3D_RGBD_API_Ex MV3D_RGBD_STATUS MV3D_RGBD_GetU3DeviceList(MV3D_RGBD_U3DEVICE_INFO* pstU3DeviceInfos, uint32_t nMaxDeviceCount, uint32_t* pDeviceCount);

/************************************************************************
*  @fn     MV3D_RGBD_OpenGigEDevice()
*  @brief  打开GigE设备
*  @param  handle                      [IN OUT]        相机句柄
*  @param  pstDeviceInfo               [IN]            枚举的设备信息，默认为空，打开第一个相机
*  @return 成功，返回MV3D_RGBD_OK；错误，返回错误码

*  @fn     MV3D_RGBD_OpenDevice()
*  @brief  open GigE device
*  @param  handle                      [IN OUT]        camera handle
*  @param  pstDeviceInfo               [IN]            enum camera info. the default is null, open first camera
*  @return Success, return MV3D_RGBD_OK. Failure, return error code
************************************************************************/
MV3D_RGBD_API_Ex MV3D_RGBD_STATUS MV3D_RGBD_OpenGigEDevice(HANDLE *handle, MV3D_RGBD_GigEDEVICE_INFO* pstGigeDeviceInfo = NULL);

/************************************************************************
*  @fn     MV3D_RGBD_OpenU3Device()
*  @brief  打开USB设备
*  @param  handle                      [IN OUT]        相机句柄
*  @param  pstDeviceInfo               [IN]            枚举的设备信息，默认为空，打开第一个相机
*  @return 成功，返回MV3D_RGBD_OK；错误，返回错误码

*  @fn     MV3D_RGBD_OpenDevice()
*  @brief  open USB device
*  @param  handle                      [IN OUT]        camera handle
*  @param  pstDeviceInfo               [IN]            enum camera info. the default is null, open first camera
*  @return Success, return MV3D_RGBD_OK. Failure, return error code
************************************************************************/
MV3D_RGBD_API_Ex MV3D_RGBD_STATUS MV3D_RGBD_OpenU3Device(HANDLE *handle, MV3D_RGBD_U3DEVICE_INFO* pstU3DeviceInfo = NULL);

/************************************************************************
*  @fn     MV3D_RGBD_GetDeviceInfo
*  @brief  获取当前设备的详细信息
*  @param  handle                      [IN]            相机句柄
*  @param  pstDevInfo                  [IN][OUT]       返回给调用者有关相机设备信息结构体指针
*  @return 成功,MV3D_RGBD_OK,失败,返回错误码

*  @fn     MV3D_RGBD_GetDeviceInfo
*  @brief  Get current device information
*  @param  handle                      [IN]            camera handle
*  @param  pstDevInfo                  [IN][OUT]       Structure pointer of device information
*  @return Success, return MV3D_RGBD_OK. Failure, return error code
************************************************************************/
MV3D_RGBD_API_Ex MV3D_RGBD_STATUS MV3D_RGBD_GetU3DeviceInfo(HANDLE handle, MV3D_RGBD_U3DEVICE_INFO* pstDevInfo);

/************************************************************************
*  @fn     MV3D_RGBD_GetDeviceInfo
*  @brief  获取当前设备的详细信息
*  @param  handle                      [IN]            相机句柄
*  @param  pstDevInfo                  [IN][OUT]       返回给调用者有关相机设备信息结构体指针
*  @return 成功,MV3D_RGBD_OK,失败,返回错误码

*  @fn     MV3D_RGBD_GetDeviceInfo
*  @brief  Get current device information
*  @param  handle                      [IN]            camera handle
*  @param  pstDevInfo                  [IN][OUT]       Structure pointer of device information
*  @return Success, return MV3D_RGBD_OK. Failure, return error code
************************************************************************/
MV3D_RGBD_API_Ex MV3D_RGBD_STATUS MV3D_RGBD_GetGigEDeviceInfo(HANDLE handle, MV3D_RGBD_GigEDEVICE_INFO* pstDevInfo);


/************************************************************************
*  @fn     MV3D_RGBD_YUV422ToRGB
*  @brief  将YUV422转换为RGB
*  @param  pYuvImgge                  [IN][OUT]       输入的YUV422数据
*  @param  pRgbImage                  [IN][OUT]       输出的RGB数据
*  @return 成功,MV3D_RGBD_OK,失败,返回错误码，不支持的格式

*  @fn     MV3D_RGBD_GetDeviceInfo
*  @brief  yuv422 image convert to rgb image
*  @param  pYuvImgge                  [IN][OUT]       In YUV422 data
*  @param  pRgbImage                  [IN][OUT]       Out RGB data
*  @return Success, return MV3D_RGBD_OK. Failure, return error code
************************************************************************/
MV3D_RGBD_API_Ex MV3D_RGBD_STATUS MV3D_RGBD_YUV422ToRGB(MV3D_RGBD_IMAGE_DATA *pYuvImgge, MV3D_RGBD_IMAGE_DATA* pRgbImage);















MV3D_RGBD_STATUS  MV3D_RGBD_GetU3DeviceInfo(HANDLE handle, MV3D_RGBD_U3DEVICE_INFO* pstU3DevInfo)
{
	MV3D_RGBD_DEVICE_INFO* pstDeviceInfo = new MV3D_RGBD_DEVICE_INFO();
	MV3D_RGBD_STATUS ret = MV3D_RGBD_GetDeviceInfo(handle, pstDeviceInfo);
	//将MV3D_RGBD_DEVICE_INFO转换为MV3D_RGBD_U3DEVICE_INFO

	strcpy_s(pstU3DevInfo->chDeviceVersion, pstDeviceInfo->chDeviceVersion);
	strcpy_s(pstU3DevInfo->chManufacturerName, pstDeviceInfo->chManufacturerName);
	strcpy_s(pstU3DevInfo->chManufacturerSpecificInfo, pstDeviceInfo->chManufacturerSpecificInfo);
	strcpy_s(pstU3DevInfo->chModelName, pstDeviceInfo->chModelName);
	strcpy_s(pstU3DevInfo->chSerialNumber, pstDeviceInfo->chSerialNumber);
	strcpy_s(pstU3DevInfo->chUserDefinedName, pstDeviceInfo->chUserDefinedName);
	pstU3DevInfo->enDeviceType = pstDeviceInfo->enDeviceType;
	strcpy_s(pstU3DevInfo->chDeviceGUID, pstDeviceInfo->SpecialInfo.stUsbInfo.chDeviceGUID);
	pstU3DevInfo->enUsbProtocol = pstDeviceInfo->SpecialInfo.stUsbInfo.enUsbProtocol;
	pstU3DevInfo->nProductId = pstDeviceInfo->SpecialInfo.stUsbInfo.nProductId;
	pstU3DevInfo->nVendorId = pstDeviceInfo->SpecialInfo.stUsbInfo.nVendorId;
	*pstU3DevInfo->nReserved = *pstDeviceInfo->SpecialInfo.stUsbInfo.nReserved;
	return ret;
}

MV3D_RGBD_STATUS  MV3D_RGBD_GetGigEDeviceInfo(HANDLE handle, MV3D_RGBD_GigEDEVICE_INFO* pstGigeDevInfo)
{
	MV3D_RGBD_DEVICE_INFO* pstDeviceInfo = new MV3D_RGBD_DEVICE_INFO();
	MV3D_RGBD_STATUS ret = MV3D_RGBD_GetDeviceInfo(handle, pstDeviceInfo);
	//	将MV3D_RGBD_DEVICE_INFO转换为MV3D_RGBD_GigEDEVICE_INFO

	strcpy_s(pstGigeDevInfo->chDeviceVersion, pstDeviceInfo->chDeviceVersion);
	strcpy_s(pstGigeDevInfo->chManufacturerName, pstDeviceInfo->chManufacturerName);
	strcpy_s(pstGigeDevInfo->chManufacturerSpecificInfo, pstDeviceInfo->chManufacturerSpecificInfo);
	strcpy_s(pstGigeDevInfo->chModelName, pstDeviceInfo->chModelName);
	strcpy_s(pstGigeDevInfo->chSerialNumber, pstDeviceInfo->chSerialNumber);
	strcpy_s(pstGigeDevInfo->chUserDefinedName, pstDeviceInfo->chUserDefinedName);
	pstGigeDevInfo->enDeviceType = pstDeviceInfo->enDeviceType;

	strcpy_s(pstGigeDevInfo->chCurrentIp, pstDeviceInfo->SpecialInfo.stNetInfo.chCurrentIp);
	strcpy_s(pstGigeDevInfo->chCurrentSubNetMask, pstDeviceInfo->SpecialInfo.stNetInfo.chCurrentSubNetMask);
	strcpy_s(pstGigeDevInfo->chDefultGateWay, pstDeviceInfo->SpecialInfo.stNetInfo.chDefultGateWay);
	*pstGigeDevInfo->chMacAddress = *pstDeviceInfo->SpecialInfo.stNetInfo.chMacAddress;
	strcpy_s(pstGigeDevInfo->chNetExport, pstDeviceInfo->SpecialInfo.stNetInfo.chNetExport);
	pstGigeDevInfo->enIPCfgMode = pstDeviceInfo->SpecialInfo.stNetInfo.enIPCfgMode;
	*pstGigeDevInfo->nReserved = *pstDeviceInfo->SpecialInfo.stNetInfo.nReserved;
	return ret;
}

MV3D_RGBD_STATUS MV3D_RGBD_GetGigEDeviceList(MV3D_RGBD_GigEDEVICE_INFO* pstGigEDeviceInfos, uint32_t nMaxDeviceCount, uint32_t* pDeviceCount)
{
	MV3D_RGBD_DEVICE_INFO* pstDeviceInfos = (MV3D_RGBD_DEVICE_INFO*)pstGigEDeviceInfos;
	MV3D_RGBD_STATUS ret = MV3D_RGBD_GetDeviceList(DeviceType_Ethernet, pstDeviceInfos, nMaxDeviceCount, pDeviceCount);
	//将MV3D_RGBD_DEVICE_INFO转换为MV3D_RGBD_GigEDEVICE_INFO
	pstGigEDeviceInfos = (MV3D_RGBD_GigEDEVICE_INFO*)pstDeviceInfos;
	return ret;
}

MV3D_RGBD_STATUS  MV3D_RGBD_GetU3DeviceList(MV3D_RGBD_U3DEVICE_INFO* pstU3DeviceInfos, uint32_t nMaxDeviceCount, uint32_t* pDeviceCount)
{
	MV3D_RGBD_DEVICE_INFO* pstDeviceInfos = (MV3D_RGBD_DEVICE_INFO*)pstU3DeviceInfos;
	MV3D_RGBD_STATUS ret = MV3D_RGBD_GetDeviceList(DeviceType_USB, pstDeviceInfos, nMaxDeviceCount, pDeviceCount);
	//将MV3D_RGBD_DEVICE_INFO转换为MV3D_RGBD_GigEDEVICE_INFO
	pstU3DeviceInfos = (MV3D_RGBD_U3DEVICE_INFO*)pstDeviceInfos;
	return ret;
}

MV3D_RGBD_STATUS MV3D_RGBD_OpenGigEDevice(HANDLE *handle, MV3D_RGBD_GigEDEVICE_INFO* pstGigeDeviceInfo) {
	MV3D_RGBD_DEVICE_INFO* pstDeviceInfo = new MV3D_RGBD_DEVICE_INFO();

	//将MV3D_RGBD_GigEDEVICE_INFO转换为MV3D_RGBD_DEVICE_INFO，方便MV3D_RGBD_OpenDevice调用

	strcpy_s(pstDeviceInfo->chDeviceVersion, pstGigeDeviceInfo->chDeviceVersion);
	strcpy_s(pstDeviceInfo->chManufacturerName, pstGigeDeviceInfo->chManufacturerName);
	strcpy_s(pstDeviceInfo->chManufacturerSpecificInfo, pstGigeDeviceInfo->chManufacturerSpecificInfo);
	strcpy_s(pstDeviceInfo->chModelName, pstGigeDeviceInfo->chModelName);
	strcpy_s(pstDeviceInfo->chSerialNumber, pstGigeDeviceInfo->chSerialNumber);
	strcpy_s(pstDeviceInfo->chUserDefinedName, pstGigeDeviceInfo->chUserDefinedName);
	pstDeviceInfo->enDeviceType = (Mv3dRgbdDeviceType)pstGigeDeviceInfo->enDeviceType;
	strcpy_s(pstDeviceInfo->SpecialInfo.stNetInfo.chCurrentIp, pstGigeDeviceInfo->chCurrentIp);
	strcpy_s(pstDeviceInfo->SpecialInfo.stNetInfo.chCurrentSubNetMask, pstGigeDeviceInfo->chCurrentSubNetMask);
	strcpy_s(pstDeviceInfo->SpecialInfo.stNetInfo.chDefultGateWay, pstGigeDeviceInfo->chDefultGateWay);
	*pstDeviceInfo->SpecialInfo.stNetInfo.chMacAddress = *pstGigeDeviceInfo->chMacAddress;
	strcpy_s(pstDeviceInfo->SpecialInfo.stNetInfo.chNetExport, pstGigeDeviceInfo->chNetExport);
	pstDeviceInfo->SpecialInfo.stNetInfo.enIPCfgMode = (Mv3dRgbdIpCfgMode)pstGigeDeviceInfo->enIPCfgMode;
	*pstDeviceInfo->SpecialInfo.stNetInfo.nReserved = *pstGigeDeviceInfo->nReserved;
	MV3D_RGBD_STATUS ret = MV3D_RGBD_OpenDevice(handle, pstDeviceInfo);
	return ret;
}

MV3D_RGBD_STATUS MV3D_RGBD_OpenU3Device(HANDLE *handle, MV3D_RGBD_U3DEVICE_INFO* pstU3DeviceInfo) {
	MV3D_RGBD_DEVICE_INFO* pstDeviceInfo = new MV3D_RGBD_DEVICE_INFO();
	//将MV3D_RGBD_U3DEVICE_INFO转换为MV3D_RGBD_DEVICE_INFO，方便MV3D_RGBD_OpenDevice调用
	strcpy_s(pstDeviceInfo->chDeviceVersion, pstU3DeviceInfo->chDeviceVersion);
	strcpy_s(pstDeviceInfo->chManufacturerName, pstU3DeviceInfo->chManufacturerName);
	strcpy_s(pstDeviceInfo->chManufacturerSpecificInfo, pstU3DeviceInfo->chManufacturerSpecificInfo);
	strcpy_s(pstDeviceInfo->chModelName, pstU3DeviceInfo->chModelName);
	strcpy_s(pstDeviceInfo->chSerialNumber, pstU3DeviceInfo->chSerialNumber);
	strcpy_s(pstDeviceInfo->chUserDefinedName, pstU3DeviceInfo->chUserDefinedName);
	pstDeviceInfo->enDeviceType = (Mv3dRgbdDeviceType)pstU3DeviceInfo->enDeviceType;
	*pstDeviceInfo->SpecialInfo.stUsbInfo.chDeviceGUID = *pstU3DeviceInfo->chDeviceGUID;
	pstDeviceInfo->SpecialInfo.stUsbInfo.enUsbProtocol = (Mv3dRgbdUsbProtocol)pstU3DeviceInfo->enUsbProtocol;
	pstDeviceInfo->SpecialInfo.stUsbInfo.nProductId = pstU3DeviceInfo->nProductId;
	*pstDeviceInfo->SpecialInfo.stUsbInfo.nReserved = *pstU3DeviceInfo->nReserved;
	pstDeviceInfo->SpecialInfo.stUsbInfo.nVendorId = pstU3DeviceInfo->nVendorId;

	MV3D_RGBD_STATUS ret = MV3D_RGBD_OpenDevice(handle, pstDeviceInfo);
	return ret;
}



MV3D_RGBD_STATUS MV3D_RGBD_YUV422ToRGB(MV3D_RGBD_IMAGE_DATA *pYuvImgge, MV3D_RGBD_IMAGE_DATA* pRgbImage) {
	//2.整数形式（减少计算量）未量化     R，G，B~[0, 255]   U，V~[0, 255]
	//R = Y + ((360 * (V - 128)) >> 8);
	//G = Y - (((88 * (U - 128) + 184 * (V - 128))) >> 8);
	//B = Y + ((455 * (U - 128)) >> 8);
	pRgbImage->enImageType = Mv3dRgbdImageType::ImageType_RGB8_Planar;
	pRgbImage->nDataLen = pYuvImgge->nHeight*pYuvImgge->nWidth * 3;
	pRgbImage->nFrameNum = pYuvImgge->nFrameNum;
	pRgbImage->nHeight = pYuvImgge->nHeight;
	pRgbImage->nTimeStamp = pYuvImgge->nTimeStamp;
	pRgbImage->nWidth = pYuvImgge->nWidth;
	static uint8_t buffer[1280 * 720 * 9];
	for (size_t i = 0; i < pRgbImage->nWidth*pRgbImage->nHeight; i += 2)
	{
		uint16_t Y1 = (uint16_t)pYuvImgge->pData[i * 2];
		uint16_t U1 = (uint16_t)(pYuvImgge->pData[i * 2 + 1]);
		uint16_t Y2 = (uint16_t)pYuvImgge->pData[i * 2 + 2];
		uint16_t V2 = (uint16_t)(pYuvImgge->pData[i * 2 + 3]);

		buffer[i * 3 + 0] = (uint8_t)(Y1 + ((360 * (V2 - 128)) >> 8));								//R通道
		buffer[i * 3 + 1] = (uint8_t)(Y1 - (((88 * (U1 - 128) + 184 * (V2 - 128))) >> 8));			//G通道
		buffer[i * 3 + 2] = (uint8_t)(Y1 + ((455 * (U1 - 128)) >> 8));								//B通道
		buffer[i * 3 + 3] = (uint8_t)(Y2 + ((360 * (V2 - 128)) >> 8));								//R通道
		buffer[i * 3 + 4] = (uint8_t)(Y2 - (((88 * (U1 - 128) + 184 * (V2 - 128))) >> 8));			//G通道
		buffer[i * 3 + 5] = (uint8_t)(Y2 + ((455 * (U1 - 128)) >> 8));								//B通道
	}
	pRgbImage->pData = buffer;
	return 0;
}












#ifdef __cplusplus
}
#endif
