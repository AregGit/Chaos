#include "Chaos.hpp"


namespace Chaos {

namespace {

void drawPoints(QPainter& p, ElementsObserver::Elements& lm)
{
	p.setBrush(Qt::yellow);
	ElementsObserver::Elements::iterator it = lm.begin(), ie = lm.end();
	for(; it != ie; ++it) {
		p.drawEllipse((*it)->getQPoint(), (*it)->getRadius(), (*it)->getRadius());
	}
	p.setBrush(QBrush());
}

} /// End of unnamed namespace

Chaos::
Chaos(QWidget* p)
	: QWidget(p)
{
}

Chaos::
~Chaos()
{
}

void Chaos::
paintEvent(QPaintEvent*) {
	QPainter p(this);
	p.fillRect(rect(), QColor(29, 48, 60));
	drawPoints(p, mObserver->getElements());
	mObserver->Move();
	update();
}

void Chaos::
setObserver(ElementsObserver* el)
{
	assert(0 != el);
	mObserver = el;
}

} /// End of namespace Chaos
