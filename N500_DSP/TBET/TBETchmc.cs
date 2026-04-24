using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Buchi.DeviceInterface.Ethernet
{
    public class CTBChannelMeasurementChannels
    {
        /// <summary>
        ///  converts a byte stream into a usable message object
        /// </summary>
        /// <param name="l_byDataPackage"></param>
        /// <returns></returns>
        public CTBChannelMessage UnwrapDataPackage(byte[] l_byDataPackage)
        {
            // perform default unwrapping
            CTBChannelMessage l_StdMsg = new CTBChannelMessage(l_byDataPackage);
            if (l_StdMsg.Command == ETBChannelCommand.eCmdMeasChannelGetDataPackage)
            {
                // message is of different kind!
                return new CTBChannelMessageMeasurementChannelDataPackage(l_byDataPackage);
            }

            return l_StdMsg;
        }
    }
}
