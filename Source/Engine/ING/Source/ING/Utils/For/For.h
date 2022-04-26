#pragma once

#define FOR_RANGE(I,START,END)\
for(size_t I = START; I < END; ++I)

#define FOR_EACH(ITEM,ARRAY)\
for (auto I = ARRAY.GetBegin(); !(I == ARRAY.GetEnd()); ++I)

#define FOR_EACH_LC(ITEM,ARRAY)\
for (auto I = ARRAY.begin(); !(I == ARRAY.end()); ++I)