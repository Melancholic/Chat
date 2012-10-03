#include"client.h"  
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
using boost::asio::ip::tcp;
int main(int argc, char* argv[]){
  client a;
  a.add_msg();
  try
  {
    if (argc != 2)
    {
      std::cerr << "Usage: client <host>" << std::endl;
      return 1;
    }

    boost::asio::io_service io_service;

    tcp::resolver resolver(io_service);
    tcp::resolver::query query(argv[1], "5183");
    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
    tcp::socket socket(io_service);
    boost::asio::connect(socket, endpoint_iterator);
    boost::system::error_code error;
    std::vector<char> buf(128);
    for (;;)
    {
      size_t len = socket.read_some(boost::asio::buffer(buf,1024), error);
      for(int i=0;i<len;++i){
		std::cerr<<a.GetSymMsg(i);
	}
      std::string message;
      std::cin>>message;
      boost::asio::write(socket, boost::asio::buffer(message), error);
      if (error == boost::asio::error::eof)
      break; // Connection closed cleanly by peer.
      else if (error)
      throw boost::system::system_error(error); // Some other error.
	  }
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}

