#include "mtgen.h"

float MTG::generate(){
    prevNum = mt();
    return static_cast<float>(prevNum) / mt.max();
}
