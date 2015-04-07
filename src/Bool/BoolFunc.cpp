#include "Bool/BoolFunc.h"
#include "Bool/BoolOr.h"
#include "Bool/BoolAnd.h"
#include "Bool/BoolNot.h"

namespace SSARI {

BoolFunc::BoolFunc() : bVar(nullptr){}

BoolFunc::BoolFunc(string name) {
    bVar = shared_ptr<BoolVar>(new BoolVar(name));
}

BoolFunc::BoolFunc(shared_ptr<BoolVar> var) : bVar(var) {}


BoolFunc BoolFunc::operator|(const BoolFunc& rhs) {
    return BoolFunc(shared_ptr<BoolOr>(new BoolOr(this->bVar, rhs.bVar)));
}

BoolFunc BoolFunc::operator&(const BoolFunc& rhs) {
    return BoolFunc(shared_ptr<BoolAnd>(new BoolAnd(this->bVar, rhs.bVar)));
}

BoolFunc BoolFunc::operator!() {
    return BoolFunc(shared_ptr<BoolNot>(new BoolNot(this->bVar)));
}

shared_ptr<BoolTseitin> BoolFunc::getTseitin() {
    if(bVar)
        return bVar->getTseitin();
    return nullptr;
}

shared_ptr<BoolVar> BoolFunc::getBoolVar() {
    return this->bVar;
}

string BoolFunc::getName() const {
    if(bVar)
        return bVar->getName();
    return "";
}

string BoolFunc::toString() const {
    if(bVar)
        return bVar->toString();
    return "";
}



}

