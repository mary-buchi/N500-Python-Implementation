using System;

namespace Buchi.HWToolbox.Common
{
    public class CTBMeasurementChannelDataPackage : IDisposable
    {
        // data package identification and size
        private uint m_uiID;
        private uint m_uiSize;

        // data streams
        private byte[] m_byLaserDataStream;
        private byte[] m_byDetectorDataStream;

        // property access
        public uint ID { get { return m_uiID; } }
        public byte[] LaserDataStream { get { return m_byLaserDataStream; } }
        public byte[] DetectorDataStream { get { return m_byDetectorDataStream; } }
        public uint Size { get { return m_uiSize; } }

        /// <summary>
        /// the highest eight bits of each data sample (32 Bit) is used for bitwise status information
        /// the highest bit marks the data point as a forward scan, the next bit as a reverse scan, etc.
        /// The highest bit is used for signed / unsigned information and therefore not used for status information!
        /// </summary>
        /// 
        public const uint m_uiStatusBitMask = 0xFF000000;
        public const uint m_ui24BitValueSignBit = 0x00800000;
        public const uint m_ui32BitValueSignMask = 0xFF000000;
        public const uint m_uiBitForwardScan = 0x80000000;
        public const uint m_uiBitReverseScan = 0x40000000;
        public const uint m_uiBitOverflow = 0x20000000;
        public const uint m_uiBitError = 0x10000000;

        /// <summary>
        /// construction
        /// </summary>
        /// <param name="p_uiID">ID of the ongoing data transfer cycle</param>
        /// <param name="p_byLaserDataStream">reference to laser data byte stream</param>
        /// <param name="p_byDetectorDataStream">reference to detector data byte stream</param>
        public CTBMeasurementChannelDataPackage(uint p_uiID, byte[] p_byLaserDataStream, byte[] p_byDetectorDataStream)
        {
            m_uiID = p_uiID;
            m_byLaserDataStream = p_byLaserDataStream;
            m_byDetectorDataStream = p_byDetectorDataStream;

            m_uiSize = (uint)m_byLaserDataStream.Length;
        }

        /// <summary>
        /// returns the converted data and status information of the current data package
        /// in a usable form
        /// </summary>
        /// <param name="p_dbLaserData">array of laser sample data points</param>
        /// <param name="p_dbDetectorData">array of detector sample data points</param>
        /// <param name="p_uiStatus">array with status information to each data point</param>
        public void GetData(out double[] p_dbLaserData, out double[] p_dbDetectorData, out uint[] p_uiStatus)
        {
            int l_iNoOfDataPoints = (int)(m_byLaserDataStream.Length / 4);

            // create arrays
            p_dbLaserData = new double[l_iNoOfDataPoints];
            p_dbDetectorData = new double[l_iNoOfDataPoints];
            p_uiStatus = new uint[l_iNoOfDataPoints];
            uint l_uiValue, l_uiStatus;
            for (int l_iCnt = 0; l_iCnt < l_iNoOfDataPoints; l_iCnt++)
            {
                // laser data point
                l_uiValue = ((uint)m_byLaserDataStream[l_iCnt * 4 + 3]) << 24 |
                              ((uint)m_byLaserDataStream[l_iCnt * 4 + 2]) << 16 |
                              ((uint)m_byLaserDataStream[l_iCnt * 4 + 1]) << 8 |
                              (uint)m_byLaserDataStream[l_iCnt * 4];

                // extract status
                l_uiStatus = l_uiValue & m_uiStatusBitMask;

                // mask out status in the value
                l_uiValue &= ~m_uiStatusBitMask;

                // check for sign bit
                if ((l_uiValue & m_ui24BitValueSignBit) != 0)
                {
                    l_uiValue |= m_ui32BitValueSignMask;
                }

                p_dbLaserData[l_iCnt] = (double)(int)l_uiValue;
                p_uiStatus[l_iCnt] = l_uiStatus;

                // detector data point
                l_uiValue = ((uint)m_byDetectorDataStream[l_iCnt * 4 + 3]) << 24 |
                                ((uint)m_byDetectorDataStream[l_iCnt * 4 + 2]) << 16 |
                                ((uint)m_byDetectorDataStream[l_iCnt * 4 + 1]) << 8 |
                                (uint)m_byDetectorDataStream[l_iCnt * 4];

                // extract status
                l_uiValue &= ~m_uiStatusBitMask;

                // check for sign bit
                if ((l_uiValue & m_ui24BitValueSignBit) != 0)
                {
                    l_uiValue |= m_ui32BitValueSignMask;
                }

                p_dbDetectorData[l_iCnt] = (double)(int)l_uiValue;
            }
        }

        /// <summary>
        /// reset references to huge arrays to zero
        /// </summary>
        public void Dispose()
        {
            m_byLaserDataStream = null;
            m_byDetectorDataStream = null;
        }
    }
}
