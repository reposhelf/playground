#include "tipcontainer.h"

// constructor()

TipContainer::TipContainer()
{
    initialize();
}

// ~destructor()

TipContainer::~TipContainer()
{
    qDeleteAll(m_tips);
    m_tips.clear();
}

// tip()

Tip TipContainer::tip(int index) const
{
    return *m_tips[index];
}

// count()

int TipContainer::count() const
{
    return m_tips.count();
}

// initialize()

void TipContainer::initialize()
{
    m_tips.append(new Tip(":/texts/tips/0001.htm", ":/images/tips/0001.png"));
    m_tips.append(new Tip(":/texts/tips/0002.htm"));
    m_tips.append(new Tip(":/texts/tips/0003.htm", ":/images/tips/0003.png"));
    m_tips.append(new Tip(":/texts/tips/0004.htm"));
    m_tips.append(new Tip(":/texts/tips/0005.htm"));
    m_tips.append(new Tip(":/texts/tips/0006.htm"));
    m_tips.append(new Tip(":/texts/tips/0007.htm"));
    m_tips.append(new Tip(":/texts/tips/0008.htm"));
    m_tips.append(new Tip(":/texts/tips/0009.htm"));
    m_tips.append(new Tip(":/texts/tips/0010.htm"));
    m_tips.append(new Tip(":/texts/tips/0011.htm"));
    m_tips.append(new Tip(":/texts/tips/0012.htm"));
    m_tips.append(new Tip(":/texts/tips/0013.htm"));
    m_tips.append(new Tip(":/texts/tips/0014.htm"));
    m_tips.append(new Tip(":/texts/tips/0015.htm", ":/images/tips/0015.png"));
    m_tips.append(new Tip(":/texts/tips/0016.htm", ":/images/tips/0016.png"));
}
