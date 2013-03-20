#ifndef MAIN_H
#define MAIN_H

#include <assert.h>
#include <iostream>
using namespace std;

#include "Core\ValueModel.h"
#include "Core\Expression.h"

#include "Fuzzy\And\AndMin.h"
#include "Fuzzy\And\AndMult.h"
#include "Fuzzy\Agg\AggMax.h"
#include "Fuzzy\Agg\AggPlus.h"
#include "Fuzzy\Or\OrMax.h"
#include "Fuzzy\Or\OrPlus.h"
#include "Fuzzy\Then\ThenMin.h"
#include "Fuzzy\Then\ThenMult.h"
#include "Fuzzy\Not\NotMinus.h"

#include "Fuzzy\Is\IsTriangle.h"
#include "Fuzzy\Is\IsTrapeze.h"
#include "Fuzzy\Is\IsTrapezeLeft.h"
#include "Fuzzy\Is\IsTrapezeRight.h"
#include "Fuzzy\Is\IsGaussian.h"
#include "Fuzzy\Is\IsBell.h"

#include "Fuzzy\Factory\FuzzyFactory.h"

#endif