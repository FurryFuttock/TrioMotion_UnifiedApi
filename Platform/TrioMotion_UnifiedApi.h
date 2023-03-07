/* ********************************************************************
   * Project   : 
   * Author    : Simon Martin
   ********************************************************************

    Modifications:
    0.01 07/03/2023 Initial version.
*/

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
    public:
        /* Types */
        /**
         * Base struct for context.
         */
        typedef struct Context_s {} Context_t;

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
        } Connection_t;

        /**
         * Encapsulation for supported protocol types.
         */
        typedef class Protocol
        {
        protected:
            std::vector<std::string> Name = 
            {
                "Remote",                 
                "MPE",                 
                "TextFileLoader",                 
                "Project",                 
                "Firmware",                 
                "ChannelTransact",                 
            };

        public:
            typedef enum 
            {
                Remote,
                MPE,
                TextFileLoader,
                Project,
                Firmware,
                ChannelTransact,
            } Type;

            Type Value;

            operator const char *() const { return (Value >= 0) && (Value < Name.size()) ? Name[Value].c_str() : ""; }
        } Protocol_t;

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

        /* Attributes */
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

        /* Methods */
        /**
         * Open a connection to the Motion Coordinator.
         * <p>
         * An application can have multiple different connections open simultaneously.
         * 
         * @param Connection The type of connection to open.
         * @param Protocol   The protocol to use over this connection.
         * @param Context    Receives a pointer to the context of the underlying implementation.
         * 
         * @return If successful returns true, otherwise false.
         */
        virtual bool Open(const Connection_t &Connection, const Protocol_t &Protocol, Context_t **Context) = 0;
        /**
         * Close an existing connection.
         * 
         * @param Connection The type of connection to close.
         * @param Protocol   The protocol to use over this connection.
         * 
         * @return If successful returns true, otherwise false.
         */
        virtual bool Close(Context_t *Context) = 0;
    };
}

/*---------------------------------------------------------------------
  -- function prototypes
  ---------------------------------------------------------------------*/

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

