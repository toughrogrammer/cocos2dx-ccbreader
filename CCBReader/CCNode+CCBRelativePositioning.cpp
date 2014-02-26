#include "CCNode+CCBRelativePositioning.h"
#include "CCBReader.h"

using namespace cocos2d;

NS_CC_EXT_BEGIN

CCPoint getAbsolutePosition(const CCPoint &position, 
							const CCPositionUnit xUnit, const CCPositionUnit yUnit,
							const int corner, 
							const CCSize &containerSize, 
							const char *pPropName)
{
    CCPoint positionInPoints;
    float x = 0;
    float y = 0;
    
    // Convert position to points
    if (xUnit == CCPositionUnitPoints) 
		x = position.x;
    else if (xUnit == CCPositionUnitUIPoints) 
		x = position.x * CC_CONTENT_SCALE_FACTOR();
    else if (xUnit == CCPositionUnitNormalized) 
		x = position.x * containerSize.width;
    
    if (yUnit == CCPositionUnitPoints) 
		y = position.y;
    else if (yUnit == CCPositionUnitUIPoints) 
		y = position.y * CC_CONTENT_SCALE_FACTOR();
    else if (yUnit == CCPositionUnitNormalized) 
		y = position.y * containerSize.height;
    
    // Account for reference corner
    if (corner == CCPositionReferenceCornerBottomLeft)
    {
        // Nothing needs to be done
    }
    else if (corner == CCPositionReferenceCornerTopLeft)
    {
        // Reverse y-axis
        y = containerSize.height - y;
    }
    else if (corner == CCPositionReferenceCornerTopRight)
    {
        // Reverse x-axis and y-axis
        x = containerSize.width - x;
        y = containerSize.height - y;
    }
    else if (corner == CCPositionReferenceCornerBottomRight)
    {
        // Reverse x-axis
        x = containerSize.width - x;
    }
    
    positionInPoints.x = x;
    positionInPoints.y = y;
    
    return positionInPoints;
}

void setRelativeScale(CCNode *pNode, float fScaleX, float fScaleY, int nType, const char* pPropName)
{
    CCAssert(pNode, "pNode should not be null");
    
    if (nType == kCCBScaleTypeMultiplyResolution)
    {
        float resolutionScale = CCBReader::getResolutionScale();
        
        fScaleX *= resolutionScale;
        fScaleY *= resolutionScale;
    }
    
    pNode->setScaleX(fScaleX);
    pNode->setScaleY(fScaleY);
}

NS_CC_EXT_END
