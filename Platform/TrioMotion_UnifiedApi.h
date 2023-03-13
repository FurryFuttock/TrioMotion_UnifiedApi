/* ********************************************************************
   * Project   : 
   * Author    : Simon Martin
   ********************************************************************

    Modifications:
    0.01 07/03/2023 Initial version.
*/

#ifndef __TRIOMOTION_UNIFIEDAPI_H__
#define __TRIOMOTION_UNIFIEDAPI_H__

/*---------------------------------------------------------------------
  -- compatibility
  ---------------------------------------------------------------------*/

/*---------------------------------------------------------------------
  -- project includes (import)
  ---------------------------------------------------------------------*/

/*---------------------------------------------------------------------
  -- project includes (export)
  ---------------------------------------------------------------------*/

/*---------------------------------------------------------------------
  -- C standard includes
  ---------------------------------------------------------------------*/
#include <stdint.h>

/*---------------------------------------------------------------------
  -- C++ standard includes
  ---------------------------------------------------------------------*/
#include <string>
#include <vector>

/*---------------------------------------------------------------------
  -- macros
  ---------------------------------------------------------------------*/

/*---------------------------------------------------------------------
  -- forward declarations
  ---------------------------------------------------------------------*/

/*---------------------------------------------------------------------
  -- data types
  ---------------------------------------------------------------------*/
namespace TrioMotion
{
    class UnifiedApi
    {
    protected:
        /**
         * Encapsulation for supported protocol types.
         */
        typedef class Protocol_c
        {
        protected:
            std::vector<std::string> Name = 
            {
                "RemoteTCP",                 
                "RemoteUDP",                 
                "MPE",                 
                "TextFileLoader",                 
                "Project",                 
                "Firmware",                 
                "ChannelTransact",                 
            };

        public:
            typedef enum 
            {
                RemoteTCP,
                RemoteUDP,
                MPE,
                TextFileLoader,
                Project,
                Firmware,
                ChannelTransact,
            } Type;

            Type Value;

            operator const char *() const { return (Value >= 0) && (Value < Name.size()) ? Name[Value].c_str() : ""; }
        } Protocol_t;

        Protocol_t Protocol;

    public:
        /* Types */
        /**
         * Base struct for context.
         */
        typedef struct Context {} Context;

        /**
         * Encapsulation for supported connection types.
         */
        typedef class Connection
        {
        protected:
            std::vector<std::string> Name = 
            {
                "TCP",                 
                "UDP",                 
                "RS232",                 
                "PCMCAT",                 
                "FLEX7",                 
            };

        public:
            typedef enum 
            {
                TCP,
                UDP,
                RS232,
                PCMCAT,
                FLEX7,
            } Type;

            Type Value;

            operator const char *() const { return (Value >= 0) && (Value < Name.size()) ? Name[Value].c_str() : ""; }
        } Connection;

        typedef class Event
        {
        protected:
            std::vector<std::string> Name = 
            {
                "WriteFail",
                "ReadFail",
                "Message",
                "Receive",
                "BufferOverrun",
                "ProgressCreate",
                "ProgressDestroy",
                "ProgressSetPos",
                "GetControllerKey",
            };

        public:
            typedef enum 
            {
                WriteFail,
                ReadFail,
                Message,
                Receive,
                BufferOverrun,
                ProgressCreate,
                ProgressDestroy,
                ProgressSetPos,
                GetControllerKey,
            } Type;

            Type Value;

            operator const char *() const { return (Value >= 0) && (Value < Name.size()) ? Name[Value].c_str() : ""; }
        } Event;

        /* Attributes */
        template<class T>
        class Attribute
        {
        protected:
            T Value;

        public:
            Attribute(T Value) : Value(Value) {}
            bool Get(T &Value) const { Value = this->Value; return true; }
            bool Set(const T &Value) { this->Value = Value; return true; }
        };

        /**
         * Port number of the remote for UDP or TCP connections.
         */
        Attribute<int16_t> Port;
        /**
         * Host name or IP address of the remote for UDP or TCP connections.
         */
        Attribute<std::string> Host;
        /**
         * Serial port name for RS232 connections.
         */
        Attribute<std::string> ComPort;

        /**
         * Prototype for the callback function that will be called when events happen on the underlying connection.
         */
        typedef void (*ConnectionCallback)(void *ConnectionCallbackContext, const Event &Event, const long IntegerData, const char *StringData);

        /* We don't want this. UDP/TCP/ etc are implementations, i.e. DLLs. What we want are functionality, so Remote,  */
        
        /* Methods */
        /**
         * Open REMOTE protocol connection to the Motion Coordinator. A 
         * REMOTE protocol connection can be used to run Remote 
         * functions. 
         * <p>
         * An application can have multiple different connections open simultaneously.
         * <p> 
         * A REMOTE connection can be run in parallel with 
         * MotionPerfect. 
         * 
         * @param Connection         The type of connection to open.
         * @param ConnectionCallback Function that will be called when 
         *                           an event occurrs on the underlying
         *                           connection.
         * @param ConnectionCallbackContext
         *                           Context that will be passed to the
         *                           ConnectionCallback when it is
         *                           called.
         * @param Context            Receives a pointer to the context 
         *                           of the underlying implementation.
         * 
         * @return If successful returns true, otherwise false.
         */
        virtual bool RemoteOpen(const Connection &Connection, ConnectionCallback ConnectionCallback, void *ConnectionCallbackContext, Context **Context) = 0;

        /**
         * Open an MPE protocol connection to the Motion Coordinator. An
         * MPE protocol connection can be used to run commands directly 
         * on the command line, use the MotionPerfect command 
         * encapsulation, and also perform project and firmware loads.
         * <p>
         * An application can have multiple different connections open simultaneously.
         * <p> 
         * Depending on the implementation, this might use the same 
         * connection as MotionPerfect, MotionPerfect cannot be 
         * connected to the Motion Coordinator simultaneously. 
         * 
         * @param Connection         The type of connection to open.
         * @param ConnectionCallback Function that will be called when 
         *                           an event occurrs on the underlying
         *                           connection.
         * @param ConnectionCallbackContext
         *                           Context that will be passed to the
         *                           ConnectionCallback when it is
         *                           called.
         * @param Context            Receives a pointer to the context 
         *                           of the underlying implementation.
         * 
         * @return If successful returns true, otherwise false.
         */
        virtual bool MpeOpen(const Connection &Connection, ConnectionCallback ConnectionCallback, void *ConnectionCallbackContext, Context **Context) = 0;

        /**
         * Open TextFileLoader protocol connection to the Motion 
         * Coordinator. A TextFileLoader protocol connection can be used
         * to transfer files to and from the Motion Coordinator. 
         * <p>
         * An application can have multiple different connections open 
         * simultaneously.
         * <p> 
         * A TextFileLoader connection can be run in parallel with 
         * MotionPerfect. This might not be avaiable on all 
         * implementations. 
         * 
         * @param Connection         The type of connection to open.
         * @param ConnectionCallback Function that will be called when 
         *                           an event occurrs on the underlying
         *                           connection.
         * @param ConnectionCallbackContext
         *                           Context that will be passed to the
         *                           ConnectionCallback when it is
         *                           called.
         * @param Context            Receives a pointer to the context 
         *                           of the underlying implementation.
         * 
         * @return If successful returns true, otherwise false.
         */
        virtual bool TextFileLoaderOpen(const Connection &Connection, ConnectionCallback ConnectionCallback, void *ConnectionCallbackContext, Context **Context) = 0;

        /**
         * Open ChannelTransact protocol connection to the Motion 
         * Coordinator. A ChannelTransact protocol connection can be 
         * used to transfer numeric data to the Motion Coordinator. 
         * <p>
         * An application can have multiple different connections open simultaneously.
         * <p> 
         * A TextFileLoader connection can be run in parallel with 
         * MotionPerfect. This might not be avaiable on all 
         * implementations. 
         * 
         * @param Connection         The type of connection to open.
         * @param ConnectionCallback Function that will be called when 
         *                           an event occurrs on the underlying
         *                           connection.
         * @param ConnectionCallbackContext
         *                           Context that will be passed to the
         *                           ConnectionCallback when it is
         *                           called.
         * @param Context            Receives a pointer to the context 
         *                           of the underlying implementation.
         * 
         * @return If successful returns true, otherwise false.
         */
        virtual bool ChannelTransactOpen(const Connection &Connection, ConnectionCallback ConnectionCallback, void *ConnectionCallbackContext, Context **Context) = 0;

        /**
         * Close an existing connection.
         * 
         * @param Connection The type of connection to close.
         * @param Protocol   The protocol to use over this connection.
         * 
         * @return If successful returns true, otherwise false.
         */
        virtual bool Close(Context *Context) = 0;

        /**
         * Prototype for the callback function that will be called when 
         * a Remote protocol request to the Motion Coordinator 
         * completes. 
         */
        typedef void (*RequestCallback)(void *RequestCallbackContext, int Error, double Value);

        /**
         * Read VR variable values from the Motion Coordinator and 
         * wait until the response arrives. 
         * 
         * @param Offset  Offset to the first VR variable to be read.
         * @param Length Number of VR variables to be read.
         * @param Values Array to receive the values read.
         * 
         * @return Returns true if the request was sent to the Motion Coordinator correctly, the Motion Coordinator processed the request correctly, and the response received was correct.
         */
        virtual bool RemoteGetVr(Context *Context, size_t Offset, size_t Length, double Values[]) = 0;

        /**
         * Read VR variable values from the Motion Coordinator and
         * call the callback function when the response arrives.
         * 
         * @param Offset                Offset to the first VR variable to be read.
         * @param Length                Number of VR variables to be read.
         * @param RequestCallback        Function to be called when the 
         *                               request completes.
         * @param RequestCallbackContext Context to pass to the 
         *                               RequestCallback function when
         *                               it is called.
         * @param Values                Array to receive the values read.
         * 
         * @return Returns true if the request was sent to the Motion Coordinator correctly, the Motion Coordinator processed the request correctly, and the response received was correct.
         */
        virtual bool RemoteGetVr(Context *Context, size_t Offset, size_t Length, RequestCallback RequestCallback, void *RequestCallbackContext, double Values[]) = 0;

        /**
         * Write VR variable values to the Motion Coordinator and 
         * wait until the response arrives. 
         * 
         * @param Offset  Offset to the first VR variable to be read.
         * @param Length Number of VR variables to be read.
         * @param Values Array to receive the values read.
         * 
         * @return Returns true if the request was sent to the Motion Coordinator correctly, the Motion Coordinator processed the request correctly, and the response received was correct.
         */
        virtual bool RemoteSetVr(Context *Context, size_t Offset, size_t Length, const double Values[]) = 0;

        /**
         * Write VR variable values from the Motion Coordinator and
         * call the callback function when the response arrives.
         * 
         * @param Offset                Offset to the first VR variable to be read.
         * @param Length                Number of VR variables to be read.
         * @param RequestCallback        Function to be called when the 
         *                               request completes.
         * @param RequestCallbackContext Context to pass to the 
         *                               RequestCallback function when
         *                               it is called.
         * @param Values                Array to receive the values read.
         * 
         * @return Returns true if the request was sent to the Motion Coordinator correctly, the Motion Coordinator processed the request correctly, and the response received was correct.
         */
        virtual bool RemoteSetVr(Context *Context, size_t Offset, size_t Length, RequestCallback RequestCallback, void *RequestCallbackContext, const double Values[]) = 0;

        virtual bool MpeWrite(Context *Context, const uint8_t Channel, const char Data[], size_t DataLength) = 0;
        virtual bool MpeRead(Context *Context, const uint8_t Channel, char Data[], size_t DataSize, size_t &DataLength) = 0;

        enum TFLDestinations { TFLDestinationRAM, TFLDestinationFIFO, TFLDestinationSD };
        enum TFLProtocol { TFLProtocolTransparent, TFLProtocolMC2XX, TFLProtocolMC4XX };
        enum TFLDirection { TFLDirectionToMC, TFLDirectionFromMC };

        virtual bool TextFileLoader(Context *Context, const char *SourceFile, enum TFLDestinations Destination, const char *DestinationFile, unsigned int CompressionEnable, int CompressionLevel, unsigned int TimeoutEnable, int Timeout, enum TFLDirection Direction) = 0;
    };
}

/*---------------------------------------------------------------------
  -- function prototypes
  ---------------------------------------------------------------------*/
extern "C"
{
    TrioMotion::UnifiedApi *factory();    
}

/*---------------------------------------------------------------------
  -- global variables
  ---------------------------------------------------------------------*/

/*---------------------------------------------------------------------
  -- local variables
  ---------------------------------------------------------------------*/

/*---------------------------------------------------------------------
  -- private functions
  ---------------------------------------------------------------------*/

/*---------------------------------------------------------------------
  -- public functions
  ---------------------------------------------------------------------*/

#endif

