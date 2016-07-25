#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "Chaos.hpp"
#include "Elements.hpp"

#include <memory>


namespace Chaos {

/**
 * Manager class of Chaos namespace which control and automate 
 * Chaos project flow.
 */
class Manager
{
private:
	typedef std::shared_ptr<Chaos> ptr;

private:
	/**
	 * @Brief Constructor
	 */
	Manager();

	/**
	 * @brief Ignore Copy constructor from compiler
	 */
	Manager(const Manager&) = delete;

	/**
	 * @brief Ignore assign operator from compiler
	 */
	Manager& operator=(const Manager&) = delete;

public:
	/**
	 * @Brief Destructor
	 */
	~Manager();
public:
	/**
	 * @brief return instance of singleton object
	 **/
	static Manager& getInctance()
	{
		static Manager m;
		return m;
	}

public:
	/**
	 * @brief The start point of program
	 * 	  Function create and initialize Widget,
	 * 	  data structures, threads etc.
	 * 	  After start drawing.
	 **/
	static void Start();

private:
	ptr mChaosWidget;
	ElementsObserver* mObserver;
	ElementsObserver::Elements mElements;

};

} /// End of namespace Chaos

#endif /// MANAGER_HPP
