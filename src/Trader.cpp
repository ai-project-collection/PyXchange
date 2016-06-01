/**
 * @brief This module implements simulator of exchange
 * @file Trader.cpp
 *
 */


#include "Trader.hpp"
#include "Utils.hpp"


namespace pyxchange
{

namespace py = boost::python;


namespace report
{

const std::string new_   = "NEW";
const std::string cancel = "CANCELED";
const std::string fill   = "FILL";
const std::string err    = "ERROR";

} /* namespace report */


/**
 * @brief FIXME
 *
 */
void Trader::notifyError( const std::string& text )
{
    boost::python::dict response;

    response[ keys::message ] = message::executionReport;
    response[ keys::report  ] = report::err;
    response[ keys::text    ] = text;

    // send response
    writeData( response );
}


/**
 * @brief FIXME
 *
 */
void Trader::notifyCreateOrderSuccess( const orderId_t orderId )
{
    py::dict response;

    response[ keys::message ] = message::executionReport;
    response[ keys::report  ] = report::new_;
    response[ keys::orderId ] = orderId;

    // send response
    writeData( response );
}



/**
 * @brief FIXME
 *
 */
void Trader::notifyCreateOrderError( const orderId_t orderId, const std::string& text )
{
    py::dict response;

    response[ keys::message ] = message::executionReport;
    response[ keys::report  ] = report::err;
    response[ keys::text    ] = text;
    response[ keys::orderId ] = orderId;

    // send response
    writeData( response );
}


/**
 * @brief FIXME
 *
 */
void Trader::notifyCancelOrderSuccess( const orderId_t orderId )
{
    py::dict response;

    response[ keys::message ] = message::executionReport;
    response[ keys::report  ] = report::cancel;
    response[ keys::orderId ] = orderId;

    // send response
    writeData( response );
}


/**
 * @brief FIXME
 *
 */
void Trader::notifyCancelOrderError( const orderId_t orderId, const std::string& text )
{
    py::dict response;

    response[ keys::message ] = message::executionReport;
    response[ keys::report  ] = report::err;
    response[ keys::text    ] = text;
    response[ keys::orderId ] = orderId;

    // send response
    writeData( response );
}


} /* namespace pyxchange */



/* EOF */

