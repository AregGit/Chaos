#include "Elements.hpp"

#include <chrono>
#include <cmath>
#include <thread>
#include <iostream>

#define PI 3.14159265359

namespace Chaos {

namespace {

bool is_intersected(const ElementsObserver* c1, const ElementsObserver* c2)
{
	float dx = c1->getQPoint().x() - c2->getQPoint().x();
	float dy = c1->getQPoint().y() - c2->getQPoint().y();
	float rs = c1->getRadius() + c2->getRadius();
	return dx * dx + dy * dy <= rs * rs;
}

} /// End of unnamed namespace 

ElementsObserver::
~ElementsObserver()
{
}

ElementsObserver::intersectedElements 
ElementsObserver::getIntersectedElements()
{
	intersectedElements ps;
	Elements::const_iterator it = mElements.begin(), ie = mElements.end();
	for(; it != ie; ++it) {
		Elements::const_iterator jt = it, je = mElements.end();
		for(; jt != je; ++jt) {
			if(it != jt && is_intersected(*it, *jt)) {
				ps.push_back(std::make_pair(*it, *jt));
			}
		}
	}
	return ps;
}

void ElementsObserver::
Move()
{
	Elements::const_iterator it = mElements.begin(), ie = mElements.end();
	for(; it != ie; ++it) {
		(*it)->Move();
	}
}

Element::
Element(ElementsObserver* ob, const QPoint& pt, const QRect& rc
					      , int sp, int rd
					      , int an, int id)
	: mID(id)
	, mSpeed(sp)
	, mRadius(rd)
	, mAngle(an)
	, mStep(5)
	, mQPoint(pt)
	, mObserver(ob)
	, mRect(rc)
{
	assert(0 != mObserver);
	mObserver->addElement(this);
}

Element::
~Element()
{
	mObserver->removeElement(this);
}

void Element::
Move()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(10 / mSpeed));
	bool left = mQPoint.x() <= mRect.x() + mRadius;
	bool right = mQPoint.x() >= mRect.x() + mRect.width() - mRadius;
	bool bottom = mQPoint.y() <= mRect.y() + mRadius;
	bool top = mQPoint.y() >= mRect.y() + mRect.height() - mRadius;
	if(right || left || top || bottom) {
		if(left || top) {
			mAngle -= 90;
		} else {
			mAngle += 90;
		}
	}
	int x = mQPoint.x() + (int)(mSpeed * cos(mAngle * PI/180));
	int y = mQPoint.y() + (int)(mSpeed * sin(mAngle * PI/180));
	std::cout << x << " " << y << " " << mAngle << std::endl;
	mQPoint.setX(x);
	mQPoint.setY(y);
}

} /// End of namespace Chaos
