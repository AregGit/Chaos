#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include <QPoint>
#include <QRect>

#include <cassert>
#include <list>


namespace Chaos {

class Element;

/**
 * Class ElementsObserver of Chaos namespace
 * The class presented object oriented construction
 * for handling points intersection.
 */
class ElementsObserver
{
public:
	typedef std::list<std::pair<ElementsObserver*, ElementsObserver*> >
								intersectedElements;
	typedef std::list<Element*> Elements;

public:
	/**
	 * @Brief Destructor
	 */
	virtual ~ElementsObserver();

public:
	/**
	 * @Brief Gets the all intersected elements.
	 */
	intersectedElements getIntersectedElements();

	/**
	 * @Brief Gets the all elements.
	 */
	Elements& getElements()
	{
		return mElements;
	}

	/**
	 * @Brief Traverse into all elements and call Move function for each.
	 */
	virtual void Move();

public:
	/**
	 * @Brief Add element into list of observation.
	 */
	void addElement(Element* t)
	{
		mElements.push_back(t);
	}

	/**
	 * @Brief Remove element into list of observation.
	 */
	void removeElement(Element* t)
	{
		mElements.remove(t);
	}

public:
	virtual int getID() const
	{
		assert(!"This function must not be called");
	}

	virtual void setID(int)
	{
		assert(!"This function must not be called");
	}

	virtual QPoint getQPoint() const
	{
		assert(!"This function must not be called");
	}

	virtual void setQPoint(const QPoint&)
	{
		assert(!"This function must not be called");
	}

	virtual int getSpeed() const
	{
		assert(!"This function must not be called");
	}

	virtual void setSpeed(int)
	{
		assert(!"This function must not be called");
	}

	virtual int getRadius() const
	{
		assert(!"This function must not be called");
	}

	virtual void setRadius(int)
	{
		assert(!"This function must not be called");
	}

	virtual int getAngle() const
	{
		assert(!"This function must not be called");
	}

	virtual void setAngle(int)
	{
		assert(!"This function must not be called");
	}

private:
	Elements mElements;

};

/**
 * Class Element of Chaos namespace 
 * The Class Containing all information about elements
 * Coordinates, parent observer, ID, etc.
 */
class Element : public ElementsObserver
{

public:
	/**
	 * @Brief Constructor
	 * @param[in] ob Observer for Element
	 * @param[in] qp QT point
	 * @param[in] rc QT Rect
	 * @param[in] sp Speed of point
	 * @param[in] rd Radius of element
	 * @param[in] an Direction angle of element
	 * @param[in] ID The number of current point
	 */
	Element(ElementsObserver* ob, const QPoint& pt, const QRect& rc
						      , int sp = 1, int rd = 20
						      , int an = 0 , int id = 0);

	/**
	 * @Brief Destructor
	 */
	virtual ~Element();

public:
	/**
	 * @Brief Return ID of current Element.
	 */
	virtual int getID() const
	{
		return mID;
	}

	/**
	 * @Brief Set ID to Element.
	 */
	virtual void setID(int id)
	{
		mID = id;
	}

	/**
	 * @Brief Return QT Element from current Element.
	 */
	virtual QPoint getQPoint() const
	{
		return mQPoint;	
	}

	/**
	 * @Brief Set QT Element into current Element.
	 */
	virtual void setQPoint(const QPoint& p)
	{
		mQPoint = p;	
	}

	/**
	 * @Brief Return speed of element
	 */
	virtual int getSpeed() const
	{
		return mSpeed;	
	}

	/**
	 * @Brief Set Speed of element
	 */
	virtual void setSpeed(int p)
	{
		mSpeed = p;	
	}

	/**
	 * @Brief Return radius of element
	 */
	virtual int getRadius() const
	{
		return mRadius;	
	}

	/**
	 * @Brief Set radius of element
	 */
	virtual void setRadius(int p)
	{
		mSpeed = p;	
	}

	/**
	 * @Brief Return direction angle of element
	 */
	virtual int getAngle() const
	{
		return mAngle;	
	}

	/**
	 * @Brief Set direction angle of element
	 */
	virtual void setAngle(int p)
	{
		mAngle = p;	
	}

public:
	void Move();

private:
	int mID;
	int mSpeed;
	int mRadius;
	int mAngle;
	int mStep;
	QPoint mQPoint;
	ElementsObserver* mObserver;
	QRect mRect;
};

} /// End of namespace Chaos

#endif /// ELEMENTS_HPP
