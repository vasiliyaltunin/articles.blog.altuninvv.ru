#ifndef FOO_H
#define FOO_H

#include <QString>



class Foo
{
public:
    Foo (int foo);
    explicit Foo (QString str);
    int getFoo();
private:
  int m_foo;
};

int doBar(Foo foo);

#endif // FOO_H
