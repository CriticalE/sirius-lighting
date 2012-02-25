#include <Windows.h>
#include "Singleton.h"

using namespace Patten;

class cWndClass
{
private:
	cWndClass() {}
	cWndClass(cWndClass &){}
	DECLARE_SINGLETON_CLASS(cWndClass);
protected:
public:
	HRESULT initialWindows();
};