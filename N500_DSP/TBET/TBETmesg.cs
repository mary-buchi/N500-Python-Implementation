using System;

using Buchi.HWToolbox.Common;

namespace Buchi.DeviceInterface.Ethernet
{
    public enum ETBChannelMessageType
    {
        eInitial, eReply
    }

    public enum ETBChannelExpectedReturn
    {
        eNone, eEvent
    }

    public enum ETBChannelCommand
    {
        eObjCrDeleteObject = 0,
        eObjCrMotorStepper = 1,
        eObjCrMeasurementChannel = 2,
        eObjCrSensorAnalog = 3,
        eObjCrSensorDigital = 4,
        eObjCrOutputAnalog = 5,
        eObjCrOutputDigital = 6,
        eObjCrTemperatureControl = 7,
        eObjCrPowerControl = 8,
        eObjCrWedgeControl = 9,
        eObjCrEventSource = 10,
        eObJCrPersistentObjMananager = 11,
        eObjCrDiagnostics = 12,
        eObjCrSystem = 13,
        eObjCrI2CTempSensorDS1631Z = 14,
        eObjCrI2CAdcMax1037 = 15,
        eObjCrI2CDigitalPotiAD5245 = 16,

        eCmdStartup = 20,
        eCmdShutdown = 21,

        eCmdStepperMoveAbsolute = 30,
        eCmdStepperMoveRelative = 31,
        eCmdStepperMoveManual = 32,
        eCmdStepperGetPosition = 35,
        eCmdStepperStop = 36,
        eCmdStepperStopImmediately = 37,
        eCmdStepperSetProfile = 40,
        eCmdStepperSetSpeed = 41,
        eCmdStepperLimitAdd = 45,
        eCmdStepperLimitConfig = 46,
        eCmdStepperLimitGetFootPrint = 47,
        eCmdStepperLimitActivate = 48,
        eCmdStepperLimitDeactivate = 49,
        eCmdStepperHome = 55,
        eCmdStepperHomeSetPosition = 56,
        eCmdStepperSetConfig = 57,
        eCmdStepperHome2 = 58,

        eCmdMeasChannelSetProfile = 60,
        eCmdMeasChannelInitialize = 61,
        eCmdMeasChannelStart = 62,
        eCmdMeasChannelStop = 63,
        eCmdMeasChannelGetDataPackage = 64,

        eCmdSensorAnalogGetValue = 70,
        eCmdSensorDigitalIsActive = 71,
        eCmdSensorDigitalSetPolarity = 72,
        eCmdSensorDigitalGetPolarity = 73,

        eCmdOutputAnalogSetValue = 80,
        eCmdOutputAnalogGetValue = 81,
        eCmdOutputDigitalSet = 85,
        eCmdOutputDigitalClear = 86,
        eCmdOutputDigitalIsActive = 87,
        eCmdOutputDigitalSetPolarity = 88,
        eCmdOutputDigitalGetPolarity = 89,

        eCmdTempCtrlSetProfile = 100,
        eCmdTempCtrlSetConfig = 101,
        eCmdTempCtrlGetTemperature = 102,
        eCmdTempCtrlStart = 103,
        eCmdTempCtrlStop = 104,

        eCmdPwrCtrlSetProfile = 110,
        eCmdPwrCtrlSetConfig = 111,
        eCmdPwrCtrlStart = 112,
        eCmdPwrCtrlStop = 113,
        eCmdPwrCtrlPowerOn = 114,
        eCmdPwrCtrlPowerOff = 115,

        eCmdWedgeCtrlSetProfile = 120,
        eCmdWedgeCtrlSetConfig = 121,
        eCmdWedgeCtrlPark = 122,
        eCmdWedgeCtrlInitialize = 123,
        eCmdWedgeCtrlReference = 124,
        eCmdWedgeCtrlStart = 125,
        eCmdWedgeCtrlStop = 126,
        eCmdWedgeCtrlGetDacZeroCurrent = 127,

        eCmdEventSourceRegister = 130,
        eCmdEventSourceUnregister = 131,

        eCmdPsObjReadParameters = 140,
        eCmdPsObjWriteParameter = 141,
        eCmdPsObjStartMonitoring = 142,
        eCmdPsObjStopMonitoring = 143,
        eCmdPsObjSave = 144,
        eCmdPsObjReadLifeTimeCounter = 145,
        eCmdPsObjWriteLifeTimeCounter = 146,
        eCmdPsObjReadIdentifications = 147,
        eCmdPsObjWriteIdentification = 148,
        eCmdPsObjSetConfig = 149,
        eCmdPsObjReset = 150,
        eCmdPsObjCellUndocked = 151,

        eCmdDiagReadDWord = 160,
        eCmdDiagWriteDWord = 161,
        eCmdDiagEnableEventSignal = 162,
        eCmdDiagDisableEventSignal = 163,
        eCmdDiagPCSetNomVoltage = 164,
        eCmdDiagPCLampSelection = 165,
        eCmdDiagPCLampOnOff = 166,
        eCmdDiagPCGetActCurrent = 167,
        eCmdDiagPCGetActVoltage = 168,
        eCmdDiagPCGetLampIdentification = 169,
        eCmdDiagWCGetActVelocityCounts = 170,
        eCmdDiagWCGetLastVelocityCounts = 171,
        eCmdDiagWCGetPosition = 172,
        eCmdDiagWCInitializeDAC = 173,
        eCmdDiagWCSetDACValue = 174,
        eCmdDiagReadFpgaArtNr = 175,
        eCmdDiagReadFpgaSwVersion = 176,
        eCmdDiagI2CEpromByteRead = 177,
        eCmdDiagI2CEpromByteWrite = 178,
        eCmdDiagGetDigitsLaserLevelDetection = 179,
        eCmdDiagReleaseHWReset = 180,
        eCmdDiagDisableWatchdog = 181,
        eCmdDiagGetOsVersion = 182,
        eCmdDiagGetUsedMemory = 183,
        eCmdDiagGetMemoryAllocInfo = 184,

        eCmdSysGetState = 200,
        eCmdSysReset = 201,
        eCmdSysStart = 202,
        eCmdSysReadIdentifications = 203,
        eCmdSysWriteIdentification = 204,
        eCmdSysReadSWVersions = 205,
        eCmdSysDownloadSoftware = 206,
        eCmdSysSetInterfaceConfig = 207,
        eCmdSysSetComponentState = 208,
        eCmdSysGetObjectList = 209,
        eCmdSysSetSystemTime = 210,
        eCmdSysRegisterClient = 211,
        eCmdSysGetVersion = 212,
        eCmdSysSetStandbyTimeout = 213,
        eCmdSysPing = 214,
        eCmdSysGetOsVersion = 215,
        eCmdSysGetFpgaVersion = 216,
        eCmdSysStartDownload = 217,
        eCmdSysDownloadSoftwareComponent = 218,
        eCmdSysEndDownload = 219,

        eCmdI2CTempDS1631ZStartup = 250,
        eCmdI2CTempDS1631ZShutdown = 251,
        eCmdI2CTempDS1631ZSetConfig = 252,
        eCmdI2CTempDS1631ZGetValue = 253,

        eCmdI2CAdcMax1037Startup = 260,
        eCmdI2CAdcMax1037Shutdown = 261,
        eCmdI2CAdcMax1037Initialize = 262,
        eCmdI2CAdcMax1037GetData = 263,

        eCmdI2CPotiAD5245Startup = 270,
        eCmdI2CPotiAD5245Shutdown = 271,
        eCmdI2CPotiAD5245WriteValue = 272,
        eCmdI2CPotiAD5245ReadValue = 273,

        eCmdNameConnection = 300,
    }

    public class CTBChannelMessage
    {
        protected const int m_iObjRefVersionLength = 32;
        protected const int m_iMessageBaseSize = m_iObjRefVersionLength + 32;
        protected uint m_uiTelegramSize;
        protected uint m_uiID;
        protected ETBChannelCommand m_eCommand;
        protected ETBChannelExpectedReturn m_eExpectedReturn;
        protected uint m_uiObjRefID;
        protected int m_iData;
        protected ETBChannelMessageType m_eType;
        protected uint m_uiExceptionID;
        protected string m_sObjRefVersion;

        // properties
        public uint ID { get { return m_uiID; } }
        public int Data { get { return m_iData; } }
        public uint ObjID { get { return m_uiObjRefID; } }
        public string ObjVersion { get { return m_sObjRefVersion; } }
        public uint ExceptionID { get { return m_uiExceptionID; } }
        public ETBChannelCommand Command { get { return m_eCommand; } }

        public CTBChannelMessage(byte[] p_byStream)
        {
            UnSerialize(p_byStream);
        }

        /// <summary>
        ///  returns m_iData as default return value
        /// </summary>
        /// <returns></returns>
        public virtual object GetReturnValue()
        {
            // return m_iData as default return value
            return m_iData;
        }

        unsafe protected virtual void UnSerialize(byte[] p_byStream)
        {
            fixed (byte* pStream = p_byStream)
            {
                m_uiTelegramSize = *((uint*)pStream);
                m_uiID = *((uint*)(pStream + 4));
                m_eCommand = *((ETBChannelCommand*)(pStream + 8));
                m_eExpectedReturn = *((ETBChannelExpectedReturn*)(pStream + 12));
                m_uiObjRefID = *((uint*)(pStream + 16));
                m_iData = *((int*)(pStream + 20));
                m_eType = *((ETBChannelMessageType*)(pStream + 24));
                m_uiExceptionID = *((uint*)(pStream + 28));

                // restore string
                m_sObjRefVersion = System.Runtime.InteropServices.Marshal.PtrToStringAuto((IntPtr)(pStream + 32));
            }
        }
    }

    public class CTBChannelMessageMeasurementChannelDataPackage : CTBChannelMessage
    {
        private HWToolbox.Common.CTBMeasurementChannelDataPackage m_DataPackage;

        public CTBChannelMessageMeasurementChannelDataPackage(byte[] p_byStream)
            : base(p_byStream)
        {
        }

        /// <summary>
        ///  returns the current data package
        /// </summary>
        /// <returns></returns>
        public override object GetReturnValue()
        {
            // return m_iData as default return value
            return m_DataPackage;
        }

        unsafe protected override void UnSerialize(byte[] p_byStream)
        {
            // unserialize base stuff
            base.UnSerialize(p_byStream);

            fixed (byte* pStream = p_byStream)
            {
                uint l_uiID = *((uint*)(pStream + m_iMessageBaseSize));
                uint l_uiSize = *((uint*)(pStream + m_iMessageBaseSize + 4)) / 2;

                if (l_uiSize == 0)
                {
                    m_DataPackage = null;
                }
                else
                {
                    byte[] l_byLaserData = new byte[l_uiSize];
                    byte[] l_byDetectorData = new byte[l_uiSize];
                    System.Runtime.InteropServices.Marshal.Copy((IntPtr)(pStream + m_iMessageBaseSize + 8), l_byLaserData, 0, (int)l_uiSize);
                    System.Runtime.InteropServices.Marshal.Copy((IntPtr)(pStream + m_iMessageBaseSize + 8 + l_uiSize), l_byDetectorData, 0, (int)l_uiSize);
                    m_DataPackage = new CTBMeasurementChannelDataPackage(l_uiID, l_byLaserData, l_byDetectorData);
                }
            }
        }
    }

}
