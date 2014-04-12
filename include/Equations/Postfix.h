#ifndef POSTFIX_H
#define POSTFIX_H
#include "Equations/Equation.h"

namespace Equations {
    class Postfix : public Equation
    {
        public:
            Postfix();
            void toInfix();
        protected:
        private:
            std::stack <std::string> buffer;
            void makeEquation(std::string);
    };
}

#endif // POSTFIX_H
