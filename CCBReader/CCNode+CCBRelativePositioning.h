#ifndef __CCB_CCNODE_RELATIVEPOSITIONING_H__
#define __CCB_CCNODE_RELATIVEPOSITIONING_H__

#include "cocos2d.h"
#include "ExtensionMacros.h"

NS_CC_EXT_BEGIN

typedef enum 
{
	CCPositionUnitPoints,
	CCPositionUnitUIPoints,
	CCPositionUnitNormalized,
} CCPositionUnit;

extern CCPoint getAbsolutePosition(const CCPoint &position, 
								   const CCPositionUnit xUnit, const CCPositionUnit yUnit,
								   const int corner, 
								   const CCSize &containerSize, 
								   const char *pPropName);

extern void setRelativeScale(CCNode *pNode, float fScaleX, float fScaleY, int nType, const char* pPropName);

NS_CC_EXT_END

#endif // __CCB_CCNODE_RELATIVEPOSITIONING_H__
