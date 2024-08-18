#ifndef AppComponent_hpp
#define AppComponent_hpp

#include <oatpp/parser/json/mapping/ObjectMapper.hpp>
#include <oatpp/web/server/HttpConnectionHandler.hpp>
#include <oatpp/network/tcp/server/ConnectionProvider.hpp>
#include <oatpp/core/macro/component.hpp>

class AppComponent {
public:

    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, ConnectionProvider)([] 
        {
            return oatpp::network::tcp::server::ConnectionProvider::createShared({ "localhost", 8000, oatpp::network::Address::IP_4 });
        }()
    );

    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, Router)([] 
        {
            return oatpp::web::server::HttpRouter::createShared();
        }()
    );

    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, ConnectionHandler)([] 
        {
            OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router); // get Router component
            return oatpp::web::server::HttpConnectionHandler::createShared(router);
        }()
    );

    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, ObjectMapper)([]
        {
            return oatpp::parser::json::mapping::ObjectMapper::createShared();
        }()
    );

};

#endif /* AppComponent_hpp */
