#ifndef EQUATION_H
#define EQUATION_H
#include <string>
#include <stack>

namespace Equations {
    class Equation
    {
        public:
            Equation();
            virtual void toPrefix();
            virtual void toInfix();
            virtual void toPostfix();
            void setEquation(std::string);
            std::string getResult();
            bool isSign(std::string);
        protected:
            std::string equation;
            std::string result;
    };
}

#endif // EQUATION_H
