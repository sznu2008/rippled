//------------------------------------------------------------------------------
/*
    This file is part of Beast: https://github.com/vinniefalco/Beast
    Copyright 2013, Vinnie Falco <vinnie.falco@gmail.com>

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

Socket::~Socket ()
{
}

//------------------------------------------------------------------------------
//
// General
//
//------------------------------------------------------------------------------

bool Socket::requires_handshake ()
{
    return false;
}

//------------------------------------------------------------------------------
//
// SocketInterface::Close
//
//------------------------------------------------------------------------------

boost::system::error_code Socket::close (boost::system::error_code& ec)
{
    return pure_virtual (ec);
}

//------------------------------------------------------------------------------
//
// SocketInterface::Acceptor
//
//------------------------------------------------------------------------------

boost::system::error_code Socket::accept (Socket&, boost::system::error_code& ec)
{
    return pure_virtual (ec);
}

BEAST_ASIO_INITFN_RESULT_TYPE_MEMBER(Socket::ErrorCall, void (boost::system::error_code))
Socket::async_accept (Socket&, BOOST_ASIO_MOVE_ARG(ErrorCall) handler)
{
#if BEAST_ASIO_HAS_FUTURE_RETURNS
    boost::asio::detail::async_result_init<
        ErrorCall, void (boost::system::error_code)> init(
        BOOST_ASIO_MOVE_CAST(ErrorCall)(handler));
    boost::system::error_code ec;
    ec = pure_virtual (ec);
    get_io_service ().post (boost::bind (
        BOOST_ASIO_MOVE_CAST(ErrorCall)(handler), ec));
    return init.result.get();
#else
    boost::system::error_code ec;
    ec = pure_virtual (ec);
    get_io_service ().post (boost::bind (
        BOOST_ASIO_MOVE_CAST(ErrorCall)(handler), ec));
#endif
}

//------------------------------------------------------------------------------
//
// SocketInterface::LowestLayer
//
//------------------------------------------------------------------------------

void* Socket::lowest_layer_raw (char const*) const
{
    pure_virtual ();
    return nullptr;
}

//--------------------------------------------------------------------------
//
// SocketInterface::Socket
//
//--------------------------------------------------------------------------

boost::system::error_code Socket::cancel (boost::system::error_code& ec)
{
    return pure_virtual (ec);
}

boost::system::error_code Socket::shutdown (shutdown_type, boost::system::error_code& ec)
{
    return pure_virtual (ec);
}

//--------------------------------------------------------------------------
//
// SocketInterface::Stream
//
//--------------------------------------------------------------------------

std::size_t Socket::read_some (MutableBuffers const&, boost::system::error_code& ec)
{
    pure_virtual (ec);
    return 0;
}

std::size_t Socket::write_some (ConstBuffers const&, boost::system::error_code& ec)
{
    pure_virtual (ec);
    return 0;
}

BEAST_ASIO_INITFN_RESULT_TYPE_MEMBER(Socket::TransferCall, void (boost::system::error_code, std::size_t))
Socket::async_read_some (MutableBuffers const&, BOOST_ASIO_MOVE_ARG(TransferCall) handler)
{
#if BEAST_ASIO_HAS_FUTURE_RETURNS
    boost::asio::detail::async_result_init<
        TransferCall, void (boost::system::error_code, std::size_t)> init(
        BOOST_ASIO_MOVE_CAST(TransferCall)(handler));
    boost::system::error_code ec;
    ec = pure_virtual (ec);
    get_io_service ().post (boost::bind (BOOST_ASIO_MOVE_CAST(TransferCall)(handler), ec, 0));
    return init.result.get();
#else
    boost::system::error_code ec;
    ec = pure_virtual (ec);
    get_io_service ().post (boost::bind (BOOST_ASIO_MOVE_CAST(TransferCall)(handler), ec, 0));
#endif
}

BEAST_ASIO_INITFN_RESULT_TYPE_MEMBER(Socket::TransferCall, void (boost::system::error_code, std::size_t))
Socket::async_write_some (ConstBuffers const&, BOOST_ASIO_MOVE_ARG(TransferCall) handler)
{
#if BEAST_ASIO_HAS_FUTURE_RETURNS
    boost::asio::detail::async_result_init<
        TransferCall, void (boost::system::error_code, std::size_t)> init(
        BOOST_ASIO_MOVE_CAST(TransferCall)(handler));
    boost::system::error_code ec;
    ec = pure_virtual (ec);
    get_io_service ().post (boost::bind (
        BOOST_ASIO_MOVE_CAST(TransferCall)(handler), ec, 0));
    return init.result.get();
#else
    boost::system::error_code ec;
    ec = pure_virtual (ec);
    get_io_service ().post (boost::bind (
        BOOST_ASIO_MOVE_CAST(TransferCall)(handler), ec, 0));
#endif
}

//--------------------------------------------------------------------------
//
// SocketInterface::Handshake
//
//--------------------------------------------------------------------------

boost::system::error_code Socket::handshake (handshake_type, boost::system::error_code& ec)
{
    return pure_virtual (ec);
}

BEAST_ASIO_INITFN_RESULT_TYPE_MEMBER(Socket::ErrorCall, void (boost::system::error_code))
Socket::async_handshake (handshake_type, BOOST_ASIO_MOVE_ARG(ErrorCall) handler)
{
#if BEAST_ASIO_HAS_FUTURE_RETURNS
    boost::asio::detail::async_result_init<
        ErrorCall, void (boost::system::error_code)> init(
        BOOST_ASIO_MOVE_CAST(ErrorCall)(handler));
    boost::system::error_code ec;
    ec = pure_virtual (ec);
    get_io_service ().post (boost::bind (
        BOOST_ASIO_MOVE_CAST(ErrorCall)(handler), ec));
    return init.result.get();
#else
    boost::system::error_code ec;
    ec = pure_virtual (ec);
    get_io_service ().post (boost::bind (
        BOOST_ASIO_MOVE_CAST(ErrorCall)(handler), ec));
#endif
}

//--------------------------------------------------------------------------

#if BEAST_ASIO_HAS_BUFFEREDHANDSHAKE

boost::system::error_code Socket::handshake (handshake_type,
    ConstBuffers const&, boost::system::error_code& ec)
{
    return pure_virtual (ec);
}

BEAST_ASIO_INITFN_RESULT_TYPE_MEMBER(Socket::TransferCall, void (boost::system::error_code, std::size_t))
Socket::async_handshake (handshake_type, ConstBuffers const&,
    BOOST_ASIO_MOVE_ARG(TransferCall) handler)
{
#if BEAST_ASIO_HAS_FUTURE_RETURNS
    boost::asio::detail::async_result_init<
        TransferCall, void (boost::system::error_code, std::size_t)> init(
        BOOST_ASIO_MOVE_CAST(TransferCall)(handler));
    boost::system::error_code ec;
    ec = pure_virtual (ec);
    get_io_service ().post (boost::bind (
        BOOST_ASIO_MOVE_CAST(TransferCall)(handler), ec, 0));
    return init.result.get();
#else
    boost::system::error_code ec;
    ec = pure_virtual (ec);
    get_io_service ().post (boost::bind (
        BOOST_ASIO_MOVE_CAST(TransferCall)(handler), ec, 0));
#endif
}

#endif

boost::system::error_code Socket::shutdown (boost::system::error_code& ec)
{
    return pure_virtual (ec);
}

BEAST_ASIO_INITFN_RESULT_TYPE_MEMBER(Socket::ErrorCall, void (boost::system::error_code))
Socket::async_shutdown (BOOST_ASIO_MOVE_ARG(ErrorCall) handler)
{
#if BEAST_ASIO_HAS_FUTURE_RETURNS
    boost::asio::detail::async_result_init<
        ErrorCall, void (boost::system::error_code, std::size_t)> init(
        BOOST_ASIO_MOVE_CAST(ErrorCall)(handler));
    boost::system::error_code ec;
    ec = pure_virtual (ec);
    get_io_service ().post (boost::bind (
        BOOST_ASIO_MOVE_CAST(ErrorCall)(handler), ec));
    return init.result.get();
#else
    boost::system::error_code ec;
    ec = pure_virtual (ec);
    get_io_service ().post (boost::bind (
        BOOST_ASIO_MOVE_CAST(ErrorCall)(handler), ec));
#endif
}

