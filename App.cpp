#include <oatpp/network/Server.hpp>
#include <AppComponent.hpp>
#include <controller/MyController.hpp>

int main()
{
	oatpp::base::Environment::init();

	AppComponent components;

	OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

	auto myController = std::make_shared<MyController>();
	router->addController(myController);

	OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connHandler);
	OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connProvider);

	oatpp::network::Server server(connProvider, connHandler);

	OATPP_LOGI("MyApp", "Server running on http://localhost:%s", connProvider->getProperty("port").getData());
	server.run();

	oatpp::base::Environment::destroy();

	return 0;
}
