/* ********************************************************************
   * Project   : TrioMotion UnifiedApi
   * Author    : Simon Martin
   ********************************************************************

    Modifications:
    0.01 08/03/2023 Initial version.
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
#include "TrioMotion_UnifiedApi.h"

/*---------------------------------------------------------------------
  -- C standard includes
  ---------------------------------------------------------------------*/

/*---------------------------------------------------------------------
  -- C++ standard includes
  ---------------------------------------------------------------------*/

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
    class UnifiedApi_TCP : public UnifiedApi
    {
    public:
        virtual bool RemoteOpen(const Connection &Connection, ConnectionCallback ConnectionCallback, void *ConnectionCallbackContext, Context **Context);
        virtual bool MpeOpen(const Connection &Connection, ConnectionCallback ConnectionCallback, void *ConnectionCallbackContext, Context **Context);
        virtual bool TextFileLoaderOpen(const Connection &Connection, ConnectionCallback ConnectionCallback, void *ConnectionCallbackContext, Context **Context);
        virtual bool ChannelTransactOpen(const Connection &Connection, ConnectionCallback ConnectionCallback, void *ConnectionCallbackContext, Context **Context);
        virtual bool Close(Context *Context);

        virtual bool RemoteGetVr(Context *Context, size_t Offset, size_t Length, double Values[]);
        virtual bool RemoteGetVr(Context *Context, size_t Offset, size_t Length, RequestCallback RequestCallback, void *RequestCallbackContext, double Values[]);
        virtual bool RemoteSetVr(Context *Context, size_t Offset, size_t Length, const double Values[]);
        virtual bool RemoteSetVr(Context *Context, size_t Offset, size_t Length, RequestCallback RequestCallback, void *RequestCallbackContext, const double Values[]);

        virtual bool MpeWrite(Context *Context, const uint8_t Channel, const char Data[], size_t DataLength);
        virtual bool MpeRead(Context *Context, const uint8_t Channel, char Data[], size_t DataSize, size_t &DataLength);

        virtual bool TextFileLoader(Context *Context, const char *SourceFile, enum TFLDestinations Destination, const char *DestinationFile, unsigned int CompressionEnable, int CompressionLevel, unsigned int TimeoutEnable, int Timeout, enum TFLDirection Direction);
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




