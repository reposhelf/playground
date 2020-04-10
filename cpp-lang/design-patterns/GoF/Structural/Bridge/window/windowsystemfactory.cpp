#include "windowsystemfactory.h"

#include "xwindowimp.h"
#include "pmwindowimp.h"

WindowSystemFactory *WindowSystemFactory::m_instance = nullptr;

WindowSystemFactory *WindowSystemFactory::instance()
{
    if (m_instance == nullptr)
        m_instance = new WindowSystemFactory;
    return m_instance;
}

/*!
 * In theory, makes concrete subclass of WindowImp which depend on
 * the system.
 */
WindowImpPtr WindowSystemFactory::makeWindowImp() const
{
#ifdef X_WINDOW_SYSTEM
    return std::make_shared<XWindowImp>();
#endif

#ifdef PM_WINDOW_SYSTEM
    return std::make_shared<PMWindowImp>();
#endif
}
