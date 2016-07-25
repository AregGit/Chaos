#ifndef CHAOS_HPP
#define CHAOS_HPP

#include "Elements.hpp"

#include <QPainter>
#include <QWidget>

namespace Chaos {

/**
 * Chaos class of Chaos namespace is the Canvase which is 
 * Preseting moving of elements.
 */
class Chaos : public QWidget
{
	Q_OBJECT

	friend class Manager;

private:
	std::map<int, Element*> Direction;
	
private:
	/**
	 * @Brief Constructor
	 */
	Chaos(QWidget* p = 0);

	/**
	 * @brief Ignore Copy constructor from compiler.
	 */
	Chaos(const Chaos&) = delete;

	/**
	 * @brief Ignore assign operator from compiler.
	 */
	Chaos& operator=(const Chaos&) = delete;

public:
	/**
	 * @Brief Destructor
	 */
	virtual ~Chaos();

protected:
	void paintEvent(QPaintEvent*);

public:

	/**
	 * @Brief Sets the observer of elements.
	 */
	void setObserver(ElementsObserver* el);

private:
	ElementsObserver* mObserver;

};

} /// End of namespace Chaos

#endif /// CHAOS_HPP
