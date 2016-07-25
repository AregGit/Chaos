#include "Manager.hpp"

#include <QApplication>

int main(int argc, char *argv[]) {

	QApplication app(argc, argv);  
	Chaos::Manager::getInctance().Start();

return app.exec();
}
