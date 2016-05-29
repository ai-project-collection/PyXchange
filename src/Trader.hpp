/**
 * @brief This module implements simulator of exchange
 * @file OrderBook.hpp
 *
 */

#ifndef TRADER
#define TRADER

#include "PyXchangeFwd.hpp"


namespace pyxchange
{


class Trader
{

public:
    explicit                                Trader( const boost::python::object& write_ );

    void                                    writeString( const std::string& data );
    void                                    writeData( const boost::python::object& data );

    void                                    notifyError( const std::string& text );

    void                                    notifyCreateOrderSuccess( const orderId_t orderId );
    void                                    notifyCreateOrderError( const orderId_t orderId, const std::string& text );

    void                                    notifyCancelOrderSuccess( const orderId_t orderId );
    void                                    notifyCancelOrderError( const orderId_t orderId, const std::string& text );

    static void                             addTrader( const MatcherPtr& matcher, const TraderPtr& trader );
    static void                             removeTrader( const MatcherPtr& matcher, const TraderPtr& trader );
    static bool                             checkRegistered( const MatcherConstPtr& matcher, const TraderPtr& trader );

private:
    const boost::python::object             write;
};


} /* namespace pyxchange */


#endif /* TRADER */


/* EOF */

