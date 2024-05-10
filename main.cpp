#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <memory>
#include "csv.h"
#include "include/lib.hpp"

#define VERSION "1.1.0"

using namespace boost::asio;

int main(int argc, char *argv[]) 
{
  bool is_set_csv=false;

  io_service io;
  serial_port serial(io);

  std::string port;
  int baud_rate;
  int data_size;
  int parity;
  std::string stop_bit;

  try 
  {
    if(argc==2)
    {
      std::string arg_str = argv[1];
      if (arg_str=="--version" || arg_str=="-v")
      {
        std::cout<<VERSION<<std::endl;
        exit(EXIT_SUCCESS);
      }
      else
      {
        auto opt = std::shared_ptr<Option>(new Option(arg_str));
        if(opt.get()->is_readed)
        {
          port=opt.get()->get_port();
          baud_rate=opt.get()->get_baud_rate();
          data_size=opt.get()->get_data_size();
          parity=opt.get()->get_parity();
          stop_bit=opt.get()->get_stop_bit();
          is_set_csv=true;
        }
        std::cout<<"Reading CSV Complete !!\n"<<std::endl;
      }
    }

    if(!is_set_csv)
    {
      std::cout<<"Select Port (ex: COM3) >> ";
      std::cin>>port;
      std::cout<<"Select Baudrate (ex: 9600) >> ";
      std::cin>>baud_rate;
      std::cout<<"Select Data Size (ex: 8) >> ";
      std::cin>>data_size;
      std::cout<<"Select Parity (ex: 0) >> ";
      std::cin>>parity;
      std::cout<<"Select Stop Bit (ex: 1) Select List [1, 1.5 ,2] >> ";
      std::cin>>stop_bit;
    }

    serial.open(port);
    serial.set_option(serial_port_base::baud_rate(baud_rate));
    serial.set_option(serial_port_base::character_size(data_size));
    switch(parity)
    {
      case 0:
        serial.set_option(serial_port_base::parity(serial_port_base::parity::none));
        break;
      case 1:
        serial.set_option(serial_port_base::parity(serial_port_base::parity::odd));
        break;
      case 2:
        serial.set_option(serial_port_base::parity(serial_port_base::parity::even));
        break;
      default:
        serial.set_option(serial_port_base::parity(serial_port_base::parity::none));
        break;
    }

    if ("1")
    {
      serial.set_option(serial_port_base::stop_bits(serial_port_base::stop_bits::one));
    }
    else if ("1.5")
    {
      serial.set_option(serial_port_base::stop_bits(serial_port_base::stop_bits::onepointfive));
    }
    else if ("2")
    {
      serial.set_option(serial_port_base::stop_bits(serial_port_base::stop_bits::two));
    }
    else
    {
      serial.set_option(serial_port_base::stop_bits(serial_port_base::stop_bits::one));
    }
    std::cout<<"Config Complete !!\n"<<std::endl;
  }
  catch (io::error::can_not_open_file e) 
  {
    std::cout<<"Reading CSV Error: "<<e.what()<<std::endl;
    std::cout<<"Or Not Such Command."<<e.what()<<std::endl;
    exit(EXIT_FAILURE);
  }
  catch (io::error::line_length_limit_exceeded e)
  {
    std::cout<<"CSV Length Over Error: "<<e.what()<<std::endl;
    exit(EXIT_FAILURE);
  }
  catch (boost::system::system_error e) 
  {
    std::cout<<"Setting Error: "<<e.what()<<std::endl;
    exit(EXIT_FAILURE);
  }

  std::string uart_mode_str;
  std::cout<<"UART Mode Setting"<<std::endl;
  std::cout<<"Ping Pong: 1"<<std::endl;
  std::cout<<"Read Only: 2"<<std::endl;
  std::cout<<"Write Only: 3"<<std::endl;
  std::cout<<">>";
  std::cin>>uart_mode_str;

  try 
  {
    try
    {
      int uart_mode = stoi(uart_mode_str);
      if (uart_mode!=1 && uart_mode!=2 && uart_mode!=3)
      {
        std::cout<<"Set wrong value!! Use Default Mode 1."<<std::endl;
        uart_mode=1;
      }
      switch (uart_mode)
      {
        case 1:
          uart_ping_pong(serial);
          break;
        case 2:
          uart_read_only(serial);
          break;
        case 3:
          uart_write_only(serial);
          break;
      }
    }
    catch(boost::system::system_error e)
    {
      std::cout<<"Error Occured!! : "<<e.what()<<std::endl;
      exit(EXIT_FAILURE);
    }
  }
  catch (std::invalid_argument& e)
  {
    std::cout<<"Set wrong value!! Use Default Mode 1."<<std::endl;
    int uart_mode=1;
    try
    {
      switch (uart_mode)
      {
        case 1:
          uart_ping_pong(serial);
          break;
        case 2:
          uart_read_only(serial);
          break;
        case 3:
          uart_write_only(serial);
          break;
      } 
    }
    catch(boost::system::system_error e)
    {
      std::cout<<"Error Occured!! : "<<e.what()<<std::endl;
      exit(EXIT_FAILURE);
    }
  }

  serial.close();
}