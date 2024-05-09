#include <iostream>
#include "csv.h"
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