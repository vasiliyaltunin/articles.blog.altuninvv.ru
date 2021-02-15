#include "foo.h"

Foo::Foo (int foo) : m_foo (foo)
{
}

int Foo::getFoo()
{
    return m_foo;
}

Foo::Foo (QString str)
{
    this->m_foo = str.toInt();
}

int doBar(Foo foo)
{
    return foo.getFoo();
}
