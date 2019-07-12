#ifndef LEARN_VARIADIC_TEMPLATES_H
#define LEARN_VARIADIC_TEMPLATES_H
#include "command.h"
#include <iostream>
#include <type_traits>

template <class T>
typename std::enable_if<std::is_integral<T>::value,bool>::type
  is_odd (T i) {return bool(i%2);}

class IEmptyClass{

};
class IEmptyClass1{

};
template<typename T,class = typename std::enable_if<typeid(T) == typeid(IEmptyClass),bool>::type>
class uiDevAlertHandler : public T{
public:
    void print(){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

class learn_variadic_templates: public Command
{
public:
    void execute()
    {
        uiDevAlertHandler<IEmptyClass1,void> obj;
        is_odd(2);
    }

};
#endif // LEARN_VARIADIC_TEMPLATES_H
