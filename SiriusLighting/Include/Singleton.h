#pragma once

#include <boost/shared_ptr.hpp>

namespace Patten
{
template <class T>
class Singleton
{
public:
	static inline T* getInstance();

private:
	Singleton(void){}
	~Singleton(void){}
	Singleton(const Singleton&){}
	Singleton & operator=(const Singleton &){}

	static boost::shared_ptr<T> m_pInstance;
};

template <class T>
boost::shared_ptr<T> Singleton<T>::m_pInstance;

template <class T>
inline T* Singleton<T>::getInstance()
{
	if(m_pInstance.get() == NULL)
	{
		m_pInstance.reset(new T);
	}

	return m_pInstance.get();
}

//Class that will implement the singleton mode,
//must use the macro in it's delare file
#define DECLARE_SINGLETON_CLASS( type ) \
       friend class boost::shared_ptr< type >;\
       friend class Singleton< type >;
};