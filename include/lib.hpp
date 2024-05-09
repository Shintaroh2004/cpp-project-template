#include <iostream>

class Option
{
    private:
        std::string _port;
        int _baud_rate;
        int _data_size;
        int _parity;
        std::string _stop_bit;
    public:
        bool is_readed;
        Option(std::string path);
        std::string get_port();
        int get_baud_rate();
        int get_data_size();
        int get_parity();
        std::string get_stop_bit();
};