#include "Manager.hpp"

namespace Chaos {

Manager::
Manager()
	: mObserver(0)
{
}

Manager::
~Manager()
{
	ElementsObserver::Elements::const_iterator it = mElements.begin(), ie = mElements.end();
	for(; it != ie; ++it) {
		delete *it;
	}
	delete mObserver;
}

void Manager::
Start()
{
	Manager& m = getInctance();
	m.mChaosWidget.reset(new Chaos());
	m.mChaosWidget->setFixedSize(1000, 600);

	m.mObserver = new ElementsObserver();

	//m.mElements.push_back(new Element(m.mObserver, QPoint(500, 300), m.mChaosWidget->rect(), 4, 20, 155));
	//m.mElements.push_back(new Element(m.mObserver, QPoint(200, 300), m.mChaosWidget->rect(), 5, 40, 30));
	m.mElements.push_back(new Element(m.mObserver, QPoint(400, 200), m.mChaosWidget->rect(), 5, 20, 120));
//	m.mElements.push_back(new Element(m.mObserver, QPoint(700, 70), 20, 10, 3));
//	m.mElements.push_back(new Element(m.mObserver, QPoint(900, 290), 20, 10, 4));

	m.mChaosWidget->setObserver(m.mObserver);

	m.mChaosWidget->show();
}

} /// End of namespace Chaos
