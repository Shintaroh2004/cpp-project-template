#include <iostream>
#include <chrono>
#include <future>
#include "csv.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "../include/lib.hpp"

Option::Option(std::string path)
{
    io::CSVReader<5> in(path);
    in.read_header(io::ignore_extra_column,"Port","Baud Rate","Data Size","Parity","Stop Bit");
    std::string port;
    int baud_rate;
    uint8_t data_size;
    uint8_t parity;
    std::string stop_bit;
    while(in.read_row(port,baud_rate,data_size,parity,stop_bit))
    {
        this->_port=port;
        this->_baud_rate=baud_rate;
        this->_data_size=data_size;
        this->_parity=parity;
        this->_stop_bit=stop_bit;
        break;
    }
    this->is_readed=true;
};

std::string Option::get_port()
{
    return this->_port;
}

int Option::get_baud_rate()
{
    return this->_baud_rate;
}

int Option::get_data_size()
{
    return this->_data_size;
}

int Option::get_parity()
{
    return this->_parity;
}

std::string Option::get_stop_bit()
{
    return this->_stop_bit;
}

void uart_ping_pong(serial_port& serial)
{ 
  while (true)
  {
    std::string input;
    std::cout<<"input >> ";
    std::cin>>input;

    if (input=="exit")
    {
      break;
    }

    boost::asio::write(serial, boost::asio::buffer(input+"\n"));
    std::cout<<"Send data: "<<input<<std::endl;
    std::future<void> f = std::async([input,&serial](){
      boost::asio::streambuf buf;
      boost::asio::read(serial,buf,boost::asio::transfer_at_least(1));
      std::string uart(boost::asio::buffer_cast<const char*>(buf.data()));
      std::cout<<"Recieve  : "<<uart<<std::endl;
    });

    if (f.wait_for(std::chrono::milliseconds(2000)) == std::future_status::timeout)
    {
      std::cout << "No response within 2000 ms." << std::endl;
      serial.cancel();
    }

  }
}

void uart_read_only(serial_port& serial)
{ 
  std::cout<<"Press 'Ctrl+c' to exit."<<std::endl;
  while (true)
  {
    std::future<void> f = std::async([&](){
      boost::asio::streambuf buf;
      boost::asio::read(serial,buf,boost::asio::transfer_at_least(1));
      std::string uart(boost::asio::buffer_cast<const char*>(buf.data()));
      std::cout<<"Recieve  : "<<uart<<std::endl;
    });

    if (f.wait_for(std::chrono::milliseconds(2000)) == std::future_status::timeout)
    {
      std::cout << "No response within 2000 ms." << std::endl;
      serial.cancel();
    }

  }
}

void uart_write_only(serial_port& serial)
{ 
  while (true)
  {
    std::string input;
    std::cout<<"input >> ";
    std::cin>>input;

    if (input=="exit")
    {
      break;
    }
    boost::asio::write(serial, boost::asio::buffer(input));
    std::cout<<"Send data: "<<input<<std::endl;
  }
}