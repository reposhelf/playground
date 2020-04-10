#ifndef WINDOWSYSTEMFACTORY_H
#define WINDOWSYSTEMFACTORY_H

#include <memory>

class WindowImp;

using WindowImpPtr = std::shared_ptr<WindowImp>;

class WindowSystemFactory
{
public:
    static WindowSystemFactory *instance();
    WindowImpPtr makeWindowImp() const;

protected:
    WindowSystemFactory() = default;

private:
    static WindowSystemFactory *m_instance;
};

#endif // WINDOWSYSTEMFACTORY_H
